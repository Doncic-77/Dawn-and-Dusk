//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
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
        string s ;
        cin >> s ;
        deque<char> q ;
        for(auto u : s)  q.push_back(u) ;
        int now = 0 ;
        int flag = 1 ;
        while(!q.empty())
        {
            if(now == 0)
            {
                q.pop_front() ;
            }
            else
            {
                if(q.size() == 1)
                {
                    flag = 0 ;
                    break ;
                }
                char x = q.front() ;
                q.pop_front() ;
                char y = q.front() ;
                q.pop_front() ;
                if(x != y)
                {
                    flag = 0 ;
                    break ;
                }
            }
            now ^= 1 ;
        }
        if(flag == 1)  cout << "YES\n" ;
        else  cout << "NO\n" ;
    }

    return 0 ;
}