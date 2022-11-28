#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T,k,n,l;
char x[N],rs[N];
vector<int>V[15];
void slv(){
    scanf("%s %d",x+1,&k);
    int n=strlen(x+1);
    k=n-k;
    for(int i=0;i<=9;++i)V[i].clear();
    for(int i=1;i<=n;++i){
        V[x[i]-'0'].push_back(i);
    }
    int m=n,fl=1,nw=0;
    l=0;
    // cout << "???\n" ;
    while(m>k&&l<k){
        // puts("dfsfdsdsdsf");
        for(int i=fl;i<=9;++i){
            if(!V[i].size())continue;
            int t=upper_bound(V[i].begin() , V[i].end() , nw) - V[i].begin() ;
            if(t==V[i].size())continue;
            int p=V[i][t];
            // printf("     %d %d\n",i,p);
            if(p-nw-1<=m-k){
                // printf("________%d %d %d \n",p,p-nw-1,m-k);
                rs[++l]=x[p];
                m-=p-nw-1;
                nw=p;
                break;
            }
        }
        fl=0;
        // cout << "!!!\n" ;
        // printf("_%d %d %d\n",m,k,l);
    }
    // puts("LLLLLLLLL");
    for(int i=n-k+l+1;i<=n;++i){
        rs[++l]=x[i];

    }
    rs[++l]=0;
    puts(rs+1);
}
int main(){
    scanf("%d",&T);
    while(T--)slv();
}