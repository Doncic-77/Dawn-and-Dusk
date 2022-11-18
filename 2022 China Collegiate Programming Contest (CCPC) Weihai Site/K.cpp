#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int T,n,l,r;
struct P{
	int l,r;
	bool operator < (const P&t)const{
		return l<t.l;
	}
}b[N],c[N];
bool fid(int k,int x){
	if(1ll*k*(k+1)/2>x)return 0;
	l=(x-k*(k-1)/2)/k;
	if(l*k+k*(k-1)/2==x)r=l+k-1;
	else r=l+k;
	return 1;
}
void slv(){
	scanf("%d",&n);
	bool fl=1;
	int bl=0,L=2e9,R=0;
	for(int i=1;i<=n;++i){
		int op,x,k;
		scanf("%d %d %d",&op,&k,&x);
//		printf("___%d %d %d    %d\n",k,k*(k+1)/2,x,fid(k,x));
		if(!fid(k,x)){
			fl&=(op==2);
		}else {
//			printf("   %d   %d %d\n",op,l,r);
			if(op==1)L=min(L,l),R=max(R,r);
			else {
				++bl;
				b[bl].l=l,b[bl].r=r;
			}
		}
	}
//	printf("___%d %d  %d\n",L,R,bl);
	if(!fl){
		puts("0");
		return;
	}
	if(R==0){
		puts("-1");
		return;
	}
	sort(b+1,b+bl+1);
	int tl=0;
	for(int i=1;i<=bl;++i){
//		printf("??????___%d %d   %d\n",b[i].l,b[i].r,i);
		
		while(tl&&b[tl].r>=b[i].r)tl--;
		b[++tl]=b[i];
	}
	bl=tl;
	int cl=0,ll=0,rr=2e9;
	for(int i=1;i<=bl;++i){
//		printf("___%d %d   %d\n",b[i].l,b[i].r,i);
		if(L<=b[i].l&&b[i].r<=R){
			puts("0");
			return;
		}
		if(b[i].l<L&&b[i].r>R){
			c[++cl]=b[i];
		}else if(b[i].l<L)ll=max(ll,b[i].l);
		else if(b[i].r>R)rr=min(rr,b[i].r);
	}
	if(rr>1e9+17){
		puts("-1");
		return;
	}
	c[0].l=ll;
	c[cl+1].l=L;
	c[cl+1].r=rr;
	long long rs=0;
	for(int i=0;i<=cl;++i){
		int lw=c[i+1].l-c[i].l,rw=c[i+1].r-R;
		rs+=1ll*lw*rw;
	}
	printf("%lld\n",rs);
}
int main(){
	scanf("%d",&T);
	while(T--)slv();
}