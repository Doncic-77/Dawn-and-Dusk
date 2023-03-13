//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , q ;
    cin >> n >> q ;
    vector<pair<int , int>> ans ;
    auto gcd = [&](int x , int y)
    {
        if(y == 1)  return 1 ;
        while(y > 0)
        {
            x = x / y ;
            swap(x , y) ;
        }
        return x ;
    } ;
    for(int y = 2 ; y <= n ; y ++)
    {
        ans.push_back({y , y}) ;
        for(int w = 2 ; w * y <= n && w <= y ; w ++)
        {
            int g = gcd(y , w) ;
            if(y % g != 0)  continue ;
            int z = y / g ;
            for(int k = 0 ; k < z ; k ++)
                if(__gcd(k , z) == 1)
                {
                    int x = (w * z + k) * g ; 
                    if(x <= n)  ans.push_back({x , y}) ;
                }
        }
    }
    sort(ans.begin() , ans.end()) ;

    while(q --)
    {
        long long x ;
        cin >> x ;
        if(x > ans.size())  cout << "-1 -1\n" ;
        else  cout << ans[x - 1].first << ' ' << ans[x - 1].second << '\n' ;
    }

    return 0 ;
}
