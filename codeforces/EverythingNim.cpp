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
        vector<int>arr(n);
        for(int i =0 ;i<n ; i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        vector<int>seted;
        for(int i =0 ;i< arr.size();i ++)
        {
            if(i==0)
            {
                seted.push_back(arr[0]);
            }
            if(arr[i]==seted[seted.size()-1])continue;
            seted.push_back(arr[i]);
        }
        vector<int>b(seted.size());
        b[0] = seted[0];
        for(int i = 1; i<seted.size(); i++)
        {
            b[i] = seted[i]-seted[i-1];
        }
        int winner = 0;
        for(int i =0 ;i < seted.size(); i++)
        {
            if(b[i]==1)winner++;
            else {
                winner++;
                break;
            }
        }
        if(winner%2==0)cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    return 0;
}