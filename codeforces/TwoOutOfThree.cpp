#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    map<ll,ll> mp,idx;

    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
        idx[a[i]]=i;
    }
    ll cnt=0;
    ll f=-1;
    for(auto it:mp){
        if(it.second>1){
         cnt++;
         f=it.first;
        }
    }
    if(cnt<2){
        cout<<"-1\n";
        return ;
    }

    vector<int> ans(n,1);

    for(auto it: mp){
        if(it.second > 1){
            ans[idx[it.first]] = 2;
        }
    }
    ans[idx[f]] = 3;

    for(auto c:ans)
    cout<<c<<" ";
    cout<<"\n";

}

int main(){
    ll t;
    cin>>t;
    while(t--)
    solve();

    return 0;
}