#include<bits/stdc++.h>
using namespace std;
int n,a,b; 
int main(){
	scanf("%d %d %d",&n,&a,&b);
	if(n==1){
		printf("%d\n",a==b);
		printf("%d:%d\n",a,b);
		return 0;
	}
	int rs=max(0,n-a-b);
	printf("%d\n",rs);
	for(int i=1;i<=rs;++i)puts("0:0");
	if(!a){
		for(int i=rs+1;i<=n;++i){
			if(i!=n)puts("0:1"),b--;
			else printf("0:%d\n",b);
		}
	}else if(!b){
		for(int i=rs+1;i<=n;++i){
			if(i!=n)puts("1:0"),a--;
			else printf("%d:0\n",a);
		}
	}else {
		n-=rs;
		while(n>2&&a){
			puts("1:0");
			n--,a--;
		}
		if(a)n--,printf("%d:0\n",a);
		while(n){
			if(n==1)printf("0:%d\n",b);
			else puts("0:1");
			n--,b--;
		}
	}
	return 0;
}
