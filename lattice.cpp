#include<bits/stdc++.h>
using namespace std;
int main()
{
  double r; 
  long long int ans = 0;
  cin>>r;
  long long x = 1;
  long long y = r;
  while(x<=r and y>=0)
    {
      if(x*x + y*y < r*r){ans += y+1; x++;}
      else{ y--;}
    }
  cout<<4*ans+1;
}