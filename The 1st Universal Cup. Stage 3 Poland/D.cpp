//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int T ;
    cin >> T ;
    while(T --)
    {
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
        vector<int> siz(n + 1 , 0) ;
        int cur = 0 ;
        vector<int> dfn(n + 1 , 0) ;
        vector<int> l(n + 1 , 0) ;
        function<void(int , int)> dfs = [&](int fa , int u)
        {
            dfn[u] = ++ cur ;
            siz[u] = 1 ;
            int f = 0 ;
            for(auto v : g[u])
            {
                if(v == fa)  continue ;
                dfs(u , v) ;
                siz[u] += siz[v] ;
                f = 1 ;
                l[u] += l[v] ;
            }
            if(f == 0)  l[u] = 1 ;
        } ;
        dfs(1 , 1) ;
        vector<int> res ;
        vector<int> id(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  id[i] = i ;
        sort(id.begin() + 1 , id.end() , [&](int x , int y){
            return siz[x] < siz[y] ;
        }) ;        
        for(int i = 1 ; i <= n ; i ++)
        {
            int j = i ;
            while(j + 1 <= n && siz[id[j + 1]] == siz[id[j]])  j += 1 ;
            int c = 0 ;
            for(int k = i ; k <= j ; k ++)  c += l[id[k]] ;
            if(c == l[1])  res.push_back(siz[id[i]]) ;
            i = j ;
        }
        cout << res.size() << '\n' ;
        for(auto u : res)  cout << u << " \n"[u == res.back()] ;
    }

    return 0 ;
}
/*
1
9
1 2
2 3
3 4
3 5
2 6
6 7
7 8
7 9
*/