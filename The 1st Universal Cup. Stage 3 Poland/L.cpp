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
        int n , p ;
        cin >> n >> p ;
        vector<int> vip(n + 1 , 0) ;
        for(int i = 1 ; i <= p ; i ++)
        {
            int x ;
            cin >> x ;
            vip[x] = 1 ;
        }
        vector<array<int , 2>> g(n) ;
        vector<int> c(n + 1 , 0) ;
        for(int i = 1 ; i <= n - 1 ; i ++)  cin >> g[i][0] >> g[i][1] >> c[i] ;
        int z ;
        cin >> z ;
        vector<int> ans(z) ;
        vector<int> ban(n , 0) ;
        for(int i = 0 ; i < z ; i ++)  cin >> ans[i] , ban[ans[i]] = 1 ;
        sort(ans.begin() , ans.end() , [&](int i , int j)
        {
            return c[i] < c[j] ;
        }) ;
        int flag = 0 ;
        vector<int> mx(n + 1 , 0) ;
        vector<long long> d(n + 1 , 0ll) ;
        for(int i = 1 ; i <= n - 1 ; i ++)
        {
            if(ban[i] == 1)  continue ;
            for(auto u : g[i])  mx[u] = max(mx[u] , c[i]) , d[u] += c[i] ;
        }
        auto bad = [&](int u)
        {
            return vip[u] == 0 && (d[u] % 2 == 1 || 1ll * mx[u] * 2 > d[u]) ;
        } ;
        for(int i = 1 ; i <= n ; i ++)  
            if(bad(i))
                flag = 1 ;
        for(auto i : ans)
        {
            for(auto u : g[i])
            {
                mx[u] = max(mx[u] , c[i]) ;
                d[u] += c[i] ;
                if(bad(u))  flag = 1 ;
            }
        }
        if(flag == 1)
        {
            cout << "NIE\n" ;
            continue ;
        }
        cout << "TAK\n" ;
        reverse(ans.begin() , ans.end()) ;
        for(auto u : ans)  cout << u << " \n"[u == ans.back()] ;
    }

    return 0 ;
}
/*
1
7 5
1 2 3 4 6
7 1 3
7 2 4
7 3 4
7 4 3
5 3 1
5 6 1
2
2 3
*/