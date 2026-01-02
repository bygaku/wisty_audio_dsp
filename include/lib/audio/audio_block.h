//
// Created by intwi on 2026/01/02.
//

#ifndef AUDIO_DSP_AUDIO_BLOCK_H
#define AUDIO_DSP_AUDIO_BLOCK_H

#include "data_type.h"
#include "audio_buffer.h"

namespace wwist::audio_engine {
	/**
	 * @brief View of an audio buffer.
	 * @remark Does not own the memory.
	 */
	struct AudioBlock {
		BUF_TYPE**	in;		// Access as in[channel][frame].
		BUF_TYPE**	out;	// Access as out[channel][frame].
		size_t		num_channels;
		size_t		num_frames;
		MY_DWORD	sample_rate;
	};

	/**
	 * @brief Creates AudioBlock.
	 * @param buf Reference to the AudioBuffer containing audio data.
	 * @param s_rate The sample rate to be assigned to the AudioBlock.
	 * @return A configured AudioBlock representing a view of the provided buffer.
	 * @remark The generated AudioBlock does not own the memory of the buffer. Modifications to
	 *         the AudioBlock's channel access pointers will affect the original buffer.
	 * @remark The returned AudioBlock's in and out pointers reference the same channel data.
	 */
	[[nodiscard]] inline AudioBlock MakeAudioBlock(AudioBuffer& buf, const size_t& s_rate) {
		AudioBlock block{};
		block.sample_rate  = s_rate;
		block.num_channels = buf.ch.size();
		block.num_frames   = buf.ch.empty() ? 0 : buf.ch[0].size();

		std::vector<BUF_TYPE*> ch_ptrs;
		ch_ptrs.resize(block.num_channels);
		for (size_t ch = 0; ch < block.num_channels; ++ch) {
			ch_ptrs[ch] = buf.ch[ch].data();
		}

		block.in  = ch_ptrs.data();
		block.out = ch_ptrs.data();

		return block;
	};
}

#endif //AUDIO_DSP_AUDIO_BLOCK_H