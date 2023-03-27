//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int T ;
    cin >> T ;
    int cas = 0 ;
    while(T --)
    {
        int x , y , n ;
        cin >> x >> y >> n ;
        if(x > y)
        {
            cout << "Case #" << ++ cas << ": " << n << '\n' ;
            continue ;
        }
        swap(x , y) ;
        int t = (11 * n * x - 9 * n * y + 11 * x + 2 * y - 1) / (11 * x + 2 * y) ;
        if(t < 0)  cout << "Case #" << ++ cas << ": " << 0 << '\n' ;
        else  cout << "Case #" << ++ cas << ": " << n - t << '\n' ;
    }
    

    return 0 ;
}
/*
2
10 10 1
10 10 2
*/