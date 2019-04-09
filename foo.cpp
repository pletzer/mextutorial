#include <mex.h>
#include <matrix.h>

/*
Example of a mex'ed function, ie a C++ function that can be called from 
MATLAB. The function has the followig signature:

[y1, y2] foo(x1, x2, x3)

x1, x2, x3 are matrices an we assume size(x1) == size(x2)

To compile the function type:
> mex foo.cpp

*/

// all mex'ed functions have this interface
// nlhs: number of output variables
// plhs: list of outputs (plhs[0], plhs[1], ...plhs[nlhs-1])
// nrhs: number of input variables
// prhs: list of inputs (prhs[0], prhs[1], ... prhs[nrhs-1])
void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[]) {

	// get the number of elements of the first input
    size_t ntot12 = mxGetNumberOfElements(prhs[0]);

    // get the number of elements of the second intput
    size_t n3 = mxGetNumberOfElements(prhs[2]);

    // this converts the inputs into C/C++ primitive arrays, which
    // you can then manipulate
    double* x1 = mxGetPr(prhs[0]);
    double* x2 = mxGetPr(prhs[1]);
    double* x3 = mxGetPr(prhs[2]);

    // sometimes you need to get the dimensions of the matlab matrix
    const mwSize* dims = mxGetDimensions(prhs[0]); 

    // let's create the return matrix y a real matrix of size dims[0] * dims[1]
    mxArray* y1Matrix = mxCreateDoubleMatrix(dims[0], dims[1], mxREAL);
    double* y1 = mxGetPr(y1Matrix);

    // fill in the elements of y1
    for (size_t i = 0; i < ntot12; ++i) {
        y1[i] = x1[i] + x2[i];
    }

    // compute the sum of the third input 
    double y2 = 0;
    for (size_t i = 0; i < n3; ++i) {
        y2 += x3[i];
    }

    // associate the return values
    plhs[0] = y1Matrix;
    plhs[1] = mxCreateDoubleScalar(y2);

}