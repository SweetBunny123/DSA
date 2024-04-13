#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    int height;
    int count;

    // Constructor
    Node() : key(0), left(nullptr), right(nullptr), height(0), count(1) {}
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
    Height(Z);
    Height(Y);
    return Y;
}

Node* Right_Rotate(Node* &Z){
    Node* Y = Z->left;
    Node* T = Y->right;
    Y->right = Z;
    Z->left = T;
    Height(Z);
    Height(Y);
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
        node->left = Insert(node->left, X);
    }
    else if(X > node->key){
        node->right = Insert(node->right, X);
    }
    else{
        node->count++;
        return node;
    }
    Height(node);
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
        if(root->count > 0){
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
                root->key = temp->key;
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
            root->left = Delete(root->left, temp->key);
        }
    }
    if(root == nullptr){
        return root;
    }
    Height(root);
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
// Here since we need to maintain the AVL Property, we can't directly search and delete a node
// Therefore we don't need to use Search()
// We'll call Delete recursively
    Node* node = New_Node();
    node = root;
    root = Delete(root, X);
    cout << "The Inorder Traversal -> ";
    Inorder_Traversal(root);
    cout << endl;
    cout << "The Level Order Traversal -> ";
    Level_Order_Traversal(root);
    cout << endl;
    return 0;
}
