#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int h,w,xa,ya,xb,yb;
        cin>>h>>w>>xa>>ya>>xb>>yb;
        int val = abs(xb-xa);
        int direction = yb-ya;
        string ans;
        if(val%2!=0)
        {
            vector<string>result={"Alice", "Draw"};
                int movesAlice = val/2+1;
                int movesBob = val/2;
                if(direction<0)
                {
                    ya = max(ya-movesAlice,1);
                    xa = xa+movesAlice;
                    yb = max(yb-movesBob,1);
                    xb = xb-movesBob;
                }
                else if(direction>0)
                {
                    ya = min(ya+movesAlice,w);
                    xa = xa+movesAlice;
                    yb = min(yb+movesBob,w);
                    xb = xb-movesBob;

                }
                else if(direction==0 && xa<xb)
                {
                    xa=xb;
                    ya=yb;
                }
                if(xa==xb && ya==yb)
                {
                    ans = "Alice";
                }
                else
                {
                    ans = "Draw";
                }
        }
        else
        {   
            int movesAlice = val/2;
            int movesBob = val/2;
                if(direction<0)
                {
                    ya = min(ya+movesAlice,w);
                    xa = xa+movesAlice;
                    yb = min(yb+movesBob,w);
                    xb = xb-movesBob;
                }
                else if(direction>0)
                {
                    ya = max(ya-movesAlice,1);
                    xa = xa+movesAlice; 
                    yb = max(yb-movesBob,1);
                    xb = xb-movesBob;
                }
                else if(direction==0 && xa<xb)
                {
                    xa=xb;
                    ya=yb;
                }
                if(xa==xb && ya==yb)
                {
                    ans = "Bob";
                }
                else
                {
                    ans = "Draw";
                }
        }
    cout<<ans<<endl;
    }
  return 0;
}