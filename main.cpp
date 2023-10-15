#include <iostream>

#include <thread>

#include "LFQueue.h"
#include "TSQueue.h"
#include "HelpFunctions.h"
#include "Constants.h"

int main() {
    std::cout << "MAIN STARTED" << std::endl;
    TSQueue queueIn;
    TSQueue queueOut;
    for (uint32_t arrayNumber = 0; arrayNumber < NUMBER_OF_ARRAYS; ++arrayNumber) {
        auto random_array = generateRandomArray();
        queueIn.push(random_array);
    }

    std::thread th1{ computeSHA256, std::ref(queueIn), std::ref(queueOut)};
    std::thread th2{ computeSHA256, std::ref(queueIn), std::ref(queueOut)};
    std::thread th3{ computeSHA256, std::ref(queueIn), std::ref(queueOut)};
    std::thread th4{ computeSHA256, std::ref(queueIn), std::ref(queueOut)};
    std::thread th5{ computeSHA256, std::ref(queueIn), std::ref(queueOut)};
    std::thread th6{ computeSHA256, std::ref(queueIn), std::ref(queueOut)};

    std::cout << "Threads started" << std::endl;

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();

    std::cout << "Threads finished" << std::endl;

    return 0;
}