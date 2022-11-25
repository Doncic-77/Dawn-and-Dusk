#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct E{
	int l,to;
}e[N<<1];
int n,h[N],s[N],ma,rs;
void dfs(int x,int f,int dep){
	ma=max(ma,dep);
	for(int i=h[x];i;i=e[i].l){
		int to=e[i].to;
		if(to==f)continue;
		dfs(to,x,dep+1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		e[i<<1].to=x;e[i<<1].l=h[y];h[y]=i<<1;
		e[i<<1|1].to=y;e[i<<1|1].l=h[x];h[x]=i<<1|1;
	}
	for(int i=h[1];i;i=e[i].l){
		int to=e[i].to;
		dfs(to,1,1);
		rs+=ma;
		ma=0;
	}
	printf("%d\n",rs);
	return 0;
}