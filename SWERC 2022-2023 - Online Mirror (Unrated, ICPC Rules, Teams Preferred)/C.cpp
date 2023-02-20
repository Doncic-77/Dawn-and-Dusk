//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    // std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m ;
    cin >> n >> m ;
    vector<int> x(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> x[i] ;
    sort(x.begin() + 1 , x.end()) ;
    reverse(x.begin() + 1 , x.end()) ;
    int k = 0 ;
    for(int i = 1 ; i <= n ; i ++)
        if(x[i] > m / i)
        {
            k = i ;
            break ;
        }
    if(k == 0)
    {
        cout << "Alessia" << endl ;
        priority_queue<array<int , 3>> q ;
        q.push({n , 1 , m}) ;
        set<pair<int , int>> s ;
        s.insert({1 , m}) ;
        for(int _ = 1 ; _ <= n ; _ ++)
        {
            while(true)
            {
                auto [t , l , r] = q.top() ;
                q.pop() ;
                auto it = s.lower_bound({l , r}) ;
                if(it == s.end() || (*it) != pair<int , int>{l , r})  continue ;
                cout << x[_] << ' ' << l << endl ;
                s.erase({l , r}) ;
                int x ;
                cin >> x ;
                if(x > l)  s.insert({l , x - 1}) , q.push({x - l , l , x - 1}) ;
                if(x < r)  s.insert({x + 1 , r}) , q.push({r - x , x + 1 , r}) ;
                break ;
            }
        }
    }
    else
    {
        cout << "Bernardo" << endl ;
        set<int> s ;
        for(int i = 1 ; i <= m ; i ++)
            if(i % x[k] == 0)
                s.insert(i) ;
        for(int _ = 1 ; _ <= n ; _ ++)
        {
            int l , r ;
            int t ;
            cin >> t >> l ;
            r = l + t - 1 ;
            auto it = s.lower_bound(l) ;
            if(it != s.end() && (*it) >= l && (*it) <= r)  cout << (*it) << endl ;
            else  cout << l << '\n' ;
        }
    }

    return 0 ;
}