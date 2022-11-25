#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,dp[N*2][11][11],a[N],b[N];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i]);
		a[i]=-a[i];
		b[i]=-b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i){
		a[i]=-a[i];
		b[i]=-b[i];
	}
	for(int i=n-1;~i;i--){
		int j=i*2+1;
		for(int u=0;u<=k;++u){
			for(int o=0;o<=k;++o){
				dp[j][u][o]=dp[j+1][u][o];
				if(o<k&&i+1-u+o+1<=n)dp[j][u][o]=min(dp[j][u][o],dp[j+1][u][o+1]-b[i+1-u+o+1]);
//				printf("__%d %d %d    %d\n",j,u,o,dp[j][u][o]);
			}
		}
		j--;
		for(int u=0;u<=k;++u){
			for(int o=0;o<=k;++o){
				dp[j][u][o]=dp[j+1][u][o];
				if(u<k&&i-o+u+1<=n)dp[j][u][o]=max(dp[j][u][o],dp[j+1][u+1][o]+a[i-o+u+1]);
//				printf("__%d %d %d    %d\n",j,u,o,dp[j][u][o]);
			}
		}
	}
	printf("%d\n",dp[0][0][0]);
	return 0;
}