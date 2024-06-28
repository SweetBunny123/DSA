#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        long long n, k;
        cin >> n >> k;
        long long maxsum = 0;
        vector<int> ans(n);
        int j = 1;
        for(int i= n; i>=1; i--)
        {
            maxsum += abs(i-j);
            j++;
        }
        // Check if k is achievable
        if (maxsum < k || k % 2 != 0) {
            cout << "NO" << endl;
        } else {
            if(n%2== 0)
            {
                int val = n-1;
                int strt = 0;
                int end = n-1;
                long long min = 1;
                long long max = n;
                while(strt<=end)
                {
                    if(k>= val*2)
                    {
                        ans[strt] = max;
                        ans[end] = min;
                        k-= val*2;
                        strt++;
                        end--;
                        min++;
                        max--;
                    }
                    else
                    {
                        if(k%4== 0)
                        {
                            ans[end] = max;
                            end--;
                            max--;
                            val--;
                            continue; 
                        }
                        ans[strt] = min;
                        ans[end]  = max;
                        min++;
                        max--;
                        strt ++;
                        end--;
                    }
                    val -= 2;
                }

            }
            else
            {
                int val = n-1;
                int strt = 0;
                int end = n-1;
                long long min = 1;
                long long max = n;
                while(strt<=end)
                {
                    if(k>= val*2)
                    {
                        ans[strt] = max;
                        ans[end] = min;
                        k-= val*2;
                        strt++;
                        end--;
                        min++;
                        max--;
                    }
                    else
                    {
                        if(k%4!= 0)
                        {
                            ans[end] = max;
                            end--;
                            max--;
                            val--;
                            continue; 
                        }
                        ans[strt] = min;
                        ans[end]  = max;
                        min++;
                        max--;
                        strt ++;
                        end--;
                    }
                    val -= 2;
                }

            }
            cout<<"YES"<<endl;
            for(int i =0 ;i< ans.size();i ++)
            {
                cout<<ans[i]<<" ";

            }cout<<endl;
        }
    }
    return 0;
}
