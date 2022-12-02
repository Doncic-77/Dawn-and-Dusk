#include<bits/stdc++.h>
using namespace std ;
int main()
{
  int T ;
  scanf("%d" , &T) ;
  while(T --)
  {
    int n ;
    scanf("%d" , &n) ;
    vector<int> a(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++) scanf("%d" , &a[i]) ;
    int sum = 0 ;
    int carry = 0 ;
    for(int _ = 1 ; _ <= 30 ; _ ++)
    {
      int t = carry ;
      for(int i = 1 ; i <= n ; i ++)
      {
        t += a[i] % 10 ;
        a[i] /= 10 ;
      }
      t /= 10 ;
      carry = t ;
      sum += t ;
    }
    printf("%d\n" , sum) ;
  }
}