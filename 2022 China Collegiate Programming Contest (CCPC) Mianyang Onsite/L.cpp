//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m , q ;
    cin >> n >> m >> q ;
    vector<int> a(n + 1 , 0) ;
    vector<int> b(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> a[i] >> b[i] ;
    long long res = 0 ;
    vector<int> lim(m + 1 , 0) ;
    vector<vector<multiset<int>>> less_k(m + 1 , vector<multiset<int>>(2)) ;
    vector<vector<multiset<int>>> geq_k(m + 1 , vector<multiset<int>>(2)) ; 
    auto add = [&](int t , int id , int val)
    {
        less_k[t][id].insert(val) ;
        if(less_k[t][id].size() > lim[t])
        {
            geq_k[t][id].insert(*less_k[t][id].begin()) ;
            res += *less_k[t][id].begin() ;
            less_k[t][id].erase(less_k[t][id].begin()) ;
        }
    } ;
    auto del = [&](int t , int id , int val)
    {
        auto it = less_k[t][id].find(val) ;
        if(it == less_k[t][id].end())
        {
            auto it2 = geq_k[t][id].find(val) ;
            geq_k[t][id].erase(it2) ;
            res -= val ;
        }
        else
        {
            less_k[t][id].erase(it) ;
            if(!geq_k[t][id].empty())
            {
                auto it = geq_k[t][id].end() ;
                it -- ;
                res -= (*it) ;
                less_k[t][id].insert(*it) ;
                geq_k[t][id].erase(it) ;
            }
        }
    } ;
    vector<int> pos(n + 1 , 0) ;
    vector<int> out(n + 1 , 0) ;
    for(int i = 1 ; i <= m ; i ++)
    {
        vector<int> v ;
        int l ;
        cin >> l ;
        lim[i] = l / 2 ;
        while(l --)
        {
            int x ;
            cin >> x ;
            if(x > 0)  v.push_back(x) ;
            else  v.push_back(out[-x]) ;
        }
        sort(v.begin() , v.end()) ;
        out[i] = v.back() ;
        v.pop_back() ;
        for(auto u : v)
        {
            pos[u] = i ;
            add(i , a[u] , b[u]) ;
        }
    }
    while(q --)
    {
        int x , y , z ;
        cin >> x >> y >> z ;
        if(x == n)
        {
            cout << res << '\n' ;
            continue ;
        }
        del(pos[x] , a[x] , b[x]) ;
        a[x] = y ;
        b[x] = z ;
        add(pos[x] , a[x] , b[x]) ;
        cout << res << '\n' ;
    }

    return 0 ;
}