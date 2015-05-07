--[[
# Copyright (c) 2015, Nils Hammerla
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
--]]

function ecdfRep(data, components, notInPlace)
	local d = data
	local e, m
	
	-- are we doing it in place? (changing data in the process?)
	if notInPlace then
		d = data:clone()
	end
	
	-- get mean over all axes
	m = d:mean(1)
	
	-- get indeces for sorted array (ascending)
	local _, ind = d:sort(1)
	
	-- sort array in place
	for i=1,data:size(2) do
		d[{{},i}] = d[{{},i}]:index(1,ind[{{},i}])
	end
	
	-- index the right elements and add mean (transpose for compatibility with matlab etc)
	e = d:index(1, torch.linspace(1, d:size(1), components):round():long()):t():reshape(1,components*d:size(2))
	
	-- add mean and return
	return torch.cat(e,m,2)
end