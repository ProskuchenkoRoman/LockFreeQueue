#pragma once

#include <cstdint>
#include <atomic>

struct Node {
	uint8_t* data = nullptr;
	Node* next = nullptr;
};

struct ANode {
    uint8_t* data;
    std::atomic<ANode*> next;
};