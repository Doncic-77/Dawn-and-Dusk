from math import gcd

m,n,p=map(int,input().split())
dp=[[[0 for k in range(n+1)]for j in range(p+1)]for i in range(n+1)]
dp[0][0][0]=1
for a in range(p):
    for x in range(n+1):
        for b in range(n+1):
            if x+b>a or b>x or a-x-b>m-2*n:
                dp[x][a][b]=0
                continue
            if b+1<=n:
                dp[x][a+1][b+1]+=(x-b)*dp[x][a][b]
            if x+1<=n:
                dp[x+1][a+1][b]+=2*(n-x)*dp[x][a][b]
            dp[x][a+1][b]+=(m-2*n-(a-x-b))*dp[x][a][b]

s=0
c=0
for x in range(n+1):
    for b in range(n+1):
        s+=dp[x][p][b]

# print(sum(dp[n][p][b] for b in range(n+1)))
# print(sum(dp[n][p-1][b] for b in range(n+1)))
# print(sum(dp[x][p][b] for x in range(n+1) for b in range(n+1)))

for b in range(n+1):
    c+=dp[n][p][b]
for b in range(n+1):
    c-=(m-p+1)*dp[n][p-1][b]

# print(c,s, c/s)
if n == 0 and p == 0 :
    print('1/1')
elif c == 0 :
    print('0/1')
else :
    g=gcd(c,s)
    print(c//g,'/',s//g,sep='')