//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
pair<int , int> operator - (pair<int , int> u , pair<int , int> v)
{
    return pair<int , int>{u.first - v.first , u.second - v.second} ;
}
int main()
{
    // std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n ;
    cin >> n ;
    vector<pair<int , int>> v(n) ;
    for(int i = 0 ; i < n ; i ++)  cin >> v[i].first >> v[i].second ;
    vector<int> vis(n , 0) ;
    auto cross = [&](pair<int , int> u , pair<int , int> v)
    {
        return abs(1ll * u.first * v.second - 1ll * u.second * v.first) ;
    } ;
    auto find_mn = [&]()
    {
        vector<int> s ;
        for(int i = 0 ; i < n ; i ++)
            if(vis[i] == 0)
                s.push_back(i) ;
        int m = s.size() ;
        long long mn = 5e18 ;
        int id = -1 ;
        for(int i = 0 ; i < m ; i ++)
        {
            int x = s[i] ;
            int y = s[(i - 1 + m) % m] ;
            int z = s[(i + 1) % m] ;
            long long val = cross(v[x] - v[y] , v[z] - v[x]) ;
            if(val < mn)
            {
                mn = val ;
                id = s[i] ;
            }
        }
        return id ;
    } ;
    if(n % 2 == 0)
    {
        cout << "Alberto" << endl ;
        for(int _ = 1 ; _ <= n - 2 ; _ += 2)
        {
            int id = find_mn() ;
            vis[id] = 1 ;
            cout << id + 1 << endl ;
            int x ;
            cin >> x ;
            x -= 1 ;
            vis[x] = 1 ;
        }
    }
    else
    {
        cout << "Beatrice" << endl ;
        int x ;
        cin >> x ;
        x -= 1 ;
        vis[x] = 1 ;
        for(int _ = 2 ; _ <= n - 2 ; _ += 2)
        {
            int id = find_mn() ;
            vis[id] = 1 ;
            cout << id + 1 << endl ;
            int x ;
            cin >> x ;
            x -= 1 ;
            vis[x] = 1 ;
        }
    }

    return 0 ;
}