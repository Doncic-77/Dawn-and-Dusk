#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
int n;
long long exgcd( long long a,  long long b,  long long &x,  long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
   long long d = exgcd(b, a % b, x, y);
   long long t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}

int main(){
	scanf("%d",&n);
	while(n--){
		long long a,b,c,d;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		long long X=(c-a),Y=(b-d),A=0,B=0,g=0;
		if(abs(X)>=abs(Y))g=exgcd(abs(X),abs(Y),A,B);
		else g=exgcd(abs(Y),abs(X),B,A);
		if(X<0)A=-A;
		if(Y<0)B=-B;
		long long ma=max(abs(X),abs(Y)),t;
		if(A>ma){
			t=(A-ma)/Y;
			if((ma-A)%Y){
				if(Y>0)t++;
				else t--;
			}
			A-=Y*t;
			B+=X*t;
		}
		if(A<-ma){
			t=(-ma-A)/Y;
			if((-ma-A)%Y){
				if(Y>0)t++;
				else t--;
			}
			A+=Y*t;
			B-=X*t;
		}
		if(B>ma){
			t=(B-ma)/X;
			if((ma-B)%X){
				if(X>0)t++;
				else t--;
			}
			B-=X*t;
			A+=Y*t;
		}
		if(B<-ma){
			t=(-ma-B)/X;
			if((ma-B)%X){
				if(X>0)t++;
				else t--;
			}
			B+=X*t;
			A-=Y*t;
		}
		long long w=b*c-a*d+g;
		long long nx=0,ny=0;
		if(abs(Y)>=abs(X)){
			nx+=w/Y;
			w-=nx*Y;
		}else {
			ny+=w/X;
			w-=ny*X;
		}
		t=w/g;
		nx+=B*t,ny+=A*t;
		if(nx>inf){
			t=(nx-inf)/X;
			if(X>0)t++;
			else t--;
			nx-=X*t;
			ny+=Y*t;
		}
		if(nx<-inf){
			t=(-inf-nx)/X;
			if(X>0)t++;
			else t--;
			nx+=X*t;
			ny-=Y*t;
		}
		if(ny>inf){
			t=(ny-inf)/Y;
			if(Y>0)t++;
			else t--;
			ny-=Y*t;
			nx+=X*t;
		}
		if(ny<-inf){
			t=(-inf-ny)/Y;
			if(Y>0)t++;
			else t--;
			ny+=Y*t;
			nx-=X*t;
		}
		printf("%lld %lld\n",nx,ny);
	}
	return 0;
}
 