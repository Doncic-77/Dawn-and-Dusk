#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	vector<int> a0(n , 0) ;
	vector<int> a(n , 0) ;
	for(int i = 0 ; i < n ; i ++)
	{
		int x ;
		cin >> x ;
		a0[i] = x ;
		cin >> a[i] ;
	}
	vector<int> vis(360 , 0) ;
	auto move = [&](int l , int r)
	{
		if(abs(l - r) == 180)
		{
			cout << "yes\n" ;
			exit(0) ;
		}
		if(l == r)  return ;
		int d = 1 ;
		if(l > r && l - r < 180)  d = -1 ;
		if(l < r && l - (-180) + (180 - r) < 180)  d = -1 ;
		while(l != r)
		{
			if(d == 1)  vis[l + 180] = 1 ;
			else
			{
				int l0 = l - 1 ;
				if(l0 < -180)  l0 = 179 ;
				vis[l0 + 180] = 1 ;
			}
			l += d ;
			if(l < -180)  l = 179 ;
			if(l >= 180)  l = -180 ;
		}
	} ;
	for(int i = 0 ; i < n ; i ++)  move(a[i] , a[(i + 1) % n]) ;
	for(int i = 0 ; i < 360 ; i ++)
		if(vis[i] == 0)
		{
			cout << "no " ;
			if(i - 180 == -1)  cout << "-0.5\n" ;
			else if(i - 180 < 0)  cout << i - 180 + 1 << ".5\n" ;
			else  cout << i - 180 << ".5\n" ;
			return 0 ;
		}
	cout << "yes\n" ;
	
	return 0;
}