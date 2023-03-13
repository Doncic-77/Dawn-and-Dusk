#include<bits/stdc++.h>
using namespace std;
int T,n,a[55][55];
struct P{
	int a,b,c,d,e,f;
	P right(){
		return (P){b,f,c,d,a,e};
	}
	P down(){
		return (P){c,b,f,a,e,d};
	}
	bool operator < (const P&t)const{
		if(a!=t.a)return a<t.a;
		if(b!=t.b)return b<t.b;
		if(c!=t.c)return c<t.c;
		if(d!=t.d)return d<t.d;
		if(e!=t.e)return e<t.e;
		return f<t.f;
	}
};
set<P>st[55][55];
void slv(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			st[i][j].clear();
			scanf("%d",&a[i][j]);
		}
	}
	st[n][n].insert((P){a[n][n],-1,-1,-1,-1,-1});
	for(int i=n;i;--i){
		for(int j=n;j;--j){
//			printf("___%d %d   %d\n",i,j,st[i][j].size());
			for(auto x:st[i][j]){
//				
				if(i>1){
					P y=x.down();
					if(y.a==-1)y.a=a[i-1][j];
					if(y.a==a[i-1][j]){
						st[i-1][j].insert(y);
					}
				}
				if(j>1){
					P y=x.right();
					if(y.a==-1)y.a=a[i][j-1];
					if(y.a==a[i][j-1]){
						st[i][j-1].insert(y);
					}
				}
			}
		}
	}
	if(st[1][1].size()){
		puts("Yes");
		P x=*(st[1][1].begin());
		x.a=max(x.a,0);
		x.b=max(x.b,0);
		x.c=max(x.c,0);
		x.d=max(x.d,0);
		x.e=max(x.e,0);
		x.f=max(x.f,0);
		printf("%d %d %d %d %d %d\n",x.a,x.b,x.c,x.d,x.e,x.f);
	}
	else puts("No");
}
int main(){
	scanf("%d",&T);
	while(T--)slv();
}
