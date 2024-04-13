#include<bits/stdc++.h>
using namespace std;

// 1 4 21 5 4 6 3 464 35 54 4 5

struct Node{
    int key;
    Node* left;
    Node* right;
    int height;
    int count;
    int repeat;

    // Constructor
    Node() : key(0), left(nullptr), right(nullptr), height(0), count(1), repeat(1) {}
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
    //cout << root->count << endl;
    if(root->right != nullptr){
        current = root->right;
        Inorder_Traversal(current);
    }
}

void Update_Count(Node* &node){
    int a, b;
    if(node->right == nullptr){
        b = 0;
    }
    else{
        b = node->right->count;
    }
    if(node->left == nullptr){
        a = 0;
    }
    else{
        a = node->left->count;
    }
    node->count = node->repeat + a + b;
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
    int c1 = Z->left ? Z->left->count : 0;
    Node* T = Y->left;
    int c2 = Y->left ? Y->left->count : 0;
    int c3 = Z->count;
    //cout << "Left Rotate-> c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << endl;
    Y->left = Z;
    Z->right = T;
    Y->count = c3;
    Z->count = c1 + c2 + Z->repeat;
    Height(Z);
    Height(Y);
    //cout << "(after rotation) node->count of " << Z->key << " = "  << Z->count << endl;
    return Y;
}

Node* Right_Rotate(Node* &Z){
    Node* Y = Z->left;
    int c1 = Z->right ? Z->right->count : 0;
    Node* T = Y->right;
    int c2 = Y->right ? Y->right->count : 0;
    int c3 = Z->count;
    //cout << "RIght Rotate-> c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << endl;
    Y->right = Z;
    Z->left = T;
    Y->count = c3;
    Z->count = c1 + c2 + Z->repeat;
    Height(Z);
    Height(Y);
    //cout << "(after rotation) node->count of " << Z->key << " = "  << Z->count << endl;
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
        node->count++;
        //cout << "Repeat ho raha aur uske pehle: " << node->repeat << endl;
        node->repeat++;
        //cout << "Update ke baad: " << node->repeat << endl;
        Update_Count(node);
        return node;
    }
    Height(node);
    //cout << "(before update) node->count of " << node->key << " = "  << node->count << endl;
    Update_Count(node);
    //cout << "(after update) node->count of " << node->key << " = "  << node->count << endl;
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
    //cout << "(after rotation) node->count of " << node->key << " = "  << node->count << endl;
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
        root->count--;
        root->repeat--;
        //cout << "AAAAAAAAH " << root->repeat << endl;
        //cout << "FASTERRR " << root->count << endl;
        if(root->repeat > 0){
            Update_Count(root);
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
                //cout << temp->key << " and " << temp->count << " and " << temp->repeat << endl;
                //cout << root->key << " and " << root->count << " and " << root->repeat << endl;
                root->key = temp->key;
                swap(root->repeat, temp->repeat);
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
            Update_Count(temp);
            Update_Count(root);
            root->left = Delete(root->left, temp->key);
        }
    }
    if(root == nullptr){
        return root;
    }
    //cout << root->key << " PUSSHHH " << root->count << " SLOOWWWWW " << root->repeat << endl;
    Height(root);
    Update_Count(root);
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


int Find_Element(Node* root, int rank){
    Node* travel = New_Node();
    travel = root;
    while(travel != nullptr){
        int left_rank = travel->left ? travel->left->count : 0;
        if((rank <= travel->count - left_rank) && (rank > travel->count - left_rank - travel->repeat)){
            return travel->key;
        }
        else if(rank <= travel->count - left_rank - travel->repeat){
            travel = travel->right;
        }
        else if(rank > travel->count - left_rank){
            return Find_Element(travel->left, (rank - travel->count + left_rank));

        }
    }
    return -1;
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

    int element;
    for(int i = 1; i<=n+1; i++){
        element = Find_Element(root, i);
        cout << "The element with rank " << i << " = " << element << endl;
    }

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

    for(int i = 1; i<=n; i++){
        cout << "The element with rank " << i << " = " << Find_Element(root, i) << endl;
    }

    cout << "The key of the node that is to be deleted -> ";
    cin >> X;
    root = Delete(root, X);
    cout << "The Inorder Traversal -> ";
    Inorder_Traversal(root);
    cout << endl;
    cout << "The Level Order Traversal -> ";
    Level_Order_Traversal(root);
    cout << endl;

    for(int i = 1; i<=n; i++){
        cout << "The element with rank " << i << " = " << Find_Element(root, i) << endl;
    }
    return 0;
}
