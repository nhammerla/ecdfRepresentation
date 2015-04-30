/*
Copyright (c) 2015, Nils Hammerla
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

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
