#include "TSQueue.h"


TSQueue::TSQueue()
{
	mHead = mTail = new Node();
}

void TSQueue::push(uint8_t* data) {
	std::lock_guard<std::mutex> lockGuard{mMutex};
	mTail->data = data;
	mTail->next = new Node();
	mTail = mTail->next;
}

uint8_t* TSQueue::pop() {
	std::lock_guard<std::mutex> lockGuard{ mMutex };
	if (mHead->next != nullptr) {
		auto result = mHead->data;
		auto newHead = mHead->next;
		delete mHead;
		mHead = newHead;
		return result;
	}
	return nullptr;
}

TSQueue::~TSQueue()
{
	std::lock_guard<std::mutex> lockGuard{mMutex};
	while (mHead != mTail)
	{
		if (mHead->data != nullptr) {
			delete[] mHead->data;
		}
		auto oldHead = mHead;
		mHead = mHead->next;
		delete oldHead;
	}
	if (mTail->data != nullptr) {
		delete[] mTail->data;
	}
	delete mTail;
}
