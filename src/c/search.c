#include "search.h"

int get_total_frequency (const int count, const int frequency[BLOCK]) {
    int total = 0;

    for(int i = 0; i < count; i++)
    {
        total += frequency[i];
    }

    return total;
}

int get_every_frequency (const int count, const int frequency[BLOCK]) {
    int every = 1;

    for(int i = 0; i < count; i++)
    {
        if(frequency[i] == 0) {
            every = 0;
            return every;
        }
    }

    return every;
}