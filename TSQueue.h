#pragma once

#include <mutex>

#include "QueueBase.h"
#include "Node.h"

class TSQueue : public QueueBase {
public:
	TSQueue();
	void push(uint8_t* data) override;
	uint8_t* pop() override;
	~TSQueue();
private:
	std::mutex mMutex;
	Node* mHead = nullptr;
	Node* mTail = nullptr;
};