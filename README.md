# mextutorial

A short tutorial showing how to extend Matlab with C++. The goal is to convert 
```
function [y1, y2] = fooSlow(x1, x2, x3)
    y1 = x1 + x2;
    y2 = sum(sum(x3));
end
```
to C++. The corresponding C++ file is `foo.cpp`. 


## How to run the example

In MATLAB type
```
mex foo.cpp
```

Create two three random matrices x1, x2 and x3 with `size(x1) == size(x2)`. Apart from this the matrices can be anything. For instance,
```
x1 = rand(1000, 2000); x2 = x1; x3 = rand(100,50);
```
Then call foo:
```
[y1, y2] = foo(x1, x2, x3);
```

## Important points to remember

 1. The name of the C++ file (without extension) becomes the name of the function
 2. Unlike MATLAB, C++ uses 0-based indexing, `x1[0]` is the first element. 
 3. Create the return objects using `mxCreate*`. MATLAB will take ownership of the objects, i.e. free the memory when the object can no longer be accessed. 
 4. When working with MATLAB matrices, work with flat arrays in C++. All array elements are stored contiguously in memory. The first index varies fastest. So `a(i, j)` in MATLAB becomes `a[i + j*n]` in C++ if `n` is the number of columns. 

