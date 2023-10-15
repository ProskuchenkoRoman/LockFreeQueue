#pragma once

#include <memory>
#include <atomic>

#include "SHA256.h"
#include "QueueBase.h"
#include "Node.h"

class LFQueue : public QueueBase
{
public:
    void push(uint8_t* data) override;
    uint8_t* pop() override;
private:
    std::atomic<ANode*> mHead = nullptr;
    std::atomic<ANode*> mTail = nullptr;
};

