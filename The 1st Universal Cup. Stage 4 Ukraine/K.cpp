#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+50;

vector<int> G[N];
int tim, sta[N], sz[N], id[N], idx; 
int scc_idx, dfn[N], low[N], du[N];
bool in_sta[N];

void tarjan(int u){
	dfn[u] = low[u] = ++tim;
	sta[++idx] = u; in_sta[u] = true;
	for(int i = 0;i < G[u].size();i++){
		int v = G[u][i];
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(in_sta[v]){
			low[u] = min(low[u], low[v]);
		}
	}
	if(low[u] == dfn[u]){
		int y;
		scc_idx++;
		do{
			y = sta[idx--];
			in_sta[y] = false;
			id[y] = scc_idx;
			sz[scc_idx]++;
		}while(u != y);
	}
}

int main(){
    ios::sync_with_stdio(false);
    #ifdef _DEBUG
        freopen("data.txt", "r", stdin);
    #endif
    int T;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) G[i].clear(), dfn[i] = 0;
        for(int i=1;i<=m;i++) {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
        }
        scc_idx = 0;
        tarjan(1);
        int ans = 1;
        for(int i=1;i<=n;i++) {
            if(!dfn[i]) {
                ans = 0;
                break;
            }
        }
        if(scc_idx != 1) ans = 0;
        if(ans) 
            cout<<"YES\n";
        else 
            cout<<"NO\n";
        
    }
}
