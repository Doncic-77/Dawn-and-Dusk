#include<bits/stdc++.h>
using namespace std;
int T,n; 
int main(){
	scanf("%d",&T);
	for(int I=1;I<=T;++I){
		scanf("%d",&n);
		int rs=0;
		for(int i=1;i<=n;++i){
			int x;
			scanf("%d",&x);
			rs+=x+(x-1)/10+1;
		}
		printf("Case #%d: %d\n",I,rs);
	}
	return 0;
}