//
// Created by intwi on 2026/01/02.
//

#ifndef AUDIO_DSP_GAIN_H
#define AUDIO_DSP_GAIN_H

#include "interface/i_effect.h"
#include <atomic>

namespace wwist::audio_engine {
	/**
	 * @brief A basic audio effect that applies a linear gain (amplification/attenuation) to the input signal.
	 */
	class Gain final : public IEffect {
	public:
		/**
		 * @brief Constructor.
		 * @param gain Initial linear gain value. Defaults to 1.0 (unity gain).
		 */
		explicit Gain(float gain = 1.f) : gain_linear_(gain) {
		}

		/**
		 * @brief Processes the audio block by applying the current gain value to all samples.
		 * @param block The audio block containing input/output buffers and metadata.
		 */
		void ProcessBlock(AudioBlock &block) noexcept override {
			const float g = gain_linear_.load(std::memory_order_relaxed);
			const size_t num_channels = block.num_channels;
			const size_t num_frames   = block.num_frames;

			for (size_t ch = 0; ch < num_channels; ++ch) {
				const auto* in  = block.in[ch];
				auto* out = block.out[ch];

				for (size_t i = 0; i < num_frames; ++i) {
					out[i] = in[i] * g;
				}
			}
		};

		/**
		 * @brief Sets a new gain value.
		 * @remark This method is thread-safe and can be called from the UI or controller thread.
		 * @param new_gain The new linear gain factor.
		 */
		void SetGain(float new_gain) noexcept {
			gain_linear_.store(new_gain, std::memory_order_relaxed);
		}

	private:
		std::atomic<float> gain_linear_; // Current gain factor stored as an atomic float for thread-safe access.

	};

}

#endif //AUDIO_DSP_GAIN_H