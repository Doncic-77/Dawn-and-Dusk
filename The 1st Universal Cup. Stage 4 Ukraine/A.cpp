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
        deque<int> q ;
        int n ;
        cin >> n ;
        vector<int> a(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
        sort(a.begin() + 1 , a.end()) ;
        reverse(a.begin() + 1 , a.end()) ;
        q.push_back(a[1]) ;
        int f = 0 ;
        for(int i = 2 ; i <= n ; i ++)
        {
            if(f == 0)  q.push_front(a[i]) ;
            else  q.push_back(a[i]) ;
            f ^= 1 ;
        }
        long long res = 0 ;
        for(int i = 0 ; i < n ; i ++)  res += 1ll * q[i] * q[(i + 1) % n] ;
        cout << res << '\n' ;
    }


    return 0 ;
}