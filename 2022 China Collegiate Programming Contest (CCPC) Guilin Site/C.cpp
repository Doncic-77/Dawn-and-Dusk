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

    int n , m ;
    cin >> n >> m ;
    vector<int> a(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;

    int res = 0 ;
    //全S
    mint sum = 0 ;
    for(int i = 1 ; i <= n ; i ++)
    {
        sum += (power(mint(2) , m) * mint(n - i + 1) + mint(n) * (power(mint(2) , m) - 1) * power(mint(2) , m) / 2) * a[i] ; 
    }
    res = max(res , sum.val()) ;

    mint f = 0 ; //val_S
    for(int i = 1 ; i <= n ; i ++)  f += mint(n - i + 1) * a[i] ;
    mint g = 0 ; //val_S'
    for(int i = 1 ; i <= n ; i ++)  g += mint(i) * a[i] ;
    mint S = 0 ; //sum_S
    for(int i = 1 ; i <= n ; i ++)  S += a[i] ;

    //循环节内S长度为2^i
    //循环节是 2^i个S' + 2^i个S
    //2 ^ (m - 1 - i)个循环节
    for(int i = 0 ; i < m ; i ++)
    {
        mint sum = 0 ;
        sum += (f + g) * power(mint(2) , m - 1) ;
        //S'
        sum += mint(n) * S * power(mint(2) , i) * (power(mint(2) , m - 1 - i) * power(mint(2) , i) + power(mint(2) , m - 1 - i) * (power(mint(2) , m - 1 - i) - 1) / 2 * power(mint(2) , i + 1)) ;
        sum += mint(n) * S * power(mint(2) , m - 1 - i) * ((power(mint(2) , i) - 1) * power(mint(2) , i) / 2) ;
        //S
        sum += mint(n) * S * power(mint(2) , i) * (power(mint(2) , m - 1 - i) * (power(mint(2) , m - 1 - i) - 1) / 2 * power(mint(2) , i + 1)) ;
        sum += mint(n) * S * power(mint(2) , m - 1 - i) * ((power(mint(2) , i) - 1) * power(mint(2) , i) / 2) ;
        res = max(res , sum.val()) ;
    }

    cout << res << '\n' ;

    return 0 ;
}