#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 ;
# define vec point
struct point
{
	int x , y ;
	point(){}
	point(int x2 , int y2)
	{
		x = x2 , y = y2 ;
	}
	void input()
	{
		int x2 , y2 ;
		cin >> x2 >> y2 ;
		x = x2 ;
		y = y2 ;
	}
	point operator + (const point &s) const {return (point){x + s.x , y + s.y} ;}
	point operator - (const point &s) const {return (point){x - s.x , y - s.y} ;}
	bool operator < (point b) const
	{
		return x == b.x ? y < b.y : x < b.x ;
	}
} ;
long long cross(vec s , vec t)
{
	return 1ll * s.x * t.y - 1ll * s.y * t.x ;
}
long long dot(vec s , vec t)
{
	return 1ll * s.x * t.x + 1ll * s.y * t.y ;
}
int n;
int ok[N] ;
int ban[N] ;
//pair<int , int>
//[0 , m - 1]
int tr[N << 1];
void Ad(int m , int i){for(;i<=m;i+=i&-i)tr[i]++;}
int Qr(int i){
	int rs=0;
	for(;i;i-=i&-i)rs+=tr[i];
	return rs;
}
long long res = 0 ;
void clc(vector<array<int,3>> a){
	int m = a.size() ;
	if(m == 0)  return ;
	sort(a.begin() , a.end());
	// for(auto u : a)  cout << u[0] << ' ' << u[1] << ' ' << u[2] << "???\n" ;
	for(int i=0;i<=m*2;++i)tr[i]=0;
	for(int i=0;i<m;++i){
		int t=a[i][1];
		res += Qr(t) ;
		Ad(m+10,t);
	}
}
long long dis(point p1 , point p2)
{
	return 1ll * (p1.x - p2.x) * (p1.x - p2.x) + 1ll * (p1.y - p2.y) * (p1.y - p2.y) ;
}
int main(){
	
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;	
	
	point s , e ;
	s.input() ;
	e.input() ;
	int n ;
	cin >> n ;
	vector<point> p(n) ;
	for(int i = 0 ; i < n ; i ++)  p[i].input() ;
	auto mark = [&](int op)
	{
		vector<int> id ;
		for(int i = 0 ; i < n ; i ++)
			if(cross((s - e) , p[i] - s) == 0)
			{
				if(dot(e - s , p[i] - s) * op > 0)
				{
					id.push_back(i) ;
				}
			}
		sort(id.begin() , id.end() , [&](int x , int y)
		{
			return dis(p[x] , s) < dis(p[y] , s) ;
		}) ;
		int m = id.size() ;
		for(int i = 0 ; i < m ; i ++)
		{
			res += i ;
			ban[id[i]] = 1 ;
		}
	} ;
	
	
	mark(-1) ;
	mark(1) ;
	
	
	vector<vector<int>> v(2) ;
	for(int i = 0 ; i < n ; i ++)
	{
		if(ban[i] == 1)  continue ;
		//ni shi zhen
		if(cross(e - s , p[i] - s) > 0)  v[0].push_back(i) ;
		else  v[1].push_back(i) ;
	}
	

	vector<point> pp(2) ;
	pp[0] = s ;
	pp[1] = e ;
	
	auto common_line = [&](int op , int op2 , int op3) 
	{
		vector<int> t ;
		for(auto u : v[op])
		{
			t.push_back(u) ;
		}
		sort(t.begin() , t.end() , [&](int x , int y)
		{ 
			return cross(p[x] - pp[op2] , p[y] - pp[op2]) * op3 > 0 ; 
		}) ;
		int m = t.size() ;
		for(int i = 0 ; i < m ; i ++)
		{
			int j = i ;
			while(j + 1 < m && cross(p[t[j + 1]] - p[t[j]] , p[t[j]] - pp[op2]) == 0)  j += 1 ;
			sort(t.begin() + i , t.begin() + j + 1 , [&](int x , int y)
			{
				return dis(p[x] , pp[op2]) < dis(p[y] , pp[op2]) ;
			}) ;
			for(int k = i + 1 ; k <= j ; k ++)
			{
				res += k - i ;
				//ok[t[k]] = 1 ;
				// ban[t[k]] = 1 ;
			}
			i = j ;
		}
	} ;
	
	// common_line(0 , 0 , 1) ;
	// common_line(1 , 0 , 1) ;
	// common_line(0 , 1 , -1) ;
	// common_line(1 , 1 , -1) ;
	
    // cout << res << '\n' ;
	
	auto recal = [&](int op)
	{
		vector<int> vv ;
		for(auto u : v[op])
			if(ban[u] == 0)
				vv.push_back(u) ;
		v[op] = vv ;	
	} ;
	
	recal(0) ;
	recal(1) ;
	
	auto solve = [&](int op)
	{
		int tt = 1 ;
		if(op == 1)  tt = -1 ;
		vector<int> ord_s(n , -1) ;
		vector<int> ord_e(n , -1) ;
		sort(v[op].begin() , v[op].end() , [&](int x , int y)
		{
			return cross(p[x] - s , p[y] - s) * tt > 0 ;
		}) ;
		int cur = 0 ;
        int lst = -1 ;
		for(auto u : v[op])
        {
            if(lst == -1)  ord_s[u] = cur ++ ;
            else
            {
                if(cross(p[u] - s , p[lst] - s) == 0)  ord_s[u] = ord_s[lst] ;
                else  ord_s[u] = cur ++ ;
            }
            lst = u ;
        }
		sort(v[op].begin() , v[op].end() , [&](int x , int y)
		{
			return cross(p[x] - e , p[y] - e) * tt < 0 ;
		}) ;
		cur = 0 ;
		lst = -1 ;
		for(auto u : v[op])
        {
            if(lst == -1)  ord_e[u] = cur ++ ;
            else
            {
                if(cross(p[u] - e , p[lst] - e) == 0)  ord_e[u] = ord_e[lst] ;
                else  ord_e[u] = cur ++ ;
            }
            lst = u ;
        }
		vector<array<int , 3>> a ;
		for(auto u : v[op])  a.push_back({ord_s[u] + 1 , ord_e[u] + 1 , u}) ;
		clc(a) ;
	} ;
	
	solve(0) ;
	solve(1) ;
	
	cout << res << '\n' ;
	
	return 0;
}
