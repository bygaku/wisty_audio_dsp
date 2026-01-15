//
// Created by intwi on 2026/01/02.
//

#ifndef AUDIO_DSP_AUDIO_BUFFER_H
#define AUDIO_DSP_AUDIO_BUFFER_H

#include "../utils/data_type.h"
#include <vector>

namespace wwist::audio_engine {
	/**
	 * @brief linear buffer to store audio data.
	 * - monaural: 1
	 * - stereo: 2
	 */
	struct AudioBuffer {
		std::vector<std::vector<BUF_TYPE>> ch; // Access as ch[channel][frame].

		/**
		 * TODO: added helper methods.
		 * e.g., const size_t& GetNumFrames()
		 *		 const size_t& GetNumChannels()
		 *		 BUF_TYPE* GetLChannelSamples()
		 *		 BUF_TYPE* GetRChannelSamples()
		 *		 BUF_TYPE* GetInterleavingSamples() <- front is L channel.
		 *
		 *	and Channel enum class.
		 *	enum class CHANNELTYPE {
		 *		M,
		 *		S.
		 *	}
		 */
	};
}

#endif //AUDIO_DSP_AUDIO_BUFFER_H