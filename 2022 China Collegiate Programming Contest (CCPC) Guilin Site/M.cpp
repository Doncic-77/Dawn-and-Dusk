//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
struct BIT
{
	int n ;
	vector<long long> tree ;
	BIT(int t)
	{
		n = t ;
		tree.resize(0) ;
		tree.resize(n + 1 , 0ll) ;
	}
	void init(int t)
	{
		n = t ;
		tree.resize(0) ;
		tree.resize(n + 1 , 0ll) ;
	}
	int lowbit(int k)
	{
		return k & -k ;
	}
	void add(int x , long long k)  // a[x] += k
	{
		while(x <= n)  //维护的是 [1 , n] 的序列
		{
			tree[x] += k ;
			x += lowbit(x) ;
		}
	}
	long long sum(int x)  // sum[l , r] = sum(r) - sum(l - 1)
	{
        if(x <= 0)  return 0ll ;
		long long ans = 0 ;
		while(x != 0)
		{
			ans += tree[x] ;
			x -= lowbit(x) ;
		}
		return ans ;
	}
	long long query(int l , int r)
	{
		if(l > r)  return 0ll ;
		return sum(r) - sum(l - 1) ;
	}
} ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m ;
    cin >> n >> m ;
    vector<int> p(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> p[i] ;
    string s ;
    cin >> s ;

    long long res = 0 ;
    BIT tree(n + 10) ;
    for(int i = 1 ; i <= n ; i ++)
    {
        res += tree.query(p[i] + 1 , n) ;
        tree.add(p[i] , 1) ;
    }
    cout << res << '\n' ;

    long long all = 1ll * n * (n - 1) / 2 ;

    list<int> v ;
    for(int i = 1 ; i <= n ; i ++)  v.push_back(p[i]) ;
    int op = 0 ;

    for(auto u : s)
    {
        if(u == 'R')
        {
            res = all - res ;
            op ^= 1 ;
        }
        else
        {
            if(op == 0)
            {
                int x = v.front() ;
                v.pop_front() ;
                v.push_back(x) ;
                res -= x - 1 ;
                res += n - x ;
            }
            else
            {
                int x = v.back() ;
                v.pop_back() ;
                v.push_front(x) ;
                res -= x - 1 ;
                res += n - x ;
            }
        }
        cout << res % 10 ;
    }
    cout << '\n' ;

    return 0 ;
}