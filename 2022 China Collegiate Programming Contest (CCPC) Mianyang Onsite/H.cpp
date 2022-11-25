#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
int main(){
	scanf("%d",&n);
	n=2*n-1;
	printf("%d\n",n);
	for(int i=1;i<=n;++i){
		printf("%d %d\n",i,i);
	}
	return 0;
}