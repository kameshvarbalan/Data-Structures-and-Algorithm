#include <iostream>
using namespace std;

void printParentheses(int i, int j, int *bracket[], char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParentheses(i, bracket[i][j] - 1, bracket, name);
    printParentheses(bracket[i][j], j, bracket, name);
    cout << ")";
}


void matrixChainMultiplication(int order[], int n){
    int matrix[n-1][n-1], **bracket;
    bracket = new int*[n-1];
    for (int i = 0; i < n-1; i++) {
        bracket[i] = new int[n-1];
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            matrix[i][j] = 0;
            bracket[i][j] = 0;
        }
    }

    for(int len = 2; len < n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            matrix[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int cost = matrix[i][k] + matrix[k + 1][j] + order[i] * order[k + 1] * order[j + 1];
                if (cost < matrix[i][j]) {
                    matrix[i][j] = cost;
                    bracket[i][j] = k+1; 
                }
            }
        }
    }

    cout << "Optimal Parenthesis placement: ";
    char name = 'A';
    printParentheses(0, n-2, bracket, name); 
    cout << "\nMinimum number of scalar multiplications: " << matrix[0][n-2] << endl;
}

int main() {
    int n;
    cout<<"Enter number of matrices : ";
    cin>>n;
    cout<<"Enter the order : ";
    int order[n+1];
    for(int i=0;i<=n;i++){
        cin>>order[i];
    }
    matrixChainMultiplication(order, n+1);
    return 0;
}
