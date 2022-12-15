#include<bits/stdc++.h>
using namespace std;

const int maxn = 3e6 + 10 ;
int n ;
struct Trie
{
	int nxt[maxn][28] ;
	int num[maxn] ;
	int ans[maxn] ;
	int cnt = 0 ;
	void solve()
	{
		cin >> n ;
		vector<string> s(n) ;
		for(int i = 0 ; i < n ; i ++)  cin >> s[i] ;
		for(int i = 0 ; i < n ; i ++)
		{
			int now = 0 ;
			for(auto u : s[i])
			{
				int c = 0 ;
				if(u >= 'a' && u <= 'z')  c = u - 'a' ;
				else if(u == '.')  c = 26 ;
				else  c = 27 ;
				if(nxt[now][c] == 0)  nxt[now][c] = ++ cnt ;
				now = nxt[now][c] ;
				num[now] += 1 ;
			}
		}
		int res = 0 ;
		for(int i = 0 ; i < n ; i ++)
		{
			int now = 0 ;
			for(auto u : s[i])
			{
				int c = 0 ;
				if(u >= 'a' && u <= 'z')  c = u - 'a' ;
				else if(u == '.')  c = 26 ;
				else  c = 27 ;
				if(nxt[now][c] == 0)  nxt[now][c] = ++ cnt ;
				now = nxt[now][c] ;
				num[now] -= 1 ;
			}
			now = 0 ;
			vector<int> pre ;
			for(auto u : s[i])
			{
				int c = 0 ;
				if(u >= 'a' && u <= 'z')  c = u - 'a' ;
				else if(u == '.')  c = 26 ;
				else  c = 27 ;
				now = nxt[now][c] ;
				if(num[now] == 0)
				{
//					cout << "fk1 " << res << ' ' << now << ' ' << ans[now] << ' ' << c << '\n' ;
					res -= ans[now] ;
					for(auto u : pre)  ans[u] -= ans[now] , ans[u] += 1 ;
					ans[now] = 0 ;
//					cout << "fk2 " << res << '\n' ;
					res += 1 ;
//					cout << "fk3 " << res << '\n' ;
					ans[now] = 1 ;
					for(int j = 0 ; j < 28 ; j ++)  nxt[now][j] = 0 ;
					break ;
				}	
				pre.push_back(now) ;
			}
			cout << res << '\n' ;
		}
	}

} trie ;


int main(){
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	
	trie.solve() ;
	
	return 0;
}