#include <iostream>
#include <unistd.h>
#include "shared_var3.h"
#include "fifo.h"

void readFromFifo() {
    int value;
    while (1) {
        
        sleep(7);
        
        sharedVariableMutex.lock();

        value = gSharedFifo.get();
        std::cout << "Read " << value << " from FIFO\n";
        
        sharedVariableMutex.unlock();
    }
}