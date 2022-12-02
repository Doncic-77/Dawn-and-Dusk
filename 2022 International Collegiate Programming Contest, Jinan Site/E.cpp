#include<bits/stdc++.h>
using namespace std;
int main(){
  int T,n,k;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&n,&k);
    if(k%2==0){
      puts("YES");
      continue;
    }
    int a=n%k,b=k-n%k,c=n/k;
    if(b>=c&&a>=c-1)puts("YES");
    else puts("NO");
  }
}