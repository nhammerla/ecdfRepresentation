//
//  ecdf.c
//  ecdf
//
//  Created by Nils on 19/03/2015.
//  Copyright (c) 2015 Nils Hammerla. All rights reserved.
//

#include <stdlib.h>
#include <math.h>
#include "ecdfRep.h"

// for qsort
static int compare (const void * a, const void * b)
{
    if (*(double*)a > *(double*)b)
        return 1;
    else if (*(double*)a < *(double*)b)
        return -1;
    else
        return 0;
}

void ecdfRep(double input[], double output[], double tmp[], int numSamples, int numDims, int components)
{
    double mm;
    double inc;
    int offset;
    int offsetR;
    int pos[components];
    
    // increase for ecdf^-1 points (0, 1inc, 2inc, 3inc, ...)
    inc = ((double) numSamples - 1.0) / ((double) components - 1.0);
    // pre-calculate positions
    for (int i=0; i<components; i++)
        pos[i] = (int) (round(i*inc));
    
    // pre-calculate positions
    for (int d = 0; d < numDims; d++)
    {
        // get offset for data
        offset =  (int) d*numSamples;
        offsetR = (int) d*components;
        // get samples along dimension for sorting
        // Also: calculate mean
        mm = 0.0;
        for (int j=0; j < numSamples; j++)
        {
            tmp[j] = input[offset+j];
            mm += input[offset+j];
        }
        mm /= numSamples; // mean
        
        // sort per column
        qsort(tmp, numSamples, sizeof(double), compare);
        
        /* Get the data from the right positions in the sorted array.
         * In sorted data:
         * sup( P(X<=x) == p ) is at position p/length(perDim), or p*inc in
         * our case here.
         */
        for (int j=0; j < components; j++)
            output[(int) (offsetR+j)] = tmp[pos[j]];
        
        // save mean
        output[(int) (numDims*components+d)] = mm;
    }
}