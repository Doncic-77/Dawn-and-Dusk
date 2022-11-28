//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m ;
    cin >> n >> m ;
    vector<int> p(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> p[i] ;
    vector<vector<int>> g(n + 1) ;
    while(m --)
    {
        int u , v ;
        cin >> u >> v ;
        g[v].push_back(u) ;
    }
    auto solve = [&](int t)
    {
        int now = n ;
        vector<int> in(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)
        {
            for(auto v : g[i])
                in[v] += 1 ;
        }
        priority_queue<pair<int , int>> q ;
        for(int i = 1 ; i <= n ; i ++)
            if(in[i] == 0)
                q.push({p[i] , i}) ;
        while(!q.empty())
        {
            auto [val , u] = q.top() ;
            q.pop() ;
            if(u == t)  continue ;
            if(now > val)  break ;
            now -= 1 ;
            for(auto v : g[u])
            {
                in[v] -= 1 ;
                if(in[v] == 0)  q.push({p[v] , v}) ;
            }
        }
        return now ;
    } ;
    for(int i = 1 ; i <= n ; i ++)  cout << solve(i) << " \n"[i == n] ;

    return 0 ;
}