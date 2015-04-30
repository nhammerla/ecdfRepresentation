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

#ifndef ecdf_ecdf_h
#define ecdf_ecdf_h
/*
 * ecdf(double input[], double output[], double tmp[], int numSamples, int numDims, int components);
 * 
 * Estimate ecdf-representation according to 
 *  Hammerla, Nils Y., et al. "On preserving statistical characteristics of 
 *  accelerometry data using their empirical cumulative distribution." 
 *  ISWC. ACM, 2013.
 *
 * INPUT is an array of double with NUMSAMPLES * NUMDIMS elements, where the first NUMSAMPLES are in the first "column" of
 *  the matrix, the second NUMSAMPLES elements are in the second columns, ... column <= NUMDIMS.
 * TMP is used for column-wise sorting and is a double array of size NUMSAMPLES
 * OUTPUT is an array of size NUMDIMS*COMPONENTS+NUMDIMS.
 */
extern void ecdfRep(double input[], double output[], double tmp[], int numSamples, int numDims, int components);
#endif
