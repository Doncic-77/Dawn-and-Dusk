#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=1e9;
int n,m1,m2,s,w[N],h[N],f[N],cnt[N],q[N],ql,v[N];
int fi(int x){
	return f[x]==x? x:f[x]=fi(f[x]);
}
struct Edge{
	int to,l,w;
}e[N<<1];
struct D{
	int x,w;
	bool operator < (const D&t)const{
		return w>t.w;
	}
};
priority_queue<D>Q;
vector<int>P[N];
struct Edge2{
	int x,y,w;
};
vector<Edge2>V[N];
int main(){
	scanf("%d %d %d %d",&n,&m1,&m2,&s);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m1;++i){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		int a=fi(x),b=fi(y);
		f[a]=b;
		e[i<<1].to=y;e[i<<1].l=h[x];h[x]=i<<1;
		e[i<<1|1].to=x;e[i<<1|1].l=h[y];h[y]=i<<1|1;
		e[i<<1].w=e[i<<1|1].w=z;
	}
	for(int i=1;i<=n;++i)P[fi(i)].push_back(i);
	for(int i=1;i<=m2;++i){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		int a=f[x],b=f[y];
		V[a].push_back({x,y,z});
		cnt[b]++;
//		printf("___%d %d\n",a,b);
	}
	memset(w,63,sizeof(w));
	w[s]=0;
	for(int i=1;i<=n;++i){
		int x=f[i];
		if(v[x])continue;
		v[x]=1;
		if(!cnt[x])q[++ql]=x;
	}
	for(int i=1;i<=ql;++i){
		int nw=q[i];
//		printf("     ___%d %d\n",i,nw);
		for(auto x:P[nw]){
			if(w[x]<inf)Q.push((D){x,w[x]});
		}
		while(!Q.empty()){
			D t=Q.top();
			Q.pop();
			if(t.w!=w[t.x])continue;
			for(int j=h[t.x];j;j=e[j].l){
				int to=e[j].to;
				if(w[to]>t.w+e[j].w){
					Q.push((D){to,w[to]=t.w+e[j].w});
				}
			}
		}
		for(auto t:V[nw]){
			cnt[f[t.y]]--;
			if(!cnt[f[t.y]])q[++ql]=f[t.y];
			if(w[t.x]<inf)w[t.y]=min(w[t.y],w[t.x]+t.w);
		}
	}
	for(int i=1;i<=n;++i){
		if(w[i]>=inf)puts("NO PATH");
		else printf("%d\n",w[i]);
	}
	return 0;
}
