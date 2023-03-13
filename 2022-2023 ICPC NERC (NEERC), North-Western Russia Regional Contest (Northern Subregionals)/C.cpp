#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,a[N],ans;
priority_queue<int,vector<int>,greater<int> >Q;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=k;++i)Q.push(a[i]),ans+=a[i];
	for(int i=k+1;i<=n;++i){
		int x=Q.top();
		Q.pop();
		ans+=x+a[i];
		Q.push(x+a[i]);
	}
	printf("%d\n",ans);
	return 0;
}

