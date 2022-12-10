#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	
	map<string , int> left ;
	map<string , int> right ;
	map<string , int> any ;
	
	int n ;
	cin >> n ;
	while(n --)
	{
		string s , t ;
		int x ;
		cin >> s >> t >> x ;
		if(t == "left")  left[s] = x ;
		else if(t == "right")  right[s] = x ;
		else  any[s] = x ;
	}
	int flag = 0 ;
	for(auto u : any)
		if(u.second >= 2)
			flag = 1 ;
	for(auto u : left)
		if(right.count(u.first))
			flag = 1 ;
	if(flag == 0)
	{
		cout << "impossible\n" ;
		return 0 ;
	}
	
	int sum = 0 ;
	for(auto u : any)
		if(!left.count(u.first) && !right.count(u.first))
	  		sum += 1 ;
	int odd = 0 ;
	for(auto u : left)
		if(!right.count(u.first))
			sum += u.second ;
		else  odd += u.second ;
	int even = 0 ;
	for(auto u : right)
		if(!left.count(u.first))
			sum += u.second ;
		else  even += u.second ;
	cout << sum + max(odd , even) + 1 << '\n' ;
	
	return 0;
}