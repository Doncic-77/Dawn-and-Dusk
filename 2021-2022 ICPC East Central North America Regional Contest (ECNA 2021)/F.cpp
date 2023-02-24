//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
typedef long double db ;
const db eps = 1e-9 ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n ;
    cin >> n ;
    vector<array<db , 5>> p(n) ;
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < 4 ; j ++)
            cin >> p[i][j] ;
        p[i][4] = 0 ;
    }
    db t = 0 ;
    auto ss = [&](db x)
    {
        return x * x ;
    } ;
    auto dis = [&](db x_1 , db y_1 , db x_2 , db y_2)
    {
        return sqrtl(ss(x_2 - x_1) + ss(y_2 - y_1)) ;
    } ;
    while(p.size() > 1)
    {
        int m = p.size() ;
        vector<int> vis(m , 0) ;
        vector<tuple<db , int , int>> v ;
        db mn = 1e10 ;
        for(int i = 0 ; i < m ; i ++)
        {
            db x_1 = p[i][0] ;
            db y_1 = p[i][1] ;
            db r_1 = p[i][2] + (t - p[i][4]) * p[i][3] ;
            for(int j = i + 1 ; j < m ; j ++)
            {
                db x_2 = p[j][0] ;
                db y_2 = p[j][1] ;
                db r_2 = p[j][2] + (t - p[j][4]) * p[j][3] ;    
                db d = dis(x_1 , y_1 , x_2 , y_2) - r_1 - r_2 ;
                if(d <= eps)
                {
                    mn = t ;
                    v.push_back({t , i , j}) ;    
                    continue ;
                }
                db z = t + d / (p[i][3] + p[j][3]) ;
                mn = min(mn , z) ;
                v.push_back({z , i , j}) ;
            }
        }
        for(auto [tt , x , y] : v)
        {
            if(tt - mn > eps)  continue ;
            vis[x] = 1 ;
            vis[y] = 1 ;
        }
        vector<array<db , 5>> q ;
        vector<int> f ;
        for(int i = 0 ; i < m ; i ++)
            if(vis[i] == 0)
                q.push_back(p[i]) ;
            else  f.push_back(i) ;
        t = mn ;
        db mx_s = 0 ;
        db new_x = 0 ;
        db new_y = 0 ;
        db new_r = 0 ;
        int c = f.size() ;
        for(int i = 0 ; i < c ; i ++)
        {
            mx_s = max(mx_s , p[f[i]][3]) ;
            new_x += p[f[i]][0] ;
            new_y += p[f[i]][1] ;
            new_r += ss(p[f[i]][2] + (t - p[f[i]][4]) * p[f[i]][3]) ;
        }
        new_x /= c ;
        new_y /= c ;
        new_r = sqrtl(new_r) ;
        q.push_back({new_x , new_y , new_r , mx_s , t}) ;
        p = q ;
    }
    cout << fixed << setprecision(8) << p[0][0] << ' ' << p[0][1] << '\n' ;
    cout << fixed << setprecision(8) << p[0][2] << '\n' ;

    return 0 ;
}