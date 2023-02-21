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
        int n ;
        cin >> n ;
        vector<int> a(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
        vector<int> pre(n + 1 , 0) ;
        vector<int> suf(n + 2 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  pre[i] = pre[i - 1] ^ a[i] ;
        for(int i = n ; i >= 1 ; i --)  suf[i] = suf[i + 1] ^ a[i] ;
        int f = 0 ;
        for(int i = 1 ; i <= n - 1 ; i ++)
            if(pre[i] != suf[i + 1])
            {
                f = 1 ;
                cout << "YES\n" ;
                cout << 2 << '\n' ;
                cout << 1 << ' ' << i << '\n' ;
                cout << i + 1 << ' ' << n << '\n' ;
                break ;
            }
        if(f == 1)  continue ;
        map<int , int> mp ;
        for(int i = 1 ; i <= n ; i ++)  mp[suf[i]] = i ;
        int x = pre[n] ;
        for(int i = 1 ; i <= n - 2 ; i ++)
        {
            if(mp[suf[i]] == i)  mp.erase(suf[i]) ;
            int a = pre[i] ;
            if(a == x)  continue ;
            for(auto [u , c] : mp)
            {
                int b = u ;
                if(c <= i + 1)  continue ;
                if(a == b)  continue ;
                if(b == x)  continue ;
                f = 1 ;
                cout << "YES\n" ;
                cout << 3 << '\n' ;
                cout << 1 << ' ' << i << '\n' ;
                cout << i + 1 << ' ' << c - 1 << '\n' ;
                cout << c << ' ' << n << '\n' ;
                break ;
            }
            if(f == 1)  break ;
        }
        if(f == 0)  cout << "NO\n" ;
    }

    return 0 ;
}