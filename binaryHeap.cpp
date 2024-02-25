#include<bits/stdc++.h>
using namespace std;
void bottom_up_heapify(vector<int>&heap, int i )
{
    int parent = (i-1)/2;
    while(i>0 && heap[i]<heap[parent])
      {
        swap(heap[i], heap[parent]);
      }
}
int shortestPath(vector<int>&heap, int i, int j)
{
  int c = 0; 
  while(i!=j)
    {
      if(i<j)
      {
        j = (j-1)/2;
      }
      else
      {
        i = (i-1)/2;
      }
      c++;
    }
  return c;
}
int levelHeap(vector<int>&heap, int i, int k)
{
  int level = 0; 
  while(i>0)
    {
      i = (i-1)/k;
      level ++;
    }
  return level;
}

int height(vector<int>&heap, int i)
{
  int n = heap.size();
  int h;
  if(i>n-1)
  {
    return -1;
  }
  h = 1+ max(height(heap, 2*i+1), height(heap, 2*i+2));
  return h;
}
int heightBetter(vector<int>&heap, int i)
{
  int height;
  if(i>heap.size()-1)
  {
    return -1;
  }
  while(i<heap.size())
    {
      i= 2*i+1;
      height ++;
    }
  return height;
}
int leastCommonAncestor(vector<int>&heap, int i , int j, int k)
{
  int l1 = levelHeap(heap, i, k);
  int  l2 = levelHeap(heap, j, k);
  while(l1<l2)
    {
      j = (j-1)/k;
      l2--;
    }
  while(l1>l2)
    {
      i = (i-1)/k;
      l1--;
    }
  while(i!=j)
    {
      i = (i-1)/k;
      j = (j-1)/k;
    }
    return heap[i];
}


int leastCommonAncestorArray(vector<int>& heap, vector<int>& arrOfIndex, int k) {   vector<pair<int, int>> v;
    int minlevel = INT_MAX;                      
    for(int i = 0; i < arrOfIndex.size(); i++) {
        int level = levelHeap(heap, arrOfIndex[i], k);
        minlevel = min(minlevel, level);
        v.push_back(make_pair(level, arrOfIndex[i]));
    }                                                                          
    for(int i = 0; i < v.size(); i++) {
        while(v[i].first > minlevel) {
            v[i].second = (v[i].second - 1) / k;
            v[i].first--;
        }
    }
    bool allSame = false;
    int commonAncestor = -1;
    while(!allSame) {
        allSame = true;
        commonAncestor = v[0].second;
        for(int i = 1; i < v.size(); i++) {
            if(v[i].second != commonAncestor) {
                allSame = false;
                break;
            }
        }
        if(allSame) {
            return commonAncestor;
        }
        for(int i = 0; i < v.size(); i++) {
            v[i].second = (v[i].second - 1) / k;
        }
    }
    return commonAncestor;
}

int leastCommonAncestorBetter(vector<int>&heap, int i , int j, int k){
  while(i!=j)
    {
      if(i>j)i = (i-1)/k;
      else j = (j-1)/k;
    }
  return heap[i];
}


void top_down_heapify(vector<int> &heap, int i) {
    int c;
    while (2 * i + 1 < heap.size()) { // Change the termination condition
        if (2 * i + 2 < heap.size() && heap[2 * i + 1] > heap[2 * i + 2]) {
            c = 2 * i + 2;
        } else {
            c = 2 * i + 1;
        }
        if (heap[i] > heap[c]) {
            swap(heap[i], heap[c]);
        }
        i = c;
    }
}


void insert(vector<int>&heap, int n)
{
    heap.push_back(n);
    int i = heap.size() -1;
    bottom_up_heapify(heap, i);
}


void del_min(vector<int>&heap)
{
    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    top_down_heapify(heap, 0);
}


int main()
{   vector<int>myheap = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int> min_heap = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    vector<int> heap = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190};
    vector<int>elements = {31, 8, 10, 36};
    // cout<<leastCommonAncestor(min_heap, 6, 11)<<endl;
    // cout<<leastCommonAncestorBetter(min_heap, 6, 11)<<endl;
    cout<<leastCommonAncestorArray(min_heap, elements, 5)<<endl;
    // cout<<levelHeap(myheap, 4)<<endl;
    // cout<<height(myheap, 1)<<endl;
  //   insert(myheap, 43);
  //   for(int i=0; i<myheap.size(); i++)
  //     {
  //       cout<<myheap[i]<<" ";
  //     }
  // cout<<endl;
  // del_min(myheap);
  // for(int i=0; i<myheap.size(); i++)
  //   {
  //     cout<<myheap[i]<<" ";
  //   }
  return 0;
}
