#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,T,w[N],a[N],h[N],dp[N][5],X,Y,f[N],rs,ans;
struct E{
	int l,to;
}e[N<<1];
void Max(int &x,int y){(x<y)&&(x=y);}
void dfs(int x){
	int ma2=0;
	for(int i=h[x];i;i=e[i].l){
		int to=e[i].to;
		if(to==f[x])continue;
		f[to]=x;
		dfs(to);
		Max(dp[x][4],dp[x][1]+dp[to][3]+a[x]);
		Max(dp[x][4],dp[x][2]+dp[to][2]+a[x]);
		Max(dp[x][4],dp[to][2]+ma2);
		Max(dp[x][4],dp[x][3]+dp[to][1]);
		
		Max(dp[x][3],dp[to][3]+a[x]);
		Max(dp[x][3],dp[x][1]+dp[to][2]+a[x]);
		Max(dp[x][3],ma2+dp[to][1]+a[x]);
		Max(dp[x][3],dp[x][2]+dp[to][1]);
		
		Max(ma2,dp[to][2]);
		
		Max(dp[x][2],dp[x][1]+dp[to][1]);
		Max(dp[x][1],dp[to][1]);
	}
	dp[x][1]+=a[x];
	dp[x][2]+=a[x];
	Max(dp[x][2],ma2);
	
	Max(ans,dp[x][1]);
	Max(ans,dp[x][2]);
	Max(ans,dp[x][3]);
	Max(ans,dp[x][4]);
//	printf("___%d  %d %d %d %d\n",x,dp[x][1],dp[x][2],dp[x][3],dp[x][4]);
}
int main(){	
	scanf("%d",&n);
	if(n==1){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		e[i<<1].to=x;e[i<<1].l=h[y];h[y]=i<<1;
		e[i<<1|1].to=y;e[i<<1|1].l=h[x];h[x]=i<<1|1;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
 