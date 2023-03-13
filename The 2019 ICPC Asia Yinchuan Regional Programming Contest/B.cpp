//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n ;
    cin >> n ;
    vector<vector<int>> a(n + 1 , vector<int>(n + 1 , 0)) ;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            cin >> a[i][j] ;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            if(a[i][j] == -1)
            {
                if(i >= 2 && j >= 2)
                {
                    cout << a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1] << '\n' ;
                    return 0 ;
                }
                if(i >= 2 && j + 1 <= n)
                {
                    cout << a[i][j + 1] + a[i - 1][j] - a[i - 1][j + 1] << '\n' ;
                    return 0 ;
                }
                if(i + 1 <= n && j >= 2)
                {
                    cout << a[i][j - 1] + a[i + 1][j] - a[i + 1][j - 1] << '\n' ;
                    return 0 ;
                }
                if(i + 1 <= n && j + 1 <= n)
                {
                    cout << a[i][j + 1] + a[i + 1][j] - a[i + 1][j + 1] << '\n' ;
                    return 0 ;
                }
            }

    return 0 ;
}