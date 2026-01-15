//
// Created by intwi on 2026/01/13.
//

#ifndef AUDIO_DSP_AUDIO_SOURCE_H
#define AUDIO_DSP_AUDIO_SOURCE_H

#include <algorithm>

#include "i_audio_clip.h"
#include "audio_block.h"

#include <memory>

namespace wwist::audio_engine {

	class AudioSource {
	public:
		/**
		 * @brief Default constructor.
		 */
		AudioSource()
			: clip_(nullptr), volume_(1.f), read_pos_(0), loop_(false), is_playing_(false)
		{}

		/**
		 * @brief Default destructor.
		 */
		~AudioSource() = default;

		/**
		 * @brief Process audio block.
		 * @param block Audio buffer info.
		 */
		void ProcessBlock(const AudioBlock& block);

#pragma region Setters
		/**
		 * @brief Set volume for audio source.
		 * @param volume Volume value between 0.0f and 1.5f.
		 *
		 * @note Default volume value is 1.f (100%).
		 */
		void SetVolume(float volume) noexcept;

		/**
		 * @brief Set audio clip for audio source.
		 * @param clip The shared_ptr to AudioClip.
		 */
		void SetClip(const std::shared_ptr<IAudioClip>& clip) noexcept;

		/**
		 * @brief Set looping for audio source.
		 * @param loop True to enable looping, false to disable.
		 */
		void SetLooping(bool loop) noexcept;

		/**
		 * @brief Change is_playing to true.
		 */
		void Play() noexcept;

		/**
		 * @brief Change is_playing to false.
		 */
		void Stop() noexcept;

#pragma endregion
#pragma region Getters

		/**
		 * @brief Check if audio is playing.
		 * @return True if audio is playing, false otherwise.
		 */
		bool IsPlaying() const noexcept;

		/**
		 * @brief Get current read position in audio source.
		 * @return Current read position.
		 */
		MY_DWORD GetReadPosition() const noexcept;

		/**
		 * @brief Get current volume of audio source.
		 * @return Current volume.
		 */
		float GetVolume() const { return volume_; }

		/**
		 * @brief Check if audio source is looping.
		 * @return True if audio source is looping, false otherwise.
		 */
		bool IsLooping() const { return loop_; }
#pragma endregion

	private:
		std::shared_ptr<IAudioClip> clip_;
		std::atomic<bool>			is_playing_;
		MY_DWORD					read_pos_;
		bool						loop_;

		float volume_;

	};


}

#endif //AUDIO_DSP_AUDIO_SOURCE_H