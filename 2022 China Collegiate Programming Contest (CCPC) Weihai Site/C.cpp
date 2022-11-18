//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
#define vec point
typedef double db ; //卡精度就换long double，不过long double很慢
const db eps = 1e-6 ; //调参
const db pi = acos(-1.0) ;
const db inf = 40000 ;
int sgn(db x)
{
	if(x < -eps) return -1 ;
	else if (x > eps)  return 1 ;
	else return 0 ;
}
int cmp(db x , db y)
{
	return sgn(x - y) ;
}
void print(int num , db x)
{
	cout << fixed << setprecision(num) << x << '\n' ;
}
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
	point operator + (const point& s)const{return (point){x + s.x , y + s.y} ;}
	point operator - (const point& s)const{return (point){x - s.x , y - s.y} ;}
} ;
int sgn(int x)
{
    int eps = 0 ;
	if(x < -eps) return -1 ;
	else if (x > eps)  return 1 ;
	else return 0 ;
}
int cmp(int x , int y)
{
	return sgn(x - y) ;
}
int in_mid(int k1 , int k2 , int k3) // k3 在 [k1,k2] 内
{
	return cmp(k1 , k3) * cmp(k2 , k3) <= 0 ;
}
int in_mid(point p1 , point p2 , point p3)
{
	return in_mid(p1.x , p2.x , p3.x) && in_mid(p1.y , p2.y , p3.y) ;
}
db cross(vec s , vec t){return s.x * t.y - s.y * t.x ;} // 叉积
mt19937  rnd(chrono::high_resolution_clock::now().time_since_epoch().count()) ;
long long rand_l_r(long long l , long long r)
{
	uniform_int_distribution<long long> dist(l , r) ;
	return dist(rnd) ;
}
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int T ;
    cin >> T ;
    while(T --)
    {
        int n ;
        cin >> n ;
        vector<point> p(n) ;
        for(int i = 0 ; i < n ; i ++)  p[i].input() ;
        int id = -1 ;
        for(int i = 2 ; i < n ; i ++)
        {
            if(cross(p[i] - p[i - 1] , p[i] - p[i - 2]) != 0)
            {
                id = i ;
                break ;
            }
        }
        if(n < 5 || id == -1)
        {
            cout << "NO\n" ;
            continue ;
        }
        vector<int> v = {id} ;
        for(int i = id - 1 ; i >= max(0 , id - 4) ; i --)  v.push_back(i) ;
        for(int i = id + 1 ; i <= min(n - 1 , id + 4) ; i ++)  if(v.size() < 5) v.push_back(i) ;
        for(int i = 0 ; i < 5 ; i ++)
        {
            int flag = 1 ;
            for(int j = 0 ; j < 5 ; j ++)
                for(int k = j + 1 ; k < 5 ; k ++)
                {
                    if(v[k] == v[i] || v[j] == v[i])  continue ;
                    if(cross(p[v[k]] - p[v[i]] , p[v[j]] - p[v[i]]) == 0 && (in_mid(p[v[i]] , p[v[j]] , p[v[k]]) || in_mid(p[v[i]] , p[v[k]] , p[v[j]])))
                    {
                        flag = 0 ;
                        goto pp ;
                    }
                }
            pp : ;
            if(flag == 1)
            {
                cout << "YES\n" ;
                vector<int> tt = {v[i]} ;
                for(int j = 0 ; j < 5 ; j ++)
                    if(j != i)
                        tt.push_back(v[j]) ;
                for(auto j : tt)
                {
                    cout << p[j].x << ' ' << p[j].y << '\n' ;
                }                
                goto ok ;
            }
        }
        cout << "NO\n" ;
        ok : ;
    }

    return 0 ;
}