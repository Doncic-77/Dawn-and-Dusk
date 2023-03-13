#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e; 
int main(){
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	if(a==b&&b==c&&c==d){
		puts("1");
		return 0;
	}else {
		if(a>b)swap(a,b);
		if(a>c)swap(a,c);
		if(a>d)swap(a,d);
		a+=e;
		if(a==b&&b==c&&c==d){
			puts("1");
			return 0;
		}else puts("0");
	}
	return 0;
}

