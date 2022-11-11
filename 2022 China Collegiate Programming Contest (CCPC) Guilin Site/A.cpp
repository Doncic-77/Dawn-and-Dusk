#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n;
char c[N];
int main(){
	scanf("%d",&n);
	scanf("%s",c+1);
	for(int i=1;i<=n;++i){
		if(c[i+1]!='L'&&c[i-1]!='L'&&c[i]!='L')c[i]='C';
	}
	puts(c+1);
	return 0;
}
 