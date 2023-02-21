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
        vector<vector<int>> d(n , vector<int>(n , 0)) ;
        vector<vector<int>> f(n , vector<int>(n , n + n)) ; 
        for(int i = 0 ; i < n ; i ++)
        {
            string s ;
            cin >> s ;
            for(int j = 0 ; j < n ; j ++)  d[i][j] = (s[j] - '0') ;
            for(int j = 0 ; j < n ; j ++)
                if(d[i][j] == 1)
                    f[i][j] = 1 ;
        }
        vector<int> vis(n , 0) ;
        function<void(int)> dfs = [&](int u)
        {
            if(vis[u] == 1)  return ;
            vis[u] = 1 ;
            for(int i = 0 ; i < n ; i ++)
                if(f[u][i] == 1)
                    dfs(i) ;
        } ;
        dfs(0) ;
        if(accumulate(vis.begin() , vis.end() , 0) != n)
        {
            cout << "NO\n" ;
            continue ;
        }

        for(int k = 0 ; k < n ; k ++)
            for(int i = 0 ; i < n ; i ++)
                for(int j = 0 ; j < n ; j ++)
                    f[i][j] = min(f[i][j] , f[i][k] + f[k][j]) ;
        int flag = 0 ;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < n ; j ++)
                if(d[i][j] % 2 != f[i][j] % 2)
                    flag = 1 ;
        if(flag == 1)
        {
            cout << "NO\n" ;
            continue ;
        }
        cout << "YES\n" ;
        int res = 0 ;
        for(int i = 0 ; i < n ; i ++)
            for(int j = i + 1 ; j < n ; j ++)
                if(d[i][j] == 1)
                    res += 1 ;
        cout << res << '\n' ;
        for(int i = 0 ; i < n ; i ++)
            for(int j = i + 1 ; j < n ; j ++)
                if(d[i][j] == 1)
                    cout << i + 1 << ' ' << j + 1 << '\n' ;
    }

    return 0 ;
}