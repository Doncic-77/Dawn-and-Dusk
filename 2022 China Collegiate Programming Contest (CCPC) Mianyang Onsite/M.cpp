#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char c[N],top;
int t,s;
int cmp(char a,char b){
	if(a==b)return 1;
	if(a=='S'&&b=='R')return 2;
	if(a=='R'&&b=='P')return 2;
	if(a=='P'&&b=='S')return 2;
	return 0;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",c+1);
		top=c[1];
		s=1;
		int n=strlen(c+1);
		for(int i=2;i<=n;++i){
			if(cmp(c[i-1],c[i])==1)continue;
			if(!cmp(c[i-1],c[i])==1)s++;
			else s--;
			if(!s){
				top=c[i];
				s=1;
			}
		}
		printf("%c\n",top);
	}
	return 0;
}