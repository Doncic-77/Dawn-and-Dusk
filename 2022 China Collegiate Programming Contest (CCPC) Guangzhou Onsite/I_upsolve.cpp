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

    int n ;
    cin >> n ;
    vector<vector<int>> g(n + 1) ;
    for(int i = 1 ; i <= n - 1 ; i ++)
    {
        int u , v ;
        cin >> u >> v ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    mint sum = 0 ;
    vector<mint> a(n + 1 , mint(0)) ;
    vector<mint> p(n + 1 , mint(0)) ;
    for(int i = 1 ; i <= n ; i ++)
    {
        int t , b , c ;
        cin >> t >> b >> c ;
        a[i] = t ;
        sum += t ;
        p[i] = mint(b) / mint(c) ;
    }
    for(int i = 1 ; i <= n ; i ++)  a[i] /= sum ;
    // f[i][j] 表示 i子树有j个感染且i感染了且i子树内没有感染源的概率
    vector<vector<mint>> f(n + 1 , vector<mint>(n + 1 , mint(0))) ;
    // h[i][j] 表示 i子树有j个感染且i感染了且i子树内有感染源的概率
    vector<vector<mint>> h(n + 1 , vector<mint>(n + 1 , mint(0))) ; 
    // 难点是怎么把a放进答案
    // 解决方案是直接塞即可 直接合并就是对的
    vector<int> siz(n + 1 , 0) ;
    vector<int> pre(n + 1 , 0) ;
    function<void(int , int)> dfs = [&](int fa , int u)
    {
        pre[u] = fa ;
        siz[u] = 1 ;
        f[u][1] = p[u] ;
        h[u][1] = a[u] ;
        for(auto v : g[u])
        {
            if(v == fa)  continue ;
            dfs(u , v) ;
            vector<mint> f2(n + 1 , mint(0)) ;
            vector<mint> h2(n + 1 , mint(0)) ;
            for(int i = 1 ; i <= siz[u] ; i ++)
                for(int j = 0 ; j <= siz[v] ; j ++)
                {
                    f2[i + j] += f[u][i] * f[v][j] ;
                    h2[i + j] += h[u][i] * f[v][j] ;
                    h2[i + j] += f[u][i] * h[v][j] ;
                }
            siz[u] += siz[v] ;
            f[u] = f2 ;
            h[u] = h2 ;
        }
        f[u][0] = mint(1) - p[u] ;
    } ;
    dfs(1 , 1) ;


    for(int i = 1 ; i <= n ; i ++)
    {
        mint res = 0 ;
        for(int j = 1 ; j <= n ; j ++)
        {
            mint pp = 1 ;
            if(j != 1)  pp = mint(1) - p[pre[j]] ;
            res += h[j][i] * pp ;
        } 
        cout << res.val() << '\n' ;
    }

    return 0 ;
}