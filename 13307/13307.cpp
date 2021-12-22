// C++ program to demonstrate insertion in a BST recursively.
#include <iostream>
using namespace std;
class BST
{
    int key;
    BST *left, *right;

public:
    // Default constructor.
    BST();

    // Parameterized constructor.
    BST(int);

    // Insert function.
    BST* Insert(BST*, int);

    BST* deleteNode(BST*,int);

    BST* minValueNode(BST*);

    BST* searchValue(BST*,int, int&);

    // Inorder traversal.
    void Inorder(BST*);

    // Postorder traversal.
    void Postorder(BST*);

    //void Preorder(BST*);
};

// Default Constructor definition.
BST ::BST()
: key(0)
, left(NULL)
, right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
    key = value;
    left = right = NULL;
}

// Insert function definition.
BST* BST ::Insert(BST* root, int key)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        //TODO
        return new BST(key);
    }
    if(key < root->key){
        root->left = Insert(root->left, key);

    } else {
        root->right = Insert(root->right, key);
    }
    return root;
    // Insert data.
    //TODO
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
    //TODO
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->key <<endl;
    Inorder(root->right);

}

//Postorder traversal function.
void BST ::Postorder(BST* root)
{
    if (!root) {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->key <<endl;
}

//minValueNode
BST* BST::minValueNode(BST* root){
    BST* current = root;

    while (current && current->left!=NULL)
        current = current->left;

    return current;
}
//deleteNode
BST* BST::deleteNode(BST* root,int key){
    if (root == NULL)
        return NULL;
    //TODO
    if(key < root->key){
        root->left = deleteNode(root->left, key);
    } else if(key > root->key){
        root->right = deleteNode(root->right, key);
    } else {
        // 3 case
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        } else if(root->left == NULL && root->right != NULL){
            //  rigth children not empty
            BST* temp = root-> right;
            delete(root);
            return temp;
        } else if (root->left != NULL && root->right == NULL){
            BST* temp = root->left;
            delete(root);
            return temp;
        } else {
            BST* minnode = minValueNode(root->right);
            root->key = minnode->key;
            root->right = deleteNode(root->right, root->key);
        }
    }
    return root;

}
//searchValue
BST* BST::searchValue(BST* root,int key, int& found){
    if (root == NULL){
        found = 0;
        return NULL;
    }
    //TODO
    if(key < root->key){
        root->left = searchValue(root->left, key, found);
    } else if(key > root->key){
        root->right = searchValue(root->right, key, found);
    } else {
        found = 1;
        return root;
    }
    return root;

}
// Driver code
int main()
{
    BST b, *root = NULL;
    string cmd;
    int count = 0;
    while(cin >> cmd){
        if(cmd == "Insert"){
            int x;
            cin >> x;
            if (count == 0)
                root = b.Insert(root,x);
            else
                b.Insert(root,x);
            count+=1;
        }else if(cmd == "Delete"){
            int x;
            cin >> x;
            b.deleteNode(root,x);
            count-=1;
        }else if(cmd == "Inorder"){
            b.Inorder(root);
        }else if(cmd == "Search"){
            int x;
            cin >> x;
            int found = 0;
            if(b.searchValue(root,x, found) && found == 1)
                cout<<"found"<<endl;
            else if(!b.searchValue(root,x, found) || found == 0)
                cout<<"not found"<<endl;
        }else if(cmd == "Postorder"){
            b.Postorder(root);
        }else if(cmd == "exit"){
            return 0;
        }
    }
    return 0;
}

// This code is contributed by pkthapa
// This code is contributed by shivanisinghss2110
