#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=998244353;
int n,m,T,r[N][N],c[N][N],pre_r[N][N],suf_r[N][N],pre_c[N][N],suf_c[N][N];
void ck(int &x){(x>=M)&&(x-=M);}
void slv(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&r[i][j]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&c[i][j]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			ck(pre_r[i][j]=r[i][j]+pre_r[i][j-1]);
		}
		for(int j=m;j;--j){
			ck(suf_r[i][j]=r[i][j]+suf_r[i][j+1]);
		}
	}
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			ck(pre_c[i][j]=c[i][j]+pre_c[i-1][j]);
		}
		for(int i=n;i;i--){
			ck(suf_c[i][j]=c[i][j]+suf_c[i+1][j]);
		}
	}
	int rs=2;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			rs=(rs+1ll*pre_r[i][j-1]*pre_c[i-1][j]%M*suf_r[i+1][j]%M*suf_c[i][j+1])%M;
		}
	}
	printf("%d\n",rs);
}
int main(){
//	scanf("%d",&T);
	T=1;
	while(T--)slv();
	return 0;
}
