#ifndef SHARED_VAR3_H
#define SHARED_VAR3_H

#include <mutex>
#include <fifo.h>

extern void writeToFifo();
extern void readFromFifo();
extern std::mutex sharedVariableMutex;
extern Fifo gSharedFifo;
extern int putvalue;

#endif