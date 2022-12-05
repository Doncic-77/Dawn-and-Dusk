#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
double a[N],s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%lf",&a[i]),s+=a[i];
    double x=s/(n+1);
    for(int i=1;i<=n;++i)a[i]=x;
    a[1]+=x;
    for(int i=1;i<=n;++i)printf("%lf ",a[i]);
}
