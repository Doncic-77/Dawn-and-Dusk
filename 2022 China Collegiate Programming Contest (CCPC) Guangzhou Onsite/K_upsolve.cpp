//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
const int mod = 1e9 + 7 ;
int norm(int x)
{
    if(x < 0)  x += mod ;
    if(x >= mod)  x -= mod ;
    return x ;
}
template<class T>
T power(T a , int b) //一定记得加强制类型转换power(mint(2),x)
{
    T res = 1 ;
    for( ; b ; b /= 2 , a *= a)
    if(b % 2)  res *= a ;
    return res ;
}
template<class T>
T print(T a , int b)
{
    T res = 1 ;
    for( ; b ; b /= 2 , a *= a)
    if(b % 2)  res *= a ;
    return res ;
}
struct mint
{
    int x ;
    mint(int x = 0) : x(norm(x)) {}
    int val() const
    {
        return x ;
    }
    mint operator-() const
    {
        return mint(norm(mod - x)) ;
    }
    mint inv() const
    {
        assert(x != 0);
        return power(*this, mod - 2) ;
    }
    mint &operator*=(const mint &rhs)
    {
        x = (long long)x * rhs.x % mod ;
        return *this ;
    }
    mint &operator+=(const mint &rhs)
    {
        x = norm(x + rhs.x) ;
        return *this ;
    }
    mint &operator-=(const mint &rhs)
    {
        x = norm(x - rhs.x) ;
        return *this ;
    }
    mint &operator/=(const mint &rhs)
    {
        return *this *= rhs.inv() ;
    }
    friend mint operator*(const mint &lhs , const mint &rhs)
    {
        mint res = lhs ;
        res *= rhs ;
        return res ;
    }
    friend mint operator+(const mint &lhs , const mint &rhs)
    {
        mint res = lhs ;
        res += rhs ;
        return res ;
    }
    friend mint operator-(const mint &lhs , const mint &rhs)
    {
        mint res = lhs ;
        res -= rhs ;
        return res ;
    }
    friend mint operator/(const mint &lhs , const mint &rhs)
    {
        mint res = lhs ;
        res /= rhs ;
        return res ;
    }
} ;
vector<mint> fac ;
vector<mint> inv ;
void init(int n)
{
    n <<= 1 ;
    fac.resize(0) ;
    fac.resize(n + 10 , mint(1)) ;
    inv.resize(0) ;
    inv.resize(n + 10 , mint(1)) ;
    for(int i = 2 ; i <= n ; i ++)  fac[i] = fac[i - 1] * i ;
    inv[n] = fac[n].inv() ;
    for(int i = n - 1 ; i >= 1 ; i --)  inv[i] = inv[i + 1] * (i + 1) ;
}
mint C(int n , int m)
{
    if(n < 0 || m < 0 || n < m)  return mint(0) ;
    return fac[n] * inv[m] * inv[n - m] ;
}
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;


    int T ;
    cin >> T ;
    while(T --)
    {
        int n , m ;
        cin >> n >> m ;
        vector<vector<int>> g(n + 1) ;
        vector<int> deg(n + 1 , 0) ;
        for(int i = 0 ; i < m ; i ++)
        {
            int u , v ;
            cin >> u >> v ;
            g[u].push_back(v) ;
            g[v].push_back(u) ;
            deg[u] += 1 ;
            deg[v] += 1 ;
        }
        if(n + m < 4)
        {
            cout << "0\n" ;
            continue ;
        }
        vector<vector<int>> G(n + 1) ;
        for(int i = 1 ; i <= n ; i ++)
            for(auto v : g[i])
            {
                if(deg[i] > deg[v] || deg[i] == deg[v] && i > v)
                    G[i].push_back(v) ;
            }
        auto three_ring = [&]()
        {
            mint res = 0 ;
            vector<int> vis(n + 1 , 0) ;
            for(int i = 1 ; i <= n ; i ++)
            {
                for(auto v : G[i])  vis[v] = i ;
                for(auto v : G[i])
                    for(auto w : G[v])
                        if(vis[w] == i)
                            res += 1 ;
            }
            return res ;
        } ;
        auto four_ring = [&]()
        {
            mint res = 0 ;
            vector<int> cnt(n + 1 , 0) ;
            for(int i = 1 ; i <= n ; i ++)
            {
                for(auto v : g[i])
                    for(auto w : G[v])
                        if(deg[w] < deg[i] || deg[w] == deg[i] && w < i)
                            res += cnt[w] , cnt[w] += 1 ;
                for(auto v : g[i])
                    for(auto w : G[v])
                        if(deg[w] < deg[i] || deg[w] == deg[i] && w < i)
                            cnt[w] = 0 ;
            }
            return res ;
        } ;
        mint res = 0 ;
        // 4个中点
        res += four_ring() ;
        // 3个中点
        res += three_ring() * 3 ;
        // 2个中点
        if(m > 1)  res += mint(m) * (m - 1) ;
        mint two = mint(1) / 2 ;
        for(int i = 1 ; i <= n ; i ++)
            for(auto v : g[i])
                res += (deg[v] - 1) * two ;
        // 1个中点
        if(n > 2)  res += mint(m) * (n - 2) ;

        cout << res.val() << '\n' ;
    }

    return 0 ;
}