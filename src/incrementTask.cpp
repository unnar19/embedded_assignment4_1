#include <iostream>
#include <unistd.h>
#include "shared_var.h"

void incrementTask() {
    while (1) {
        
        sleep(3);
        
        sharedVariableMutex.lock();

        gSharedVariable++;
        std::cout << "Increment Task: shared var is " << gSharedVariable << "\n";
        
        sharedVariableMutex.unlock();
    }
}