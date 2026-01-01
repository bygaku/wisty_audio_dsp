//
// Created by intwi on 2026/01/02.
//

#ifndef AUDIO_DSP_EFFECT_CHAIN_H
#define AUDIO_DSP_EFFECT_CHAIN_H

#include "interface/i_effect.h"
#include "audio_block.h"
#include <memory>
#include <vector>

namespace wwist::audio_engine {
	/**
	 * @brief Register an effect module to container and processing block.
	 */
	class EffectChain {
	public:
		/**
		 * @brief Register an effect module to the IEffect container.
		 * @param effect The module that inherits from IEffect.
		 */
		void Entry(std::unique_ptr<IEffect> effect) noexcept;

		/**
		 * @brief Processing and overwrite the input samples.
		 */
		void ProcessBlock(AudioBlock& block, const size_t& num_samples) noexcept;

	private:
		std::vector<std::unique_ptr<IEffect>> effects_;

	};

}

#endif //AUDIO_DSP_EFFECT_CHAIN_H