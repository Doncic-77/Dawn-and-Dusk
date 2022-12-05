#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,a[N],s,x,y,rs;
void ck(int &x){(x>=k)&&(x-=k);}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),s=(s+a[i])%k;
    if(n%2==1){
        if(n%k==0){
            printf("%d\n0 0\n",s);
            return 0; 
        }
        n%=k;
        int g=__gcd(n,k);
        rs=s%g;
        while(s!=rs){
            int t=(k-s-1)/n+1;
            ck(x+=t);
            s=(s+1ll*t*n)%k;
        }
    }else {
        if((n/2)%k==0){
            printf("%d\n0 0\n",s);
            return 0; 
        }else if(n%k==0){
            n=(1ll*n*(n+1)/2)%k;
            int g=__gcd(n,k);
            rs=s%g;
            while(s!=rs){
                int t=(k-s-1)/n+1;
                ck(y+=t);
                s=(s+1ll*t*n)%k;
            }
            printf("%d\n%d %d\n",rs,x,y);
            return 0;
        }
        int X=k-(n+1)/2,Y=1;
        X=(X%k+k)%k;
        n=n/2;
        n%=k;
        int g=__gcd(n,k);
        rs=s%g;
        while(s!=rs){
            int t=(k-s-1)/n+1;
            x=(x+1ll*X*t)%k;
            ck(y+=t);
            s=(s+1ll*t*n)%k;
        }
    }
    printf("%d\n%d %d\n",rs,x,y);
    return 0;
}
