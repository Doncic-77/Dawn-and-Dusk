#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=998244353;
int n,ans=1;
char c[N][N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",c[i]+1);
		int s=0,fl=0;
		for(int j=1;j<=n;++j){
			if(c[i][j]!='?'){
				if(!s)continue;
				fl=0;
				fl+=(c[i][j-s-1]=='#');
				fl+=(c[i][j]=='#');
				if(fl==2)ans=0;
				if(!fl)ans=1ll*ans*(s+1)%M;
				s=0;
			}else s++;
		}
		if(s&&c[i][n-s]!='#')ans=1ll*ans*(s+1)%M;
	}
	for(int i=1;i<=n;++i){
		int s=0,fl=0;
		for(int j=1;j<=n;++j){
			if(c[j][i]!='?'){
				if(!s)continue;
				fl=0;
				fl+=(c[j-s-1][i]=='#');
				fl+=(c[j][i]=='#');
				if(fl==2)ans=0;
				if(!fl)ans=1ll*ans*(1+s)%M;
				s=0;
			}else s++;
		}
		if(s&&c[n-s][i]!='#')ans=1ll*ans*(s+1)%M;
	}
	printf("%d\n",ans);
}