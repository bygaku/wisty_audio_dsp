//
// Created by intwi on 2026/01/10.
//

#ifndef AUDIO_DSP_WAV_CLIP_H
#define AUDIO_DSP_WAV_CLIP_H

#include <string_view>

#include "utils/data_type.h"
#include "utils/error_enum.h"
#include "interface/i_audio_clip.h"
#include "binary/wave.h"

namespace wwist::audio_engine {

	class AudioClip final : public IAudioClip {
	public:
		/**
		 * @brief Constructor
		 * @param data Pointer to audio data buffer.
		 * @param num_frames Number of audio frames.
		 * @param num_chs Number of audio channels.
		 * @param sample_rate Sample rate in Hz.
		 * @param b_depth A bit depth.
		 */
		explicit AudioClip(BUF_TYPE*		data
						 , const MY_DWORD&	num_frames
						 , const MY_WORD&	num_chs
						 , const MY_DWORD&	sample_rate
						 , const MY_WORD&	b_depth
						 );

		~AudioClip() override = default;

		const BUF_TYPE** data() noexcept override;

		const MY_DWORD& num_frames() const noexcept override;

		const MY_WORD& num_channels() const noexcept override;

		const MY_DWORD& sample_rate() const noexcept override;

		const MY_WORD& bit_depth() const noexcept override;

	private:
		MY_DWORD num_frames_;
		MY_WORD  num_channels_;
		MY_DWORD sample_rate_;
		MY_WORD  bit_depth_;

		std::vector<std::vector<BUF_TYPE>>	 data_;		// [ch][frame]
		mutable std::vector<const BUF_TYPE*> view_;

	};

}

#endif //AUDIO_DSP_WAV_CLIP_H