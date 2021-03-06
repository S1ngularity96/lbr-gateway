/*
 * databuffer.h
 *
 *  Created on: Jul 2, 2018
 *      Author: rambonator
 */

#ifndef SRC_RADIO_DATABUFFER_H_
#define SRC_RADIO_DATABUFFER_H_

#include "dataset.h"
#include <stdint.h>
#include <string.h>
#include <assert.h>


typedef uint16_t Buffersize;

template <Buffersize Size>
class DataBuffer {
public:
	DataBuffer() {
		readIndex = 0;
		writeIndex = 0;
		space = Size;
	}

	const DataSet * peekFront() {
		if(isEmpty()) {
			return nullptr;
		}
		const DataSet * data = &dataSetArray[readIndex];
		return data;
	}

	bool isEmpty() {
		return (space == Size);
	}

	bool isFull() {
		return (space == 0);
	}

	Buffersize size() {
		return (Size - space);
	}

	Buffersize spaceRemaining() {
		return space;
	}

	bool pushBack(DataSet &dataset) {
		if(isFull()) {
			return false;
		}
		dataSetArray[writeIndex] = dataset;
		writeIndex = (writeIndex + 1)%Size;
		space -= 1;
		return true;
	}

	DataSet popFront() {
		assert(!isEmpty());
		DataSet dataset = dataSetArray[readIndex];
		readIndex = (readIndex + 1)%Size;
		space += 1;
		return dataset;
	}


private:
	DataSet dataSetArray[Size];
	volatile Buffersize readIndex;
	volatile Buffersize writeIndex;
	volatile Buffersize space;

};


#endif /* SRC_RADIO_DATABUFFER_H_ */
