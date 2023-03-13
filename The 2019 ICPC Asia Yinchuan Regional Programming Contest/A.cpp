//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int T ;
    cin >> T ;
    while(T --)
    {
        int n ;
        cin >> n ;
        vector<tuple<string , string , int>> v(n) ;
        for(int i = 0 ; i < n ; i ++)
        {
            string name , color ;
            int power ;
            cin >> name >> color >> power ;
            v[i] = {name , color , power} ;
        }
        sort(v.begin() , v.end()) ;
        map<string , int> mp ;
        for(int i = 1 ; i <= 5 ; i ++)
        {
            string s ;
            cin >> s ;
            mp[s] = 1 ;
        }
        string p ;
        cin >> p ;
        vector<vector<vector<int>>> f(6 , vector<vector<int>>(6 , vector<int>(6 , -1))) ;
        f[0][0][0] = 0 ;
        for(int i = 0 ; i < n ; i ++)
        {
            int j = i ;
            while(j + 1 < n && get<0>(v[j + 1]) == get<0>(v[j]))  j += 1 ;
            vector<vector<vector<int>>> g = f ;
            for(int k = i ; k <= j ; k ++)
            {
                for(int x = 0 ; x <= 4 ; x ++)
                    for(int y = 0 ; y <= 5 ; y ++)
                        for(int z = 0 ; z <= 5 ; z ++)
                        {
                            if(f[x][y][z] < 0)  continue ;
                            int ny = y ;
                            int nz = z ;
                            if(mp.count(get<0>(v[k])))  ny += 1 ;
                            if(get<1>(v[k]) == p)  nz += 1 ;
                            if(ny > 5 || nz > 5)  continue ;
                            g[x + 1][ny][nz] = max(g[x + 1][ny][nz] , f[x][y][z] + get<2>(v[k])) ;
                        }
            }
            f = g ;
            i = j ;
        }
        int mx = 0 ;
        for(int i = 0 ; i <= 5 ; i ++)
            for(int j = 0 ; j <= 5 ; j ++)
            {
                if(f[5][i][j] < 0)  continue ;
                int val = f[5][i][j] ;
                int s = val * 10 ;
                s += val * i ;
                s += val * j * 2 ;
                s /= 10 ;
                mx = max(mx , s) ;               
            }
        cout << mx << '\n' ;
    }

    return 0 ;
}
/*
1
6
Saaya Power 45000
Aya Power 2000
Kokoro Happy 45000
Kasumi Cool 45000
Rimi Power 45000
Aya Pure 45000


Saaya Tae Kasumi Rimi Arisa
Power
*/