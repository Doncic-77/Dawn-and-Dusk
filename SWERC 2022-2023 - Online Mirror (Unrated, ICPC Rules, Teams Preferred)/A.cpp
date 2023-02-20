#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,T,a[N]; 
void slv(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	a[n+1]=1440;
	int w=0;
	for(int i=1;i<=n+1;++i){
		w+=(a[i]-a[i-1])/120;
	}
	puts(w>=2? "YES":"NO");
}
int main(){
	scanf("%d",&T);
	while(T--)slv();
	return 0;
}
