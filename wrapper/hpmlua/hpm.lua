local hpm = require('lhpm')

for key,value in pairs(hpm) do
    print("found member " .. key);
end

print(hpm.init(hpm.SIMD.SSE))

print(hpm.version())

v = hpm.vec4(1,10,10,3)
y = hpm.vec4(1)


v[1] = 1
print(v)
print(y)
print(v:x())
print(v:y())

z = v * 2.0
print(z)
z = v + y
print(z)

print(v:length())
print(v:normalize())

print(v[0])
print(v.x)
print(v == y)
print(-v)

hpm.release()
