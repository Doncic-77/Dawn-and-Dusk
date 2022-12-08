//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
mt19937  rnd(chrono::high_resolution_clock::now().time_since_epoch().count()) ;
long long rand_l_r(long long l , long long r)
{
	uniform_int_distribution<long long> dist(l , r) ;
	return dist(rnd) ;
}
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    auto walk = [&](int x)
    {
        cout << "walk " << x << endl ;
        int y ;
        cin >> y ;
        return y ;
    } ;
    auto guess = [&](int x)
    {
        cout << "guess " << x << endl ;
        exit(0) ;
    } ;
    int m = 1 ;
    for(int i = 1 ; i <= 3333 ; i ++)  m = max(m , walk(rand_l_r(1 , 1000000000))) ;
    vector<int> v ;
    map<int , int> mp ;
    for(int i = 1 ; i <= 3333 ; i ++)  v.push_back(walk(1)) , mp[v.back()] = i - 1 ;
    int t = walk(m) ;
    if(mp.count(t))
    {
        guess(m + 3332 - mp[t]) ;
    }
    for(int i = 1 ; i <= 3333 ; i ++)
    {
        int t = walk(3333) ;
        m += 3333 ;
        if(mp.count(t))
        {
            guess(m + 3332 - mp[t]) ;
        }
    }

    return 0 ;
}