//
// Created by intwi on 2025/12/31.
//

#include <gtest/gtest.h>

#include "../include/lib/utils/data_type.h"
#include "../include/lib/audio/audio_block.h"
#include "../include/lib/audio/effect_chain.h"
#include "effect/gain.h"

using wwist::audio_engine::AudioBlock;
using wwist::audio_engine::EffectChain;
using wwist::audio_engine::MakeAudioBlock;
using wwist::BUF_TYPE;
using wwist::MY_DWORD;
using wwist::audio_engine::AudioBuffer;

using wwist::audio_engine::Gain;

// TEST audio block.
TEST(AudioBlockTest, MakeAudioBlockBasic) {
	constexpr size_t channels = 2;
	constexpr size_t capacity = 2;
	constexpr MY_DWORD sample_rate = 44100;
	BUF_TYPE  inputL[channels] = { 1.f, 2.f };
	BUF_TYPE  inputR[channels] = { 3.f, 4.f };
	BUF_TYPE* input_channels[channels]  = { inputL,  inputR  };

	BUF_TYPE  outputL[channels] = { 1.f, 2.f };
	BUF_TYPE  outputR[channels] = { 3.f, 4.f };
	BUF_TYPE* output_channels[channels] = { outputL, outputR };

	AudioBuffer buffer;
	buffer.ch.resize(channels, std::vector<BUF_TYPE>(2));
	buffer.ch[0] = { 1.f, 2.f };
	buffer.ch[1] = { 3.f, 4.f };

	AudioBlock excepted = MakeAudioBlock(buffer, sample_rate);
	AudioBlock actual {
		.in				= input_channels,
		.out			= output_channels,
		.num_channels	= channels,
		.num_frames		= capacity,
		.sample_rate	= sample_rate,
	};

	ASSERT_EQ(excepted.sample_rate, 	actual.sample_rate	);
	ASSERT_EQ(excepted.in[0][0],  		actual.in[0][0]		);
	ASSERT_EQ(excepted.in[0][1],  		actual.in[0][1]		);
	ASSERT_EQ(excepted.in[1][0],  		actual.in[1][0]		);
	ASSERT_EQ(excepted.in[1][1],  		actual.in[1][1]		);
	ASSERT_EQ(excepted.out[0][0], 		actual.out[0][0]	);
	ASSERT_EQ(excepted.out[0][1], 		actual.out[0][1]	);
	ASSERT_EQ(excepted.out[1][0], 		actual.out[1][0]	);
	ASSERT_EQ(excepted.out[1][1], 		actual.out[1][1]	);
	ASSERT_EQ(excepted.num_channels, 	actual.num_channels	);
	ASSERT_EQ(excepted.num_frames,   	actual.num_frames	);
}

// TEST gain effect.
TEST(GainEffectTest, GainEffectBasic) {
	constexpr size_t channels = 2;
	constexpr size_t frames = 4;

	BUF_TYPE  inputL[frames] = { 1.f, 2.f, 3.f, 4.f };
	BUF_TYPE  inputR[frames] = { 4.f, 3.f, 2.f, 1.f };
	BUF_TYPE* input[channels] = { inputL, inputR };

	BUF_TYPE outputL[frames] = { 1.f, 2.f, 3.f, 4.f };
	BUF_TYPE outputR[frames] = { 4.f, 3.f, 2.f, 1.f };
	BUF_TYPE* output[channels] = { outputL, outputR };

	AudioBlock expected{
		.in				= input,
		.out			= output,
		.num_channels	= channels,
		.num_frames		= frames,
		.sample_rate	= 44100,
	};
	Gain gain{1.0f};
	gain.ProcessBlock(expected);

	ASSERT_EQ(expected.out[0][0], output[0][0]);
	ASSERT_EQ(expected.out[0][1], output[0][1]);
	ASSERT_EQ(expected.out[1][0], output[1][0]);
	ASSERT_EQ(expected.out[1][1], output[1][1]);
}

TEST(GainEffectTest, GainEffectHalfReduce) {
	constexpr size_t channels = 2;
	constexpr size_t frames = 4;

	BUF_TYPE  inputL[frames] = { 1.f, 2.f, 3.f, 4.f };
	BUF_TYPE  inputR[frames] = { 4.f, 3.f, 2.f, 1.f };
	BUF_TYPE* input[channels] = { inputL, inputR };

	BUF_TYPE outputL[frames] = { 1.f, 2.f, 3.f, 4.f };
	BUF_TYPE outputR[frames] = { 4.f, 3.f, 2.f, 1.f };
	BUF_TYPE* output[channels] = { outputL, outputR };

	AudioBlock expected{
		.in				= input,
		.out			= output,
		.num_channels	= channels,
		.num_frames		= frames,
		.sample_rate	= 44100,
	};
	Gain gain{0.5f};
	gain.ProcessBlock(expected);

	ASSERT_EQ(expected.out[0][0], expected.in[0][0] * 0.5f);
	ASSERT_EQ(expected.out[0][1], expected.in[0][1] * 0.5f);
	ASSERT_EQ(expected.out[1][0], expected.in[1][0] * 0.5f);
	ASSERT_EQ(expected.out[1][1], expected.in[1][1] * 0.5f);
}

TEST(GainEffectTest, GainEffectTwoMulti) {
	constexpr size_t channels = 2;
	constexpr size_t frames = 4;

	BUF_TYPE  inputL[frames] = { 1.f, 2.f, 3.f, 4.f };
	BUF_TYPE  inputR[frames] = { 4.f, 3.f, 2.f, 1.f };
	BUF_TYPE* input[channels] = { inputL, inputR };

	BUF_TYPE outputL[frames] = { 1.f, 2.f, 3.f, 4.f };
	BUF_TYPE outputR[frames] = { 4.f, 3.f, 2.f, 1.f };
	BUF_TYPE* output[channels] = { outputL, outputR };

	AudioBlock expected{
		.in				= input,
		.out			= output,
		.num_channels	= channels,
		.num_frames		= frames,
		.sample_rate	= 44100,
	};
	Gain gain{2.f};
	gain.ProcessBlock(expected);

	ASSERT_EQ(expected.out[0][0], expected.in[0][0] * 2.f);
	ASSERT_EQ(expected.out[0][1], expected.in[0][1] * 2.f);
	ASSERT_EQ(expected.out[1][0], expected.in[1][0] * 2.f);
	ASSERT_EQ(expected.out[1][1], expected.in[1][1] * 2.f);
}
