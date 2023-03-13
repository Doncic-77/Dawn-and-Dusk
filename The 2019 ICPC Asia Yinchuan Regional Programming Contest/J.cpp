#include<bits/stdc++.h>
using namespace std;
const int N=8e5+5;
int n,m,h[N],f[N],Ef[N],ew[N],dp[N],hh[N],cntc,id[N],ecnt;
long long ans,rs[N],ma,ww[N];
struct E{
	int l,to,w;
}e[N<<1];
struct EE{
	int l,to;
	long long w;
}ee[N<<1];
vector<int>V[N];
vector<int>W[N];
void dfs(int x,int ef){
	dp[x]=dp[f[x]]+1;
	for(int i=h[x];i;i=e[i].l){
		if(i==ef)continue;
		int to=e[i].to;
		if(dp[to]){
			if(dp[to]>dp[x])continue;
			++cntc;
			long long s=e[i].w;
			int y=x;
			id[i>>1]=cntc;
			V[cntc].push_back(to);
			while(y!=to){
				s+=ew[y];
				id[Ef[y]]=cntc;
				V[cntc].push_back(y);
				y=f[y];
			}
			ans-=s;
			W[cntc].push_back(0);
			y=x;
			long long s2=e[i].w;
			while(y!=to){
				W[cntc].push_back(min(s-s2,s2));
				s2+=ew[y];
				y=f[y];
			}
		}else {
			Ef[to]=i>>1;
			f[to]=x;
			ew[to]=e[i].w;
			dfs(to,i^1);
		}
	}
}
void dfs2(int x,int f){
//	printf("___%d %d\n",x,f);
	for(int i=hh[x];i;i=ee[i].l){
		int to=ee[i].to;
		if(to==f)continue;
		rs[to]=rs[x]+ee[i].w;
		ma=max(ma,rs[to]);
		dfs2(to,x);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		ans+=w<<1;
		e[i<<1].to=y;e[i<<1].l=h[x];h[x]=i<<1;
		e[i<<1|1].to=x;e[i<<1|1].l=h[y];h[y]=i<<1|1;
		e[i<<1].w=e[i<<1|1].w=w;
	}
//	printf("%lld\n",ans);
	dfs(1,0);
//	printf("%lld\n",ans-ma);
	for(int i=1;i<=m;++i){
		int x=e[i<<1].to,y=e[i<<1|1].to,w=e[i<<1].w;
		if(!id[i]){
			++ecnt;
			ee[ecnt<<1].to=y;ee[ecnt<<1].l=hh[x];hh[x]=ecnt<<1;
			ee[ecnt<<1|1].to=x;ee[ecnt<<1|1].l=hh[y];hh[y]=ecnt<<1|1;
			ee[ecnt<<1].w=ee[ecnt<<1|1].w=w;
//			printf("______%d %d %d\n",x,y,w);
		}
	}
	for(int i=1;i<=cntc;++i){
		for(int j=0;j<V[i].size();++j){
			int x=V[i][j]; 
			++ecnt;
			int y=n+i;
			ee[ecnt<<1].to=y;ee[ecnt<<1].l=hh[x];hh[x]=ecnt<<1;
			ee[ecnt<<1|1].to=x;ee[ecnt<<1|1].l=hh[y];hh[y]=ecnt<<1|1;
			ee[ecnt<<1].w=ee[ecnt<<1|1].w=-W[i][j];
//			printf("______%d %d %lld\n",x,y,-ww[x]);
		}
	}
	dfs2(1,0);
	printf("%lld\n",ans-ma);
	return 0;
}
