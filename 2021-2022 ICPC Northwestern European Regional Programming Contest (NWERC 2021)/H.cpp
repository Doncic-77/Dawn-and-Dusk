#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,lG[N];
long long a[N],Pre[N][22],Suf[N][22],pre[N],suf[N],ans;
long long w_pre(int l,int r){
	int k=lG[r-l+1];
	return max(Pre[l][k],Pre[r-(1<<k)+1][k])+pre[l-1];
}
long long w_suf(int l,int r){
	int k=lG[r-l+1];
	return max(Suf[l][k],Suf[r-(1<<k)+1][k])+suf[r+1];
}
long long find_pre(int l,int r,long long nw){
	int k=lG[r-l+1],p=l;
	for(int i=k;~i;i--){
		if(p+(1<<i)-1>r)continue;
		if(Pre[p][i]+pre[p-1]<=nw){
			p+=(1<<i);
		}
	}
	return p;
}
long long find_suf(int l,int r,long long nw){
	int k=lG[r-l+1],q=r;
	for(int i=k;~i;i--){
		if(q-(1<<i)+1<l)continue;
		if(Suf[q-(1<<i)+1][i]+suf[q+1]<=nw){
			q-=(1<<i);
		}
	}
	return q;
}
long long clc(int l,int r,long long nw){
	if(l>r)return 0;
//	printf("              %d %d    %lld %lld %lld\n",l,r,w_pre(l,r),w_suf(l,r),nw);
	if(w_pre(l,r)<=nw||w_suf(l,r)<=nw)return 0;
	if(a[l]>nw&&a[r]>nw)return min(a[l],a[r])-nw+clc(l,r,min(a[l],a[r]));
	else {
		int p=find_pre(l,r,nw);
		nw+=pre[p-1]-pre[l-1];
		l=p;
		int q=find_suf(l,r,nw);
		nw+=suf[q+1]-suf[r+1];
		r=q;
		return clc(l,r,nw);
	}
}
void slv(int rt){
	long long rs=a[rt],nw=rs<<1;
	rs+=clc(rt+1,rt+n-1,nw);
//	printf("____%d %lld  %lld\n",rt,rs,nw);
	if(rt==1)ans=rs;
	else ans=min(ans,rs);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		a[n+i]=a[i];
	}
	for(int i=2;i<=n+n;++i)lG[i]=lG[i>>1]+1;
	for(int i=1;i<=n+n;++i){
		Pre[i][0]=a[i]-pre[i-1];
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=n+n;i;i--){
		Suf[i][0]=a[i]-suf[i+1];
		suf[i]=suf[i+1]+a[i];
	}
	int up=1;
	while(up<=n)up<<=1;
	up>>=1;
	for(int i=1,up=2;up<=n+n;++i,up<<=1){
		for(int j=1;j<=n+n-up+1;++j){
			Pre[j][i]=max(Pre[j][i-1],Pre[j+(up>>1)][i-1]);
			Suf[j][i]=max(Suf[j][i-1],Suf[j+(up>>1)][i-1]);
		}
	}
	for(int i=1;i<=n;++i){
		slv(i);
	}
	printf("%lld\n",ans);
	return 0;
}