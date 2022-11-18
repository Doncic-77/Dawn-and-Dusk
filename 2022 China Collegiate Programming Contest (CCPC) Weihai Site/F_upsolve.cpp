//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
const long long inf = 1e18 ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int T ;
    cin >> T ;
    while(T --)
    {
        int n , m ;
        cin >> n >> m ;
        vector<int> c(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  cin >> c[i] ;
        vector<int> w(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  cin >> w[i] ;
        vector<vector<long long>> ans(n + 1 , vector<long long>(n + 1 , inf)) ;
        vector<vector<int>> g(n + 1 , vector<int>(n + 1 , 0)) ;
        while(m --)
        {
            int u , v ;
            cin >> u >> v ;
            g[u][v] = g[v][u] = 1 ;
        }
        vector<vector<long long>> d(n + 1 , vector<long long>(n + 1 , inf)) ;
        for(int i = 1 ; i <= n ; i ++)
        {
            for(int j = 1 ; j <= n ; j ++)
                if(c[i] == c[j] && g[i][j] == 1)
                    d[i][j] = w[j] ;
            d[i][i] = 0 ;
            g[i][i] = 1 ;
        }
        for(int k = 1 ; k <= n ; k ++)
           for(int i = 1 ; i <= n ; i ++)
                for(int j = 1 ; j <= n ; j ++)
                    d[i][j] = min(d[i][j] , d[i][k] + d[k][j]) ;
        vector<vector<long long>> d2(n + 1 , vector<long long>(n + 1 , inf)) ;
        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= n ; j ++)
                if(c[i] != c[j])
                {
                    for(int k = 1 ; k <= n ; k ++)
                        if(c[k] == c[i] && g[k][j] == 1)
                            d2[i][j] = min(d2[i][j] , w[i] + d[i][k] + w[j]) ;
                }
        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= n ; j ++)
                if(i != j)  d[i][j] += w[i] ;
        for(int i = 1 ; i <= n ; i ++)
        {
            vector<int> vis(n + 1 , 0) ;
            vector<long long> dis(n + 1 , inf) ;
            for(int j = 1 ; j <= n ; j ++)  dis[j] = d2[i][j] ;
            dis[i] = 0 ;
            vis[i] = 1 ;
            while(true)
            {
                int pos = -1 ;
                for(int j = 1 ; j <= n ; j ++)
                    if(vis[j] == 0)
                    {
                        if(pos == -1 || dis[j] < dis[pos])  pos = j ;
                    }
                if(pos == -1)  break ;
                vis[pos] = 1 ;
                for(int j = 1 ; j <= n ; j ++)
                    if(vis[j] == 0)
                        dis[j] = min(dis[j] , max(dis[pos] , d2[pos][j])) ;
            }
            for(int j = 1 ; j <= n ; j ++)
                for(int k = 1 ; k <= n ; k ++)
                    ans[i][j] = min(ans[i][j] , max(dis[k] , d[k][j])) ;
        }

        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= n ; j ++)
                cout << ans[i][j] << " \n"[j == n] ;
    }

    return 0 ;
}
/*

1
3 2
1 1 2
1 2 4
1 2
2 3

*/
