//
// Created by intwi on 2025/12/31.
//

#ifndef AUDIO_DSP_RING_BUFFER_H
#define AUDIO_DSP_RING_BUFFER_H

#include <cstdint>
#include "../../private_header/buffer_type.h"
#include <vector>

namespace wwist::audio::buffer {

	/**
	 * @brief Generic ring buffer for audio samples or arbitrary data.
	 * @tparam T Sample type stored in the buffer (e.g., float, short).
	 */
	template<typename T>
	struct RingBuffer {
		std::vector<T> data;	// Data in buffer.
		int32_t capacity{};		// Maximum number of elements the ring buffer can hold.
		int32_t read_pos{};		// Current read position in the buffer.
	};

	/**
	 * @brief Make a ring buffer for T type samples.
	 * @tparam T Sample type stored in the buffer (e.g., short, float).
	 * @param capacity Number of samples to allocate.
	 * @return The Ring buffer instance.
	 */
	template<Sample T>
	RingBuffer<T> MakeRingBuffer(const int& capacity) {
		// Make buffer instance.
		RingBuffer<T> buf;
		buf.data.resize(static_cast<std::size_t>(capacity));
		buf.capacity = capacity;
		buf.read_pos = 0;

		return buf;
	}
}

#endif //AUDIO_DSP_RING_BUFFER_H