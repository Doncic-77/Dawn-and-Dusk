#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int T,n,m,a[N],b[N],p[N],q[N],c[N];
void slv1(){
	int k=1;
	for(int i=1;i<=n;++i){
		b[a[i]]=i;
		k*=i;
		p[i]=i;
	}
	while(k--){
		for(int i=1;i<=n;++i)c[p[i]]=i;
		for(int i=1;i<=n;++i)q[i]=c[b[i]];
		bool fl=1;
		for(int i=1;i<=n;++i)if(p[i]==i||q[i]==i){
			fl=0;
			break;
		}
		if(fl){
			puts("Possible");
			for(int i=1;i<=n;++i)printf("%d ",p[i]);puts("");
			for(int i=1;i<=n;++i)printf("%d ",q[i]);puts("");
			return;
		}
		next_permutation(p+1,p+n+1);
	}
	puts("Impossible");
}
void slv2(){
	for(int i=1;i<=n;++i)b[a[i]]=i,p[i]=i;
	while(1){
		shuffle(p+1,p+n+1,rnd);
		for(int i=1;i<=n;++i)c[p[i]]=i;
		for(int i=1;i<=n;++i)q[i]=c[b[i]];
		bool fl=1;
		for(int i=1;i<=n;++i)if(p[i]==i||q[i]==i){
			fl=0;
			break;
		}
		if(fl){
			puts("Possible");
			for(int i=1;i<=n;++i)printf("%d ",p[i]);puts("");
			for(int i=1;i<=n;++i)printf("%d ",q[i]);puts("");
			return;
		}
	}
}
void slv(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	if(n<=7)slv1();
	else slv2();
}
int main(){
	scanf("%d",&T);
	while(T--)slv();
	return 0;
}
