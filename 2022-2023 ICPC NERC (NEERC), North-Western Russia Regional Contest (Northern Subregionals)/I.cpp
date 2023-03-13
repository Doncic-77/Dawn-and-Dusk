#include<bits/stdc++.h>
using namespace std;
const int M=998244353,N=205;
int pw(int x,int t){
	int rs=1;
	for(;t;t>>=1,x=1ll*x*x%M)if(t&1)rs=1ll*rs*x%M;
	return rs;
}
int n,m,s,a[N],b[N],pre[N][N],C[N][N],rs,bl,w[N][N],dp[N][N];
int main(){
	scanf("%d %d %d",&n,&m,&s);
	int p=0;
	for(int i=1;i<=m;++i){
		scanf("%d",&a[i]);
		if(s==a[i])p=i;
	}
	if(p!=1){
		for(int i=p+1;i!=p;++i){
			if(i==m+1){
				b[++bl]=n+a[1]-a[m];
				i=1;
			}else b[++bl]=a[i]-a[i-1];
		}
		b[++bl]=a[p]-a[p-1];
	}else {
		for(int i=2;i<=m;++i)b[++bl]=a[i]-a[i-1];
		b[++bl]=n+a[1]-a[m];
	}
	C[0][0]=1;
	for(int i=1;i<=m;++i)a[i]=1ll*b[i]*pw(n,M-2)%M;
//	printf("_%d  %d %d\n",p,b[1],b[2]);
	for(int i=1;i<=m;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
		for(int j=i;j<=m;++j)pre[i][j]=(pre[i][j-1]+a[j])%M;
	}
	
	for(int i=0;i<=m;++i)w[i+1][i]=1;
	for(int i=m;i;--i){
		for(int j=i;j<=m;++j){
			for(int k=i;k<=j;++k){
				w[i][j]=(w[i][j]+1ll*w[i][k-1]*w[k+1][j]%M*C[j-i][k-i]%M*pre[i][k])%M;
//				if(i==1&&j==2)printf("     %d\n",w[i][j]);
			}
		}
	}
//	printf("_%d %d %d\n",w[1][1],w[2][2],w[1][2]);
	dp[0][0]=1;
	for(int i=0;i<m;++i){
		for(int j=i;j<m;++j){
			for(int k=0;k<=i;++k){
				int g=1ll*dp[i][k]*w[i+1][j]%M*C[k+j-i][k]%M;
				dp[j+1][k+j-i]=(dp[j+1][k+j-i]+g)%M;
				if(j+1==m){
//					printf("____%d %d %d   %d %d   %d\n",i,j,k,g,pre[i+1][m],(k+j-i+1));
					rs=(rs+1ll*(k+j-i+1)*pre[i+1][m]%M*g)%M;
				}
			}
		}
	}
	printf("%d\n",rs);
}
