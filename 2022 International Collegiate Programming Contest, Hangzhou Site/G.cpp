#include "bits/stdc++.h"
using namespace  std;
const int MAXN = 1e5+5;
const int MAXM = 1e7;
const long long MOD1 = 1e9+7;
const long long MOD2 = 1e9+9;
const long long MOD3 = 997137961 ;
const long long MOD4 = 1003911991 ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int>g[MAXN];
bool vis[MAXN];
bool flag;
bool isprime[MAXM];
int prime[MAXM];
int siz[MAXN];
array<long long , 4> val[MAXN];
void init() {
    memset(isprime, true, sizeof isprime);
    isprime[1]=false;
    for(int i=2;i<MAXM;i++) {
        if(isprime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&1ll*i*prime[j]<MAXM;j++) {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
    for(int i = 1 ; i <= prime[0] ; i ++)  prime[i] = rng() % 1000000007 + 1 ;
//    cout << prime[0] << '\n' ; 
}
void dfs(int now, int fa) {
    siz[now] = 1;
    array<long long , 4> ret={1,1,1,1};

    for(auto x:g[now])if(x!=fa&&!vis[x]) {
        dfs(x, now);
        siz[now]+=siz[x];
        for(int i = 0 ; i < 4 ; i ++)
        {
            ret[i] += prime[siz[x]] * val[x][i] ;
        }
        ret[0] %= MOD1 ;
        ret[1] %= MOD2 ;
        ret[2] %= MOD3 ;
        ret[3] %= MOD4 ;
    }
    val[now] = ret;
}
void solve() {
    int n;
    cin>>n;
    int m;
    cin>>m;
    flag=true;
    vector<int>du(n+1);
    for(int i=1;i<=n;i++)vis[i]=false, g[i].clear(), siz[i] = 0;
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        g[a].push_back( b );
        g[b].push_back( a );
        du[a]++;
        du[b]++;
    }
    if(m==n-1) {
        cout<<"YES\n";
        return;
    }
    if(m>n) {
        cout<<"NO\n";
        return;
    }
    queue<int>q;
    for(int i=1;i<=n;i++) {
        if(du[i]==1) q.push(i);
    }
    vector<bool>inq(n+1);
    while(q.size()) {
        auto now=q.front();
        inq[now]=true;
        q.pop();
        for(auto x:g[now]) {
            du[x]--;
            if(du[x] == 1) {
                q.push(x);
            }
        }
    }    
    for(int i=1;i<=n;i++)if(!inq[i])vis[i]=true;
    for(int i=1;i<=n&&flag;i++)if(vis[i]) {
        dfs(i,0);
    }
    vector<int>all;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            vector<bool>vv(n+1);
            function<void(int,int)>dfs1=[&](int now,int fa) {
                vv[now]=true;
                all.push_back(now);
                for(auto x:g[now])
                    if(x!=fa&&vis[x]&&!vv[x])dfs1(x,now);
            };
            dfs1(i,0);
            break;
        }
    }
    if(all.size()%2==0) {
        for(int i=2;i<all.size()&&flag;i++) {
            if(val[all[i]]!=val[all[i-2]]||siz[all[i]]!=siz[all[i-2]])flag=false;
        }
    } else {
        for(int i=1;i<all.size()&&flag;i++) {
            if(val[all[i]]!=val[all[i-1]]||siz[all[i]]!=siz[all[i-1]])flag=false;
        }
    }
    if(flag)cout<<"YES\n";
    else cout<<"NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

