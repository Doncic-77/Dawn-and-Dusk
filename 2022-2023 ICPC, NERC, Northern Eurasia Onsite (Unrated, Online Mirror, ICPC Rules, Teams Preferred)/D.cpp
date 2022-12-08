//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
struct Hungary
{
	int nL ; //左边的点数
	int nR ; //右边的点数
	vector<int> used ; //右边的点是否用过
	vector<int> match ; //右边的点的匹配点
	queue <int> q ; //玄学优化  
	vector<vector<int>> g ; //左边连右边的单向边
    vector<vector<int>> rg ;
    vector<vector<int>> ban ;
    vector<int> rmatch ;
    vector<int> p ;
	void init(int num1 , int num2)
	{
		nL = num1 ;
		nR = num2 ;
		while(!q.empty())  q.pop() ;
		match.resize(0) ;
		match.resize(nR + 1 , -1) ;
        rmatch.resize(0) ;
		rmatch.resize(nL + 1 , -1) ;
		used.resize(0) ;
		used.resize(nR + 1 , 0) ;
		g.resize(0) ;
		g.resize(nL + 1) ;
        rg.resize(0) ;
		rg.resize(nR + 1) ;
        ban.resize(0) ;
        ban.resize(2) ;
        ban[0].resize(num1 , 0) ;
        ban[1].resize(num2 , 0) ;
        p.resize(0) ;
	}
	void clear_used()
	{
		while(!q.empty())
		{
			int x = q.front() ;
			q.pop() ;
			used[x] = 0 ; 
		}
	}
    void add(int u , int v)
    {
        g[u].push_back(v) ;
        rg[v].push_back(u) ;
    }
	bool dfs(int u)  
	{  
        if(ban[0][u])  return false ;
		for(auto v : g[u])  
		{  
            if(ban[1][v])  continue ;
			if(!used[v])  
			{  
				used[v] = 1 , q.push(v) ;
				if(match[v] == -1 || dfs(match[v])) 
				{  
					match[v] = u ;
                    rmatch[u] = v ;
					return true ; 
				}  
			}  
		}  
		return false ;  
	}  
    int cal0()
	{
		int ans = 0 ;  
		for(int i = 0 ; i < nL ; i ++)  
		{  
			//used.resize(0) ;
			//used.resize(n + 1 , 0) ;
			clear_used() ;
			if(dfs(i))  ans ++ ;
            else  p.push_back(i) ;
		}  
		return ans ;
	}
	int cal(int x)
	{
        queue<int> q ;
        q.push(x) ;
        vector<int> vis(nL + nR , 0) ;
        vis[x] = 1 ;
        int ans = 0 ;
        while(!q.empty())
        {
            int u = q.front() ;
            q.pop() ;
            if(u >= nL)  ans += 1 ;
            if(u < nL)
            {
                for(auto v : g[u])
                {
                    if(v != rmatch[u])  continue ;
                    v += nL ;
                    if(vis[v] == 0)
                    {
                        q.push(v) , vis[v] = 1 ;
                    }
                }
            }
            else
            {
                for(auto v : rg[u - nL])
                { 
                    if(vis[v] == 0)
                    {
                        q.push(v) , vis[v] = 1 ;
                    }
                }
            }
        }
        return ans ;
	}
} hungary ;
mt19937  rnd(chrono::high_resolution_clock::now().time_since_epoch().count()) ;
long long rand_l_r(long long l , long long r)
{
	uniform_int_distribution<long long> dist(l , r) ;
	return dist(rnd) ;
}
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m ;
    // n = 1000 , m = 1000 ;
    cin >> n >> m ;
    vector<string> s(n) ;
    // for(int i = 0 ; i < n ; i ++)
    // {
    //     s[i] = "" ;
    //     for(int j = 0 ; j < m ; j ++)
    //         if(rand_l_r(0 , 100) == 0)
    //             s[i] += '.' ;
    //         else  s[i] += '#' ;
    // }
    for(int i = 0 ; i < n ; i ++)  cin >> s[i] ;
    vector<vector<int>> v(2) ;
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
            if(s[i][j] == '.')
            {
                v[(i + j) % 2].push_back(i * m + j) ;
            }
    long long t1 = v[0].size() ;
    long long t2 = v[0].size() ;
    if(1ll * t1 * (t1 - 1) / 2 + 1ll * t2 * (t2 - 1) / 2 >= 1000000)
    {
        cout << 1000000 << '\n' ;
        return 0 ;
    }
    hungary.init(v[0].size() , v[1].size()) ;
    for(int i = 0 ; i < v[0].size() ; i ++)
        for(int j = 0 ; j < v[1].size() ; j ++)
        {
            int x = v[0][i] ;
            int y = v[1][j] ;
            int tx1 = x / m ;
            int ty1 = x % m ;
            int tx2 = y / m ;
            int ty2 = y % m ;
            if(abs(tx1 - tx2) + abs(ty1 - ty2) != 1)  continue ;
            hungary.add(i , j) ;
        }
    int t = hungary.cal0() ;
    int res = 1ll * t1 * (t1 - 1) / 2 + 1ll * t2 * (t2 - 1) / 2 ;
    for(int i = 0 ; i < v[0].size() ; i ++)
    {
        res += v[1].size() - hungary.cal(i) ;
        if(res == 1000000)  goto ff ;
    }
    ff : ;
    cout << min(res , 1000000) << '\n' ;

    return 0 ;
}