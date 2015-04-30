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

% Copyright (c) 2015, Nils Hammerla
% All rights reserved.
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
% 1. Redistributions of source code must retain the above copyright notice, this
%    list of conditions and the following disclaimer.
% 2. Redistributions in binary form must reproduce the above copyright notice,
%    this list of conditions and the following disclaimer in the documentation
%    and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
% ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
% WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
% DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
% ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
% (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
% LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
% ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
% SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

m = mean(data,1)'; 
data = sort(data,1);
data = data(round(linspace(1,size(data,1), components)),:);
data = [data(:) ; m]; 
end
