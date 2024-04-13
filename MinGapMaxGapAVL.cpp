#include<bits/stdc++.h>
using namespace std;

// 1 4 21 5 4 6 3 464 35 54 4 5

struct Node{
    int key;
    Node* left;
    Node* right;
    int height;
    int repeat; 
    int min;
    int max;
    int mingap;

    // Constructor
    Node() : key(0), left(nullptr), right(nullptr), height(0), repeat(1), min(0), max(0), mingap(INT_MAX) {}
};

Node* New_Node(){
    Node* node = new Node();
    return node;
}

void Inorder_Traversal(Node* root){
    Node* current = New_Node();
    current = root;
    if(root->left != nullptr){
        current = root->left;
        Inorder_Traversal(current);
    }
    cout << root->key << " ";
    //cout << root->min << " and " << root->max << " --- " << root->mingap << endl;
    if(root->right != nullptr){
        current = root->right;
        Inorder_Traversal(current);
    }
}

void Level_Order_Traversal(Node* root){
    Node* current = New_Node();
    current = root;
    deque<Node*> que;
    que.push_back(current);
    while(!que.empty()){
        if(current->left != nullptr){
            que.push_back(current->left);
        } 
        if(current->right != nullptr){
            que.push_back(current->right);
        }
        cout << que.front()->key << " ";
        que.pop_front();
        current = que.front();
    }
}

void Update_Min(Node* &node){
    int min = node->key;
    if(node->left != nullptr && min > node->left->min){
        min = node->left->min;
    }
    if(node->right != nullptr && min > node->right->min){
        min = node->right->min;
    }
    node->min = min;
}

void Update_Max(Node* &node){
    int max = node->key;
    if(node->left != nullptr && max < node->left->max){
        max = node->left->max;
    }
    if(node->right != nullptr && max < node->right->max){
        max = node->right->max;
    }
    node->max = max;
}

void Update_Mingap(Node* &node){
    int mingap = node->mingap;
    if(node->left != nullptr){
        if(mingap > node->left->mingap){
            mingap = node->left->mingap;
        }
        if(mingap > (node->key - node->left->max)){
            mingap = node->key - node->left->max;
        }
    }
    if(node->right != nullptr){
        if(mingap > node->right->mingap){
            mingap = node->right->mingap;
        }
        if(mingap > (node->right->min - node->key)){
            mingap = node->right->min - node->key;
        }
    }
    node->mingap = mingap;
}

void Height(Node* &node){
    int max = -1;
    if(node->left != nullptr && node->left->height > max){
         max = node->left->height;
    }
    if(node->right != nullptr && node->right->height > max){
        max = node->right->height;
    }
    node->height = max+1;   
}

int Get_Balance(Node* node){
    int a, b;
    if(node->left == nullptr){
        a = -1;
    }
    else{
        a = node->left->height;
    }
    if(node->right == nullptr){
        b = -1;
    }
    else{
        b = node->right->height;
    }
    return a-b;
}

Node* Left_Rotate(Node* &Z){
    Node* Y = Z->right;
    Node* T = Y->left;
    Y->left = Z;
    Z->right = T;
    Update_Min(Z);
    Update_Max(Z);
    Update_Mingap(Z);
    Update_Min(Y);
    Update_Max(Y);
    Update_Mingap(Y);
    Height(Z);
    Height(Y);
    //cout << "(after rotation) node->mingap of " << Z->key << " = "  << Z->mingap << endl;
    return Y;
}

Node* Right_Rotate(Node* &Z){
    Node* Y = Z->left;
    Node* T = Y->right;
    //cout << "RIght Rotate-> c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << endl;
    Y->right = Z;
    Z->left = T;
    Update_Min(Z);
    Update_Max(Z);
    Update_Mingap(Z);
    Update_Min(Y);
    Update_Max(Y);
    Update_Mingap(Y);
    Height(Z);
    Height(Y);
    //cout << "(after rotation) node->mingap of " << Z->key << " = "  << Z->mingap << endl;
    return Y;
}

Node* Left_Right_Rotate(Node* &Z){
    Node* Y = Z->left;
    Z->left = Left_Rotate(Y);
    return (Right_Rotate(Z));
}

Node* Right_Left_Rotate(Node* &Z){
    Node* Y = Z->right;
    Z->right = Right_Rotate(Y);
    return (Left_Rotate(Z));
}

Node* Insert(Node* node, int X){
    if(node == nullptr){
        Node* add = New_Node();
        add->key = X;
        add->height = 0;
        add->min = X;
        add->max = X;
        return add;
    }
    else if(X < node->key){
        //cout << "Inserting " << X << endl;
        node->left = Insert(node->left, X);

    }
    else if(X > node->key){
        //cout << "Inserting " << X << endl;
        node->right = Insert(node->right, X);
    }
    else{
        //cout << "Inserting and equal" << X << endl;
        //node->count++;
        //cout << "Repeat ho raha aur uske pehle: " << node->repeat << endl;
        node->repeat++;
        node->mingap = 0;
        //cout << "Update ke baad: " << node->repeat << endl;
        //Update_Count(node);
        Update_Min(node);
        Update_Max(node);
        //Update_Mingap(node);
        return node;
    }
    Height(node);
    //cout << "(before update) node->mingap of " << node->key << " = "  << node->mingap << " -> " << node->min << " " << node->max << endl;
    Update_Min(node);
    Update_Max(node);
    if(node->repeat == 1){
        node->mingap = INT_MAX;
        Update_Mingap(node);
    }
    else{
        node->mingap = 0;
    }
    //cout << "(after update) node->mingap of " << node->key << " = "  << node->mingap << " -> " << node->min << " " << node->max << endl;
    int balance = Get_Balance(node);
    if(balance > 1){
        if(X <= node->left->key){
            return Right_Rotate(node);
        }
        else{
            return Left_Right_Rotate(node);
        }
    }
    else if(balance < -1){
        if(X > node->right->key){
            return Left_Rotate(node);
        }
        else{
            return Right_Left_Rotate(node);
        }
    }
    //cout << "(after rotation) node->mingap of " << node->key << " = "  << node->mingap << " -> " << node->min << " " << node->max << endl;
    return node;
}

