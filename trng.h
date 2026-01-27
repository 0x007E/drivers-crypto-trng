/**
 * @file trng.h
 * @brief Header file with declarations and macros for the True Random Number Generator (TRNG) module.
 * 
 * This file provides function prototypes, type definitions, and constants for managing a True Random Number Generator that collects entropy bits, applies Von Neumann correction, and stores the resulting random data in a configurable buffer.
 * 
 * The TRNG library is designed for use in embedded systems where nondeterministic randomness is required, such as for cryptographic operations, random initialization data, or simulation purposes.
 * 
 * @author g.raf
 * @date 2026-01-27
 * @version 1.0 Release
 * @copyright
 * Copyright (c) 2026 g.raf
 * Released under the GPLv3 License. (see LICENSE in repository)
 * 
 * @note This file is part of a larger embedded project and is subject to the license specified in the repository. For updates, documentation, and the complete revision history, see the project's GitHub repository.
 * 
 * @see https://github.com/0x007e/driver-crypto-trng "TRNG driver library"
 */

#ifndef TRNG_H_
#define TRNG_H_
	
	#ifndef TRNG_BUFFER_SIZE
		/**
		 * @def TRNG_BUFFER_SIZE
		 * @brief Size of the internal random data buffer in bytes.
		 *
		 * This macro defines the number of bytes the TRNG (True Random Number Generator) uses internally to store generated random bits temporarily. The buffer is filled until it reaches the specified size.
		 *
		 * @note The default value is 10 bytes, but it can be redefined before including the header file to adjust the buffer size.
		 * 
		 * @warning A larger buffer size increases memory usage but allows for more random data to be collected before processing.
		 *
		 * @see trng_buffer(), trng_buffer_status()
		 */
		#define TRNG_BUFFER_SIZE 10UL
	#endif
	
	/**
	 * @enum TRNG_Buffer_t
	 * @brief Represents the current fill status of the TRNG data buffer.
	 *
	 * @details
	 * This enumeration indicates the current state of the internal True Random Number Generator (TRNG) buffer used to store random bits. It helps determine whether the buffer is empty, currently being filled with new data, or already full.
	 */
	enum TRNG_Buffer_t
	{
		TRNG_Buffer_Empty = 0,   /**< The buffer is empty; no random data has been written yet. */
		TRNG_Buffer_Filling,     /**< The buffer is being filled with random bits. */
		TRNG_Buffer_Full         /**< The buffer is full and ready for retrieval or reset. */
	};

	/**
	 * @typedef TRNG_Buffer
	 * @brief Alias for enum TRNG_Buffer_t representing the TRNG buffer status type.
	 */
	typedef enum TRNG_Buffer_t TRNG_Buffer;
	
                       void trng_init(void);
	                   void trng_next_bit(unsigned char bit);
	            TRNG_Buffer trng_buffer_status(void);
	volatile unsigned char* trng_buffer(void);
	                   void trng_reset(void);

#endif /* TRNG_H_ */