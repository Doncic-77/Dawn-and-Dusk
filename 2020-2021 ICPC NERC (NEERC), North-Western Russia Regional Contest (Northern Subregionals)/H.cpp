#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,v[N],c,sn[N][2],cnt=1,m;
double w[2][55],rs,p2[55];
void Ad(int nw,int x,int y,int s,int fl){
//	printf("___%d %d %d\n",nw,x,y);
	if(x==0){
		if(!fl)rs+=1;
		else rs+=p2[s];
		v[nw]=1;
		return;
	}
	if(v[nw])fl=1,s=0;
	int u=(y>>(x-1))&1;
	if(!sn[nw][u])sn[nw][u]=++cnt;
	Ad(sn[nw][u],x-1,y,s+1,fl);
}
void dfs(int nw,int dep,int s,int fl){
	if(dep==n)return;
//	printf("_____%d %d %d %d  %lf\n",nw,v[nw],s,fl,w[fl][s]);
	if(v[nw])fl=1,s=0;
	else rs+=w[fl][s];
	if(sn[nw][0])dfs(sn[nw][0],dep+1,s+1,fl);
	else {
		for(int i=dep+1,cnt=1;i<n;++i,cnt<<=1){
			rs+=cnt*w[fl][s+i-dep];
		}
	}
	if(sn[nw][1])dfs(sn[nw][1],dep+1,s+1,fl);
	else {
		for(int i=dep+1,cnt=1;i<n;++i,cnt<<=1){
			rs+=cnt*w[fl][s+i-dep];
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	double k=1;
	for(int i=1;i<=n;++i){
		p2[i]=1-k;
		k/=2;
	}
	for(int i=1;i<=n;++i){
		double k=1;
		for(int j=1;j<i;++j){
			w[0][i]+=1.0/j/(j+1)*(1-k);
			k/=2;
		}
		w[1][i]=w[0][i];
		w[0][i]+=1.0/i;
		w[1][i]+=1.0/i*(1-k);
	}
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		x=n-x;
		y+=(1<<x)-1;
		Ad(1,x,y,1,0);
	}
//	printf("%lf\n",rs);
	dfs(1,0,1,0);
	printf("%.12f\n",rs);
	return 0;
}