#include <iostream>
using namespace std;

bool isValid(int row, int col, int board[]){
    for(int i=0; i<row; i++){
        if(board[i]==col || abs(board[i]-col)==abs(i-row)){
            return false;
        }
    }
    return true;
}

void backtrack(int board[], int n, int row, bool& ans){
    if(ans){
        return;
    }
    if(row==n){
        for(int i=0; i<n; i++){
            cout<<i<<","<<board[i]<<" ";
        }
        cout<<endl;
        ans = true;
        return;
    }
    for(int col=0; col<n; col++){
        if(isValid(row, col, board)){
            board[row]=col;
            backtrack(board, n, row+1, ans);
        }
    }
}

int main(){
    int n;
    cout<<"Enter number of queens : ";
    cin>>n;
    int board[n];
    for(int i=0;i<n;i++){
        board[i]=-1;
    }
    bool answer = false;
    backtrack(board, n, 0, answer);
    return 0;
}