#include <bits/stdc++.h>

using namespace std;

struct Node{
    int key,value,min,max,sum;
    struct Node* lc;
    struct Node* rc;
};

struct Node* newNode(vector<int> a, int m){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = m;
    node->value = a[m];
    return node;
}

void NodeUpdate(vector<int> a, struct Node* node){
    if(node){
        node->min = node->max = node->key;
        node->sum = node->value;

        if(node->lc){
            if(a[node->lc->min] < a[node->min]) node->min = node->lc->min;
            if(a[node->lc->max] > a[node->max]) node->max = node->lc->max;
            node->sum += node->lc->sum;
        }
        if(node->rc){
            if(a[node->rc->min] < a[node->min]) node->min = node->rc->min;
            if(a[node->rc->max] > a[node->max]) node->max = node->rc->max;
            node->sum += node->rc->sum;
        }
    }
}

struct Node* CreateBBST(vector<int> a, int l, int r){
    struct Node* node = NULL;
    if(l<=r){
        int m = (l+r)/2;
        node = newNode(a,m);
        node->lc = CreateBBST(a,l,m-1);
        node->rc = CreateBBST(a,m+1,r);
        NodeUpdate(a,node);
    }

    return node;
}

void Update(struct Node* node, vector<int> &a, int i, int x){
    if(node){
        if(i < node->key) Update(node->lc,a,i,x);
        else if(i > node->key) Update(node->rc,a,i,x);
        else{
            a[i] = x;
            node->value = x;
        }
        NodeUpdate(a,node);
    }
}

void inOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->lc);
    cout<<root->value<<" ";
    inOrder(root->rc);
}

int PreSum(struct Node* node, int i){
    int sum = 0;
    while(node){
        if(i < node->key){
            node = node->lc;
        }

        else if(i > node->key){
            if(node->lc) sum += node->lc->sum;
            sum += node->value;
            node = node->rc;
        }

        else{
            if(node->lc) sum += node->lc->sum;
            sum += node->value;
            return sum;
        }
    }
    return 0;
}

int RangeMin(vector<int> a, struct Node* node, int l, int r, int s, int e){
    if(node){
        if(l<=s && e<=r) return node->min;
        else if(e < l || r < s) return -1;
        else{
            int min, m1, m = (s+e)/2;

            if(node->key >=l && node->key<=r) min = node->key;
            else min = -1;

            m1 = RangeMin(a,node->rc,l,r,m+1,e);
            if(min<0) min = m1;
            if(min>-1 && m1>-1 && a[m1]<a[min]) min = m1;

            m1 = RangeMin(a,node->lc,l,r,s,m-1);
            if(min<0) min = m1;
            if(min>-1 && m1>-1 && a[m1]<a[min]) min = m1;

            return min;
        }
    }
    return -1;
}

int RangeMax(vector<int> a, struct Node* node, int l, int r, int s, int e){
    if(node){
        if(l<=s && e<=r) return node->max;
        else if(e < l || r < s) return -1;
        else{
            int max, m1, m = (s+e)/2;

            if(node->key >=l && node->key<=r) max = node->key;
            else max = -1;

            m1 = RangeMax(a,node->rc,l,r,m+1,e);
            if(max<0) max = m1;
            if(max>-1 && m1>-1 && a[m1]>a[max]) max = m1;

            m1 = RangeMax(a,node->lc,l,r,s,m-1);
            if(max<0) max = m1;
            if(max>-1 && m1>-1 && a[m1]>a[max]) max = m1;

            return max;
        }
    }
    return -1;
}


int RangeMin(vector<int> a, struct Node* node, int l, int r, int s, int e){
    if(node){
        if(l<=s && e<=r) return node->min;// if i am giving something here, that  means i will just return node-> min
        else if(e < l || r < s) return -1;//out of range
        else{
            int min, m1, m = (s+e)/2;// m here is mid 

            if(node->key >=l && node->key<=r) min = node->key;
            else min = -1;

            m1 = RangeMax(a,node->rc,l,r,m+1,e);
            if(min<0) min = m1;
            if(min>-1 && m1>-1 && a[m1]<a[min]) min = m1;

            m1 = RangeMax(a,node->lc,l,r,s,m-1);
            if(min<0) min = m1;
            if(min>-1 && m1>-1 && a[m1]<a[min]) min = m1;

            return min;
        }
    }
    return -1;
}

int RangeMaxGap(vector<int> a, struct Node* node, int l, int r, int n){
    return a[RangeMax(a,node,l,r,0,n-1)] - a[RangeMin(a,node,l,r,0,n-1)];
}

int main(){
    vector<int> a = {4,8,2,5,1,6};
    int n = a.size()-1;
    struct Node* root = CreateBBST(a,0,n);

    //Update
    Update(root,a,2,3);
    inOrder(root);
    cout<<endl;

    //PreSum
    int sum = PreSum(root,3);
    cout<<sum<<endl;

    //RMQ
    int max = RangeMax(a,root,2,4,0,5);
    cout<<max<<" "<<a[max]<<endl;

    cout<<endl;

    //maxgap
    int max_gap = RangeMaxGap(a,root,2,5,5);
    cout<<max_gap<<endl;

    return 0;
}