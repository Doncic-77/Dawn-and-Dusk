#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int ans,n,a[N],mi[N<<2],ma[N<<2],p[N];
void js(int z,int y,int c){
  if(z==y){
    p[z]=c;
    mi[c]=ma[c]=a[z];
    return;
  }
  int mid=(z+y)>>1;
  js(z,mid,c<<1);
  js(mid+1,y,c<<1|1);
  mi[c]=min(mi[c<<1],mi[c<<1|1]);
  ma[c]=max(ma[c<<1],ma[c<<1|1]);
}
void Upd(int x){
  ma[p[x]]=mi[p[x]]=a[x];
  for(int c=p[x]>>1;c;c>>=1){
    mi[c]=min(mi[c<<1],mi[c<<1|1]);
    ma[c]=max(ma[c<<1],ma[c<<1|1]);
  }
}

int ma_Qry(int z,int y,int c,int l,int r,int w){
  if(z>r||y<l)return 0;
  if(l<=z&&y<=r){
    if(ma[c]<w)return 0;
    while(z<y){
      int mid=(z+y)>>1;
      if(ma[c<<1]>=w)y=mid,c<<=1;
      else z=mid+1,c=c<<1|1;
    }
    return z;
  }
  int mid=(z+y)>>1;
  if(l<=mid){
    int t=ma_Qry(z,mid,c<<1,l,r,w);
    if(t)return t;
  }
  if(r>mid)return ma_Qry(mid+1,y,c<<1|1,l,r,w);
  return 0;
}

int mi_Qry(int z,int y,int c,int l,int r,int w){
  if(z>r||y<l)return 0;
  if(l<=z&&y<=r){
    // printf("_____%d %d  %d %d\n",z,y,mi[c],w);
    if(mi[c]>w)return 0;
    while(z<y){
      int mid=(z+y)>>1;
      if(mi[c<<1|1]<=w)z=mid+1,c=c<<1|1;
      else y=mid,c<<=1;
    }
    // printf("???%d\n",y);
    return y;
  }
  int mid=(z+y)>>1;
  if(r>mid){
    int t=mi_Qry(mid+1,y,c<<1|1,l,r,w);
    if(t)return t;
  }
  if(l<=mid)return mi_Qry(z,mid,c<<1,l,r,w);
  return 0;
}
int pat(int l,int r){
  // printf("l r %d %d\n",l,r);
  int pv=a[(l+r)>>1];
  // printf("%d %d\n",(l+r)>>1,pv);
  int i=l-1,j=r+1;
  while(1){
//    do {i++;} while(a[i]<=pv);
//    do {j--;} while(a[j]>=pv);
    i=ma_Qry(1,n,1,i+1,r,pv);
    j=mi_Qry(1,n,1,l,j-1,pv);
    // printf("%d %d %d__\n",i,j,mi[1]);
    if(i>=j)return j;
    swap(a[i],a[j]);
  // printf("i j %d %d\n",i,j);
    Upd(i),Upd(j);
    ans++;
  }
}
void qsort(int l,int r){
  if(l>=r)return;
  int p=pat(l,r);
  qsort(l,p);
  qsort(p+1,r);
}
void slv(){
  ans=0;
  scanf("%d",&n);
  for(int i=1;i<=n;++i)scanf("%d",&a[i]);
  js(1,n,1);
  qsort(1,n);
  printf("%d\n",ans);
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--)slv();
}