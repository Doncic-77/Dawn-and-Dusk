#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    #ifdef _DEBUG
        freopen("data.txt", "r", stdin);
    #endif
    int n , m ;
    cin >> n >> m ;
    n <<= 1;
    vector<vector<int>> g(n + 1) ;
    vector<int> deg(n + 1 , 0) ;
    for(int i = 0 ; i < m ; i ++)
    {
        int u , v ;
        cin >> u >> v ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
        deg[u] += 1 ;
        deg[v] += 1 ;
    }
    vector<vector<int>> G(n + 1) ;
    for(int i = 1 ; i <= n ; i ++)
    for(auto v : g[i])
    {
        if(deg[i] > deg[v] || (deg[i] == deg[v] && i > v))
        G[i].push_back(v) ;
    }
    auto four_ring = [&]()
    {
        int res = 0 ;
        vector<int> cnt(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)
        {
            for(auto v : g[i])
            for(auto w : G[v])
            if(deg[w] < deg[i] || (deg[w] == deg[i] && w < i))
            res += cnt[w] , cnt[w] += 1 ;
            for(auto v : g[i])
            for(auto w : G[v])
            if(deg[w] < deg[i] || (deg[w] == deg[i] && w < i))
            cnt[w] = 0 ;
        }
        return res ;
    };
    if(four_ring()) cout<<"2\n";
    else cout<<"3\n";
}