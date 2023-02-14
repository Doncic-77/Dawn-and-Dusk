#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,d,a[N],b[N];
long long rs;
long long slv(int l,int r){
	for(int i=1;i<=n;++i){
		b[i]=min(r,max(a[i],l));
	}
	long long ans=0;
	for(int i=2;i<=n;++i){
		ans+=abs(b[i]-b[i-1]);
	}
	return ans;
}
int main(){
	scanf("%d %d",&n,&d);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		rs=max(rs,slv(a[i],a[i]+d));
		rs=max(rs,slv(a[i]-d,a[i]));
	}
	printf("%lld\n",rs);
	return 0;
}
