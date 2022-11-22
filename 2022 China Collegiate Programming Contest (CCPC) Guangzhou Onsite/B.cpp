//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
typedef unsigned long long ull ;
struct Info
{
    ull sum1 ; // t 时刻加入一个w，等价于以后在T时刻查询时对[1,T-1]的贡献是 w * (T - 1)
    ull add1 ; // lazy
    ull sum2 ; // t 时刻加入一个w对[1,t-1]的代价是 -w * (t - 1) 
	ull add2 ; // lazy
    ull p ; // 颜色
	Info()
	{
        sum1 = 0 ;
        add1 = 0 ;
        sum2 = 0 ;
        add2 = 0 ;
        p = 0 ;
	}
} ;
Info merge(Info a , Info b)
{
	Info res ;
    res.sum1 = a.sum1 + b.sum1 ;
    res.sum2 = a.sum2 + b.sum2 ;
    if(a.p == b.p)  res.p = a.p ;
    else  res.p = 0 ;
	return res ;
}
struct SegmentTree
{
    vector<ull> ans ;
	int n ;
	vector<Info> info ;
	SegmentTree(int t)
	{
		n = t ;
		info.resize(4 * n + 10) ;
        ans.resize(n + 1 , 0) ;
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
	void upd(Info a , Info &b , int l , int r)
	{
        b.sum1 += a.add1 * (r - l + 1) ;
        b.sum2 += a.add2 * (r - l + 1) ;
        b.add1 += a.add1 ;
        b.add2 += a.add2 ;
        if(a.p != 0)  b.p = a.p ;
	}
	void cle(Info &a)
	{
        a.add1 = 0 ;
        a.add2 = 0 ;
	}
	void push_down(int id , int l , int mid , int r)
	{
		upd(info[id] , info[lson(id)] , l , mid) ;
		upd(info[id] , info[rson(id)] , mid + 1 , r) ;
		cle(info[id]) ;
	}
	void push_up(int id)
	{
		info[id] = merge(info[lson(id)] , info[rson(id)]) ;
	}
	void build(int id , int l , int r , vector<ull> &a)
	{
		if(l == r)
		{
            info[id].p = a[l] ;
			return ;
		}
		int mid = (l + r) / 2 ;
		build(lson(id) , l , mid , a) ;
		build(rson(id) , mid + 1 , r , a) ;
		push_up(id) ;   
	}
	void modify(int id , int l , int r , int x , int y , ull w , ull t) 
	{
		if(y < l || r < x)  return ;
		if(x <= l && r <= y && info[id].p != 0)
		{
            ans[info[id].p] += info[id].sum1 * t - info[id].sum2 ;
            info[id].p = w ;
            ans[info[id].p] -= info[id].sum1 * t - info[id].sum2 ;
			return ;
		}
		int mid = (l + r) / 2 ;
		push_down(id , l , mid , r) ;
		if(x <= mid)  modify(lson(id) , l , mid , x , y , w , t) ;
		if(mid < y)  modify(rson(id) , mid + 1 , r , x , y , w , t) ;
		push_up(id) ;
	}
    void modify2(int id , int l , int r , int x , int y , ull w1 , ull w2) 
	{
		if(y < l || r < x)  return ;
		if(x <= l && r <= y)
		{
            info[id].sum1 += w1 * (r - l + 1) ;
            info[id].add1 += w1 ;
            info[id].sum2 += w2 * (r - l + 1) ;
            info[id].add2 += w2 ;
            return ;
		}
		int mid = (l + r) / 2 ;
		push_down(id , l , mid , r) ;
		if(x <= mid)  modify2(lson(id) , l , mid , x , y , w1 , w2) ;
		if(mid < y)  modify2(rson(id) , mid + 1 , r , x , y , w1 , w2) ;
		push_up(id) ;
	}
    void print(int n)
    {
        for(int i = 1 ; i <= n ; i ++)  cout << ans[i] << " \n"[i == n] ;
    }
} ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , q ;
    cin >> n >> q ;
    vector<ull> a(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
    SegmentTree seg(n + 1) ;
    seg.build(1 , 1 , n , a) ;
    for(int i = 1 ; i <= q ; i ++)
    {
        int op , l , r ;
        ull w ;
        cin >> op >> l >> r >> w ;
        if(op == 1)  seg.modify(1 , 1 , n , l , r , w , i) ;
        else  seg.modify2(1 , 1 , n , l , r , w , w * i) ;
    }
    seg.modify(1 , 1 , n , 1 , n , 0 , q + 1) ;
    seg.print(n) ;

    return 0 ;
}