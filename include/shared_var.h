#ifndef SHARED_VAR_H
#define SHARED_VAR_H

#include <mutex>

extern void decrementTask();
extern void incrementTask();
extern std::mutex sharedVariableMutex;
extern int gSharedVariable;

#endif