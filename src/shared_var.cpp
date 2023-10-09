#include "shared_var.h"

std::mutex sharedVariableMutex;
int gSharedVariable = 0;