#include <fifo.h>

Fifo::Fifo() {

    reset();
}

int Fifo::get() {
    int item = *frontp;
    move_frontp();
    if (full)
        full = false;
    return item;
}

void Fifo::put(int item) {
    *backp = item;
    move_backp();
    if (full)
        move_frontp();
    if (backp == frontp)
        full = true;
}

bool Fifo::is_empty() {
    return (frontp == backp) && !full;
}

bool Fifo::is_full() {
    return full;
}

void Fifo::reset() {
    frontp = buffer;
    backp = buffer;
    full = false;
}

// Helper function

bool Fifo::is_end(int *p_item) {
    return p_item == (buffer + FIFO_SIZE);
}

void Fifo::move_frontp() {
    frontp++;
    if (is_end(frontp))
        frontp = buffer;
}

void Fifo::move_backp() {
    backp++;
    if (is_end(backp))
        backp = buffer;
}