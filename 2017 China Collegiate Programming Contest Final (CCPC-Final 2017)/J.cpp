//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
const long long inf = 1e18 ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int T ;
    cin >> T ;
    int cas = 0 ;
    while(T --)
    {
        int n , m , x ;
        cin >> n >> m >> x ;
        set<array<int , 4>> s ;
        for(int i = 0 ; i < m ; i ++)
        {
            array<int , 4> a ;
            for(int j = 0 ; j < 4 ; j ++)  cin >> a[j] ;
            s.insert(a) ;
        }
        vector<array<int , 4>> v ;
        for(auto u : s)  v.push_back(u) ;

        // assert(m == v.size()) ;
        
        m = v.size() ;
        int err = 0 ;
        for(int i = 0 ; i < m - 1 ; i ++)
        {
            for(int j = 0 ; j < 4 ; j ++)
                if(v[i][j] > v[i + 1][j])
                    err = 1 ;
            if(v[i][0] > v[i][2])  err = 1 ;
            if(v[i][1] > v[i][3])  err = 1 ;
            if(v[i][0] == v[i][1] && v[i][1] == v[i][2] && v[i][2] == v[i][3])  err = 1 ;
        }
        if(err == 1)
        {
            cout << "Case #" << ++ cas << ": " << "IMPOSSIBLE" << '\n' ;
            continue ;
        }

        vector<vector<pair<int , int>>> g(n + 1) ;
        vector<long long> dis(n + 1 , inf) ;

        auto add = [&](int u , int v , int w)
        {
            g[u].push_back({v , w}) ;
        } ;

        for(int i = 2 ; i <= n ; i ++)  add(i , i - 1 , -1) ;

        for(auto [a , b , c , d] : v)
        {
            if(a == b && c == d)
            {
                add(c , a , -x) ;
                add(a , c , x) ;
            }
            else if(a + 1 == b && c == d)
            {
                add(b , c , x - 1) ;
                add(c , a , -(x + 1)) ;
            }
            else if(a == b && c + 1 == d)
            {
                add(a , c , x - 1) ;
                add(d , a , -(x + 1)) ;
            }
            else
            {
                add(b , c , x - 1) ;
                add(d , a , -(x + 1)) ;
            }
        }

        auto spfa = [&](int s)
        {
            vector<int> cnt(n + 1 , 0) ;
            vector<int> in(n + 1 , 0) ;
            queue<int> q ;
            while(!q.empty())  q.pop() ;
            q.push(s) ;
            dis[s] = 0 , in[s] = 1 , cnt[s] = 1 ;
            while(!q.empty())
            {
                int u = q.front() ;
                q.pop() ;
                in[u] = 0 ;
                for(auto [v , w] : g[u])        
                {
                    if(dis[v] > dis[u] + w)
                    {
                        dis[v] = dis[u] + w ;
                        cnt[v] = cnt[u] + 1 ;
                        if(cnt[v] > n)  return 1 ; //找到负环。
                        if(!in[v])
                        {
                            in[v] = 1 ;
                            q.push(v) ;
                        }
                    }          
                }
            }
            return 0 ;
        } ;
        if(spfa(n) == 1)  cout << "Case #" << ++ cas << ": " << "IMPOSSIBLE" << '\n' ;
        else  
        {
            cout << "Case #" << ++ cas << ": " ;
            for(int i = 2 ; i <= n ; i ++)  cout << dis[i] - dis[i - 1] << " \n"[i == n] ;
        }
    }

    return 0 ;
}

/*

1
4 3 2
1 1 2 3
2 3 2 3
2 3 3 4

2
4 3 2
1 1 2 3
2 3 2 3
2 3 3 4
4 2 2
1 2 3 4
2 3 2 3


*/