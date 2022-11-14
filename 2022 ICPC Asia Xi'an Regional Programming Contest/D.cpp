#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,nt[5][5][N],a[5][N],rk[5][N],q,F[17][N][5],X[5],Y[5];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i)for(int o=1;o<=n;++o){
		scanf("%d",&a[i][o]);
		rk[i][a[i][o]]=o;
	}
	for(int i=0;i<m;++i)rk[i][0]=n+1;
	for(int i=0;i<m;++i){
		for(int o=0;o<m;++o)if(i!=o){
			int mi=0;
			for(int u=n;u;u--){
				if(rk[o][a[i][u]]<rk[o][mi])mi=a[i][u];
				nt[i][o][a[i][u]]=mi;
			}
		}
	}
	for(int i=0;i<m;++i){
		for(int o=1;o<=n;++o){
			int x=a[i][o];
			for(int u=0;u<m;++u){
				if(rk[u][F[0][x][u]]>rk[u][nt[i][u][x]]){
					F[0][x][u]=nt[i][u][x];
				}
			}
		}
	}
	for(int i=1;i<=16;++i){
		for(int o=0;o<m;++o){
			for(int u=1;u<=n;++u){
				for(int j=0;j<m;++j){
					int x=F[i-1][F[i-1][u][j]][o];
					if(rk[o][F[i][u][o]]>rk[o][x])F[i][u][o]=x;
				}
			}
		}
	}
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		int rs=1e9;
		for(int i=0;i<5;++i){
			X[i]=x;
			if(rk[i][x]<rk[i][y]){
				rs=1;
			}
		}
		if(rs==1){
			puts("1");
			continue;
		}
		for(int i=16,w=0;~i;i--){
			int fl=0;
			for(int o=0;o<m&&!fl;++o){
				for(int u=0;u<m&&!fl;++u){
					int p=rk[o][F[i][X[u]][o]];
					if(p<rk[o][y])fl=1;
				}
			}
			if(fl)rs=min(rs,w|(1<<i));
			else {
				for(int o=0;o<m;++o){
					Y[o]=0;
					for(int u=0;u<m;++u){
						int p=F[i][X[u]][o];
						if(rk[o][p]<rk[o][Y[o]])Y[o]=p;
					}
				}
				for(int o=0;o<m;++o)X[o]=Y[o];
				w|=1<<i;
			}
//			printf("%d__ %d %d\n",w,/);
		}
		if(rs<=n)printf("%d\n",rs+1);
		else puts("-1");
	}
	return 0;
}
