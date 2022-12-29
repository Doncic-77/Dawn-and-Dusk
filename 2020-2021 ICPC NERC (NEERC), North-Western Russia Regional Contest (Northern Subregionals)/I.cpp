#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	
	int s ;
	cin >> s ;
	for(int a = 0 ; a <= 1000 ; a ++)
		for(int b = 0 ; b <= 1000 ; b ++)
		{
			if(a * a + b * b == s)
			{
				cout << a << ' ' << 0 << '\n' ;
				cout << a + b << ' ' << a << '\n' ;
				cout << b << ' ' << a + b << '\n' ;
				cout << 0 << ' ' << b << '\n' ;
				return 0 ;
			}
		}
	cout << "Impossible\n" ;
	
	return 0;
}