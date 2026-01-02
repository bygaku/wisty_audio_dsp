//
// Created by intwi on 2026/01/02.
//

#ifndef AUDIO_DSP_GAIN_H
#define AUDIO_DSP_GAIN_H

#include "interface/i_effect.h"

namespace wwist::audio_engine {
	/**
	 * @brief Gain Effect.
	 */
	class Gain final : public IEffect {
	public:
		/**
		 * @brief Constractor
		 * @param gain Initial gain value.
		 */
		explicit Gain(const float& gain = 1.f) : gain_(gain) {
		}

		void ProcessBlock(AudioBlock &block) noexcept override {
			for (auto i = 0; i < block.num_channels; ++i) {
				for (auto j = 0; j < block.num_frames; ++j) {
					block.out[i][j] = block.in[i][j] * gain_;
				}
			}
		};

	private:
		float gain_;

	};

}

#endif //AUDIO_DSP_GAIN_H