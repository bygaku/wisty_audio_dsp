//
// Created by intwi on 2026/01/10.
//

#ifndef AUDIO_DSP_I_AUDIO_CLIP_H
#define AUDIO_DSP_I_AUDIO_CLIP_H

#include <string>
#include <vector>

#include "utils/error_enum.h"
#include "binary/audio_info.h"

namespace wwist::audio_engine {
	/**
	 * @brief Represents the interface for an audio clip in the audio engine.
	 */
	class IAudioClip {
	public:
		/**
		 * @brief Virtual destructor.
		 */
		virtual ~IAudioClip() = default;

		/**
		 * @brief Retrieves the audio data buffer.
		 * @return View pointer to the raw audio buffer data.
		 */
		virtual const BUF_TYPE** data() noexcept = 0;

		/**
		 * @brief Retrieves the number of audio frames.
		 * @return Number of audio frames.
		 */
		virtual const MY_DWORD& num_frames() const noexcept = 0;

		/**
		 * @brief Retrieves the number of audio channels.
		 * @return Number of audio channels.
		 */
		virtual const MY_WORD& num_channels() const noexcept = 0;

		/**
		 * @brief Retrieves the sample rate.
		 * @return Sample rate in Hz.
		 */
		virtual const MY_DWORD& sample_rate() const noexcept = 0;

		/**
		 * @brief Retrieves the bit depth of the audio clip.
		 * @return A bit depth.
		 */
		virtual const MY_WORD& bit_depth() const noexcept = 0;

	};

}

#endif //AUDIO_DSP_I_AUDIO_CLIP_H