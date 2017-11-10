/* Code for this section inspired by Lab #5 Hint sheet 
(attached to original lab assignement page) */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "VoteOn.h"

int VoteOn(void *Instances[], int nInstances, int nSize) {
    
    int i, j, total;
    int max = 0;
    int same = 1;
    unsigned int row_max = -1;

    for (i = 0; i < nInstances; i++) {
        total = 0;
        // NOTE: For i = j, two values always equal, therefore not useful, therefore compare j = i+1 only
        for (j = i+1; j < nInstances; j++) {
            if (!memcmp(Instances[i], Instances[j], nSize)) total++;
        }
        if (total > max) {
            max = total;
            row_max = i;
        }
    }
    // return index of first item in majority, otherwise return -1.
    return(row_max);
}