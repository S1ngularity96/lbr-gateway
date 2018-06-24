/*
 * layer1.h
 *
 *  Created on: Jun 23, 2018
 *      Author: ted
 */

#ifndef SRC_RADIO_LAYER1_LAYER1_H_
#define SRC_RADIO_LAYER1_LAYER1_H_

#include <avr/io.h>

namespace LAYER1 {

/* Port and pin connected to transmitter module DATA */
#define DATA_OUT_PORT PORTD
#define DATA_OUT_PIN PD7

void init();

void sendBit(bool bit);

void onTimeSlice();

}
#endif /* SRC_RADIO_LAYER1_LAYER1_H_ */
