/*
 * layer3.h
 *
 *  Created on: Jul 12, 2018
 *      Author: rambonator
 */

#ifndef SRC_RADIO_LAYER3_LAYER3_H_
#define SRC_RADIO_LAYER3_LAYER3_H_

#define PACKET_CODE_DATA 0
#define PACKET_CODE_ACK 1

#define TIMEOUT 255
#define TIMEOUT_MAX_RESEND 3

#include <stdint.h>
#include "../databuffer.h"
#include "../../util/configExtern.h"


namespace LAYER3 {

	/**
	 * This function handles the layer 3 specific timing actions.
	 */
	void onTime();

	/**
	 * This function examinates if a certain  dataset needs to be sended.
	 */
	bool onHandlingNeeded(DataBuffer<TRANSMIT_BUFFER_SIZE> &databuffer);

	/**
	 * This function creates the and sends the packets that needs to be sended.
	 */
	bool sendData(DataBuffer<TRANSMIT_BUFFER_SIZE> &databuffer);
}




#endif /* SRC_RADIO_LAYER3_LAYER3_H_ */
