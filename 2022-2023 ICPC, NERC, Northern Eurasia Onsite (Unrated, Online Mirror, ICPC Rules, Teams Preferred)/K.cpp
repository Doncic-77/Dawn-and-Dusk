#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	int n , k ;
	cin >> n >> k ;
	if(n == 1)
	{
		cout << "YES\n" ;
		cout << "0\n" ;
		return 0 ;
	}
	if(n == 2)
	{
		if(k == 2)
		{
			cout << "NO\n" ;
			return 0 ;
		}
		else
		{
			cout << "YES\n" ;
			cout << 1 << '\n' ;
			cout << 1 << ' ' << 2 << '\n' ;
			return 0 ;
		}
	}
	if(k == 1)
	{
		cout << "YES\n" ;
		cout << n << '\n' ;
		for(int i = 1 ; i <= n ; i ++)
		{
			if(i < n)  cout << i << ' ' << i + 1 << '\n' ;
			else  cout << n << ' ' << 1 << '\n' ;
		}
		return 0 ;
	}
	if(k == 2)
	{
		cout << "YES\n" ;
		cout << n - 1 << '\n' ;
		for(int i = 1 ; i <= n - 1 ; i ++)  cout << n << ' ' << i << '\n' ;
		return 0 ;
	}
	if(n == k)
	{
		cout << "NO\n" ;
		return 0 ;
	}
	vector<pair<int , int>> res ;
	auto add = [&](int i , int j)
	{
		res.push_back({i , j}) ;
	} ;
	for(int i = 1 ; i <= n - 1 ; i ++)
	{
		add(n , i) ;
	}
	k -= 2 ;
	auto solve = [&]()
	{
		function<void(int , int)> dfs = [&](int l , int r)
		{
			assert(k >= 0) ;
			if(k <= 0)  return ;
			if(k == 1)
			{
				assert(l < r) ;
				k -= 1 ;
				add(l , l + 1) ;
				return ;
			}
			for(int i = l + 1 ; i <= r ; i ++)
			{
				add(l , i) ;	
			}
			k -= 2 ;
			dfs(l + 1 , r - 1) ;
		} ;
		dfs(2 , n - 1) ;	
	} ;
	solve() ;
	assert(k == 0) ;
	cout << "YES\n" ;
	cout << res.size() << '\n' ;
	for(auto u : res)  cout << u.first << ' ' << u.second << '\n' ;
	return 0;
}
