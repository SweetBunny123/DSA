#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    int x=0;
    int y=0;
    int z=0;
    while(tc--)
    {
        int l,m,n;
        cin>>l>>m>>n;
        x+=l;
        y+=m;
        z+=n;
    }
    if(x == 0 && y==0 && z==0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}