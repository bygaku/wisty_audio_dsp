//
// Created by intwi on 2026/01/02.
//

#ifndef AUDIO_DSP_EFFECT_CHAIN_H
#define AUDIO_DSP_EFFECT_CHAIN_H

#include "interface/i_effect.h"
#include "interface/i_component.h"
#include "audio_block.h"
#include <memory>
#include <vector>

namespace wwist::audio_engine {
	/**
	 * @brief Register an effect module to container and processing block.
	 */
	class EffectChain : public IComponent {
	public:
		/**
		 * @brief Destructor to clear the effect container.
		 */
		~EffectChain() override {
			effects_.clear();
		};

		/**
		 * @brief Initialize the effect chain and all registered effects.
		 * @return Error code indicating success or failure.
		 */
		wwistErr initialize() override;

		/**
		 * @brief Terminate the effect chain and release resources.
		 * @return Error code indicating success or failure.
		 */
		wwistErr terminate() override;

		/**
		 * @brief Add an effect to the end of the processing chain.
		 * @param effect Unique pointer to the effect to be added.
		 */
		void Entry(std::unique_ptr<IEffect> effect) noexcept;

		/**
		 * @brief Process an audio block through the entire chain of effects.
		 * @param block The audio block to be processed.
		 */
		void ProcessBlock(AudioBlock& block) noexcept;

	private:
		std::vector<std::unique_ptr<IEffect>> effects_; // Container for the registered effect modules.

	};

}

#endif //AUDIO_DSP_EFFECT_CHAIN_H