#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,a,b;
        scanf("%d %d %d",&n,&a,&b);
        if(a>b)puts("1");
        else printf("%d\n", (n + a - 1) / a);
    }
return 0;
}