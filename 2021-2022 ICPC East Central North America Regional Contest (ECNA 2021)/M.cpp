#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,k,sn[N*N][26],End[N*N],dp[N][N][N*N][3];
char c[N][N],s[N];
struct P{
	int x,y,z,v;
};
queue<P>Q;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%s",s);
			c[i][j]=s[0];
		}
	}
	int cnt=1;
	for(int i=1;i<=k;++i){
		scanf("%s",s+1);
		int l=strlen(s+1);
		int nw=1;
		for(int j=1;j<=l;++j){
			int t=s[j]-'A';
			if(!sn[nw][t])sn[nw][t]=++cnt;
			nw=sn[nw][t];
		}
		End[nw]=1;
	}
	memset(dp,127,sizeof(dp));
	for(int i=1;i<=m;++i){
		int t=c[1][i]-'A';
		if(sn[1][t]){
			int z=sn[1][t];
			dp[1][i][z][0]=1;
			Q.push((P){1,i,z,0});
			if(End[z]){
				dp[1][i][1][0]=1;
				Q.push((P){1,i,1,0});
			}
		}
	}
	while(!Q.empty()){
		P t=Q.front();
		Q.pop();
		if(t.x==n&&t.z==1){
			printf("%d\n",dp[t.x][t.y][t.z][t.v]);
			return 0;
		}
		if(sn[t.z][c[t.x+1][t.y]-'A']){
			int Z=sn[t.z][c[t.x+1][t.y]-'A'];
			if(dp[t.x+1][t.y][Z][0]>dp[t.x][t.y][t.z][t.v]+1){
				dp[t.x+1][t.y][Z][0]=dp[t.x][t.y][t.z][t.v]+1;
				Q.push((P){t.x+1,t.y,Z,0});
			}
			if(End[Z]){
				Z=1;
				if(dp[t.x+1][t.y][Z][0]>dp[t.x][t.y][t.z][t.v]+1){
					dp[t.x+1][t.y][Z][0]=dp[t.x][t.y][t.z][t.v]+1;
					Q.push((P){t.x+1,t.y,Z,0});
				}
			}
		}
		if(t.v!=2&&t.y>1&&sn[t.z][c[t.x][t.y-1]-'A']){
			int Z=sn[t.z][c[t.x][t.y-1]-'A'];
			if(dp[t.x][t.y-1][Z][1]>dp[t.x][t.y][t.z][t.v]+1){
				dp[t.x][t.y-1][Z][1]=dp[t.x][t.y][t.z][t.v]+1;
				Q.push((P){t.x,t.y-1,Z,1});
			}
			if(End[Z]){
				Z=1;
				if(dp[t.x][t.y-1][Z][1]>dp[t.x][t.y][t.z][t.v]+1){
					dp[t.x][t.y-1][Z][1]=dp[t.x][t.y][t.z][t.v]+1;
					Q.push((P){t.x,t.y-1,Z,1});
				}
			}
		}
		if(t.v!=1&&t.y<m&&sn[t.z][c[t.x][t.y+1]-'A']){
			int Z=sn[t.z][c[t.x][t.y+1]-'A'];
			if(dp[t.x][t.y+1][Z][2]>dp[t.x][t.y][t.z][t.v]+1){
				dp[t.x][t.y+1][Z][2]=dp[t.x][t.y][t.z][t.v]+1;
				Q.push((P){t.x,t.y+1,Z,2});
			}
			if(End[Z]){
				Z=1;
				if(dp[t.x][t.y+1][Z][2]>dp[t.x][t.y][t.z][t.v]+1){
					dp[t.x][t.y+1][Z][2]=dp[t.x][t.y][t.z][t.v]+1;
					Q.push((P){t.x,t.y+1,Z,2});
				}
			}
		}
	}
	puts("impossible");
	return 0;
}