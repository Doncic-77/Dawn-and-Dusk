//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
const int mod = 998244353 ;
const long long inf = 1e18 ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m , q ;
    cin >> n >> m >> q ;
    vector<int> a(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
    vector<vector<pair<int , int>>> g(n + 1) ;
    while(m --)
    {
        int u , v , w ;
        cin >> u >> v >> w ;
        g[u].push_back({v , w}) ;
        g[v].push_back({u , w}) ;
    }
    vector<int> deg(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  deg[i] = g[i].size() ;
    vector<int> Q(q + 1 , 0) ;
    for(int i = 1 ; i <= q ; i ++)  cin >> Q[i] ;
    vector<long long> f(n + 1 , 0ll) ;
    vector<vector<array<long long , 3>>> h(n + 1) ;
    int magic = 300 ;
    vector<int> heavy ;
    vector<int> is_heavy(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)
        if(deg[i] > magic)  heavy.push_back(i) , is_heavy[i] = 1 ;
    auto go = [&]()
    {
        for(auto u : heavy)
        {
            h[u].resize(0) ;
            for(auto [v , w] : g[u])
                h[u].push_back({f[v] + w , v , w}) ;
            nth_element(h[u].begin() + 1 , h[u].begin() + magic , h[u].end()) ;
        }
    } ;
    for(int i = q ; i >= 1 ; i --)
    {
        if(i == q || i % magic == 0)  go() ;
        int u = Q[i] ;
        if(is_heavy[u])
        {
            int cur = 0 ;
            long long t = inf ;
            for(auto [val , v , w] : h[u])
            {
                t = min(t , f[v] + w) ;
                cur += 1 ;
                if(cur > magic)  break ;
            }
            f[u] = t ;
        }
        else
        {
            long long t = inf ;
            for(auto [v , w] : g[u])  t = min(t , f[v] + w) ;
            f[u] = t ;
        }
    }
    long long res = 0 ;
    for(int i = 1 ; i <= n ; i ++)  res += f[i] % mod * a[i] % mod ;
    cout << res % mod << '\n' ; 

    return 0 ;
}