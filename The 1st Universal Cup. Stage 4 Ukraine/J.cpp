//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , q ;
    cin >> n >> q ;
    vector<int> p(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> p[i] ;
    int cycles = 0 ;
    vector<int> vis(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(vis[i] == 1)  continue ;
        function<void(int)> dfs = [&](int u)
        {
            if(vis[u] == 1)  return ;
            vis[u] = 1 ;
            dfs(p[u]) ;
        } ;
        cycles += 1 ;
        dfs(i) ;
    }
    int f = ((n - cycles) & 1) ;
    int cnt_parity = 0 ;
    int cnt_same = 0 ;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(p[i] % 2 != i % 2)  cnt_parity += 1 ;
        if(p[i] == i)  cnt_same += 1 ;
    }
    auto add = [&](int u , int x)
    {
        if(p[u] % 2 != u % 2)  cnt_parity += x ;
        if(p[u] == u)  cnt_same += x ;
    } ;
    while(q --)
    {
        int u , v ;
        cin >> u >> v ;
        f ^= 1 ;
        add(u , -1) ;
        add(v , -1) ;
        swap(p[u] , p[v]) ;
        add(u , 1) ;
        add(v , 1) ;
        if(f == 1)  cout << n << '\n' ;
        else if(cnt_parity > 0)  cout << n - 1 << '\n' ;
        else if(cnt_same == n)  cout << -1 << '\n' ;
        else  cout << n - 2 << '\n' ;
    }

    return 0 ;
}
/*
4 1
3 1 2 4
3 2
*/