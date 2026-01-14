//
// Created by intwi on 2026/01/14.
//

#include "audio_clip.h"

using namespace wwist::audio_engine;

AudioClip::AudioClip(BUF_TYPE *data
				   , const MY_DWORD &num_frames
				   , const MY_WORD &num_chs
				   , const MY_DWORD &sample_rate
				   , const MY_WORD &b_depth)
		: num_frames_(num_frames)
		, num_channels_(num_chs)
		, sample_rate_(sample_rate)
		, bit_depth_(b_depth)
{
	data_.resize(num_chs);

	for (size_t ch = 0; ch < num_chs; ++ch) {
		data_[ch].resize(num_frames);
		for (size_t i = 0; i < num_frames; ++i) {
			data_[ch][i] = data[ch * num_frames + i];
		}
	}

	view_.clear();
}

const wwist::BUF_TYPE ** AudioClip::data() noexcept {
	if (view_.size() != data_.size()) {
		view_.resize(data_.size());
		for (size_t ch = 0; ch < data_.size(); ++ch) {
			view_[ch] = data_[ch].data();
		}
	}

	return view_.data();
}

const wwist::MY_DWORD & AudioClip::num_frames() const noexcept  {
	return num_frames_;
}

const wwist::MY_WORD & AudioClip::num_channels() const noexcept {
	return num_channels_;
}

const wwist::MY_DWORD & AudioClip::sample_rate() const noexcept {
	return sample_rate_;
}

const wwist::MY_WORD & AudioClip::bit_depth() const noexcept {
	return bit_depth_;
}
