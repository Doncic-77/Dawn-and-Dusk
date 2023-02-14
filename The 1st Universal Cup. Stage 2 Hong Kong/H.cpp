//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    long long l , r , b , k ;
    cin >> l >> r >> b >> k ;
    long long res = 0 ;
    long long a = l ;
    res += (a + b - 1) / b * b * k ;
    cout << res << '\n' ;

    return 0 ;
}