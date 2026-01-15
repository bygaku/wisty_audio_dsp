//
// Created by intwi on 2026/01/03.
//

#ifndef AUDIO_DSP_ERROR_ENUM_H
#define AUDIO_DSP_ERROR_ENUM_H

namespace wwist {

	/**
	 * @brief Error codes for the wwist audio engine components.
	 */
	enum class wwistErr {
		SUCCESS = 0,
		INVALID_PARAM,
		OUT_OF_MEMORY,
		NOT_SUPPORTED,
		INTERNAL_ERROR,
		FILE_NOT_FOUND,
		FILE_OPEN_ERROR,
	};

}

#endif //AUDIO_DSP_ERROR_ENUM_H