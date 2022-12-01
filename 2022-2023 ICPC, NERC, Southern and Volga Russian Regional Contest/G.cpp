#include<bits/stdc++.h>
using namespace std;
int T,n;
char c[1005];
int qry(int op,int x){
	printf("%d %d\n",op,x);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
void slv(){
	scanf("%d",&n);
	c[1]='0';
	c[2]='1'^qry(1,2);
	for(int i=4;i<=n;i+=2){
		int op=rand()&1,p=qry(1+op,i);
		if(p>1){
			c[i-1]=c[p-1]^op,c[i]=c[p]^op;
		}else {
			c[i]='1'^op^p;
			if(c[2]==(c[i]^op)){
				c[i-1]='1'^op;
			}else {
				p=qry(1+op,i-1);
				if(p)c[i-1]=c[p]^op;
				else c[i-1]='1'^op;
			}
		}
	}
	if(n&1){
		int p=qry(1,n);
		c[n]=(p)? c[p]:'1';
	}
	c[n+1]=0;
	printf("0 ");
	puts(c+1);
	fflush(stdout);
	scanf("%d",&n);
}
int main(){
	scanf("%d",&T);
	while(T--)slv();
	return 0;
}