#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,k,s[N],b[N],a[N];
long long sa,tot;
priority_queue<long long>Q;
bool ck(long long w){
//	printf("___%lld\n",w);
	if(w*sa>tot)return 0;
	while(!Q.empty())Q.pop();
	long long t=tot,sb=w*sa;
	for(int i=0;i<k;++i)s[i]=b[i];
	for(int i=1;i<=n;++i)if(w*a[i])Q.push(w*a[i]);
	int nw=k-1;
	while(!s[nw])nw--;
	while(!Q.empty()){
		long long x=Q.top();
//		printf("     %lld  %lld %lld\n",x,sb,t);
		Q.pop();
		if(x>=(1<<nw)){
//			puts(">>");
			int g=min(1ll*s[nw],x/(1<<nw));
			s[nw]-=g;
			x-=(1ll<<nw)*g;
			if(x)Q.push(x);
			t-=(1ll<<nw)*g;
			sb-=(1ll<<nw)*g;
		}else {
			s[nw]--;
			t-=(1ll<<nw);
			sb-=x;
			if(t<sb)return 0;
		}
		while(!s[nw])nw--;
	}
	return 1;
}
void slv(){
	sa=tot=0;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sa+=a[i];
	}
	for(int i=0;i<k;++i){
		scanf("%d",&b[i]);
		tot+=(1ll<<i)*b[i];
	}
	long long l=0,r=tot/sa,rs=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(ck(mid)){
			rs=mid;
			l=mid+1;
		}else r=mid-1;
	}
	printf("%lld\n",rs);
}
int main(){
	scanf("%d",&T);
	while(T--)slv();
}