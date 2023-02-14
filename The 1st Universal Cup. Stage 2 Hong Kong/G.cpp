#include<bits/stdc++.h>
using namespace std;
const long double PI= acos(-1);
int n,m,a,b;
void slv(){
	scanf("%d %d %d %d",&n,&m,&a,&b);
	long double rs=((long double)a*(n+m)*(n+m)*PI/180.0+(long double)b*m*m*PI/180.0);
	long double k=(180.0-b)/180.0*PI, c=sqrt(1.0*n*n+1.0*m*m-2.0*n*m*cos(k));
	if(b>90){
//		printf("            %Lf %d\n",c,n);
		long double cosA= (1.0*c*c+1.0*m*m-1.0*n*n)/(2.0*c*m) ,A=acos(cosA);
		if(A>PI/2){
			long double B=PI-k-A;
			if(2*a*PI/180>=B)rs+=sin(B)*c*n-B*c*c;
			else {
//				puts("dddddddddddd");
				rs+=sin(B)*c*n;
				rs-=2*a*PI/180*c*c;
				long double a1=B-2*a*PI/180,b1=A,c1=PI-a1-b1;
				rs-=c*c*sin(a1)*sin(b1)/sin(c1);
			}
		}else {
//			printf("AAAAAA     %Lf %Lf\n",A/PI*180,k/PI*180);
			long double h=sin(k)*n,B=PI/2-k,d=sqrt(1.0*n*n-h*h);
//			printf("%Lf\n",h);
			if(2*a*PI/180>=B)rs+=d*h-B*h*h;
			else {
//				puts("dddddddddddd");
				rs+=d*h;
				rs-=2*a*PI/180*h*h;
				long double a1=B-2*a*PI/180,b1=PI/2,c1=PI-a1-b1;
				rs-=h*h*sin(a1)*sin(b1)/sin(c1);
			}
		}
	}
	printf("%.12Lf\n",rs);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)slv();
	return 0;
}
