//
// Created by intwi on 2025/01/15.
//

#include "audio/audio_clip.h"
#include <gtest/gtest.h>

using wwist::audio_engine::AudioClip;
using wwist::audio_engine::IAudioClip;

// TEST mono clip.
TEST(AudioClipTest, MakeAudioClipMono) {
	constexpr int n_frame	= 16;
	constexpr int n_ch		= 1;
	constexpr int s_rate	= 8000;
	constexpr int bd		= 16;

	// create raw data.
	auto* raw_data = new float[n_frame];
	for	(size_t i = 0; i < n_frame; ++i) {
		raw_data[i] = 1.f;
	}

	// make a clip.
	auto clip = std::make_shared<AudioClip>(raw_data, n_frame, n_ch, s_rate, bd);

	EXPECT_EQ(clip->num_frames(), n_frame);
	EXPECT_EQ(clip->num_channels(), n_ch);
	EXPECT_EQ(clip->sample_rate(), s_rate);
	EXPECT_EQ(clip->bit_depth(), bd);

	// data.
	for (size_t i = 0; i < clip->num_frames(); ++i) {
		EXPECT_FLOAT_EQ(clip->data()[0][i], raw_data[i]);
		EXPECT_NE(clip->data()[0][i], 2.f);
	}

	const auto size = sizeof(AudioClip);
	const auto i_size = sizeof(IAudioClip);
	std::cout << "AudioClip size: = " << size << std::endl;
	std::cout << "IAudioClip size: = " << i_size << std::endl;

	delete[] raw_data;
}

// TEST stereo clip.
TEST(AudioClipTest, MakeAudioClipStereo) {
	constexpr int n_frame	= 8192 * 8;
	constexpr int n_ch		= 2;
	constexpr int s_rate	= 8000;
	constexpr int bd		= 16;

	// create raw data.
	auto* raw_data = new float[n_frame * n_ch];
	for	(size_t i = 0; i < n_frame * n_ch; ++i) {
		raw_data[i] = i % 2 == 0 ? 1.f : -1.f;
	}
	// create actual data from raw data.
	auto* l_data = new float[n_frame];
	auto* r_data = new float[n_frame];
	float* actual[n_ch] = { l_data, r_data };
	for (size_t i = 0; i < n_frame; ++i) {
		l_data[i] = raw_data[i * n_ch];
		r_data[i] = raw_data[i * n_ch + 1];
	}


	// make a clip.
	auto clip = std::make_shared<AudioClip>(raw_data, n_frame, n_ch, s_rate, bd);

	EXPECT_EQ(clip->num_frames(), n_frame);
	EXPECT_EQ(clip->num_channels(), n_ch);
	EXPECT_EQ(clip->sample_rate(), s_rate);
	EXPECT_EQ(clip->bit_depth(), bd);

	// data.
	for (size_t ch = 0; ch < clip->num_channels(); ++ch) {
		for (size_t i = 0; i < clip->num_frames(); ++i) {
			EXPECT_FLOAT_EQ(clip->data()[ch][i], actual[ch][i]);
		}
	}

	const auto size = sizeof(AudioClip);
	const auto i_size = sizeof(IAudioClip);
	std::cout << "AudioClip size: = " << size << std::endl;
	std::cout << "IAudioClip size: = " << i_size << std::endl;

	delete[] raw_data;
	actual[0] = nullptr;
	actual[1] = nullptr;
	delete[] l_data;
	delete[] r_data;
}