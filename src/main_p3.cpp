#include <thread>
#include "shared_var3.h"

int main(void) {
    std::thread th1 (writeToFifo);
    std::thread th2 (readFromFifo);

    th1.join();
    th2.join();

    return 0;
}
