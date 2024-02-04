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
        int sum = 0;
        vector<int>sumarr(n);
        vector<int>result(n);
        map<int, vector<int>>index;
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
            index[arr[i]].push_back(i);
        }
        sort(arr.begin(), arr.end());
        for(int i = 0; i<n; i++)
        {
            sum += arr[i];
            sumarr[i] = sum;
        }
        for(int i = 0; i<n ;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        for(int j = 0; j<n ; j++)
        {
            cout<<sumarr[j]<<" "; 
        }
        cout<<endl;
        for(int i = 0; i<n; i++)
        {
            long long start = lower_bound(arr.begin(), arr.end(),sumarr[i])-arr.begin();
            int s = sumarr[i];
            int count = start-1;
            cout<<"lower bound of "<<sumarr[i]<<" is "<<start<<" count= "<<count<<endl;
            for(int i = start+1; i<n; i++)
            {
                if(arr[i]>s)
                {
                    break;
                }
                else
                {
                    s+= arr[i];
                    count++;
                }
            }
            cout<<"Total count is "<<count<<endl;
            int original_index = index[arr[i]].back();
            result[index[original_index] = count
            index[arr[i]].pop_back();
        }
        for(int i = 0; i<n ; i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;


    }
}