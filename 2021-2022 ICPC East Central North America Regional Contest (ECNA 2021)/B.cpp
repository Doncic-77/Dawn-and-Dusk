//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m ;
    cin >> n >> m ;
    vector<int> a(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
    vector<int> f(n + 1) ;
    vector<int> deg(n + 1 , 0) ;
    vector<bool> c(n + 1 , false) ;
    while(m --)
    {
        int a , b ;
        cin >> a >> b ;
        f[b] = a ;
        deg[a] += 1 ;
    }
    for(int i = 1 ; i <= n ; i ++)
        if(deg[i] == 0)
            c[i] = true ;
    int res = 1e9 ;
    int now = 0 ;
    vector<int> cnt(n + 1 , 0) ;
    auto add = [&](int u)
    {
        if(cnt[u] == 0)  now += a[u] ;
        cnt[u] += 1 ;
    } ;
    auto del = [&](int u)
    {
        if(cnt[u] == 1)  now -= a[u] ;
        cnt[u] -= 1 ;
    } ;
    auto add0 = [&](int u)
    {
        while(u != 0)
        {
            add(u) ;
            u = f[u] ;
        }
    } ;
    auto del0 = [&](int u)
    {
        while(u != 0)
        {
            del(u) ;
            u = f[u] ;
        }
    } ;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(!c[i])  continue ;
        add0(i) ;
        for(int j = i + 1 ; j <= n ; j ++)
        {
            if(!c[j])  continue ;
            add0(j) ;
            res = min(res , now) ;
            del0(j) ;
        }
        del0(i) ;
    }

    cout << res << '\n' ;

    return 0 ;
}