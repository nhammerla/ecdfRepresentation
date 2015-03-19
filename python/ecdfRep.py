from numpy import *

def ecdfRep(data, components):
    #
    #   rep = ecdfRep(data, components)
    #
    #   Estimate ecdf-representation according to 
    #     Hammerla, Nils Y., et al. "On preserving statistical characteristics of 
    #     accelerometry data using their empirical cumulative distribution." 
    #     ISWC. ACM, 2013.
    #
    #   Input: 
    #       data        Nxd     Input data (rows = samples).
    #       components  int     Number of components to extract per axis.
    #
    #   Output:
    #       rep         Mx1     Data representation with M = d*components+d
    #                           elements.
    #
    #   Nils Hammerla '15
    #
    m = data.mean(0)
    data = sort(data, axis=0)
    data = data[int32(around(linspace(0,data.shape[0]-1,num=components))),:]
    data = data.flatten(1)
    return hstack((data, m))

if __name__ == '__main__':
    a = random.randn(100,3)
    e1 = ecdfRep(a,5)
    print e1
    print "all done"
