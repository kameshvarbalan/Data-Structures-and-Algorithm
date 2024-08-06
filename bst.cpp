#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class bst{
    public:

    Node* insert(Node* root,int val){
        if(root==NULL)
        return new Node(val);

        if(val<=root->data)
        root->left = insert(root->left,val);
        else
        root->right = insert(root->right,val);

        return root;
    }

    bool search(Node* root , int key){
        if(root ==NULL)
        return false;

        if(key==root->data)
        return true;
        else if(key<root->data)
        search(root->left,key);
        else
        search(root->right,key);
    }

    Node* minNode(Node* node){
        while(node && node->left!=NULL)
        node = node->left;
        return node;
    }

    Node* delete_node(Node* root,int key){
        if(root==NULL)return NULL;

        if(key<root->data)
        root->left = delete_node(root->left,key);
        else if(key>root->data)
        root->right = delete_node(root->right,key);
        else{
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            //Replaces with the minimum node in the right subtree
            Node* min = minNode(root->right);
            root->data = min->data;
            root->right = delete_node(root->right, min->data);
        }
        return root;
    }

    void inorder(Node* root){
        if(root==NULL)
        return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};

int main(){
    bst ob;
    Node* root = NULL;
    root = ob.insert(root,4);
    root = ob.insert(root,3);
    root = ob.insert(root,2);
    root = ob.insert(root,5);
    root = ob.delete_node(root,4);
    ob.inorder(root);
    return 0;
}