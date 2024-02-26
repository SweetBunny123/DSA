#include<bits/stdc++.h>
using namespace std;
int level(vector<int> &h,int i){
    int j=1;
    int l=0;
    while(pow(2,j) -1 <=i){
        j++;
        l++;
    }
    return l;
}


int height(vector<int> &h,int i){
    if(i>h.size()-1){
        return -1;
    }
    int l=level(h,i);
    int cbti=pow(2,l+1)+pow(2,l)-3-i;
    int p=(cbti-1)/2;
    int rc=2*cbti+2;
    int lc=2*cbti+1;
    int hi=max(height(h,lc),height(h,rc))+1;
    return hi;
}

void Topdownheapify(vector<int>&h,int i){
    int c;
    int l=level(h,i);
    int cbti=pow(2,l+1)+pow(2,l)-3-i;
    int p=(cbti-1)/2;
    int rc=2*cbti+2;
    int lc=2*cbti+1;
    while(rc<h.size()){
        if(h[lc]<h[rc]){
            c=lc;
        }
        else{
            c=rc;
        }
        if(h[i]>h[c]){
            swap(h[i],h[c]);
            i=c;
        }
        else{
            i=h.size();
        }
    }
    c=lc;
    if(c<h.size() and h[i]>h[c]){
        swap(h[i],h[c]);
    }
}
void deletemin(vector<int> &h){
    int del_val=h[0];
    swap(h[0],h[h.size()-1]);
    vector<int> :: iterator it=h.end()-1;
    h.erase(it);
    Topdownheapify(h,0);
}
void bottomupheapify(vector<int > &h,int i){
    int l=level(h,i);
    int cbti=pow(2,l+1)+pow(2,l)-3-i;
    int p=(cbti-1)/2;
    int rc=2*cbti+2;
    int lc=2*cbti+1;
    while(p>-1){
        if(h[i]<h[p]){
            swap(h[i],h[p]);
            cbti=p;
            p=(cbti-1)/2;
        }
        else{
            p=-1;
        }
    }
}

void insertx(vector<int> &h,int x){
    h.push_back(x);
    bottomupheapify(h,h.size()-1);
}
void changekey(vector<int> &h,int i,int x){
    if(h[i]<x){
        h[i]=x;
        Topdownheapify(h,i);
    }
    else{
        h[i]=x;
        bottomupheapify(h,i);
    }
}





int lca(vector<int> &h,int i,int j){
    int l1=level(h,i);
    int l2=level(h,j);
    while(l1<l2){
        int cbtj=pow(2,l2+1)+pow(2,l2)-3-j;
        int pj=(cbtj-1)/2;
        j=pj;
        l2--;
    }
    while(l2<l1){
        int cbti=pow(2,l1+1)+pow(2,l1)-3-i;
        int pi=(cbti-1)/2;
        i=pi;
        l1--;
    }
    while(i!=j){
        int cbtj=pow(2,l2+1)+pow(2,l2)-3-j;
        int pj=(cbtj-1)/2;
        j=pj;
        l2--;
        int cbti=pow(2,l1+1)+pow(2,l1)-3-i;
        int pi=(cbti-1)/2;
        i=pi;
        l1--;
    }

    return j;
}



int main(){
    vector<int> h={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int lindex=2;
    cout<<"Level of lindex is - "<<level(h,lindex)<<endl;
    int hindex=0;
    cout<<"Height of index is - "<<height(h,hindex)<<endl;
    int a1=3;
    int a2=4;
    cout<<"Least common ancestor - "<<lca(h,a1,a2);
    return 0;
}