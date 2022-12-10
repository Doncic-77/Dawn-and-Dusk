#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n;
char c[N],k[N],a[N];
int Guess(){
	puts(c+1);
	fflush(stdout);
	scanf("%s",k+1);
	scanf("%s",k+1);
	if(k[1]=='G'){
		exit(0);
	}else {
		scanf("%s",k+1);
		int l=strlen(k+1),rs=0;
		for(int i=1;i<=l;++i){
			if('0'<=k[i]&&k[i]<='9')rs=10*rs+(k[i]-'0');
		}
		scanf("%s",k+1);
		return rs;
	}
	return 0;
}
int main(){
	for(int i=1;i<=20;++i){
		c[i]='A';
		if(Guess()!=5){
			n=i;
			break;
		}
	}
	for(int i=1;i<=26;++i)a[i]='a'+i-1,a[i+26]='A'+i-1;
	for(int i=53;i<=62;++i)a[i]='0'+(i-53);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=62;++j){
			c[i]=a[j];
			if((Guess()-5)!=9*i)break;
		}
	}
	return 0;
}