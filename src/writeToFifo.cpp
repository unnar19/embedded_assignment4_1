#include <iostream>
#include <unistd.h>
#include "shared_var3.h"
#include "fifo.h"



void writeToFifo() {
    while (1) {
        sleep(3);
        
        sharedVariableMutex.lock();

        if (!gSharedFifo.is_full()) {
            putvalue++;
            gSharedFifo.put(putvalue);
            std::cout << "Wrote " << putvalue << " to FIFO\n";
        } else {
            std::cout << "Fifo full! Could not write " << putvalue + 1 << " to FIFO\n";
        }
        
        sharedVariableMutex.unlock();
    }
}