Node* Delete(Node* root, int X){
    if(root == nullptr){
        return root;
    }
    else if(root->key > X){
        root->left = Delete(root->left, X);
    }
    else if(root->key < X){
        root->right = Delete(root->right, X);
    }
    else{
        root->repeat--;
        //cout << "AAAAAAAAH " << root->repeat << endl;
        //cout << "FASTERRR " << root->mingap << endl;
        if(root->repeat > 0){
            if(root->repeat == 1){
                root->mingap = INT_MAX;
                Update_Mingap(root);
            }
            else{
                root->mingap = 0;
            }
            return root;
        }
        if(root->left == nullptr || root->right == nullptr){
            Node* temp = New_Node();
            temp = root->left ? root->left : root->right;
            if(temp == nullptr){
                temp = root;
                root = nullptr;
            }
            else{
                //cout << temp->key << " and " << temp->mingap << " and " << temp->repeat << endl;
                //cout << root->key << " and " << root->mingap << " and " << root->repeat << endl;
                root->key = temp->key;
                swap(root->repeat, temp->repeat);
                swap(root->min, temp->min);
                swap(root->max, temp->max);
                swap(root->mingap, temp->mingap);
                if(temp == root->left){
                    root->left = nullptr;
                }
                else{
                    root->right = nullptr;
                }
            }
            delete[] temp;
        }
        else{
            Node* temp = New_Node();
            temp = root;
            temp = temp->left;
            while(temp->right != nullptr){
                temp = temp->right;
            }
            root->key = temp->key;
            swap(root->repeat, temp->repeat);
            Update_Min(root);
            Update_Max(root);
            if(root->repeat == 1){
                root->mingap = INT_MAX;
                Update_Mingap(root);
            }
            else{
                root->mingap = 0;
            }
            Update_Min(temp);
            Update_Max(temp);
            temp->mingap = INT_MAX;
            Update_Mingap(temp);
            root->left = Delete(root->left, temp->key);
        }
    }
    if(root == nullptr){
        return root;
    }
    //cout << root->key << " PUSSHHH " << root->mingap << " SLOOWWWWW " << root->repeat << endl;
    Height(root);
    Update_Min(root);
    Update_Max(root);
    if(root->repeat == 1){
        root->mingap = INT_MAX;
        Update_Mingap(root);
    }
    else{
        root->mingap = 0;
    }
    int balance = Get_Balance(root);

    if(balance > 1){ // Y lc hai Z ka
        if(Get_Balance(root->left) >= 0){ // Isse ye pata chalta ki X(max child of Y) jo hai
                                          // vo Y[max child of Z(jahan par violation hai)]
                                          // ka lc hai
            return Right_Rotate(root);
        }
        else{
            return Left_Right_Rotate(root);
        }
    }
    else if(balance < -1){
        if(Get_Balance(root->right) <= 0){
            return Left_Rotate(root);
        }
        else{
            Right_Left_Rotate(root);
        }
    }
    return root;
}


int main(){
    int n;
    cin >> n;
    vector<int> elements;
    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        elements.push_back(temp);
    }
    Node* root = New_Node();
    root = nullptr;
    for(int i = 0; i<n; i++){
        root = Insert(root, elements[i]);
    }

    // After forming the AVL Tree, we'll have to check if it is BST or not


    cout << "The Inorder Traversal -> ";
    Inorder_Traversal(root);
    cout << endl;
    cout << "The Level Order Traversal -> ";
    Level_Order_Traversal(root);
    cout << endl;

    int X;
    cout << "The key of the node that is to be deleted -> ";
    cin >> X;
    root = Delete(root, X);
    cout << "The Inorder Traversal -> ";
    Inorder_Traversal(root);
    cout << endl;
    cout << "The Level Order Traversal -> ";
    Level_Order_Traversal(root);
    cout << endl;

    cout << "The min gap between the elements = " << root->mingap << endl;
    cout << "The max gap between the elements = " << root->max - root->min << endl;

    cout << "The key of the node that is to be deleted -> ";
    cin >> X;
    root = Delete(root, X);
    cout << "The Inorder Traversal -> ";
    Inorder_Traversal(root);
    cout << endl;
    cout << "The Level Order Traversal -> ";
    Level_Order_Traversal(root);
    cout << endl;

    cout << "The min gap between the elements = " << root->mingap << endl;
    cout << "The max gap between the elements = " << root->max - root->min << endl;

    return 0;
}
