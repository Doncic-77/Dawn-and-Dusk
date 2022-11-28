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
    vector<vector<int>> a(n + 1 , vector<int>(n + 1 , 0)) ;
    long long sum = 0 ;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            cin >> a[i][j] , sum += a[i][j] ;
    int mn = 1e9 + 10 ;
    for(int i = 1 ; i <= n ; i ++)  mn = min(mn , a[i][n + 1 - i]) ;
    cout << sum - mn << '\n' ;

    return 0 ;
}