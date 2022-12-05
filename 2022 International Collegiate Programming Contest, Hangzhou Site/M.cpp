#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,h[N],l[N],dfn,r[N],v[N],tid[N];
long long w[N],sum,tr[N<<2],p[N],rs=2e18;
struct E{
    int to,l,w;  
}e[N<<1];
void dfs(int x,int f){
    l[x]=dfn+1;
    if(v[x])p[++dfn]=w[x],sum+=w[x];
    for(int i=h[x];i;i=e[i].l){
        int to=e[i].to;
        if(to==f)continue;
        w[to]=w[x]+e[i].w;
        dfs(to,x);
    }
    r[x]=dfn;
}
void js(int z,int y,int c){
    if(z==y){
        p[z]-=p[z-1];
        tr[c]=abs(p[z]);
        tid[z]=c;
        return;
    }
    int mid=(z+y)>>1;
    js(mid+1,y,c<<1|1);
    js(z,mid,c<<1);
    tr[c]=__gcd(tr[c<<1],tr[c<<1|1]);
    
}
void Upd(int z){
    if(z>k)return; 
    int c=tid[z];
//    printf("___%d\n",c);
    tr[c]=abs(p[z]);
    for(c>>=1;c;c>>=1)tr[c]=__gcd(tr[c<<1],tr[c<<1|1]);
}
void dfs2(int x,int f){
//    printf("___%d %d %lld\n",x,f,tr[1]);
    
    rs=min(rs,sum/tr[1]);
//    printf("________%d %d\n",x,f);
    for(int i=h[x];i;i=e[i].l){
        int to=e[i].to,ew=e[i].w;
        if(to==f)continue;
        p[1]+=ew;
        p[l[to]]-=ew<<1;
        p[r[to]+1]+=ew<<1;
        Upd(1),Upd(l[to]),Upd(r[to]+1);
        int t=r[to]-l[to]+1;
        sum+=1ll*(k-t-t)*e[i].w;
        dfs2(to,x);
        sum-=1ll*(k-t-t)*e[i].w;
        p[1]-=ew;
        p[l[to]]+=ew<<1;
        p[r[to]+1]-=ew<<1;
        Upd(1),Upd(l[to]),Upd(r[to]+1);
    }
}
int main(){
    scanf("%d %d",&n,&k);
    if(k==1)return puts("0"),0;
    for(int i=1;i<=k;++i){
        int x;
        scanf("%d",&x);
        v[x]=1;  
    }
    for(int i=1;i<n;++i){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        e[i<<1].to=x;e[i<<1].l=h[y];h[y]=i<<1;
        e[i<<1|1].to=y;e[i<<1|1].l=h[x];h[x]=i<<1|1;
        e[i<<1].w=e[i<<1|1].w=w;
    }
    dfs(1,0);
//    printf("%lld\n", sum) ;
//    printf("p___%lld %lld %lld\n",p[1],p[2],p[3]);
    js(1,k,1);
    dfs2(1,0);
//    puts("???");
    printf("%lld\n",rs<<1);
}