#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,dp1[N],dp2[N],dp3[N],a;
void Max(int &x,int w){(x<w)&&(x=w);}
int main(){
	memset(dp1,-127,sizeof(dp1));
	memset(dp2,-127,sizeof(dp2));
	memset(dp3,-127,sizeof(dp3));
	dp3[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a);
//		for(int j=0;j<=i;++j)printf("%d %d   %d %d  %d\n",i,j,dp1[j],dp2[j],dp3[j]);
		for(int j=i-1;~j;--j){
			Max(dp2[j],dp3[j]+a);
			Max(dp1[j],dp3[j]-a);
			Max(dp3[j+1],dp2[j]-a);
			Max(dp3[j+1],dp1[j]+a);
		}
//		for(int j=0;j<=i;++j)printf("%d %d   %d %d  %d\n",i,j,dp1[j],dp2[j],dp3[j]);
	}
	for(int i=1;i<=n;++i)printf("%d\n",dp3[i]);
	return 0;
}
 