#include <mex.h>
#include <matrix.h>

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[]) {


    size_t ntot12 = mxGetNumberOfElements(prhs[0]);
    size_t n3 = mxGetNumberOfElements(prhs[2]);

    // get the input
    double* x1 = mxGetPr(prhs[0]);
    double* x2 = mxGetPr(prhs[1]);
    double* x3 = mxGetPr(prhs[2]);

    // create y1
    const mwSize* dims = mxGetDimensions(prhs[0]); 
    mxArray y1Matrix = mxCreateDoubleMatrix(dims[0], dims[1]);
    double* y1 = mxGetPr(y1Matrix);
    for (size_t i = 0; i < n12; ++i) {
        y1[i] = x1[i] + x2[i];
    }

    double y2 = 0;
    for (size_t i = 0; i < n3; ++i) {
        y2 += x3[i];
    }

    // associate the return values
    plhs[0] = y1Matrix;
    plhs[1] = mxCreateDoubleScalar(y2);

}