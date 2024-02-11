#include<bits/stdc++.h>
using namespace std;

int main()
{

  int n;
  cin>>n;
  vector<pair<long, long>>coordinates(n);
  map<long long, long long>x;
  map<long long, long long>y;
  map<long long, long long>sum;
  map<long long, long long>diff;
  for(int i=0; i<n; i++)
    {
      cin>>coordinates[i].first>>coordinates[i].second;
      x[coordinates[i].first]++;
      y[coordinates[i].second]++;
      sum[coordinates[i].first+coordinates[i].second]++;
      diff[coordinates[i].second-coordinates[i].first]++;

    }
long long ans = 0;
for(auto i : x)
{
    ans+=i.second*(i.second-1);
}
for(auto j : y)
{
    ans+=j.second*(j.second-1);
}
for(auto x : sum)
{
    ans+=x.second*(x.second-1);
}
for(auto x : diff)
{
    ans+=x.second*(x.second-1);
}

cout<<ans<<endl;


  return 0;
}