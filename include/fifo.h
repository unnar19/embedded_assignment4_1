#ifndef FIFO_H
#define FIFO_H

#include <mutex>

const int FIFO_SIZE = 5;

class Fifo
{
public:
    Fifo();
    int get();
    void put(int item);
    bool is_empty();
    bool is_full();
    void reset();

private:
    bool is_end(int *p_item);
    void move_frontp();
    void move_backp();

    int buffer[FIFO_SIZE];
    int *frontp, *backp;
    bool full;
};



void writeToFifo();
void readFromFifo();

#endif // FIFO_H