#pragma once

#include <cstdint>

class QueueBase {
public:
	virtual void push(uint8_t*) = 0;
	virtual uint8_t* pop() = 0;
	virtual ~QueueBase() = default;
};