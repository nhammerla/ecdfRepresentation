# ECDF Representation for accelerometer data
This repository contains source-code for calculating the (badly named) representation from: Hammerla, Nils Y., et al. "On preserving statistical characteristics of accelerometry data using their empirical cumulative distribution." ISWC. ACM, 2013.

Both the matlab and python version should be straightforward to use.

To use the MEX interface to the C-version in MATLAB, simply change to the matlab directory in this repository and run:
```
>> mex ecdfMexRep.c ecdfRep.c
```

Comparing the different versions reveals what speedup you can expect from the MEX version:
```
>> a = randn(100,3);
>> tic; for i=1:5000, ecdfRep(a,15); end; toc
Elapsed time is 0.206755 seconds.
>> tic; for i=1:5000, ecdfMexRep(a,15); end; toc
Elapsed time is 0.067991 seconds.
```
In this cass, MEX took around a third of the time to complete. 

