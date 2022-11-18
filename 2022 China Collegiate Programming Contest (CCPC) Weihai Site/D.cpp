//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
const int inf = 1e9 ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    vector<int> c = {3 , 4 , 5 , 4 , 3} ;
    vector<vector<int>> a(5) ;
    vector<vector<int>> id(5) ;
    vector<int> val(19) ;
    int cur = 0 ;
    for(int i = 0 ; i < 5 ; i ++)
        for(int j = 0 ; j < c[i] ; j ++)
        {
            int x ;
            cin >> x ;
            a[i].push_back(x) ;
            id[i].push_back(cur) ;
            val[cur] = x ;
            cur += 1 ;
        }
    
    vector<array<int , 2>> p(19) ;
    p[0] = {0 , 2} ;
    p[1] = {0 , 4} ;
    p[2] = {0 , 6} ;
    p[3] = {1 , 1} ;
    p[4] = {1 , 3} ;
    p[5] = {1 , 5} ;
    p[6] = {1 , 7} ;
    p[7] = {2 , 0} ;
    p[8] = {2 , 2} ;
    p[9] = {2 , 4} ;
    p[10] = {2 , 6} ;
    p[11] = {2 , 8} ;
    p[12] = {3 , 1} ;
    p[13] = {3 , 3} ;
    p[14] = {3 , 5} ;
    p[15] = {3 , 7} ;
    p[16] = {4 , 2} ;
    p[17] = {4 , 4} ;
    p[18] = {4 , 6} ;
    vector<vector<int>> p2(5 , vector<int>(9 , -1)) ;
    for(int i = 0 ; i < 19 ; i ++)  p2[p[i][0]][p[i][1]] = i ;

    vector<array<int , 2>> d = {{-1 , -1} , {-1 , 1} , {1 , -1} , {1 , 1} , {0 , 2} , {0 , -2}} ;

    vector<int> dp(1 << 19 , -inf) ;
    function<int(int)> dfs = [&](int t)
    {
        if(t == 0)  return 0 ;
        if(dp[t] != -inf)  return dp[t] ;
        int res = -inf ;
        vector<vector<int>> f(5 , vector<int>(9 , 0)) ;
        int tmp = t ;
        for(int i = 0 ; i < 5 ; i ++)
            for(int j = 0 ; j < 9 ; j ++)
            {
                if(p2[i][j] == -1)  continue ;
                if(tmp & 1)  f[i][j] = 1 ;
                tmp >>= 1 ;
            }
        for(int i = 0 ; i < 5 ; i ++)
            for(int j = 0 ; j < 9 ; j ++)
            {
                if(f[i][j] == 1)
                {
                    //直接删除
                    res = max(res , dfs(t ^ (1 << p2[i][j]))) ;
                    //跳一下
                    for(auto [dx , dy] : d)
                    {
                        int nx = i + dx ;
                        int ny = j + dy ;
                        int nx2 = nx + dx ;
                        int ny2 = ny + dy ;
                        if(nx2 < 0 || nx2 > 4 || ny2 < 0 || ny2 > 8)  continue ;
                        if(f[nx][ny] == 1 && p2[nx2][ny2] != -1 && f[nx2][ny2] == 0)
                        {
                            int state = t ;
                            state ^= (1 << p2[i][j]) ;
                            state ^= (1 << p2[nx][ny]) ;
                            state ^= (1 << p2[nx2][ny2]) ;
                            res = max(res , dfs(state) + val[p2[nx][ny]]) ;
                        }
                    }
                }
            }
        dp[t] = res ;
        return dp[t] ;
    } ;
    int T ;
    cin >> T ;
    while(T --)
    {
        vector<string> s(5) ;
        for(int i = 0 ; i < 5 ; i ++)  cin >> s[i] ;
        int t = 0 ;
        for(int i = 4 ; i >= 0 ; i --)
            for(int j = c[i] - 1 ; j >= 0 ; j --)
            {
                t = t * 2 + (s[i][j] == '#') ;
            }
        cout << dfs(t) << '\n' ;
    }   

    return 0 ;
}
/*
9 2 2
3 3 7 2
0 3 6 8 5
4 7 7 5
8 0 7
1
...
....
..##.
....
...
...

*/