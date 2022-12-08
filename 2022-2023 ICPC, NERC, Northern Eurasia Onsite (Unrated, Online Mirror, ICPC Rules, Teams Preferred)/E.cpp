#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	vector<vector<int>> a(n) ;
	vector<int> b ;
	for(int i = 0 ; i < n ; i ++)
	{
		int m ;
		cin >> m ;
		while(m --)
		{
			int x ;
			cin >> x ;
			a[i].push_back(x) ;
			b.push_back(x) ;
		}
	}
	sort(b.begin() , b.end()) ;
	map<int , int> nxt ;
	int lst = -1 ;
	for(auto u : b)
	{
		if(lst == -1)  lst = u ;
		else
		{
			nxt[lst] = u ;
			lst = u ;
		}
	}
	int res1 = 0 , res2 = 0 ;
	for(int i = 0 ; i < n ; i ++)
	{
		int m = a[i].size() ;
		for(int j = 0 ; j < m ; j ++)
		{
			int k = j ;
			while(k + 1 < m && nxt[a[i][k]] == a[i][k + 1])  k += 1 ;
			if(k != m - 1)  res1 += 1 ;
			j = k ;
		}
	}
	res2 = n + res1 - 1 ;
	cout << res1 << ' ' << res2 << '\n' ;
	
	return 0;
}

