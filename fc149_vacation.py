n,d=list(map(int,input().split()))
r=[];s=0;m=0
for i in range(n):
    r.append(input())
for i in range(d):
    f=True
    for j in range(n):
        if r[j][i]=='x':
            f=False
    if f:
        s+=1
    else:
        s=0
    if s>m:
        m=s
print(m)

