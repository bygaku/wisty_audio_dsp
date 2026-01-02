//
// Created by intwi on 2026/01/03.
//

#ifndef AUDIO_DSP_I_COMPONENT_H
#define AUDIO_DSP_I_COMPONENT_H

#include "../error_enum.h"

namespace wwist {

	/**
	 * @brief Base interface for components requiring lifecycle management.
	 *
	 * Provides a standard way to initialize and terminate system components,
	 * ensuring resources are allocated and freed correctly.
	 */
	class IComponent {
	public:
		/**
		 * @brief a Virtual destructor to ensure proper cleanup of derived classes.
		 */
		virtual ~IComponent() = default;

		/**
		 * @brief Initializes the component and allocates the necessary resources.
		 * @return Error code indicating success or the type of failure.
		 */
		virtual wwistErr initialize() = 0;

		/**
		 * @brief Terminates the component and releases all allocated resources.
		 * @return Error code indicating success or the type of failure.
		 */
		virtual wwistErr terminate()  = 0;
	};
}
#endif //AUDIO_DSP_I_COMPONENT_H