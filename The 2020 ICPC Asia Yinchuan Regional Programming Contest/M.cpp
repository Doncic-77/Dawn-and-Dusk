#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
void Max(int &x,int w){(x<w)&&(x=w);}
int n,w0,h[N],w[N],lG[N];
long long RMQ[N][20];
long long ans,dp[N],dmg[N];
long long Qr(int l,int r){
	int k=lG[r-l+1];
	if(l>r)return 4e18;
//	printf("____%d %d  %d\n",l,r,k);
	return min(RMQ[l][k],RMQ[r-(1<<k)+1][k]);
}
vector<int>V[N];
int main(){
	int Mx=0;
	memset(RMQ,63,sizeof(RMQ));
	scanf("%d %d",&n,&w0);
	Mx=max(w0,Mx);
	for(int i=1;i<=n;++i){
		scanf("%d %d",&w[i],&h[i]);
//		mi_h[w[i]]=min(mi_h[w[i]],h[i]);
		V[w[i]].push_back(h[i]);
		Mx=max(Mx,w[i]);
		
	}
	for(int i=2;i<=100000;++i){
		lG[i]=lG[i>>1]+1;
	}
	memset(dp,63,sizeof(dp));
	dp[w0]=0;
	RMQ[w0][0]=0;
	for(int i=1,j=2;w0-j+1>0;++i,j<<=1)RMQ[w0-j+1][i]=min(RMQ[w0-j+1][i-1],RMQ[w0-(j>>1)+1][i-1]);
	for(int i=1;i<=n;++i)ans+=1ll*(h[i]-1)/Mx*w[i];
	for(int i=w0+1;i<=Mx;++i){
		
		for(auto x:V[i]){
			int k=x-1;
			long long t=4e18;
			for(int r=k,l=0;r>0;r=l-1){
				int tms=(k/r);
				l=k/(tms+1)+1;
				t=min(t,Qr(min(l,i),min(r,i-1))+1ll*tms*i);
//				printf("           %d %d  %lld\n",l,r,Qr(l,r)+1ll*tms*i);
			}
			if(k+1<i)t=min(t,Qr(k+1,i-1));
//			printf("______%d %lld\n",i,dp[i]);
			t-=1ll*k/Mx*i;
			dp[i]=min(dp[i],t);
		}
		RMQ[i][0]=dp[i];
		for(int k=1,j=2;i-j+1>0;++k,j<<=1){
			RMQ[i-j+1][k]=min(RMQ[i-j+1][k-1],RMQ[i-(j>>1)+1][k-1]);
		}
	}
//	printf("_________%lld\n",ans);
	printf("%lld\n",ans+dp[Mx]);
	return 0;
}