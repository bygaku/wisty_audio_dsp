//
// Created by intwi on 2025/12/31.
//

#include <gtest/gtest.h>

#include "../include/lib/data_type.h"
#include "../include/lib/audio/audio_block.h"
#include "../include/lib/audio/effect_chain.h"

using wwist::audio_engine::AudioBlock;
using wwist::audio_engine::EffectChain;
using wwist::audio_engine::MakeAudioBlock;
using wwist::BUF_TYPE;
using wwist::MY_DWORD;
using wwist::audio_engine::AudioBuffer;

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