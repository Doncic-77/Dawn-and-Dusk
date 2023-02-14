#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,nw;
char c[N][N],a[N];
void clc(){
	++nw;
	int k=0;
	for(int i=1;i<=n;++i)c[nw][i]=a[i],k+=a[i]-'0';
	if(k+k==n)return;
	if(nw<m){
		++nw;
		for(int i=1;i<=n;++i)c[nw][i]=(a[n-i+1]^1);
	}
}
void dfs(int p,int s){
	if(nw==m)return;
	if(n-p+1<s)return;
	if(!s){
		clc();
		return;
	}
	if(p>n)return;
	dfs(p+1,s);
	a[p]='1';
	dfs(p+1,s-1);
	a[p]='0';
}
void slv(){
	scanf("%d %d",&n,&m);
	if((n*m)&1){
		puts("NO");
		return;
	}
	bool fl=0;
	if(n>m)swap(n,m),fl=1;
	if(n<=10&&(1<<n)<m){
		puts("NO");
		return;
	}
	for(int i=1;i<=n;++i)a[i]='0';
	a[n+1]=0;
	nw=0;
	if(m&1){
		m--;
		for(int i=1;i<n/2;i++)dfs(1,i);
		dfs(1,0);
		m++;
		dfs(1,n/2);
	}else {
		for(int i=1;i<=n/2;++i)dfs(1,i);
//		puts("?????????");
		dfs(1,0);
	}
	puts("YES");
	if(fl)for(int i=1;i<=m;++i){
		c[i][n+1]=0;
		puts(c[i]+1);
	}
	else {
		a[m+1]=0;
		for(int j=1;j<=n;++j){
			for(int i=1;i<=m;++i){
				a[i]=c[i][j];
			}
			puts(a+1);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)slv();
	return 0;
}
