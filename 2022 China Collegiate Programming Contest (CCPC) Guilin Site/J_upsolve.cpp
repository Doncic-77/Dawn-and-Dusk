//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
const int inf = 1e9 ;
const int maxn = 2e5 + 10 ;
priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> mn[maxn << 2] ;
int ls(int x)
{
   return x << 1 ;
}
int rs(int x)
{
   return x << 1 | 1 ;
}
//mn[l] = {r , id}
void build(int id , int l , int r)
{
    while(!mn[id].empty())  mn[id].pop() ;
    if(l == r)  return ;
    int mid = (l + r) >> 1 ;
    build(ls(id) , l , mid) ;
    build(rs(id) , mid + 1 , r) ;
}
int used[maxn] ;
void update(int id , int l , int r , int x , int y , int z)
{
   int mid = (l + r) / 2 ;
   mn[id].push({y , z}) ;
   if(l == r && l == x)  return ;
   if(x <= mid)  update(ls(id) , l , mid , x , y , z) ;
   else  update(rs(id) , mid + 1 , r , x , y , z) ;
}
pair<int , int> query(int id , int l , int r , int x , int y)
{
   pair<int , int> ans = {inf , inf} ;
   int mid = (l + r) / 2 ;
   if(y < x)  return {inf , inf} ; //不合法的询问
   if(x <= l && r <= y)
   {
    pair<int , int> t = {inf , inf} ;
    while(!mn[id].empty())
    {
        auto [r , pos] = mn[id].top() ;
        if(used[pos] == 1)  
        {
            mn[id].pop() ;
            continue ;
        }
        t = min(t , {r , pos}) ;
        break ;
    }
    return t ;
   }
   if(x <= mid)  ans = min(ans , query(ls(id) , l , mid , x , y)) ;
   if(y > mid)  ans = min(ans , query(rs(id) , mid + 1 , r , x , y)) ;
   return ans ;
}
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;


    int T ;
    cin >> T ;
    while(T --)
    {
        int n , m ;
        cin >> n >> m ;
        for(int i = 1 ; i <= n ; i ++)  used[i] = 0 ;
        vector<int> p(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  cin >> p[i] ;
        vector<pair<int , int>> v(m) ;
        vector<vector<int>> g(n + 1) ;
        vector<int> in(n + 1 , 0) ;
        vector<vector<int>> g2(n + 1) ;
        vector<int> in2(n + 1 , 0) ;
        for(auto &[a , b] : v)  
        {
            cin >> a >> b ;
            g[a].push_back(b) ;
            in[b] += 1 ;
            g2[b].push_back(a) ;
            in2[a] += 1 ;
        }
        //先反向拓扑一下确定min
        queue<int> q ;
        vector<int> mn(n + 1 , inf) ;
        vector<int> mx(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)
            if(p[i] != 0)
            {
                mn[i] = p[i] ;
                mx[i] = p[i] ;
            }
        for(int i = 1 ; i <= n ; i ++)
            if(in2[i] == 0)
            {
                q.push(i) ;
            }
        while(!q.empty())
        {
            int u = q.front() ;
            q.pop() ;
            for(auto v : g2[u])
            {
                in2[v] -= 1 ;
                mn[v] = min(mn[v] , mn[u]) ;
                if(in2[v] == 0)  q.push(v) ;
            }
        }
        //正向拓扑直接填数 这部分要线段树套优先队列
        build(1 , 1 , n) ;
        vector<int> vis(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  vis[p[i]] = 1 ;
        for(int i = 1 ; i <= n ; i ++)
            if(in[i] == 0)
            {
                update(1 , 1 , n , max(1 , p[i]) , mn[i] , i) ;
            }
        int now = 1 ;
        auto fix = [&]()
        {
            while(now <= n && vis[now] == 1)  now += 1 ;
        } ;
        fix() ;
        while(now <= n)
        {
            auto [w , u] = query(1 , 1 , n , 1 , now) ;
            if(u == inf)
            {
                cout << "-1\n" ;
                goto ff ;
            }
            used[u] = 1 ;
            if(p[u] == 0)
            {
                p[u] = now ;
                vis[now] = 1 ;
                fix() ;
            }
            for(auto v : g[u])
            {
                in[v] -= 1 ;
                mx[v] = max(mx[v] , p[u]) ;
                if(in[v] == 0)  update(1 , 1 , n , mx[v] , mn[v] , v) ;
            }
        }
        for(int i = 1 ; i <= n ; i ++)  assert(p[i] != 0) ;
        assert(accumulate(vis.begin() + 1 , vis.end() , 0) == n) ;
        for(auto &[a , b] : v)
            if(p[a] > p[b])
            {
                cout << "-1\n" ;
                goto ff ;
            }
        for(int i = 1 ; i <= n ; i ++)  cout << p[i] << " \n"[i == n] ;
        ff : ;
    }

    return 0 ;
}
/*
2
4 4
1 0 0 4
1 2
1 3
2 4
3 4
3 2
0 3 1
1 2
3 1

1
4 4
1 0 0 4
1 2
1 3
2 4
3 4

1
4 4
1 4 0 0
1 2
1 3
2 4
3 4
*/