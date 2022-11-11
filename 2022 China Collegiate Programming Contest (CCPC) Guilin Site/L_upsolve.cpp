//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m ;
    cin >> n >> m ;
    if(n == 2) //ok
    {
        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= m ; j ++)
                cout << (j == m) << " \n"[j == m] ;
        return 0 ;
    }
    if(n == 4 && m == 3)
    {
        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= m ; j ++)
                if(i <= m)  cout << (i == j) << " \n"[j == m] ;
                else  cout << fixed << setprecision(10) << 1.0 / m << " \n"[j == m] ;
        return 0 ;
    }
    if(n >= m)
    {
        if(m - (n - m) == 2)
        {
            for(int i = 1 ; i <= n ; i ++)
                for(int j = 1 ; j <= m ; j ++)
                    if(i <= m)  cout << (i == j) << " \n"[j == m] ;
                    else  cout << (j == 1) << " \n"[j == m] ;
        }
        else
        {
            int f = 1 ;
            for(int i = 1 ; i <= n ; i ++)
            {
                for(int j = 1 ; j <= m ; j ++)
                    cout << (j == f) << " \n"[j == m] ;
                f = f + 1 ;
                if(f > m)  f = 1 ;
            }
        }
    }
    else
    {
        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= m ; j ++)
                cout << (j == m - (n - i)) << " \n"[j == m] ;
    }

    return 0 ;
}