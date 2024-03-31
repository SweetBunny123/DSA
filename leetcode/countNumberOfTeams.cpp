#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void update(int si,int ss,int se,int i, int t[])
{
   if(ss==se)
    {
      t[si]++;
      return;
    }
    int mid = (ss+se)/2;
    if(i<= mid)update(2*si+1,ss,mid,i,t);
    else update(2*si+2,mid+1,se,i,t);// if not in left look right
    t[si] = t[2*si+1]+t[2*si+2];
}
int query(int si,int ss,int se,int qs,int qe,int t[]){
    if(qs>se||qe<ss) return 0;
    if(qs<=ss&&qe>=se) return t[si];
  // find the total frequency up to a particular number
    int mid=(ss+se)>>1;
    return query(2*si+1,ss,mid,qs,qe,t)+query(2*si+2,mid+1,se,qs,qe, t);
}

vector<int> countSmaller_after(vector<int>& nums, int p[]) {

    int n=nums.size();
    for(int i=0;i<n;i++) nums[i]+=10000;// i increase te vallue to the negeaive offset , so that i can deal with negatie indexes
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
        ans.push_back(query(0,0,20000,0,nums[i]-1, p));// yes look for the numbers less than the current number 
        update(0,0,20000,nums[i], p);// now update the tree to this indes, by addfing from here
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> countSmaller_before(vector<int>& nums, int t[]) {

    int n=nums.size();
    for(int i=0;i<n;i++) nums[i]+=10000;// i increase te vallue to the negeaive offset , so that i can deal with negatie indexes
    vector<int>ans;
    for(int i=0;i<n; i++){
        ans.push_back(query(0,0,20000,0,nums[i]-1, t));// yes look for the numbers less than the current number 
        update(0,0,20000,nums[i], t);// now update the tree to this indes, by addfing from here
    }
    return ans;
}
vector<int>countLarger_before(vector<int>&nums, int r[])
{

    int n=nums.size();
    for(int i=0;i<n;i++) nums[i]+=10000;// i increase te vallue to the negeaive offset , so that i can deal with negatie indexes
    vector<int>ans;
    for(int i=0;i<n; i++){
        ans.push_back(query(0,0,20000,nums[i],20000, r));// yes look for the numbers greater than the current number 
        update(0,0,20000,nums[i], r);// now update the tree to this indes, by addfing from here
    }
    return ans;
}
vector<int>countLarger_after(vector<int>&nums, int x[])
{
    int n=nums.size();
    for(int i=0;i<n;i++) nums[i]+=10000;// i increase te vallue to the negeaive offset , so that i can deal with negatie indexes
    vector<int>ans;
    for(int i=n-1;i>=0; i--){
        ans.push_back(query(0,0,20000,nums[i],20000, x));// yes look for the numbers less than the current number 
        update(0,0,20000,nums[i], x);// now update the tree to this indes, by addfing from here
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int numTeams(vector<int>& rating) {
    int ans = 0;
    int x[100005];
    memset(x, 0, sizeof(x));
    vector<int> large = countLarger_after(rating,x);
    for(int i = 0; i<100005; i++)x[i]=0;
    vector<int> small = countSmaller_before(rating,x);
    for(int i = 0; i<large.size(); i++)
    {
        cout<<small[i]<<" ";
    }

    for (int i = 0; i < rating.size(); i++) {
         ans += large[i] * small[i];
    }
    for(int i = 0; i<100005; i++)x[i]=0;
    vector<int> largeDec = countLarger_before(rating,x);
    for(int i = 0; i<100005; i++)x[i]=0;
    vector<int> smallDec = countSmaller_after(rating,x);

    for (int i = 0; i < rating.size(); i++) {
        ans += largeDec[i] * smallDec[i];
    }
    return ans;
}
};
int main() {
    // Example usage
    Solution solution;
    vector<int> ratings = {2,5,3,4,1}; // Example ratings
    int result = solution.numTeams(ratings);
    cout << "Number of teams: " << result << endl;

    return 0;
}
