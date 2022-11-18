//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n ;
    cin >> n ;
    vector<int> s(n) ;
    for(int i = 0 ; i < n ; i ++)  cin >> s[i] ;
    auto fail = [&]()
    {
        cout << "-1\n" ;
        exit(0) ;
    } ;
    vector<int> t ;
    for(int i = n - 1 ; i >= 1 ; i --)
        if(s[i - 1] - s[i] != 1)
        {
            t.push_back(s[i] - s[i - 1]) ;
        }
    int m = t.size() ;
    if(m >= 30)  fail() ;
    vector<int> a = {s.back()} ;
    vector<int> pos(m , -1) ;
    auto solve = [&](int sum , int prod)
    {
        pair<int , int> tt = {-1 , -1} ;
        int a = sum ;
        int b = prod ;
        if(1ll * a * a - 4ll * b < 0)  return tt ;
        int d = sqrt(1ll * a * a - 4ll * b) ;
        if(1ll * d * d != 1ll * a * a - 4ll * b)  return tt ;
        int x = a - d ;
        int y = a + d ;
        if(x < 0 || y < 0)  return tt ;
        if(x & 1)  return tt ;
        return pair<int , int> {x / 2 , y / 2} ;
    } ;
    auto print = [&](vector<int> c)
    {
        for(auto u : c)  cout << u << ' ' ;
        for(int i = c.size() ; i < n ; i ++)  cout << "1 " ;
        cout << '\n' ;
        int cur = c.size() ;
        vector<pair<int , int>> v ;
        for(int i = 0 ; i < c.size() ; i ++)  v.push_back({i , i}) ;
        int now = m - 1 ;
        for(int i = 0 ; i < n - 1 ; i ++)
        {
            if(s[i] - s[i + 1] == 1)  cout << cur << '\n' , cur += 1 ;
            else
            {
                vector<pair<int , int>> v2 ;
                int p = pos[now] ;
                cout << v[p + 1].first << '\n' ;
                for(int j = 0 ; j < v.size() ; j ++)
                {
                    if(j < p || j > p + 1)  v2.push_back(v[j]) ;
                    else
                    {
                        v2.push_back({v[j].first , v[j + 1].second}) ;
                        j += 1 ;
                    }
                }
                v = v2 ;
                now -= 1 ;
            }
        }
    } ;
    function<void(int , vector<int>)> dfs = [&](int x , vector<int> c)
    {
        if(x >= m)
        {
            print(c) ;
            exit(0) ;
        }
        set<int> vis ;
        for(int i = 0 ; i <= x ; i ++)
        {
            if(vis.count(c[i]))  continue ;
            vis.insert(c[i]) ;
            auto [a , b] = solve(c[i] - t[x] , c[i]) ;
            if(a == -1)  continue ;            
            pos[x] = i ;
            vector<int> d ;
            d.insert(d.end() , c.begin() , c.begin() + i) ;
            d.push_back(a) ;
            d.push_back(b) ;
            d.insert(d.end() , c.begin() + i + 1 , c.end()) ;
            dfs(x + 1 , d) ;
        }
    } ;
    dfs(0 , a) ;
    fail() ;

    return 0 ;
}