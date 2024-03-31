#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count = 0; 
        int middlei = 0;
        for(int i = 0; i<n; i++)
        {
            int length = i+1;

            if(s[i]== '0')
            {
                count++;
            }
            if(count>=length/2.0)
            {
              int length_here = i+1;
              if(abs(length/2.0-length_here) < abs(length/2.0-middlei))
              {
                middlei = length_here
              }
            }
        }
        cout<<middlei<<endl;
    }
}