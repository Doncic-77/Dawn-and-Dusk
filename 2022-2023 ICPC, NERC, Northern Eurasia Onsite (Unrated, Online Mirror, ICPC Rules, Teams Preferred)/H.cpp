//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;


    int cnt = 0 ;
    auto ask = [&](int x , int y)
    {
        cnt += 1 ;
        cout << x << ' ' << y << endl ;
        string s ;
        getline(cin , s) ;
        if(s.back() == '!')  exit(0) ;
        return s ;
    } ;
    ask(0 , 0) ;
    string t1 = ask(1 , 1) ;
    string t2 = ask(0 , 0) ;
    if(t1 == t2)
    {
        ask(0 , 1) ;
        ask(1 , 0) ;
    }
    
    // t1 closer
    // t2 further

    auto solve = [&](int x_R , int y_R)
    {
        int x_L = 0 , y_L = 0 ;
        while(x_L != x_R || y_L != y_R)
        {
            int x = (x_L + x_R) / 2 ;
            int y = (y_L + y_R) / 2 ;
            ask(x , y) ;
            if(x_L != x_R)
            {
                x += 1 ;
                string t = ask(x , y) ;
                if(t == t1)  x_L = x ;
                else  x_R = x - 1 ;
            }
            if(y_L != y_R)
            {
                y += 1 ;
                string t = ask(x , y) ;
                if(t == t1)  y_L = y ;
                else  y_R = y - 1 ;
            }
        }
        ask(x_L , y_L) ;
    } ;
    solve(1000000 , 1000000) ;


    return 0 ;
}