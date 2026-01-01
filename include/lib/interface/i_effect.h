//
// Created by intwi on 2026/01/01.
//

#ifndef AUDIO_DSP_I_EFFECT_H
#define AUDIO_DSP_I_EFFECT_H

#include "audio/audio_block.h"

namespace wwist::audio_engine {

	/**
	 * @brief Effect interface.
	 */
	class IEffect {
	public:
		virtual ~IEffect() = default;
		virtual void ProcessBlock(AudioBlock& block, const size_t& num_samples) noexcept = 0;
	};

}

#endif //AUDIO_DSP_I_EFFECT_H