#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k,a[N],b[N],v[N],x,y,ans;

int main(){
	scanf("%d %d",&n,&m);
	k=n+m;
	for(int i=1;i<=k;++i)scanf("%d",&a[i]);
	scanf("%d %d",&x,&y);
	for(int i=1;i<=k;++i)scanf("%d",&b[i]);
	memset(v,0,sizeof(v));
	for(int i=1;i<=x;++i)v[b[i]]=1;
	for(int i=x+1;i<=k;++i)v[b[i]]=2;
	int p=1;
	for(int i=1;i<=n;++i){
		if(v[a[i]]==2)ans++;
		else if(a[i]==b[p])p++;
		else ans+=2;
	}
	p=k;
	for(int i=k;i>n;i--){
		if(v[a[i]]==1)ans++;
		else if(a[i]==b[p])p--;
		else ans+=2;
	}
	printf("%d\n",ans);
	return 0;
}