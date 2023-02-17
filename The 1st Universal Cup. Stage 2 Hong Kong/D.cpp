//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
array<int , 2> operator +(array<int , 2> cc , array<int , 2> dd)
{
    return {cc[0] + dd[0] , cc[1] + dd[1]} ;
} ;
array<int , 2> operator -(array<int , 2> cc , array<int , 2> dd)
{
    return {cc[0] - dd[0] , cc[1] - dd[1]} ;
} ;
long long cross(array<int , 2> c , array<int , 2> d)
{
    return 1ll * c[0] * d[1] - 1ll * c[1] * d[0] ;
}
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m ;
    cin >> n >> m ;
    vector<vector<array<int , 2>>> g(n + 1) ;
    while(m --)
    {
        int u , v , c ;
        cin >> u >> v >> c ;
        g[u].push_back({v , c}) ;
    }
    vector<vector<array<int , 2>>> v(n + 1) ;
    v[1] = {{0 , 0}} ;

    int q ;
    cin >> q ;
    vector<long long> ans(q + 1 , 0ll) ;
    vector<vector<array<int , 3>>> Q(n + 1) ;
    for(int i = 1 ; i <= q ; i ++)
    {
        int a , b , x ;
        cin >> a >> b >> x ;
        Q[x].push_back({a , b , i}) ;
    }
    auto merge = [&](int b , int e , int c)
    {
        vector<array<int , 2>> t ;
        int m1 = v[b].size() ;
        int m2 = v[e].size() ;
        int i = 0 , j = 0 ;
        array<int , 2> p ;
        if(c == 0)  p = {1 , 0} ;
        else  p = {0 , 1} ;
        auto add = [&](array<int , 2> d)
        {
            if(t.empty())
            {
                t.push_back(d) ;
                return ;
            }
            if(t.size() == 1)
            {
                if(d[0] > t.back()[0] && d[1] < t.back()[1])  
                {
                    t.push_back(d) ;
                    return ;
                }
                if(d[0] == t.back()[0] && d[1] < t.back()[1])
                {
                    t.pop_back() ;
                    t.push_back(d) ;
                    return ;
                }
            }
            while(t.size() >= 2)
            {
                auto c1 = t.back() ;
                t.pop_back() ;
                auto c2 = t.back() ;
                auto v1 = c1 - c2 ;
                auto v2 = d - c1 ;
                if(d[0] >= c1[0] && d[1] >= c1[1])
                {
                    t.push_back(c1) ;
                    return ;
                }
                if(cross(v1 , v2) > 0)
                {
                    t.push_back(c1) ;
                    t.push_back(d) ;
                    return ;
                }
            }
            if(t.size() == 1)
            {
                if(d[0] > t.back()[0] && d[1] < t.back()[1])  
                {
                    t.push_back(d) ;
                    return ;
                }
                if(d[0] == t.back()[0] && d[1] < t.back()[1])
                {
                    t.pop_back() ;
                    t.push_back(d) ;
                    return ;
                }
            }
        } ;
        while(i < m1 || j < m2)
        {
            if(i == m1)  add(v[e][j]) , j ++ ;
            else if(j == m2)  add(v[b][i] + p) , i ++ ;
            else
            {
                if(v[b][i][0] + p[0] < v[e][j][0])  add(v[b][i] + p) , i ++ ;
                else  add(v[e][j]) , j ++ ;
            }
        }
        v[e] = t ;
    } ;
    for(int i = 1 ; i <= n ; i ++)
    {
        for(auto [a , b , id] : Q[i])
        {
            long long mn = 1e18 ;
            for(auto [x , y] : v[i])  mn = min(mn , 1ll * a * x + 1ll * b * y) ;
            ans[id] = mn ;
        }
        for(auto [v , c] : g[i])  merge(i , v , c) ;
    }
    for(int i = 1 ; i <= q ; i ++)  cout << ans[i] << '\n' ;

    return 0 ;
}