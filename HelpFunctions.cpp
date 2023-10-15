#include <iostream>

#include <cstdint>
#include <ctime>
#include <thread>

#include "HelpFunctions.h"
#include "SHA256.h"
#include "Constants.h"
#include "QueueBase.h"

void computeSHA256(QueueBase& queue, QueueBase& outQueue) {
    uint8_t* array1 = nullptr;
    uint8_t* array2 = nullptr;

    for (array1 = queue.pop(); array1 != nullptr;) {
        for (uint8_t times = 0; times < TIMES_SHA256; ++times) {
            SHA256 sha256;
            sha256.update(array1, CHUNK_SIZE);
            array2 = sha256.digest();
            std::swap(array1, array2);
            delete[] array2;
        }
        outQueue.push(array1);
        array1 = queue.pop();
    }

}

uint8_t* generateRandomArray() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    uint8_t* randomArray = new uint8_t[CHUNK_SIZE]();

    for (uint32_t i = 0; i < CHUNK_SIZE; ++i) {
        randomArray[i] = static_cast<uint8_t>(std::rand() % 256);
    }

    return randomArray;
}
