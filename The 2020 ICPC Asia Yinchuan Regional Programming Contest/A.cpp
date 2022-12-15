#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	
	int n ;
	cin >> n ;
	
	set<pair<int , int>> X , Y , Z ;
	for(int i = 0 ; i < n ; i ++)
	{
		int x , y , z ;
		cin >> x >> y >> z ;
		X.insert({y , z}) ;
		Y.insert({x , z}) ;
		Z.insert({x , y}) ;
	}
	
//	cout << X.size() << ' ' << Y.size() << ' ' << Z.size() << "\n" ;
	
	set<pair<int , int>> res ;
	res.insert({X.size() , 2}) ;
	res.insert({Y.size() , 1}) ;
	res.insert({Z.size() , 0}) ;
	
	auto it = res.rbegin() ; 
//	for(auto u : res)  cout << u.first<< ' ' << u.second << "??\n" ;
	
	cout << (char)('X' + (2 - it -> second)) << '\n' ;
	
	return 0;
}