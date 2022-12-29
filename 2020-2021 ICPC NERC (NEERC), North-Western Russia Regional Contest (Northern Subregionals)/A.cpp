#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	
	map<int , string> mp ;
	
	mp.insert({1995, "ITMO"}) ;
mp.insert({1996, "SPbSU"}) ;
mp.insert({1997, "SPbSU"});
mp.insert({1998, "ITMO"});
mp.insert({1999, "ITMO"});
mp.insert({2000, "SPbSU"});
mp.insert({2001, "ITMO"});
mp.insert({2002, "ITMO"});
mp.insert({2003, "ITMO"});
mp.insert({2004, "ITMO"});
mp.insert({2005, "ITMO"});
mp.insert({2006, "PetrSU, ITMO"});
mp.insert({2007, "SPbSU"});
mp.insert({2008, "SPbSU"});
mp.insert({2009, "ITMO"});
mp.insert({2010, "ITMO"});
mp.insert({2011, "ITMO"});
mp.insert({2012, "ITMO"});
mp.insert({2013, "SPbSU"});
mp.insert({2014, "ITMO"});
mp.insert({2015, "ITMO"});
mp.insert({2016, "ITMO"});
mp.insert({2017, "ITMO"});
mp.insert({2018, "SPbSU"});
mp.insert({2019, "ITMO"});
	
	//cout << mp[1] << endl ;
	
	int x ;
	cin >> x ;
	cout << mp[x] << '\n' ;
	
	return 0;
}