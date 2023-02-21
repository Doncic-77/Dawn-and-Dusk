#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll qpow(ll x, ll y){
    ll res = 1;
    while(y) {
        if( y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    #ifdef _DEBUG
        freopen("data.txt", "r", stdin);
    #endif
    cin>>T;
    while(T--) {
        int n, k;
        cin>>n>>k;
        ll g = __gcd(n, k);
        ll tmp = (qpow(2,n/g) - 2 + mod)%mod;
        cout<<(g%mod*qpow(tmp+1,g-1)%mod + qpow(tmp+1,g))%mod<<"\n";
    }
}