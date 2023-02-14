#include<bits/stdc++.h>
using namespace std;
const int N=6005;
int n,k,dp[N][N],w[N][N],tr[N],a[N],b[N],bl,p[N][N];
void Ad(int i){
	for(;i<=bl;i+=i&-i)tr[i]++;
}
int Qr(int i){
	int rs=0;
	for(;i;i-=i&-i)rs+=tr[i];
	return rs;
}
void slv(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	bl= unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+bl+1,a[i])-b;
//	printf("%d\n",a[n]);
//	for(int i=1;i<=n;++i)printf("%d\n",a[i]);
	for(int i=1;i<=n;++i){
		memset(tr,0,sizeof(tr));
		Ad(a[i]);
		for(int j=i+1;j<=n;++j){
			w[i][j]=w[i][j-1]+(j-i-Qr(a[j]));
//			printf("___%d %d   %d\n",i,j,w[i][j]);
			Ad(a[j]);
		}
		dp[0][i]=w[1][i];
		p[0][i]=1;
	}
//	puts("???");
	for(int i=1;i<=k;++i){
		p[i][n+1]=n;
		for(int j=n;j>=2;--j){
			// [i][j-1]<=[i][j]<=[i-1][j]
			dp[i][j]=1e9;
			for(int P=p[i-1][j];P<=p[i][j+1];++P){
				int g=dp[i-1][P]+w[P+1][j];
				if(dp[i][j]>g){
					dp[i][j]=g,p[i][j]=P;
				}
			}
//			printf("%d %d   %d %d      [%d,%d]\n",i,j,dp[i][j],p[i][j],p[i][j-1],p[i][j+1]);
//			printf("___%d %d   %d\n",i,j,w[i][j]);
		}
	}+
	printf("%d\n",dp[k][n]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)slv();
	return 0;
}

