#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int T,n,k,a[N],nw,s,ans;
struct P{
	int x,y;
	bool operator < (const P&t)const{
		return x<t.x;
	}
}b[N];
void slv(){
	ans=0;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=k;++i){
		scanf("%d %d",&b[i].x,&b[i].y);
	}
	nw=0,s=n;
	sort(b+1,b+k+1);
	int z=1,y=0;
	while(z<=k&&b[z].x==nw){
		s=b[z].y;
		z++;
		if(!s)nw++,s=n;
	}
	for(int i=1;i<=n;++i){
		while(y<k&&b[y+1].x<=a[i]){
			y++;
			if(!b[y].y){
				z=y+1;
				nw=b[y].x+1,s=n;
				while(z<=k&&b[z].x==nw){
					s=b[z].y;
					z++;
					if(!s)nw++,s=n;
				}
			}
			y=max(y,z-1);
		}
		ans^=(a[i]-nw);
//		printf("___%d %d %d %d\n",i,a[i],nw,s);
		s--;
		if(!s){
			nw++,s=n;
			while(z<=k&&b[z].x==nw){
				s=b[z].y;
				z++;
				if(!s)nw++,s=n;
			}
			y=max(y,z-1);
		}
	}
	puts((ans&1)? "Pico":"FuuFuu");
}
int main(){
	scanf("%d",&T);
	while(T--)slv();
}