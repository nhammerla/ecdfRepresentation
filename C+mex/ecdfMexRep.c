
#include <math.h>
#include "mex.h"
#include "matrix.h"
#include "ecdfRep.h"

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
    int numSamples;
    int numDim;
    int components;
    
    numSamples = mxGetM(prhs[0]);
    numDim = mxGetN(prhs[0]);
    components = mxGetScalar(prhs[1]);
    
    // reserve space for output
    plhs[0] = mxCreateDoubleMatrix(1,numDim*components+numDim,mxREAL);
    
    // tmp-array for storing (sorted) data
    double perDim[numSamples];
    
    ecdfRep(mxGetPr(prhs[0]), mxGetPr(plhs[0]), perDim, numSamples, numDim, components);
}