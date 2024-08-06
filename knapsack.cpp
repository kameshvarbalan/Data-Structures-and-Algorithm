#include <iostream>
#include <vector>
using namespace std;

struct Item{
    int weight, value;
};

int knapsack(Item arr[], int W, int n) {
    int dp[n + 1][W + 1];
    int select[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            select[i][j]=0;
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (arr[i - 1].weight > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                int include = arr[i - 1].value + dp[i - 1][j - arr[i - 1].weight];
                int exclude = dp[i - 1][j];
                if (include > exclude) {
                    dp[i][j] = include;
                    select[i][j] = 1;
                } else {
                    dp[i][j] = exclude;
                }
            }
        }
    }
    int i = n, w = W;
    vector<int> ans;
    while (i > 0 && w > 0) {
        if (select[i][w] == 1) {
            ans.push_back(i);
            w -= arr[i - 1].weight;
        }
        i--;
    }
    cout << "Selected items" << endl;
    cout << "Item\tWeight\tValue" << endl;
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << "\t" << arr[ans[i] - 1].weight << "\t" << arr[ans[i] - 1].value << endl;
    }
    return dp[n][W];
}

int main(){
    int W, n;
    cout<<"Enter capacity of knapsack : ";
    cin>>W;
    cout<<"Enter number of elements : ";
    cin>>n;
    Item arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter weight and value of item "<<i+1<<" : ";
        cin>>arr[i].weight>>arr[i].value;
    }
    int profit = knapsack(arr, W, n);
    cout<<"Max value : "<<profit<<endl;
    return 0;
}