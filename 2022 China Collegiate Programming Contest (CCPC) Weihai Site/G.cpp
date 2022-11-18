#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int x,n,s[N];
int main(){
	scanf("%d %d",&x,&n);
	int k=1;
	while(k<=x)k<<=1;
	if(x==1)s[0]=1;
	for(int i=1;i<k;++i){
		s[i]=s[i-1]+(__gcd(x^(1ll*i*x),1ll*x)==1);
	}
	while(n--){
		long long l,r;
		scanf("%lld %lld",&l,&r);
		l--;
		printf("%lld\n",(r/k-l/k)*s[k-1]-s[l%k]+s[r%k]);
	}
}