#include<bits/stdc++.h>
#define double  long double
using namespace std;
const int N=1e5+5;
int n,m,cnt,s1,s2;
long long sum;
double ans,w;
struct P{
	int l,r;
	bool operator < (const P&t)const{
		return l<t.l;
	}
}a[N],b[N];
void clc(int l,int r,int L,int R){
	if(l>L)swap(l,L),swap(r,R);
	if(r<=L)return;
	ans+=(min(R,r)-L)/3.0*(1.0*(min(R,r)-L)*(min(R,r)-L)/sum);
	int ll=l,rr=L;
	ans+=((L+R)/2.0-(ll+rr)/2.0)*(1.0*(R-L)*(rr-ll)/sum);
//	printf("         ！！！！ %.12lf\n",ans);
	if(r<R){
		ll=r,rr=R;
		ans+=((ll+rr)/2.0-(L+r)/2.0)*(1.0*(r-L)*(rr-ll)/sum);
	}else {
		ll=R,rr=r;
		ans+=((ll+rr)/2.0-(L+R)/2.0)*(1.0*(R-L)*(rr-ll)/sum);
	}
//	printf("          %.12lf\n",ans);
}
void slv2(){
//	puts(">?????");
	if(!s1&&!s2){
//		puts("????");
		long long s2=0,s1=0;
		for(int i=1;i<=m;++i){
			s2+=b[i].l;
		}
		for(int i=1,j=1;i<=n;++i){
			while(j<=m&&a[i].l>=b[j].l){
				s1+=b[j].l;
				j++;
			}
			ans+=(a[i].l*(j-1.0)-s1)/n/m;
			ans+=((s2-s1)-a[i].l*(m-j+1.0))/n/m;
//			printf("_____%lld %d  %lf\n",s1,j-1,ans);
		}
	}else if(!s1){
		cnt=w=0;
		double sw=0;
		for(int j=1;j<=m;++j)sw+=1.0*(b[j].r+b[j].l)*(b[j].r-b[j].l)/2;
		for(int i=1,j=1;i<=n;++i){
			while(j<=m&&b[j].r<=a[i].l){
				cnt+=b[j].r-b[j].l;
				w+=1.0*(b[j].r+b[j].l)*(b[j].r-b[j].l)/2;
				j++;
			}
			ans+=(1ll*a[i].l*cnt-w)/s2/n;
			if(j<=m&&b[j].l<=a[i].l&&a[i].l<=b[j].r){
				ans+=(a[i].l-b[j].l)/2.0*(a[i].l-b[j].l)/s2/n;
				ans+=(a[i].l-b[j].r)/2.0*(a[i].l-b[j].r)/s2/n;
				ans+=((sw-w-1.0*(b[j].r+b[j].l)*(b[j].r-b[j].l)/2)-1ll*a[i].l*(s2-cnt-b[j].r+b[j].l))/s2/n;
			}else ans+=((sw-w)-1ll*a[i].l*(s2-cnt))/s2/n;
		}
	}else {
		cnt=w=0;
		double sw=0;
		for(int i=1;i<=n;++i)sw+=1.0*(a[i].r+a[i].l)*(a[i].r-a[i].l)/2;
		for(int i=1,j=1;j<=m;++j){
			while(i<=n&&a[i].r<=b[j].l){
				cnt+=a[i].r-a[i].l;
				w+=1.0*(a[i].r+a[i].l)*(a[i].r-a[i].l)/2;
				i++;
			}
//			printf("___________%d %lf\n",cnt,sw);
			ans+=(1ll*b[j].l*cnt-w)/s1/m;
//			printf("            %.12lf\n",ans);
			if(i<=n&&a[i].l<=b[j].l&&b[j].l<=a[i].r){
				ans+=(b[j].l-a[i].l)/2.0*(b[j].l-a[i].l)/s1/m;
				ans+=(b[j].l-a[i].r)/2.0*(b[j].l-a[i].r)/s1/m;
				ans+=((sw-w-1.0*(a[i].r+a[i].l)*(a[i].r-a[i].l)/2
				)-1ll*b[j].l*(s1-cnt-a[i].r+a[i].l
				))/s1/m;
				
			}else ans+=((sw-w)-1ll*b[j].l*(s1-cnt))/s1/m;
		}
	}
	printf("%.12Lf\n",ans);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d %d",&a[i].l,&a[i].r),s1+=a[i].r-a[i].l;
	for(int i=1;i<=m;++i)scanf("%d %d",&b[i].l,&b[i].r),s2+=b[i].r-b[i].l;
	sum=1ll*s1*s2;
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(!sum){
		slv2();
		return 0;
	}
	for(int i=1,j=1;i<=n;++i){
		while(j<=m&&b[j].r<=a[i].l){
			cnt+=b[j].r-b[j].l;
			w+=1.0*(b[j].r+b[j].l)*(b[j].r-b[j].l)/2;
			j++;
		}
		if(cnt)ans+=((a[i].r+a[i].l)/2.0-w/cnt)*(1.0*(a[i].r-a[i].l)*cnt/sum);
	}
	cnt=w=0;
	for(int i=1,j=1;j<=m;++j){
		while(i<=n&&a[i].r<=b[j].l){
			cnt+=a[i].r-a[i].l;
			w+=1.0*(a[i].r+a[i].l)*(a[i].r-a[i].l)/2;
			i++;
		}
		if(cnt)ans+=((b[j].r+b[j].l)/2.0-w/cnt)*(1.0*(b[j].r-b[j].l)*cnt/sum);
	}
//	printf("%.12lf\n",ans);
	for(int i=1,j=1;i<=n&&j<=m;){
		clc(a[i].l,a[i].r,b[j].l,b[j].r);
		if(a[i].r<b[j].r)i++;
		else j++;
	}
	printf("%.12Lf\n",ans);
	return 0;
}
