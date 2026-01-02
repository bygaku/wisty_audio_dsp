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
		/**
		 * @brief Destructor
		 */
		virtual ~IEffect() = default;

		/**
		 * @brief Processes a block of audio data.
		 * @param block The audio block containing input/output buffers and metadata.
		 */
		virtual void ProcessBlock(AudioBlock& block) noexcept = 0;

		/**
		 * @brief Get whether this module is active.
		 * @attention No Discard.
		 * @return module state.
		 */
		[[nodiscard]] bool IsActive() const noexcept { return is_active_; }

		/**
		 * @brief Set the life of this module.
		 * @param is_active true or false
		 */
		void SetActive(const bool& is_active) noexcept { is_active_ = is_active; }

	protected:
		bool is_active_ = true;
	};

}

#endif //AUDIO_DSP_I_EFFECT_H