//
// Created by intwi on 2025/12/31.
//

#ifndef AUDIO_DSP_BUFFER_TYPE_H
#define AUDIO_DSP_BUFFER_TYPE_H

#include <type_traits>

namespace wwist::audio_engine {
	/**
	 * @brief Concept that restricts T to float or short.
	 */
	template<typename T>
	concept Sample = std::is_same_v<T, float>
				  || std::is_same_v<T, short>;

}
#endif //AUDIO_DSP_BUFFER_TYPE_H