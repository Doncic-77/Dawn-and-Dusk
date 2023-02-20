#include<bits/stdc++.h>
using namespace std;
const int N=305;
int n,h,T,k,a[N],H[N][N];
long long dp[N][N];
struct E{
	int l,to;
}e[N<<1];;
void slv(){
	scanf("%d %d",&n,&h);
	memset(dp,63,sizeof(dp));
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=n;i;--i){
		for(int j=i;j<=n;++j){
			H[i][j]=(a[j]-a[i]+1)/2;
			if(i==j)dp[i][j]=0;
			if(H[i][j]>h)break;
			for(int k=i;k<j;++k){
				int w=H[i][j]*2-1-H[i][k]-H[k+1][j];
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+w);
			}
		}
	}
	for(int i=n;i;--i){
		for(int j=i;j<=n;++j){
			if(H[i][j]<h)dp[i][j]+=h-H[i][j];
			for(int k=i;k<j;++k){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
//	printf("%lld\n",dp[1][1]);
	printf("%lld\n",dp[1][n]);
}
int main(){
//	scanf("%d",&T);
	T=1;
	while(T--)slv();
	return 0;
}
