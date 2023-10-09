#include <thread>
#include "shared_var.h"


int main(void) {
    std::thread th1 (incrementTask);
    std::thread th2 (decrementTask);

    th1.join();
    th2.join();

    return 0;
}
