#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,T;
vector<int>V[N];
int dfs(int x){
	int ma1=0,ma2=0;
	for(auto to:V[x]){
		int w=dfs(to);
		if(w>ma1){ma2=ma1;ma1=w;}
		else ma2=max(ma2,w);
	}
	return max(ma1,ma2+1);
}
void slv(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)V[i].clear();
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		V[x].push_back(i);
	}
	printf("%d\n",dfs(1));
}
int main(){
	scanf("%d",&T);
	while(T--)slv();
	return 0;
}
