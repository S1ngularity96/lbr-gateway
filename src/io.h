/*
 * io.h
 *
 *  Created on: Jul 21, 2018
 *      Author: rambonator
 */

#ifndef SRC_IO_H_
#define SRC_IO_H_


#include <stdint>
#include "ioconfig.h"

namespace IO {
	void static setPin(uint8_t port, uint8_t pin, uint8_t value);

	void rxEnable();

	void rxDisable();
}


#endif /* SRC_IO_H_ */
