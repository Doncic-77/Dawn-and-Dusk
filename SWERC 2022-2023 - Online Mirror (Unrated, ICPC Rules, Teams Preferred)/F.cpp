#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,T,k,h[N],s[N],rs[N];
struct E{
	int l,to;
}e[N<<1];;
void slv(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)h[i]=s[i]=0;
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		e[i<<1].to=y;e[i<<1].l=h[x];h[x]=i<<1;
		e[i<<1|1].to=x;e[i<<1|1].l=h[y];h[y]=i<<1|1;
		s[x]++,s[y]++;
	}
	if(m==n*(n-1)/2){
		k=3;
		for(int i=1;i<=m;++i){
			int x=e[i<<1].to,y=e[i<<1|1].to;
			if(min(x,y)==n-1){
				rs[i]=3;
			}else if(max(x,y)==n){
				rs[i]=2;
			}else rs[i]=1;
		}
	}else {
		int rt=0;
		for(int i=1;i<=n;++i)if(s[i]<n-1)rt=i;
		k=2;
		for(int i=1;i<=m;++i)rs[i]=1;
		for(int i=h[rt];i;i=e[i].l)rs[i>>1]=2;
	}
	printf("%d\n",k);
	for(int i=1;i<=m;++i)printf("%d ",rs[i]);
	puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)slv();
	return 0;
}
