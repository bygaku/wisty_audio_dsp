//
// Created by intwi on 2026/01/13.
//

#include "audio_source.h"

using namespace wwist::audio_engine;

void AudioSource::ProcessBlock(const AudioBlock& block) {
	if (!is_playing_ || read_pos_ >= clip_->num_frames()) return;

	const size_t frames = std::min(block.num_frames, static_cast<MY_DWORD>(clip_->num_frames() - read_pos_));
	const size_t ch = std::min(clip_->num_channels(), block.num_channels);

	for (size_t c = 0; c < ch; ++c) {
		const float* src = clip_->data()[c] + read_pos_;
		float* dst = block.out[c];
		for (size_t f = 0; f < frames; ++f) {
			dst[f] += src[f] * volume_;
		}
	}

	read_pos_ += frames;
}

void AudioSource::SetVolume(float volume) noexcept {
	volume_ = std::clamp(volume, 0.f, 1.5f);
}

void AudioSource::SetClip(const std::shared_ptr<IAudioClip> &clip) noexcept {
	clip_ = clip;
}

void AudioSource::SetLooping(bool loop) noexcept {
	loop_ = loop;
}

void AudioSource::Play() noexcept {
	is_playing_.store(true, std::memory_order_relaxed);
}

void AudioSource::Stop() noexcept {
	is_playing_.store(false, std::memory_order_relaxed);
}

bool AudioSource::IsPlaying() const noexcept {
	return is_playing_.load(std::memory_order_relaxed);
}

wwist::MY_DWORD AudioSource::GetReadPosition() const noexcept {
	return read_pos_;
}
