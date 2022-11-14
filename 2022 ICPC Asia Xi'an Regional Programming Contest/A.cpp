//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
const int magic = 350 ;
const int maxn = 3e6 + 10 ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m , q ;
    cin >> n >> m >> q ;
    vector<int> f(maxn , -1) ; //走350步到达哪里。 -1表示1步都不能走了
    vector<int> lst(maxn , -1) ;
    vector<int> nxt(maxn , -1) ;
    int cur = 0 ;
    vector<array<int , 3>> p(maxn) ;
    map<array<int , 3> , int> id ;
    vector<set<int>> v(n + 10) ; //存向右的向量
    //-1 
    //1
    vector<set<pair<int , int>>> dir(n + 10) ;
    auto add = [&](int x , int y , int d)
    {
        if(id.count({x , y , d}))  return ;
        cur += 1 ;
        p[cur] = {x , y , d} ;
        id[{x , y , d}] = cur ;
        v[x].insert(y) ;
        if(d == 0)
        {
            auto it = dir[x].lower_bound({y + 1 , -1}) ;
            if(it != dir[x].end())
            {
                int pos = id[{x , (it -> first) , (it -> second)}] ;
                nxt[cur] = pos ;
                lst[pos] = cur ;
            }
        }
    } ;
    for(int i = 1 ; i <= n ; i ++)  add(i , 1 , 0) ;
    while(q --)
    {
        int op ;
        cin >> op ;
        if(op == 1)
        {
            int a , b ;
            cin >> a >> b ;
            dir[a].insert({b , 1}) ;
            dir[a + 1].insert({b , -1}) ;
            add(a , b , 1) ;
            add(a + 1 , b , -1) ;
            add(a , b , 0) ;
            add(a + 1 , b , 0) ;
            auto add_pre = [&](int x , int y , int d)
            {
                auto it = v[x].lower_bound(y) ;
                if(it == v[x].begin())  return ;
                it -- ;
                int pos = id[{x , (*it) , 0}] ;
                int pos0 = id[{x , y , d}] ;
                nxt[pos] = pos0 ;
                lst[pos0] = pos ;
            } ;
            auto add_nxt = [&](int x , int y , int d)
            {
                auto it = v[x + d].lower_bound(y) ;
                assert(it != v[x + d].end()) ;
                assert((*it) == y) ;
                int pos = id[{x + d , (*it) , 0}] ;
                int pos0 = id[{x , y , d}] ;
                nxt[pos0] = pos ;
                lst[pos] = pos0 ;
            } ;
            // (a , b , 1) 的 前驱 和 后继
            add_pre(a , b , 1) ;
            add_nxt(a , b , 1) ;
            // (a + 1 , b , -1) 的前驱 和 后继
            add_pre(a + 1 , b , -1) ;
            add_nxt(a + 1 , b , -1) ;
            
            auto go = [&](int tt)
            {
                // 不能多走 必须严格根号
                vector<int> pp ;
                int now = tt ;
                pp.push_back(now) ;
                for(int i = 1 ; i <= magic ; i ++)
                {
                    if(lst[now] == -1)  break ;
                    now = lst[now] ;
                    pp.push_back(now) ;
                }
                reverse(pp.begin() , pp.end()) ;
                now = tt ;
                for(int i = 1 ; i <= magic ; i ++)
                {
                    if(nxt[now] == -1)  break ;
                    now = nxt[now] ;
                    pp.push_back(now) ;
                }
                int t = pp.size() ;
                for(int i = 0 ; i < t - 1 ; i ++)
                {
                    if(i + magic < t)  f[pp[i]] = pp[i + magic] ;
                    else  f[pp[i]] = pp.back() ;
                }
            } ;
            go(id[{a , b , 1}]) ;
            go(id[{a + 1 , b , -1}]) ;
        }
        else
        {
            int a ;
            cin >> a ;
            int pos = id[{a , 1 , 0}] ;
            if(id.count({a , 1 , -1}))  pos = id[{a , 1 , -1}] ;
            if(id.count({a , 1 , 1}))  pos = id[{a , 1 , 1}] ;
            while(true)
            {
                if(f[pos] == -1)  break ;
                pos = f[pos] ;
            }
            cout << p[pos][0] << '\n' ;
            // pos = id[{a , 1 , 0}] ;
            // while(true)
            // {
            //     if(nxt[pos] == -1)  break ;
            //     pos = nxt[pos] ;
            //     cout << p[pos][0] << ' ' << p[pos][1] << ' ' << p[pos][2] << ' ' << nxt[pos] << '\n' ;
            // }
        }
    }

    return 0 ;
}
/*
3 5 3
1 2 4
1 2 1
2 2

3 4 2
1 2 4
2 3
*/