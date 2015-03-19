function data = ecdfRep(data, components)
%
%   rep = ecdfRep(data, components)
%
%   Estimate ecdf-representation according to 
%     Hammerla, Nils Y., et al. "On preserving statistical characteristics of 
%     accelerometry data using their empirical cumulative distribution." 
%     ISWC. ACM, 2013.
%
%   Input: 
%       data        Nxd     Input data (rows = samples).
%       components  int     Number of components to extract per axis.
%
%   Output:
%       rep         Mx1     Data representation with M = d*components+d
%                           elements.
%
%   Nils Hammerla '15
%
m = mean(data,1)'; 
data = sort(data,1);
data = data(round(linspace(1,size(data,1), components)),:);
data = [data(:) ; m]; 
end