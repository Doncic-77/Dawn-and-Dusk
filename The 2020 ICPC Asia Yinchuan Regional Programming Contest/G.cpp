#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ma,tr[N],h[N],p[N],x,sq[N],L[N],R[N];
long long ans,rs,res[N];
int abs(int x){return (x<0)? -x:x;}

void Rd(int &x){
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	do {x=(x<<1)+(x<<3)+(c^48);}while(isdigit(c=getchar()));
}
int main(){
	memset(res,-1,sizeof(res));
	for(int i=1;i<=9999;++i)sq[i]=i*i;
	Rd(n);Rd(q);
	for(int i=1;i<=n;++i)Rd(h[i]);
	for(int i=1;i<=n;++i){
		L[i]=i-1;
		R[i]=i+1;
	}
	for(int i=1;i<=n;++i){
		Rd(p[i]);
		p[i+n]=p[i];
	}
	for(int i=1;i<n;++i)ans+=sq[abs(h[i+1]-h[i])];
	for(int i=n;i;i--){
//		printf("_________%lld\n",ans);
		rs+=ans;
		int x=p[i],a=L[x],b=R[x];
		if(b<=n&&a>0){
			ans+=sq[abs(h[b]-h[a])];
			ans-=sq[abs(h[b]-h[p[i]])];
			ans-=sq[abs(h[a]-h[p[i]])];
		}else if(b<=n){
			ans-=sq[abs(h[b]-h[p[i]])];
		}else if(a>0){
			ans-=sq[abs(h[a]-h[p[i]])];
		}
		R[L[x]]=R[x];
		L[R[x]]=L[x];
	}
	printf("%lld\n",rs);
	int nw=1;
	while(q--){
		Rd(x);
		nw=(nw+rs+x-1)%n+1;
		ans=rs=0;
		for(int i=1;i<=n;++i){
			L[i]=i-1;
			R[i]=i+1;
		}
		for(int i=1;i<n;++i)ans+=sq[abs(h[i+1]-h[i])];
		for(int i=nw+n-1;i>=nw;--i){
			rs+=ans;
			int x=p[i],a=L[x],b=R[x];
			if(b<=n&&a>0){
				ans+=sq[abs(h[b]-h[a])];
				ans-=sq[abs(h[b]-h[p[i]])];
				ans-=sq[abs(h[a]-h[p[i]])];
			}else if(b<=n){
				ans-=sq[abs(h[b]-h[p[i]])];
			}else if(a>0){
				ans-=sq[abs(h[a]-h[p[i]])];
			}
			R[L[x]]=R[x];
			L[R[x]]=L[x];
		}
		printf("%lld\n",res[nw]=rs);
	}
	return 0;
}
 