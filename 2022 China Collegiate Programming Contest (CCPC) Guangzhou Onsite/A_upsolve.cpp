//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
const long long inf = 1e18 ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int T ;
    cin >> T ;
    while(T --)
    {
        int n ;
        cin >> n ;
        vector<int> a(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
        vector<int> t(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  cin >> t[i] ;
        vector<vector<int>> g(n + 1) ;
        for(int i = 1 ; i <= n - 1 ; i ++)
        {
            int u , v ;
            cin >> u >> v ;
            g[u].push_back(v) ;
            g[v].push_back(u) ;
        }
        if(n == 1)
        {
            cout << "0\n" ;
            continue ;
        }
        // dp0[i][j] 表示i子树探测j个叶子即可探测全部叶子的最小值
        // dp1[i][j] 表示i子树探测j个叶子即可探测（全部叶子 - 1个叶子）的最小值 
        // 容易知道如果只剩余一个叶子没有被检测也是可以知道答案的
        vector<vector<long long>> dp0(n + 1 , vector<long long>(n + 1 , inf)) ;
        vector<vector<long long>> dp1(n + 1 , vector<long long>(n + 1 , inf)) ;
        vector<int> siz(n + 1 , 0) ; //子树的叶子个数
        function<void(int , int)> dfs = [&](int fa , int u)
        {
            if(u != 1 && g[u].size() == 1) //leaf
            {
                dp0[u][0] = a[u] ;
                dp0[u][1] = 0 ;
                dp1[u][0] = 0 ;
                siz[u] = 1 ;
                return ;
            }
            
            //cal dp0 dp1
            dp0[u][0] = 0 ;
            dp1[u][0] = 0 ;
            vector<long long> tf(n + 1 , inf) ;
            vector<long long> th(n + 1 , inf) ;
            tf[0] = 0 ;
            th[0] = 0 ;
            for(auto v : g[u])
            {
                if(v == fa)  continue ;
                dfs(u , v) ;
                vector<long long> f(n + 1 , inf) ;
                vector<long long> h(n + 1 , inf) ;
                vector<long long> one(n + 1 , inf) ;
                for(int i = 0 ; i <= siz[u] ; i ++)
                    for(int j = 0 ; j <= siz[v] ; j ++)
                    {
                        f[i + j] = min(f[i + j] , tf[i] + dp0[v][j]) ;
                        //看一下监视器
                        h[i + j] = min(h[i + j] , th[i] + min(dp0[v][j] , dp1[v][j])) ;
                        one[i + j] = min(one[i + j] , tf[i] + dp1[v][j]) ;
                        one[i + j] = min(one[i + j] , dp1[u][i] + dp0[v][j]) ;
                    }
                siz[u] += siz[v] ;
                dp1[u] = one ;
                tf = f ;
                th = h ;
            }
            for(int i = 0 ; i <= n ; i ++)  dp0[u][i] = min(tf[i] , a[u] + th[i]) ;
        } ;
        dfs(1 , 1) ;
        long long res = inf ;
        for(int i = 0 ; i <= n ; i ++)  res = min(res , t[i] + min(dp0[1][i] , dp1[1][i])) ;
        cout << res << '\n' ;
    }

    return 0 ;
}