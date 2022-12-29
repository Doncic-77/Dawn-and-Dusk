#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	
	int n , w , h , s ;
	cin >> n >> w >> h >> s ;
	
	
	vector<vector<int>> a(n , vector<int>(h)) ;
	vector<string> ans(n) ;
	vector<vector<string>> t(n , vector<string>(h)) ;
	
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> ans[i] ;
		
		for(int j = 0 ; j < h ; j ++)  cin >> t[i][j] ;
		for(int j = 0 ; j < h ; j ++)
			for(int k = 0 ; k < w ; k ++)
			{
				if(t[i][j][k] == '#')
				{
					if(k == 0 || t[i][j][k - 1] == '.')  a[i][j] += 1 ;
				}
			}
	}
	
	
	int mn = 1e9 ;
	int x = 0 , y = 0 ;
	
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < n ; j ++)
			for(int k = 0 ; k < h ; k ++)	
			{
				if(a[i][k] == 0 || a[j][k] == 0)  continue ;
				int l = 1 , r = s ;
				int res = r ;

				auto cal = [&](int x)
				{
					int z = (a[i][k] + a[j][k]) * 2 ;
					if(x & 1)
					{
						return (x / 2) * z + a[i][k] * 2 ;
					}
					else
					{
						return (x / 2 - 1) * z + a[i][k] * 2 + a[j][k] * 2 ;
					}
				};
				while(l <= r)
				{
					int mid = (l + r) / 2 ;
					if(cal(mid) >= s)  res = mid , r = mid - 1 ;
					else  l = mid + 1 ;
				}
				if(res < mn)
				{
					mn = res ;
					x = i ;
					y = j ;
				}
			}
	
	int flag = 0 ;
	while(mn --)
	{
		if(flag == 0)  cout << (char)ans[x][0] ;
		else  cout << (char)ans[y][0] ;
		flag ^= 1 ;
	}
	cout << '\n' ;
	
	return 0;
}