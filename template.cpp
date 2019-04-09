#include <mex.h>
#include <matrix.h>

// nlhs: number of output variables
// plhs: list of outputs (plhs[0], plhs[1], ...plhs[nlhs-1])
// nrhs: number of input variables
// prhs: list of inputs (prhs[0], prhs[1], ... prhs[nrhs-1])
void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[]) {

    plhs[0] = mxCreateDoubleScalar(y);

}
