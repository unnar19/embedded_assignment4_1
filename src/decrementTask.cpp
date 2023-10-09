#include <iostream>
#include <unistd.h>
#include "shared_var.h"

void decrementTask() {
    while (1) {

        sleep(7);

        sharedVariableMutex.lock();

        gSharedVariable--;
        std::cout << "Decrement Task: shared var is " << gSharedVariable << "\n";

        sharedVariableMutex.unlock();
    }
}