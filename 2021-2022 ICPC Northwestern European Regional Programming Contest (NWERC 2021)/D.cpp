//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n ;
    cin >> n ;
    vector<pair<int , int>> a(n) ;
    for(int i = 0 ; i < n ; i ++)  cin >> a[i].first >> a[i].second ;
    if(n == 1)
    {
        cout << "4\n" ;
        return 0 ;
    }
    int mn = 1e7 ;
    int mx = -1e7 ;
    for(int i = 0 ; i < n ; i ++)
    {
        mn = min(mn , a[i].second - a[i].first) ;
        mx = max(mx , a[i].second - a[i].first) ;
    }
    int res = 4 ;
    res += max(1 , (mx - mn)) ;
    mn = 1e7 ;
    mx = -1e7 ;
    for(int i = 0 ; i < n ; i ++)
    {
        mn = min(mn , a[i].second + a[i].first) ;
        mx = max(mx , a[i].second + a[i].first) ;
    }
    res += max(1 , (mx - mn)) ;

    cout << res << '\n' ;

    return 0 ;
}