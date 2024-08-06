#include <iostream>
using namespace std;

void lcs(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    int dp[n2 + 1][n1 + 1];
    char arrow[n2][n1];
    for (int i = 0; i <= n1; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n2; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n2; i++) {
        for (int j = 1; j <= n1; j++) {
            if (s1[j - 1] == s2[i - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                arrow[i-1][j-1] = '/';
            } 
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(dp[i-1][j]>=dp[i][j-1]){
                    arrow[i-1][j-1]='|';
                }
                else{
                    arrow[i-1][j-1]='-';
                }
            }
        }
    }
    int tot = dp[n2][n1]-1;
    char ans[tot+1];
    int i = n2-1, j=n1-1;
    while(i>=0 && j>=0){
        if(arrow[i][j]=='/'){
            ans[tot]=s1[j];
            tot-=1;
            i-=1; j-=1;
        }
        else if(arrow[i][j]=='-'){
            j-=1;
        }
        else{
            i-=1;
        }
    }
    for(int i=0;i<dp[n2][n1];i++){
        cout<<ans[i];
    }
    cout<<endl;
}

int main() {
    string s1, s2;
    cout << "Enter string 1 : ";
    cin >> s1;
    cout << "Enter string 2 : ";
    cin >> s2;
    lcs(s1, s2);
    return 0;
}
