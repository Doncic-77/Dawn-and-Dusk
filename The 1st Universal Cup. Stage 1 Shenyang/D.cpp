#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;

    string s ;
    cin >> s ;
    if(count(s.begin() , s.end() , 'T') == 3)  cout << "T1\n" ;
    else  cout << "DRX\n" ;

    return 0;
}
