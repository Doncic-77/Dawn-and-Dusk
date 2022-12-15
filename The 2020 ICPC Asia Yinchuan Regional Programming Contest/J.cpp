#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	
	int m ;
	cin >> m ;
	
	vector<array<int , 4>> a(m * m + 1) ;
	for(int i = 1 ; i <= m * m ; i ++)
		for(int j = 0 ; j < 4 ; j ++)
			cin >> a[i][j] ;
	
	vector<vector<int>> ans(m + 1 , vector<int>(m + 1 , 0)) ;
	int rt = 1 ;
	for(int i = 1 ; i <= m * m ; i ++)
	{
		if(a[i][0] == -1 && a[i][2] == -1)
		{
			rt = i ;
			break ;
		}
	}
//	vector<vector<int>> ans(m + 1 , vector<int>(m + 1 , 0)) ;
	queue<array<int , 3>> q ;
	q.push({rt , 1 , 1}) ;
	ans[1][1] = rt ;
	vector<array<int , 2>> d = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}} ;
	while(!q.empty())
	{
		auto u = q.front() ;
		int i = u[0] ;
		int x = u[1] ;
		int y = u[2] ;
		q.pop() ;
		for(int j = 0 ; j < 4 ; j ++)
		{
			if(a[i][j] == -1)  continue ;
			int nx = x + d[j][0] ;
			int ny = y + d[j][1] ;
			if(ans[nx][ny] != 0)  continue ;
			ans[nx][ny] = a[i][j] ;
			q.push({a[i][j] , nx , ny}) ;
		}
	}
	
	for(int i = 1 ; i <= m ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cout << ans[i][j] << " \n"[j == m] ;
	
	return 0;
}