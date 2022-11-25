#include<bits/stdc++.h>
using namespace std;

int main(){
//	std::ios::sync_with_stdio(false) ;
//	cin.tie(0) ;
	int n ;
	cin >> n ; 
	vector<int> p(n) ;
	for(int i = 0 ; i < n ; i ++)  cin >> p[i] ;
	int res = 0 ;
	while(!p.empty())
	{
		if(p.size() == 1)
		{
		//	res += 1 ;
			break ;
		}
		res += 1 ;
		vector<int> q ;
		int m = p.size() ;
		for(int i = 0 ; i < m ; i ++)
			if(i > 0 && p[i] < p[i - 1] || i < m - 1 && p[i] < p[i + 1])  continue ;
			else  q.push_back(p[i]) ;
		p = q ;
		
//		cout << q.size() << '\n' ;
	}
	cout << res << '\n' ;
	return 0;
}