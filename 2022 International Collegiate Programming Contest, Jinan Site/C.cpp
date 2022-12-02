#include<bits/stdc++.h>
using namespace std;
const int N=505,M=998244353;
struct E{
  int l,to;
}e[N<<1];
int n,h[N],sz[N],sn[N],dp[N][N][N],cnt[N],rs[N][N],Fact[N],invc[N],tp,t[N];
int pw(int x,int t){
  int rs=1;
  for(;t;t>>=1,x=1ll*x*x%M)if(t&1)rs=1ll*rs*x%M;
  return rs;
}
void dfs1(int x,int f){
  int s=0,w=1;
  sz[x]=1;
  for(int i=h[x];i;i=e[i].l){
    int to=e[i].to;
    if(to==f)continue;
    dfs1(to,x);
    sz[x]+=sz[to];
    s++;
    w=1ll*w*s%M*cnt[to]%M;
  }
  sn[x]=s;
  cnt[x]=w;
}
void dfs2(int x,int f){
  ++tp;
  if(x!=1){
    for(int i=0;i<=n;++i){
      for(int o=0;o<=sz[f];++o){
        dp[x][i][o]=dp[f][i][o];
      }
    }
    for(int i=0;i<=n;++i){
      for(int j=0;j<=sn[f];++j){
        if(i>=sz[x]&&j)dp[x][i][j]=(dp[x][i][j]-1ll*cnt[x]*dp[x][i-sz[x]][j-1])%M;
        dp[x][i][j]=1ll*invc[x]*dp[x][i][j]%M;
        if(dp[x][i][j]<0)dp[x][i][j]+=M;
      }
    }
  }else dp[1][0][0]=1;
  //if(x==2){
  //  for(int i=0;i<=n;++i)for(int o=0;o<=sn[x];++o)printf("%d%c",dp[x][i][o],(o==sz[x])? '\n':' ');
  //}
  if(x!=1){
    for(int i=0;i<=n-tp;++i){
      t[i]=0;
      for(int o=0;o<=sn[f];++o){
        int w=1ll*Fact[o]*Fact[sn[f]-1-o]%M*dp[x][i][o]%M;
        rs[x][i+tp]=(rs[x][i+tp]+1ll*cnt[x]*w)%M;
        t[i]=(t[i]+w)%M;
        dp[x][i][o]=0;
      }
    }
    for(int i=0;i<=n;++i)dp[x][i][0]=t[i];
  }else rs[x][1]=cnt[x]; 
  
  for(int i=h[x];i;i=e[i].l){
    int to=e[i].to;
    if(to==f)continue;
    for(int o=n;~o;--o){
      for(int u=sn[x];~u;--u){
        dp[x][o][u]=1ll*dp[x][o][u]*cnt[to]%M;
        if(o>=sz[to]&&u)dp[x][o][u]=(dp[x][o][u]+1ll*cnt[to]*dp[x][o-sz[to]][u-1])%M;
      }
    }
  }
 
  for(int i=h[x];i;i=e[i].l){
    int to=e[i].to;
    if(to==f)continue;
    dfs2(to,x);
  }
  tp--;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<n;++i){
    int x,y;
    scanf("%d %d",&x,&y);
    e[i<<1].to=y;e[i<<1].l=h[x];h[x]=i<<1;
    e[i<<1|1].to=x;e[i<<1|1].l=h[y];h[y]=i<<1|1;
  }
  dfs1(1,0);
  Fact[0]=1;
  for(int i=1;i<=n;++i)Fact[i]=1ll*Fact[i-1]*i%M;
  for(int i=1;i<=n;++i)invc[i]=pw(cnt[i],M-2);
  dfs2(1,0);
  for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)printf("%d%c",rs[i][j],(j==n)? '\n':' ');
}