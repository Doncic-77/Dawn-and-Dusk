#include<bits/stdc++.h>
using namespace std;
const int N=55;
int a[N][N],b[N*N],bl,n,m,ans;
void Rcg(){
	for(int i=1;i<=n;++i){
		for(int j=m/2;j;j--)swap(a[i][j],a[i][m-j+1]);
	}
}
void Ccg(){
	for(int i=1;i<=n/2;++i){
		for(int j=m;j;j--)swap(a[i][j],a[n-i+1][j]);
	}
}
void slv(){
	int rs=0;
	for(int i=2,nw=0;i<=n+m;++i){
		int cnt=0;
		for(int x=min(n,i-1);x;--x){
			int y=i-x;
			if(y>m)break;
//			printf("___%d %d\n",x,y);
			if(a[x][y]>-1)cnt++;
		}
//		puts("");
		for(int x=min(n,i-1);x;--x){
			int y=i-x;
			if(y>m)break;
			if(a[x][y]>-1&&(a[x][y]<=nw||a[x][y]>nw+cnt))rs++;
		}
		nw+=cnt;
	}
	ans=min(ans,rs);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=-1)b[++bl]=a[i][j];
		}
	}
	sort(b+1,b+bl+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]!=-1)a[i][j]=lower_bound(b+1,b+bl+1,a[i][j])-b;
//			printf("%d ",a[i][j]);
		}
//		puts("");
	}
	
	
	ans=bl;
	slv();
	Rcg();
	slv();
	Ccg();
	slv();
	Rcg();
	slv();
	printf("%d\n",ans);
	return 0;
}