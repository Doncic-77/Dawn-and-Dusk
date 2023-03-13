//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
const int mod = 998244353 ;
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
const long long up = 1e6 + 1e5 ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    long long n ;
    cin >> n ;
    mint res = 0 ;
    
    auto small = [&]()
    {
        long long m = min(n , up) ;
        for(long long i = 2 ; i <= m ; i ++)
        {
            mint c = 0 ;
            mint cur = 0 ;
            for(long long j = i ; j <= n ; j *= i)
            {
                long long k = min(n , j * i - 1) ;
                cur += 1 ;
                c += cur * mint((k - j + 1) % mod) ;
            }
            res += mint(i) * c ;
        }
    } ;
    auto one2 = [&](long long x)
    {
        x %= mod ;
        return mint(x) * mint((x + 1) % mod) / 2 ;
    } ;
    auto one = [&](long long l , long long r)
    {
        return one2(r) - one2(l - 1) ;
    } ;
    auto two2 = [&](long long x)
    {
        x %= mod ;
        return mint(x) * mint((x + 1) % mod) * mint((2 * x + 1) % mod) / 6 ;
    } ;
    auto two = [&](long long l , long long r)
    {
        return two2(r) - two2(l - 1) ;
    } ;
    auto big = [&]()
    {
        if(n <= up)  return ;
        res += mint((n + 1) % mod) * one(up + 1 , n) ;
        res -= two(up + 1 , n) ;
    } ;

    small() ;
    big() ;

    cout << res.val() << '\n' ;

    return 0 ;
}