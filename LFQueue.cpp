
#include "LFQueue.h"


void LFQueue::push(uint8_t* data)
{
    std::atomic<ANode*> newNode = new ANode();
    newNode.load(std::memory_order_relaxed)->data = data;
    if (!mHead.load(std::memory_order_relaxed) && !mTail.load(std::memory_order_relaxed)) {
        mHead.store(newNode, std::memory_order_seq_cst);
        mTail.store(newNode, std::memory_order_seq_cst);
    }
    else {
        mTail.load(std::memory_order_seq_cst)->next.store(newNode, std::memory_order_seq_cst);
        mTail.store(newNode, std::memory_order_seq_cst);
    }
}

uint8_t* LFQueue::pop()
{
    ANode* oldHead = mHead.load();
    while (oldHead &&
        !mHead.compare_exchange_weak(oldHead, oldHead->next)) {
        oldHead = mHead.load();
    }
    return oldHead ? oldHead->data : nullptr;
}