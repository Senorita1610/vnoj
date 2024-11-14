n=int(input())
if n%4<2:
    z=1
    for i in range(n//4):
        z*=(4*i+2)
    print(z)
else:
    print(0)

