#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,ans,mx1,mx2,st[N],tp;
priority_queue<int>Q,Q2;

void slv(){
	scanf("%d %d",&n,&m);
	while(!Q.empty())Q.pop();
	while(!Q2.empty())Q2.pop();
	mx1=mx2=0;
	char c[n+5][m+5]={};
	int l[n+5][m+5]={},up[n+5][m+5]={},dw[n+5][m+5]={};
	for(int i=1;i<=n;++i){
		scanf("%s",c[i]+1);
	}
	Q.push(0);
	for(int i=1;i<=m;++i){
		int nw=0;
		for(int j=1;j<=n;++j){
			if(c[j][i]=='#'){
				for(int k=j-1;k&&c[k][i]=='.';k--){
					l[k][i]=nw;
					dw[k][i]=j-1-k;
					up[k][i]=nw-dw[k][i]-1;
				}
				if(nw)Q.push(nw);
				if(nw>mx1){mx2=mx1;mx1=nw;}
				else mx2=max(mx2,nw);
				nw=0;
			}else nw++;
		}
		if(nw>mx1){mx2=mx1;mx1=nw;}
		else mx2=max(mx2,nw);
		if(nw)Q.push(nw);
		for(int k=n;k&&c[k][i]=='.';k--){
			l[k][i]=nw;
			dw[k][i]=n-k;
			up[k][i]=nw-dw[k][i]-1;
//			if(k==5&&i==4)printf("_______%d %d\n",
		}
	}
	ans=mx1+mx2;
	mx1=mx2=0;
	for(int i=1;i<=n;++i){
		int nw=0,w2=0;
		for(int j=1;j<=m;++j){
			if(c[i][j]=='#'){
				while(!Q2.empty())Q2.pop();
				while(tp)Q.push(st[tp--]);
				if(nw>mx1){mx2=mx1;mx1=nw;}
				else mx2=max(mx2,nw);
				nw=0,w2=0;
			}else {
				nw++;
				Q2.push(l[i][j]);
				w2=max(w2,max(up[i][j],dw[i][j]));
				while(!Q2.empty()&&Q2.top()==Q.top()){
					st[++tp]=Q.top();
					Q.pop();
					Q2.pop();
				}
				ans=max(ans,nw+max(w2,Q.top()));
			}
		}
		if(nw>mx1){mx2=mx1;mx1=nw;}
		else mx2=max(mx2,nw);
		while(!Q2.empty())Q2.pop();
		while(tp)Q.push(st[tp--]);
		nw=0,w2=0;
		for(int j=m;j;--j){
			if(c[i][j]=='#'){
				while(!Q2.empty())Q2.pop();
				while(tp)Q.push(st[tp--]);
				nw=0,w2=0;
			}else {
				nw++;
				Q2.push(l[i][j]);
				w2=max(w2,max(up[i][j],dw[i][j]));
				while(!Q2.empty()&&Q2.top()==Q.top()){
					st[++tp]=Q.top();
					Q.pop();
					Q2.pop();
				}
//				if(i==5&&j==4)printf("__%d %d\n",w2,Q.top());
				ans=max(ans,nw+max(w2,Q.top()));
			}
		}
		while(!Q2.empty())Q2.pop();
		while(tp)Q.push(st[tp--]);
	}
//	printf("___%d %d\n",mx1,mx2);
	ans=max(ans,mx1+mx2);
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)slv();
}