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
    int repeated_sum;
    int sum = 0;

    // Constructor
    Node() : key(0), left(nullptr), right(nullptr), height(0), count(1), repeat(1), repeated_sum(0), sum(0) {}
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
    //cout << root->sum << endl;
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

void Update_Sum(Node* &node){
    int a, b;
    if(node->right == nullptr){
        b = 0;
    }
    else{
        b = node->right->sum;
    }
    if(node->left == nullptr){
        a = 0;
    }
    else{
        a = node->left->sum;
    }
    node->sum = node->repeated_sum + a + b;
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
    int s1 = Z->left ? Z->left->sum : 0;
    Node* T = Y->left;
    int c2 = Y->left ? Y->left->count : 0;
    int s2 = Y->left ? Y->left->sum : 0;
    int c3 = Z->count;
    int s3 = Z->sum;
    //cout << "Left Rotate-> s1 = " << s1 << " s2 = " << s2 << " s3 = " << s3 << endl;
    Y->left = Z;
    Z->right = T;

    Y->count = c3;
    Y->sum = s3;

    Z->count = c1 + c2 + Z->repeat;
    Z->sum = s1 + s2 + Z->repeated_sum;

    Height(Z);
    Height(Y);
    //cout << "(after rotation) node->count of " << Z->key << " = "  << Z->sum << endl;
    return Y;
}

Node* Right_Rotate(Node* &Z){
    Node* Y = Z->left;
    int c1 = Z->right ? Z->right->count : 0;
    int s1 = Z->right ? Z->right->sum : 0;
    Node* T = Y->right;
    int c2 = Y->right ? Y->right->count : 0;
    int s2 = Y->right ? Y->right->sum : 0;
    int c3 = Z->count;
    int s3 = Z->sum;
    //cout << "RIght Rotate-> s1 = " << s1 << " s2 = " << s2 << " s3 = " << s3 << endl;
    Y->right = Z;
    Z->left = T;

    Y->count = c3;
    Y->sum = s3;

    Z->count = c1 + c2 + Z->repeat;
    Z->count = s1 + s2 + Z->repeated_sum;
    Height(Z);
    Height(Y);
    //cout << "(after rotation) node->count of " << Z->key << " = "  << Z->sum << endl;
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
        //cout << X << endl;
        Node* add = New_Node();
        add->key = X;
        add->height = 0;
        add->sum += X;
        add->repeated_sum += X;
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
        //cout << "Let's Start baby" << endl;
        //cout << "Inserting and equal" << X << endl;
        node->count++;
        //cout << "Repeat ho raha aur uske pehle: " << node->repeated_sum << endl;
        node->repeat++;
        node->sum += X;
        node->repeated_sum += X;
        //cout << "Update ke baad: " << node->repeated_sum << endl;
        Update_Count(node);
        Update_Sum(node);
        return node;
    }
    Height(node);
    //cout << "(before update) node->count of " << node->key << " = "  << node->sum << endl;
    Update_Count(node);
    Update_Sum(node);
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
        root->repeated_sum -= X;
        root->sum -= X;
        //cout << "AAAAAAAAH " << root->repeat << endl;
        //cout << "FASTERRR " << root->count << endl;
        if(root->repeat > 0){
            Update_Sum(root);
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
                swap(root->repeated_sum, temp->repeated_sum);
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
            swap(root->repeated_sum, temp->repeated_sum);
            Update_Count(temp);
            Update_Sum(temp);
            Update_Count(root);
            Update_Sum(root);
            root->left = Delete(root->left, temp->key);
        }
    }
    if(root == nullptr){
        return root;
    }
    //cout << root->key << " PUSSHHH " << root->count << " SLOOWWWWW " << root->repeat << endl;
    Height(root);
    Update_Sum(root);
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

int Prefix_Sum(Node* root, int X){
    int prefix_sum = 0;
    Node* travel = New_Node();
    travel = root;
    while(travel != nullptr){
        if(X < travel->key){
            travel = travel->left;
        }
        else if(X > travel->key){
            prefix_sum += travel->sum;
            if(travel->right != nullptr){
                prefix_sum -= travel->right->sum;
            }
            travel = travel->right;
        }
        else{
            if(travel->left != nullptr){
                prefix_sum += travel->left->sum;
            }
            travel = travel->right;
        }
        //cout << prefix_sum << endl;
    }
    return prefix_sum;
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
    int X, Y;
    cout << "The key of the node that is to be deleted -> ";
    cin >> X;
// Here since we need to maintain the AVL Property, we can't directly search and delete a node
// Therefore we don't need to use Search()
// We'll call Delete recursively
    root = Delete(root, X);
    cout << "The Inorder Traversal -> ";
    Inorder_Traversal(root);
    cout << endl;
    cout << "The Level Order Traversal -> ";
    Level_Order_Traversal(root);
    cout << endl;
    cout << "Input the range between which you want to find the sum: ";
    cin >> X >> Y; 
    //Update_Count_Using_Post_Order_Traversal(root);
    //cout << "Count of all -> ";
    //Inorder_Traversal(root);
    //cout << endl;
    int range_sum = Prefix_Sum(root, Y) - Prefix_Sum(root, X);
    cout << "The Sum between the input elements: " << range_sum << endl;
    cout << "The key of the node that is to be deleted -> ";
    cin >> X;
    root = Delete(root, X);
    cout << "The Inorder Traversal -> ";
    Inorder_Traversal(root);
    cout << endl;
    cout << "The Level Order Traversal -> ";
    Level_Order_Traversal(root);
    cout << endl;
    //Update_Count_Using_Post_Order_Traversal(root);
    cout << "Input the range between which you want to find the sum: ";
    cin >> X;
    //Update_Count_Using_Post_Order_Traversal(root);
    //cout << "Count of all -> ";
    //Inorder_Traversal(root);
    //cout << endl;
    range_sum = Prefix_Sum(root, Y) - Prefix_Sum(root, X);
    cout << "The Sum between the input elements: " << range_sum << endl; 
    return 0;
}
