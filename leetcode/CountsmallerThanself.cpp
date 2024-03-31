#include<bits/stdc++.h>
using namespace std;
// since the constraints says that nums[i]< 10000 and nums[i]>-10000 i will create segment tree of size 10^5 
int t[100000];
void<int>update(int si,int ss,int se,int i)//si = current_index 
                                          // ss = starting_index
                                          // se = ending_index 
                                          // i = update_till/from that is if i give the number i want to update till that position
{
    if(ss==se)
    {
      t[si]++;
    }
    int mid = (ss+se)/2;
    if(i<= mid)update(2*si+2,ss,mid,i);// looking for the particular value from which the position has to be updated upwards, in other words looking for the leaf of that position
    else update(2*si+1,mid+1,se,i);// if not in left look right
    t[si] = t[2*si+1]+t[2*si+2];
}
int query(int si,int ss,int se,int qs,int qe){
    if(qs>se||qe<ss) return 0;
    if(qs<=ss&&qe>=se) return t[si];
  // find the total frequency up to a particular number
    int mid=(ss+se)>>1;
    return query(2*si+1,ss,mid,qs,qe)+query(2*si+2,mid+1,se,qs,qe);
}

vector<int> countSmaller(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;i++) nums[i]+=10000;// i increase te vallue to the negeaive offset , so that i can deal with negatie indexes
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
        ans.push_back(query(0,0,20000,0,nums[i]-1));// yes look for the numbers less than the current number 
        update(0,0,20000,nums[i]);// now update the tree to this indes, by addfing from here
    }
    reverse(ans.begin(),ans.end());
    return ans;
}