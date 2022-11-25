#include<bits/stdc++.h>
using namespace std;
typedef long double db ;
const db inf = 1e18 ,eps=1e-8;
bool eql(db x,db y){
	return fabs(x-y)<=eps;
}
int main(){
//	std::ios::sync_with_stdio(false) ;
//	cin.tie(0) ;
	int n ;
	scanf ("%d",&n) ;
	vector<pair<db , db>> v(n + 1) ;
	for(int i = 1 ; i <= n ; i ++)
	{
		db x ;
		scanf("%Lf %Lf",&v[i].first,&x) ;
//		cin >> v[i].first >> x ;
		v[i].second = x ;
	}
	db res = 0 ;
	
	sort(v.begin() + 1 , v.end()) ;
	reverse(v.begin() + 1 , v.end()) ;
	vector<db> pre(n + 1) ;
	pre[0] = 0 ;
	for(int i = 1 ; i <= n ; i ++)  pre[i] = pre[i - 1] + v[i].second ;
	vector<vector<db>> f(n + 10 , vector<db>(22 , -inf)) ;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(eql(v[i].first,1))  continue ;
		db y = 1.0 / (1 - v[i].first) ;
		db S = pre[n] - pre[i - 1] ;
		f[i][0] = S - y * S ;
		while(i + 1 <= n && eql(v[i + 1].first,v[i].first))  i += 1 ;
	}
	vector<int> lg(n + 10) ;
	for(int i = 1 ; i <= n ; i ++)  lg[i] = log2(i) ;
	for(int j = 1 ; j <= 19 ; j ++)
		for(int i = 1 ; i + (1 << j) - 1 <= n ; i ++)
			f[i][j] = max(f[i][j - 1] , f[i + (1 << (j - 1))][j - 1]) ;
	auto query = [&](int l , int r)
	{
		int len = lg[r - l + 1] ;
		return max(f[l][len] , f[r - (1 << len) + 1][len]) ;	
	} ;
	vector<int> left(n + 1 , 0) ;
	for(int i = 1 ; i <= n ; i ++)
		if(i == 1 || v[i].first != v[i - 1].first)  left[i] = i ;
		else  left[i] = left[i - 1] ;
	for(int i = 1 ; i <= n ; i ++)
	{
		if((v[i].first,0))  break ;
		int j = i ;
		while(j + 1 <= n && eql(v[j + 1].first,v[j].first))  j += 1 ;
		if(j == n)  break ;
		db x = 1.0 / v[j].first ;
		auto find = [&]()
		{
			int l = 1 , r = n ;
			int t = n + 1 ;
			auto ok = [&](int mid)
			{
				if(eql(v[mid].first,1))  return false ;
				db y = 1.0 / (1.0 - v[mid].first) ;
				return x * pre[j] >= y * (pre[n] - pre[mid - 1]) ;
			} ;	
			while(l <= r)
			{
				int mid = (l + r) / 2 ;
				if(ok(mid))  t = mid , r = mid - 1 ;
				else  l = mid + 1 ;
			}
			return t ;
		} ;
		int id = find() ;
		if(id <= n)  id = left[id] ;
//		cout << i << ' ' << j << ' ' << id << "???\n" ;
		if(id > n)
		{
			res = max(res , pre[j] + query(j + 1 , n)) ;
		}	
		else
		{
			db y = 1.0 / (1.0 - v[id].first) ;
			id = max(id , j + 1) ;
			if(id == j + 1)  res = max(res , pre[j] - max(x * pre[j] , y * (pre[n] - pre[id - 1])) + (pre[n] - pre[id - 1])) ;
			else
			{
				res = max(res , pre[j] - max(x * pre[j] , y * (pre[n] - pre[id - 1])) + (pre[n] - pre[id - 1])) ;
				res = max(res , pre[j] + query(j + 1 , id - 1)) ;
			}
		}
		i = j ;
	}	
	
	cout << fixed << setprecision(30) << res << '\n' ;
	return 0;
}
