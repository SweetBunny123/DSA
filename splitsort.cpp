#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;cha
    cin>>n;
    while(n)
      {
        int size;
        cin>>size;
        vector<int>v(size,0);
        for(int i = 0; i<size; i++)
          {
            int k;
            cin>>k;
            v[k-1]=i;
          }
        int count = 0;
        for(int i = 1 ; i<size; i++)
          {
            if(v[i-1]>v[i])count++;
          }
        n--;
        cout<<count<<endl;
      }
    
  
  return 0;
}