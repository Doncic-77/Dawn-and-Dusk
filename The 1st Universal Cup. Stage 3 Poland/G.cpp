//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
typedef long double db ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int T ;
    cin >> T ;
    while(T --)
    {
        int n , v ;
        cin >> n >> v ;
        vector<long long> p(n , 0ll) ;
        vector<int> x(n , 0) ;
        for(int i = 0 ; i < n ; i ++)  cin >> p[i] >> x[i] ;
        db l = 0.0 , r = 1e12 ;
        for(int _ = 1 ; _ <= 120 ; _ ++)
        {
            db mid = (l + r) / 2 ;
            db R = -1e12 ;
            db L = 1e12 ;
            for(int i = 0 ; i < n ; i ++)
            {
                if(p[i] <= 0)  R = max(R , p[i] + 1.0 * mid * x[i]) ;
                if(p[i] >= 0)  L = min(L , p[i] - 1.0 * mid * x[i]) ;
            }
            if(R < L)  l = mid ;
            else  r = mid ;
        }
        cout << fixed << setprecision(15) << l * v << '\n' ;
    }

    return 0 ;
}