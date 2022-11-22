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
    int m = 1e6 ;
    vector<int> cnt(m + 1 , 0) ;
    while(T --)
    {
        int n , k ;
        cin >> n >> k ;
        vector<int> a(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  cin >> a[i] , cnt[a[i]] = 1 ;
        int now = 0 ;
        vector<int> odd , even ;
        for(int i = 0 ; i <= m ; i ++)
        {
            if(odd.size() >= k && even.size() >= k)  break ;
            if(cnt[i] == 1)  continue ;
            if(i & 1)  odd.push_back(i) ;
            else  even.push_back(i) ;
        }
        for(int i = 0 ; i < k ; i ++)  cnt[odd[i]] = 1 , cnt[even[i]] = 1 ;
        for(int i = 0 ; i <= m ; i ++)
            if(cnt[i] == 0)
            {
                if(i & 1)  cout << "Bob\n" ;
                else  cout << "Alice\n" ;
                break ;
            }

        for(int i = 1 ; i <= n ; i ++)  cnt[a[i]] = 0 ;
        for(auto u : odd)  cnt[u] = 0 ;
        for(auto u : even)  cnt[u] = 0 ;
    }

    return 0 ;
}