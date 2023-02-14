#include<bits/stdc++.h>
using namespace std;
const int fix = 1e5 ;
const int up = 2e5 ;
struct Info
{
    int cnt ;
    long long sum ;
    long long sum1 , sum2 ;
    long long sum3 ;
    Info()
    {
        cnt = 0 ;
        sum = 0 ;
        sum1 = 0 ;
        sum2 = 0 ;
        sum3 = 0 ;
    }
};
const int maxn = 2e5 + 10 ;
Info info[maxn << 2] ;
int ls(int id)
{
    return id << 1 ;
}
int rs(int id)
{
    return id << 1 | 1 ;
}
Info merge(Info a , Info b)
{
    Info res ;
    res.cnt = a.cnt + b.cnt ;
    res.sum = a.sum + b.sum ;
    /*
     sum1 1001100
     sum2 11001100
     sum3 1010
     */
    if(a.cnt & 1)
    {
        // 10011 + 0011
        // 1 + 0

        // 1001100 + 1100
        if(a.cnt % 4 == 1)  res.sum1 = a.sum1 + (b.sum - b.sum2) ;
        else  res.sum1 = a.sum1 + b.sum2 ;
        if(a.cnt == 1 && b.cnt == 1)
        {
//            cout << a.sum1 << ' ' << b.sum << ' ' << b.sum1 << ' ' << b.sum2 <<  "gn\n" ;
        }
        // 11001 + 1001100
        // 1100110 + 0110011
        if(a.cnt % 4 == 1)  res.sum2 = a.sum2 + b.sum1 ;
        else  res.sum2 = a.sum2 + (b.sum - b.sum1) ;

        // 101 + 010
        res.sum3 = a.sum3 + (b.sum - b.sum3) ;
    }
    else
    {
        // 1001 + 1001
        // 100110 + 0110
        if(a.cnt % 4 == 0)  res.sum1 = a.sum1 + b.sum1 ;
        else  res.sum1 = a.sum1 + (b.sum - b.sum1) ;
        // 1100 + 1100
        // 110011 + 0011
        if(a.cnt % 4 == 0)  res.sum2 = a.sum2 + b.sum2 ;
        else  res.sum2 = a.sum2 + (b.sum - b.sum2) ;

        // 1010 + 1010
        res.sum3 = a.sum3 + b.sum3 ;
    }
    return res ;
}
void pushup(int id)
{
    info[id] = merge(info[ls(id)] , info[rs(id)]) ;
}
void change(int id , int l , int r , int pos , int x , int y , int op)
{
    if(l == r)
    {
        info[id].sum += (x + y) * op ;
        if(op == 1)
        {
            // 10011001100
            if(info[id].cnt % 4 == 0 || info[id].cnt % 4 == 3)  info[id].sum1 += x ;
            else  info[id].sum1 += y ;
            if(info[id].cnt % 4 == 0 || info[id].cnt % 4 == 1)  info[id].sum2 += x ;
            else  info[id].sum2 += y ;
            if(info[id].cnt % 2 == 0)  info[id].sum3 += x ;
            else  info[id].sum3 += y ;
        }
        else
        {
            // 11001100
            if(info[id].cnt % 4 == 1 || info[id].cnt % 4 == 0)  info[id].sum1 -= x ;
            else  info[id].sum1 -= y ;
            if(info[id].cnt % 4 == 1 || info[id].cnt % 4 == 2)  info[id].sum2 -= x ;
            else  info[id].sum2 -= y ;
            if(info[id].cnt % 2 == 1)  info[id].sum3 -= x ;
            else  info[id].sum3 -= y ;
        }


        info[id].cnt += op ;

        return ;
    }
    int mid = (l + r) / 2 ;
    if(pos <= mid)  change(ls(id) , l , mid , pos , x , y , op) ;
    else  change(rs(id) , mid + 1 , r , pos , x , y , op) ;
    pushup(id) ;
//    cout << id << ' ' << l - fix << ' ' << r - fix << ' ' << info[id].sum2 << "??\n" ;
} ;
Info query(int id , int l , int r , int x , int y)
{
    if(r < x || y < l)  return Info() ;
    if(x <= l && r <= y)  return info[id] ;
    int mid = (l + r) / 2 ;
    return merge(query(ls(id) , l , mid , x , y) , query(rs(id) , mid + 1 , r , x , y)) ;
}
int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;

    int n , m ;
    cin >> n >> m ;
    vector<int> x(n + 1 , 0) ;
    vector<int> y(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> x[i] >> y[i] ;
    for(int i = 1 ; i <= n ; i ++)  change(1 , 0 , up , fix + x[i] - y[i] , x[i] , y[i] , 1) ;
    auto cal = [&]()
    {
        Info L = query(1 , 0 , up , 0 , fix) ;
        Info R = query(1 , 0 , up , fix + 1 , up) ;
    //    cout << L.cnt << ' ' << L.sum1 << ' ' << R.sum << ' ' << R.sum3 << '\n' ;
        long long res = L.sum1 ;
        if(L.cnt % 2 == 0)  res += R.sum3 ;
        else  res += R.sum - R.sum3 ;
        cout << res << '\n' ;
    };
    cal() ;
    while(m --)
    {
        int id , xx , yy ;
        cin >> id >> xx >> yy ;
        change(1 , 0 , up , fix + x[id] - y[id] , x[id] , y[id] , -1) ;
        x[id] = xx ;
        y[id] = yy ;
        change(1 , 0 , up , fix + x[id] - y[id] , x[id] , y[id] , 1) ;
        cal() ;
    }

    return 0;
}
/*

 2 0
 1 2
 2 3

 4 0
 2 4
 5 7
 1 7
 2 1


 4 5
2 4
5 7
1 7
2 1
4 5 2
1 6 2
4 4 3
2 1 3
3 6 6

4 1
2 4
1 3
1 7
4 3
3 6 6

4 0
2 4
1 3
6 6
4 3

3 0
2 4
1 3
6 6
 */