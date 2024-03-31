                #include<bits/stdc++.h>
                using namespace std;
                int main()
                {
                    int tc;
                    cin>>tc;
                    while(tc--)
                    {
                        int n;int k;
                        cin>>n>>k;
                        int count = n;
                        int removed = 0;
                        int connections = n-1;
                        if(k>=connections)
                        {
                            cout<<1<<endl;
                        }
                        else
                        {
                            cout<<count<<endl;
                        }
                        // cout<<count-connections<<endl;
                    }
                    return 0;
                }
