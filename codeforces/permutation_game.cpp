#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n, k, pb, ps;
        cin>>n>>k>>pb>>ps;
        vector<int>p(n);
        vector<int>a(n);
        for(int i =0; i< n; i++)
        {
            cin>>p[i];
        }
        for(int i =0;  i< n; i++)cin>>a[i];
        int bod = 0; int sas = 0; 
        vector<int>bodo;
        vector<int>sasa;
        while(k--)
        {
            bodo.push_back(a[pb-1]);
            sasa.push_back(a[ps-1]);
            pb = p[pb-1];
            ps = p[ps-1];

        }
        int maxi = bodo[0]; 
        cout<<"bodo"<<endl;
        for(int i =0 ;i<bodo.size();i++)
        {
            cout<<bodo[i]<<" ";
            bod+= maxi;
            if(maxi<bodo[i])maxi  = bodo[i];
        }
        cout<<endl;
        cout<<"sasa"<<endl;
        maxi = sasa[0];
        for(int i =0 ;i< sasa.size(); i++)
        {
            cout<<sasa[i]<<" ";
            sas+= maxi;
            if(maxi<sasa[i])maxi = sasa[i];

        }
        cout<<endl;
        if(bod>sas)cout<<"Bodya"<<endl;
        else if(bod==sas)cout<<"Draw"<<endl;
        else cout<<"Sasha"<<endl;
    }
    return 0;
}