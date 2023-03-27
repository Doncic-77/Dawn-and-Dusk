#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int T,n,m,k,dp[N][N],tp[N][N];
struct P{
	int l,r;
	bool operator < (const P&t)const{
		return (l!=t.l)? l<t.l:r>t.r;
	}
}a[N];
void slv(int cas){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d %d",&a[i].l,&a[i].r);
	}
	sort(a+1,a+m+1);
	int al=1;
	for(int i=2;i<=m;++i)if(a[i].r>a[al].r)a[++al]=a[i];
	m=al;
	memset(dp,0,sizeof(dp));
	memset(tp,0,sizeof(tp));
	dp[1][1]=a[1].r-a[1].l+1;
	int rs=dp[1][1];
	for(int i=1,j=2;i<=m;++i){
		while(j<=m&&a[j].l<=a[i].r)j++;
//		printf("__%d %d\n",i,j);
		for(int u=0;u<k;++u){
			tp[i][u]=max(tp[i-1][u],tp[i][u]);
			dp[i][u+1]=max(dp[i][u+1],tp[i][u]+a[i].r-a[i].l+1);
			rs=max(rs,dp[i][u+1]);
			dp[j-1][u+1]=max(dp[j-1][u+1],dp[i][u]+a[j-1].r-a[i].r);
			rs=max(rs,dp[j-1][u+1]);
		}
		if(j<=m){
			for(int u=0;u<=k;++u){
				tp[j][u]=max(tp[j][u],dp[i][u]);
				rs=max(rs,tp[j][u]);
			}
		}
	}
	printf("Case #%d: %d\n",cas,rs);
}
int main(){
	scanf("%d",&T);
	for(int I=1;I<=T;++I){
		slv(I);
	}
	return 0;
}