#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a[N],b[N];
int T,n,al[N],bl[N],nt[N*6][26],s[N*6];
void Nw(int x){
	for(int i=0;i<26;++i)nt[x][i]=0;
	s[x]=0;
}
void slv(){
    cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		al[i]=a[i].size();
		bl[i]=b[i].size();
//		printf("___%d %d\n",al[i],bl[i]);
	}
	int ans=6,X=0,Y=0,Z=6;
	for(int x=0;x<6;++x){
		for(int y=0;y<6;++y){
			if(x+y>=6)continue;
			int cnt=0,ma=0;
			Nw(0);
			for(int i=1;i<=n;++i){
				int nw=0;
				for(int j=0;j<min(x,al[i]);++j){
					if(!nt[nw][a[i][j]-'a'])Nw(nt[nw][a[i][j]-'a']=++cnt);
					nw=nt[nw][a[i][j]-'a'];
				}
				for(int j=0;j<min(y,bl[i]);++j){
//					printf("_%d\n",b[i][j]-'a');
					if(!nt[nw][b[i][j]-'a'])Nw(nt[nw][b[i][j]-'a']=++cnt);
					nw=nt[nw][b[i][j]-'a'];
				}
//				printf("   %d\n",nw);
				s[nw]++;
				ma=max(ma,s[nw]);
			}
//			printf("______%d %d %d\n",x,y,ma);
			int rs=x+y,g=1;
			while(g<ma)g*=10,rs++;
			if(!rs)rs++;
			if(rs<ans){
				X=x,Y=y,Z=rs-X-Y;
				ans=rs;
			}
		}
	}
	printf("%d %d %d\n",X,Y,Z);
}
int main(){
	std::ios::sync_with_stdio(false) , cin.tie(0) ;
	cin>>T;
	while(T--)slv();
	return 0;
}

