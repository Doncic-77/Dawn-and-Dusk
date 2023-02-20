//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    vector<int> pre(n * 2 - 1 , 0) ;
    for(int i = 0 ; i < n * 2 - 1 ; i ++)
    {
        pre[i] = (s[i] == 'W') ;
        if(i > 0)  pre[i] += pre[i - 1] ;
    }
    int mx = 0 ;
    for(int i = n - 1 ; i < n * 2 - 1 ; i ++)
    {
        int s = pre[i] ;
        if(i >= n)  s -= pre[i - n] ;
        mx = max(mx , s) ;
    }
    cout << mx << '\n' ;

    return 0 ;
}