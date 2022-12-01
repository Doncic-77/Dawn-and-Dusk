//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
const int inf = 1e9 ;
struct Hungary
{
    int nL ;
    int nR ;
    vector<int> used ;
    vector<int> match ;
    queue<int> q ;
    vector<vector<int>> g ;
    vector<int> tt ;
    void init(int num1 , int num2)
    {
        nL = num1 ;
        nR = num2 ;
        while(!q.empty())  q.pop() ;
        match.resize(0) ;
        match.resize(nR + 1 , -1) ;
        used.resize(0) ;
        used.resize(nR + 1 , 0) ;
        g.resize(0) ;
        g.resize(nL + 1) ;
        tt.resize(0) ;
        tt.resize(nL + 1 , -1) ;
    } // no common
    void clear_used()
    {
        while(!q.empty())
        {
            int x = q.front() ;
            q.pop() ;
            used[x] = 0 ;
        }
    }
    bool dfs(int u)
    {
        for(auto v : g[u])
        {
            if(!used[v])
            {
                used[v] = 1 ;
                q.push(v) ;
                if(match[v] == -1 || dfs(match[v]))
                {
                    match[v] = u ;
                    return true ;
                }
            }
        }
        return false ;
    }
    void add(int u , int v)
    {
        g[u].push_back(v) ;
    }
    void cal()
    {
        for(int i = 0 ; i < nL ; i ++)
        {
            clear_used() ;
            dfs(i) ;
        }
        for(int i = 0 ; i < nR ; i ++)
            if(match[i] != -1)
                tt[match[i]] = i ;
    }
} hungary ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m ;
    cin >> n >> m ;
    vector<string> s0(n) ;
    for(int i = 0 ; i < n ; i ++)  cin >> s0[i] ;
    vector<string> s(m) ;
    for(int i = 0 ; i < m ; i ++)
    {
        s[i] = "" ;
        for(int j = 0 ; j < n ; j ++)  s[i] += s0[j][i] ;
    }
    vector<vector<int>> t(n + 1) ;
    for(int i = 0 ; i < m ; i ++)  t[count(s[i].begin() , s[i].end() , '1')].push_back(i) ;
    vector<int> B(m , 0) ;
    vector<int> id_group(m , 0) ;
    vector<int> doc(m , 0) ;
    for(int i = 0 ; i < m ; i ++)  doc[i] = count(s[i].begin() , s[i].end() , '0') + 2 ;
    int kk = 0 ;
    vector<vector<int>> c(n , vector<int>(m + m + 1 , 1)) ;
    hungary.init(m , m) ;
    map<pair<int , int> , int> mp ;
    for(int i = 0 ; i < m ; i ++)
        for(int j = 0 ; j < m ; j ++)
        {
            if(i == j)  continue ;
            int flag = 1 ;
            for(int k = 0 ; k < n ; k ++)
                if(s[i][k] == '0' && s[j][k] == '1')
                    flag = 0 ;
            if(flag == 1)
            {
                if(mp.count({j , i}))  continue ;
                hungary.add(i , j) ;
                mp[{i , j}] = 1 ;
            }
        }
    hungary.cal() ;
    function<void(int)> dfs = [&](int u)
    {
        id_group[u] = kk ;
        if(hungary.tt[u] == -1)
        {
            for(int i = 0 ; i < n ; i ++)
                if(s[u][i] == '1')
                    c[i][kk] = inf ;
            return ;
        }
        int nxt = hungary.tt[u] ;
        for(int i = 0 ; i < n ; i ++)
            if(s[u][i] == '1' && s[nxt][i] == '0')
                c[i][kk] = doc[u] ;
        dfs(nxt) ;
    } ;
    for(int i = 0 ; i < m ; i ++)
        if(hungary.match[i] == -1)
        {
            kk += 1 ;
            dfs(i) ;
        }

    cout << kk << '\n' ;
    for(int i = 0 ; i < m ; i ++)  cout << id_group[i] << " \n"[i == m - 1] ;
    for(int i = 0 ; i < m ; i ++)  cout << doc[i] << " \n"[i == m - 1] ;
    for(int i = 0 ; i < n ; i ++)
        for(int j = 1 ; j <= kk ; j ++)
            cout << c[i][j] << " \n"[j == kk] ;

    return 0 ;
}