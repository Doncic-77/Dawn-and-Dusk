#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int T,n,a[N],q[N],ql;
long long ans;
void slv(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	q[ql=1]=1;
	for(int i=2;i<=n;++i){
		while(ql>1&& 1ll*(a[q[ql]]-a[q[ql-1]])*(i-q[ql]) <= 1ll*(a[i]-a[q[ql]])*(q[ql]-q[ql-1]))ql--;
		q[++ql]=i;
	}
//	printf("___%d %d %d\n",ql);
	ans=0;
	for(int i=1;i<ql;++i){
		ans+=1ll*(a[q[i+1]]+a[q[i]])*(q[i+1]-q[i]);
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)slv();
	return 0;
}

