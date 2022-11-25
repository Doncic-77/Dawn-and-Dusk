#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
struct machine {
	int lim;
	ll cst;
	multiset<int> s[2], l[2]; 
	inline void set_size(int siz) {
		lim=(siz-1)/2;
		cst=0;
		s[0].clear(); l[0].clear();
		s[1].clear(); l[1].clear();
	}
	inline void insert(int id, int val) {
		l[id].insert(val);
		if(l[id].size()>lim) {
			s[id].insert(*l[id].begin());
			cst+=*l[id].begin();
			l[id].erase(l[id].begin());
		}
	}
	inline void erase(int id, int val) {
		auto now=l[id].find(val);
		if(now!=l[id].end()) {
			l[id].erase(now);
			if(s[id].empty()) return ;
			now=s[id].end();
			--now;
			l[id].insert(*now);
			cst-=*now;
			s[id].erase(now);
		}
		else {
			now=s[id].find(val);
			cst-=*now;
			s[id].erase(now);
		}
	}
}mch[MAXN];
int n, m, q, a[MAXN], b[MAXN], out_id[MAXN], vote_id[MAXN];
vector<int> v;
inline void work() {
	ll res=0;
	for(int i=1; i<=m; ++i) res+=mch[i].cst;
	
	for(int t=1; t<=q; ++t) {
		int x, y, z;
		cin>>x>>y>>z;
		if(x==n) {
			a[x]=y;
			b[x]=z;
			cout<<res<<"\n";
			continue;
		}
		machine &now=mch[vote_id[x]];
		res-=now.cst;
		now.erase(a[x], b[x]);
		a[x]=y;
		b[x]=z;
		now.insert(a[x], b[x]);
		res+=now.cst;
		
		cout<<res<<"\n";
	}
}
inline void init() {
	cin>>n>>m>>q;
	for(int i=1; i<=n; ++i) cin>>a[i]>>b[i];
	for(int i=1; i<=m; ++i) {
		int l;
		cin>>l;
		v.resize(l);
		for(int j=0; j<l; ++j) {
			cin>>v[j];
			if(v[j]<0)
				v[j]=out_id[-v[j]];
		}
		sort(v.begin(), v.end());
		
		mch[i].set_size(l);
		
		out_id[i]=v.back(); v.pop_back();
		for(auto id : v) {
			vote_id[id]=i;
			mch[i].insert(a[id], b[id]);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	init();
	work();
	cout.flush();
	return 0;
}