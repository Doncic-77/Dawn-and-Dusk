#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    set<string> st ;
    int n ;
    cin >> n ;
    while(n --)
    {
        int m ;
        cin >> m ;
        int flag = 0 ;
        while(m --)
        {
            string s ;
            cin >> s ;
            auto ok = [&]()
            {
                int t = s.size() ;
                for(int i = 0 ; i + 2 < t ; i ++)
                    if(s.substr(i , 3) == "bie")
                        return true ;
                return false ;
            } ;
            if(!ok())  continue ;
            if(st.find(s) == st.end())
            {
                st.insert(s) ;
                cout << s << '\n' ;
                flag = 1 ;
            }
        }
        if(flag == 0)
        {
            cout << "Time to play Genshin Impact, Teacher Rice!\n" ;
        }
    }
    return 0 ;
}