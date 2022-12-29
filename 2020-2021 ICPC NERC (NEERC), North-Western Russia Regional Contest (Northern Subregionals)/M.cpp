#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i;--i)a[i]-=a[i-1];
	int ma=0,mi=1e9;
	for(int i=1;i<=n;++i)ma=max(ma,a[i]);
	for(int i=1;i<n;++i)mi=min(mi,a[i]+a[i+1]);
	if(ma<mi)printf("%d\n",ma);
	else puts("0");
	return 0;
}
 