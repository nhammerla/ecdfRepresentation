//
//  ecdf.h
//  ecdf
//
//  Created by Nils on 19/03/2015.
//  Copyright (c) 2015 Nils Hammerla. All rights reserved.
//

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
