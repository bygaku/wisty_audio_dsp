//
// Created by intwi on 2026/01/02.
//

#ifndef AUDIO_DSP_DATA_TYPE_H
#define AUDIO_DSP_DATA_TYPE_H

#include <cstdint>

namespace wwist {
	typedef unsigned char  	MY_BYTE;
	typedef unsigned short 	MY_WORD;
	typedef unsigned long  	MY_DWORD;
	typedef float          	BUF_TYPE;

	typedef MY_DWORD		CHUNK_ID;	// FOURcc

	/**
	 * @brief creates a new 4-character code from four characters.
	 * @code
	 *  constexpr CHUNK_ID YOU_ID = CHUNK_ID('Y', 'O', 'U', ' ');
	 * @endcode
	*/
#define Chunk_ID(a, b, c, d) (a + (b << 8) + (c << 16) + (d << 24))
	constexpr CHUNK_ID RIFF_ID = Chunk_ID('R', 'I', 'F', 'F');
	constexpr CHUNK_ID LIST_ID = Chunk_ID('L', 'I', 'S', 'T');

}


#endif //AUDIO_DSP_DATA_TYPE_H
