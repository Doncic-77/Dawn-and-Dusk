//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int cnt = -1 ;
    int n , k ;
    cin >> n >> k ;
    vector<int> a(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
    for(int i = 1 ; i <= n ; i ++)
        if(a[i] < k)
        {
            cnt = i ;
            break ;
        }
    if(cnt == -1)
    {
        while(2 * a[n] - a[n - 1] < a[n])
        {
            a.push_back(max(0 , 2 * a[n] - a[n - 1])) ;
            n += 1 ;
            if(a[n] < k)
            {
                cnt = n ;
                break ;
            }
        }
    }

    if(cnt != -1)  cout << "Python 3." << cnt << " will be faster than C++\n" ;
    else  cout << "Python will never be faster than C++\n" ;

    return 0 ;
}