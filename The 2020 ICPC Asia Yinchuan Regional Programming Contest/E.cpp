#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	
	vector<string> p = {"-F" , "-Cl" , "-Br" , "-I" , "-CH3" , "-CH2CH3" , "-CH2CH2CH3", "-H"} ;
	
	map<string , int> mp ;
	int cur = 0 ;
	for(auto u : p)  mp[u] = ++ cur ;
	
	int T ;
	cin >> T ;
	while(T --)
	{
		string s1 , s2 , s3 , s4 ;
		cin >> s1 >> s2 >> s3 >> s4 ;
		
		if(s1 == s3 || s2 == s4)
		{
			cout << "None\n" ;
			continue ;
		}
		
		if(s1 == s2 || s3 == s4)
		{
			cout << "Cis\n" ;
			continue ;
		}
		
		if(s1 == s2 || s1 == s3 || s1 == s4 || s2 == s3 || s2 == s4 || s3 == s4)
		{
			cout << "Trans\n" ;
			continue ;
		}
		
		int id1 = mp[s1] ;
		int id2 = mp[s2] ;
		int id3 = mp[s3] ;
		int id4 = mp[s4] ;
		
		int p1 = 1 ;
		if(id3 < id1)  p1 = 3 ;
		int p2 = 2 ;
		if(id4 < id2)  p2 = 4 ;
		
		if(p1 == 1 && p2 == 2 || p1 == 3 && p2 == 4)
		{
			cout << "Zasamman\n" ;
			continue ;
		}
		
		cout << "Entgegen\n" ;
		
	}
	
	return 0;
}