//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
struct Info
{
    array<int , 4> c ;
    array<int , 4> lazy ;
    Info()
	{
        c = {0 , 0 , 0 , 0} ;
        lazy = {0 , 0 , 0 , 0} ;
	}
} ;
Info merge(Info a , Info b)
{
	Info res ;
    for(int i = 0 ; i < 4 ; i ++)  res.c[i] = max(a.c[i] , b.c[i]) ;
	return res ;
}
struct SegmentTree
{
	int n ;
	vector<Info> info ;
	SegmentTree(int t)
	{
		n = t ;
		info.resize(4 * n + 10) ;
	}
	void Clear(int t)
	{
		info.resize(0) ;
		n = t ;
		info.resize(4 * n + 10) ;
	}
	int lson(int id)
	{
		return id << 1 ;
	}
	int rson(int id)
	{
		return id << 1 | 1 ;
	}
	void upd(Info a , Info &b)
	{
        for(int i = 0 ; i < 4 ; i ++)  b.lazy[i] += a.lazy[i] , b.c[i] += a.lazy[i] ;
	}
	void cle(Info &a)
	{
        for(int i = 0 ; i < 4 ; i ++)  a.lazy[i] = 0 ;
	}
	void push_down(int id)
	{
		upd(info[id] , info[lson(id)]) ;
		upd(info[id] , info[rson(id)]) ;
		cle(info[id]) ;
	}
	void push_up(int id)
	{
		info[id] = merge(info[lson(id)] , info[rson(id)]) ;
	}
	void modify(int id , int l , int r , int x , int y , array<int , 4> d) //It's modify , not add. 
	{
		if(y < l || r < x)  return ;
		if(x <= l && r <= y)
		{
            for(int i = 0 ; i < 4 ; i ++)
            {
                info[id].c[i] += d[i] ;
                info[id].lazy[i] += d[i] ;
            }
			return ;
		}
		push_down(id) ;
		int mid = (l + r) / 2 ;
		if(x <= mid)  modify(lson(id) , l , mid , x , y , d) ;
		if(mid < y)  modify(rson(id) , mid + 1 , r , x , y , d) ;
		push_up(id) ;
	}
	Info query(int id , int l , int r , int x , int y)
	{
		if(y < l || r < x)  return Info() ;
		if(x <= l && r <= y)  return info[id] ;
		push_down(id) ;
		int mid = (l + r) / 2 ;
		Info res ;
		if(x <= mid)  res = merge(res , query(lson(id) , l , mid , x , y)) ;
		if(mid < y)  res = merge(res , query(rson(id) , mid + 1 , r , x , y)) ;
		return res ;
	}
} ;

int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , q ;
    cin >> n >> q ;

    SegmentTree seg(n + 10) ;

    while(q --)
    {
        string s ;
        cin >> s ;
        if(s[1] == 'U')
        {
            int l , r , x ;
            cin >> l >> r >> x ;
            // 2 3 5 7
            vector<int> d = {2 , 3 , 5 , 7} ;
            array<int , 4> e = {0 , 0 , 0 , 0} ;
            for(int i = 0 ; i < 4 ; i ++)
            {
                while(x % d[i] == 0)
                {
                    x /= d[i] ;
                    e[i] += 1 ;
                }
            }
            seg.modify(1 , 1 , n , l , r , e) ;
        }
        else
        {
            int l , r ;
            cin >> l >> r ;
            Info res = seg.query(1 , 1 , n , l , r) ;
            cout << "ANSWER " << max({res.c[0] , res.c[1] , res.c[2] , res.c[3]}) << '\n' ;
        }
    }

    return 0 ;
}
/*
5 6
MULTIPLY 3 5 2
MULTIPLY 2 5 3
MAX 1 5
MULTIPLY 1 4 2
MULTIPLY 2 5 5
MAX 3 5

3 3
MULTIPLY 3 3 2
MULTIPLY 1 3 2
MAX 3 3
*/