#include<bits/stdc++.h>
using namespace std;
int n,m,w[6],s,x;
string a;
map<string,int>mp1; 
int main(){
	cin>>n;
	for(int i=1;i<=n*5;++i){
		cin>>a;
		mp1[a]=1;
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>a;
		if(mp1[a])s++;
		cin>>x;
		w[x]++;
	}
	for(int i=2;i<=5;++i)w[1]=min(w[1],w[i]);
	printf("%d\n",min(s,w[1]));
}