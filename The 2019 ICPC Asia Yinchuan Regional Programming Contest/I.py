x,y,z=input().split()
x=int(x)
y=int(y)
a = 0

dd={}

now=0

for xx in "0123456789":
    dd[xx]=now
    now+=1

for xx in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
    dd[xx]=now
    now+=1

for xx in "abcdefghijklmnopqrstuvwxyz":
    dd[xx]=now
    now+=1

pp={}

for aa,bb in dd.items():
    pp[bb]=aa

now=0

for b in z:
    now=now*x+dd[b]


ans=[]
while now!=0:
    ans.append(pp[now%y])
    now//=y
if len(ans):
    print("".join(ans[::-1]))
else:
    print(0)
