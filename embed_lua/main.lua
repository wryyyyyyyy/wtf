-- simple benchmark
local x = os.clock()
local s = 0

for i=1,1000000 do
	s=s+1
end

print(string.format("Version: %s\nCycles: %d\nElapsed time: %.2f\n", _VERSION, s, os.clock() - x))
