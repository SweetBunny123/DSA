#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node* parent; 
};

Node* New_Node(){
    Node* node = new Node();
    return node;
}

void Inorder_Traversal(Node* root){
    Node* current = New_Node();
    current = root;
    if(root->left)Inorder_Traversal(current->left);
    cout << root->key << " ";
    if(root->right != nullptr)Inorder_Traversal(current->right);
}

Node* Search_Equal(Node* root, int X, int &left){
    Node* travel = New_Node();
    travel = root;
    while(travel != nullptr){
        if(travel->key == X){
            return travel;
        }
        else if(travel->key >= X){
            if(travel->left != nullptr){
                left = 1; // left ka kya kaam??
                travel = travel->left;
            }
            else{
                return nullptr;
            }

        }
        else if (travel->key < X){
            if(travel->right != nullptr){
                left = 0;
                travel = travel->right;
            }
            else{
                return nullptr;
            }
        }
    }
}

Node* Search(Node* root, int X, int &left){
    Node* travel = New_Node();
    travel = root;
    while(travel != nullptr){
        if(travel->key >= X){
            if(travel->left != nullptr){
                left = 1;
                travel = travel->left;
            }
            else{
                left = 1;
                return travel;
            }

        }
        else if (travel->key < X){
            if(travel->right != nullptr){
                left = 0;
                travel = travel->right;
            }
            else{
                left = 0;
                return travel;
            }
        }
    }
}

void Insert(Node* &root, int X){
    Node* insertion = New_Node();
    int left = 1;
    insertion = Search(root, X, left);
    Node* add_node = New_Node();
    add_node->key = X;
    add_node->parent = insertion;
    if(insertion != nullptr && left){
        insertion->left = add_node;
    }
    else if(insertion != nullptr && !left){
        insertion->right = add_node;
    }
    else if(insertion == nullptr){
        root = add_node;
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

void Delete(Node* &root, Node* &del, int left){
    if(del->left == nullptr && del->right == nullptr){
        if(left){
            del->parent->left = nullptr;
        }
        else{
            del->parent->right = nullptr;
        }
        del->parent = nullptr;
        delete[] del;
    } 
    else if((del->left != nullptr && del->right == nullptr) || (del->right != nullptr && del->left == nullptr)){
        if(del->left != nullptr){
            if(left){
                del->parent->left = del->left;
                del->left->parent = del->parent;
            }
            else{
                del->parent->right = del->left;
                del->left->parent = del->parent;
            }
            del->parent = nullptr;
            del->left = nullptr;
            //delete[] del;
        }
        else{
            if(left){
                del->parent->left = del->right;
                del->right->parent = del->parent;
            }
            else{
                del->parent->right = del->right;
                del->right->parent = del->parent;
            }
            del->parent = nullptr;
            del->right = nullptr;
            //delete[] del;
        }
        delete[] del;
    }
    else if(del->left != nullptr && del->right != nullptr){
        Node* travel = New_Node();
        travel = del;
        travel = travel->left;
        int c = 0;
        while(travel->right != nullptr){
            travel = travel->right;
            c++;
        }
        if(travel->left == nullptr && travel->right == nullptr){
            if(c > 0){
                travel->parent->right = travel->left;
            }  
            else{
                travel->parent->left = travel->left;
            }
            travel->left = del->left;
            travel->right = del->right;
            travel->parent = del->parent;
            if(del->left != nullptr){
                del->left->parent = travel;
            }
            del->right->parent  = travel;
            if(del->parent != nullptr && left){
                del->parent->left = travel;
            }
            else if(del->parent != nullptr && !left){
                del->parent->right = travel;
            }
            if(del == root){
                root = travel;
            }
            del->left = nullptr;
            del->right = nullptr;
            del->parent = nullptr;
        }
        else{
            if(c > 0){
                travel->parent->right = travel->left;
            }  
            else{
                travel->parent->left = travel->left;
            }
            travel->left->parent = travel->parent;
            travel->parent = del->parent;
            travel->left = del->left;
            travel->right = del->right;
            del->left->parent = travel;
            del->right->parent  = travel;
            if(del->parent != nullptr && left){
                del->parent->left = travel;
            }
            else if(del->parent != nullptr && !left){
                del->parent->right = travel;
            }
            if(del == root){
                root = travel;
            }
            del->left = nullptr;
            del->right = nullptr;
            del->parent = nullptr;
        }
        delete[] del;
    }
}

int main(){
    int n;
    cin >> n;
    int temp;
    vector<int> elements;
    for(int i = 0; i<n; i++){
        cin >> temp;
        elements.push_back(temp);
    }
    Node* root = nullptr;
    for(int i = 0; i<n; i++){
        Insert(root, elements[i]);
    }
    cout << "The Inorder Traversal -> ";
    Inorder_Traversal(root);
    cout << endl;
    cout << "The Level Order Traversal -> ";
    Level_Order_Traversal(root);
    cout << endl;
    int X;
    cout << "The key of the node that is to be deleted -> ";
    cin >> X;
    Node* del = New_Node();
    int left = 1;
    del = Search_Equal(root, X, left);
    if(del == nullptr){
        cout << "Node not present" << endl;
    }
    else{
        Delete(root, del, left);
    }
    cout << "The Inorder Traversal -> ";
    Inorder_Traversal(root);
    cout << endl;
    cout << "The Level Order Traversal -> ";
    Level_Order_Traversal(root);
    cout << endl;
    return 0;   
}
