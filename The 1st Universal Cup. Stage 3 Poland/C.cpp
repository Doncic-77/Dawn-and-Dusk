#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char c[N];
int T;
void slv(){
	scanf("%s",c+1);
	int n=strlen(c+1),rs=0;
	for(int i=1;i<=n-3;++i){
		if(c[i]=='a'&&c[i+1]=='n'&&c[i+2]=='i'&&c[i+3]=='a'){
			c[i+3]='x';
			rs++;
		}
	}
	printf("%d\n",rs);
}
int main(){
	scanf("%d",&T);
	while(T--)slv();
	return 0;
}

