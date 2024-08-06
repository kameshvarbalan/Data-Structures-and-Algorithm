#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node* left; Node *right;
    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};

void buildTree(Node* root, int arr[], int index, int n){
    if(index==n){
        return;
    }
    root->left = new Node(root->val + arr[index]);
    buildTree(root->left, arr, index+1, n);
    root->right = new Node(root->val);
    buildTree(root->right, arr, index+1, n);
}

void subsetSum(vector<string>& ans, string code, Node* root, int target){
    if(!root){
        return;
    }
    else if(!root->left && !root->right && target==root->val){
        ans.push_back(code);
        return;
    }
    else{
        subsetSum(ans, code+"1", root->left, target);
        subsetSum(ans , code+"0", root->right, target);
    }
}

int main(){
    int n, target;
    cout<<"Enter number of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter target : ";
    cin>>target;

    Node* root = new Node(0);
    buildTree(root, arr, 0, n);
    vector<string> ans;
    subsetSum(ans, "", root, target);

    if(ans.size()==0){
        cout<<"There is no possible subset available"<<endl;
    }
    else{
        cout<<"Possible combinations"<<endl;
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}