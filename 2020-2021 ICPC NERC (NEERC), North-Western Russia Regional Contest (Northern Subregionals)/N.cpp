#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,k;
long long dp[N][N],C[N][N],rs;
int main(){
	scanf("%d %d",&n,&k);
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		dp[i][0]=1;
		for(int j=1;j<=i;++j){
			if(j%2==0)dp[i][j]=(C[i][j]+C[i>>1][j>>1])>>1;
			else if(i&1)dp[i][j]=(C[i][j]+C[i>>1][j>>1])>>1;
			else dp[i][j]=C[i][j]>>1;
		}
	}
	for(int i=0,j=k;i<=j;i++,j--){
		if(j<=n)rs+=dp[n][j]+dp[n][i];
	}
	printf("%lld\n",rs);
	return 0;
}
 