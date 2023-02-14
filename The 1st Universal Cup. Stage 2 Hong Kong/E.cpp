#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,T,tr[N<<2],A[N<<2],a[N],p[N],l,r,rs;
long long ans;
vector<int>V[N];
void Js(int z,int y,int c){
	tr[c]=y-z+1;
	if(z==y)return;
	int mid=(z+y)>>1;
	Js(z,mid,c<<1),Js(mid+1,y,c<<1|1);
}
void Upd(int l,int r,int c){
	if(!A[c]){
		if(l<r)tr[c]=tr[c<<1]+tr[c<<1|1];
		else tr[c]=1;
	}
	else tr[c]=0;
}
void Ad(int z,int y,int c,int w){
	if(z>r||y<l)return;
	if(z>=l&&y<=r){
		A[c]+=w;
		Upd(z,y,c);
		return;
	}
	int mid=(z+y)>>1;
	if(l<=mid)Ad(z,mid,c<<1,w);
	if(r>mid)Ad(mid+1,y,c<<1|1,w);
	Upd(z,y,c);
}
void Qr(int z,int y,int c){
	if(z>r||y<l)return;
//	Upd(c);
	if(A[c])return;
	if(z>=l&&y<=r){
		rs+=tr[c];
		return;
	}
	int mid=(z+y)>>1;
	if(l<=mid)Qr(z,mid,c<<1);
	if(r>mid)Qr(mid+1,y,c<<1|1);
}
void slv(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		V[a[i]].push_back(i);
	}
	Js(1,n,1);
//	puts("????");
	for(int i=1;i<=1000000;++i){
		if(V[i].size()>=k){
			l=V[i][k-1],r= (k==V[i].size())?  n : (V[i][k]-1);
//			printf("_____%d %d %d %d\n",i,l,r,1);
			Ad(1,n,1,1);
		}
	}
	for(int i=1;i<=n;++i){
		rs=0;
		l=i,r=n;
		Qr(1,n,1);
//		printf("                  %d %d\n",i,rs);
		ans+=rs;
		int x=a[i];
		if(k+p[x]<=V[x].size()){
			l=V[x][k-1+p[x]],r= (k+p[x]==V[x].size())?  n : (V[x][k+p[x]]-1);
			Ad(1,n,1,-1);
//			printf("_____%d %d %d %d\n",i,l,r,-1);
		}
		p[x]++;
		if(k+p[x]<=V[x].size()){
			l=V[x][k-1+p[x]],r= (k+p[x]==V[x].size())?  n : (V[x][k+p[x]]-1);
			Ad(1,n,1,1);
//			printf("_____%d %d %d %d\n",i,l,r,1);
		}
	}
	printf("%lld\n",ans);
}
int main(){
//	scanf("%d",&T);
	T=1;
	while(T--)slv();
	return 0;
}
