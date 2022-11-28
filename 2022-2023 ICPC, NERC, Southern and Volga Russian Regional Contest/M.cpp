#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int largest = 1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<n/i<<" "<<n/i*(i-1)<<"\n";
            return;
        }
    }
    cout<<n-1<<" "<<1<<"\n";
}
int main(){
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){solve();}
    return 0;
}