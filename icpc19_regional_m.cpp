a,b,c,n=map(int,input().split())
if a==0 or b==0 or c==0 or (a+b+c)<n or n<3:
    print("NO")
else:
    print("YES")

