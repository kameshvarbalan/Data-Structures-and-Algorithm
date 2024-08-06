#include <iostream>
using namespace std;

void build_lps(int* lps, string pattern){
    int i=0; lps[0]=0;
    cout<<"i = 0   j = 0   lps[0] = 0"<<endl;
    for(int j=1; j<pattern.length(); j++){
        if(pattern[j]==pattern[i]){
            lps[j]=i+1;
            cout<<"i = "<<i<<"   j = "<<j<<"   lps["<<j<<"] = "<<lps[j]<<endl;
            i++;
        }
        else{
            if(i!=0){
                i = lps[i-1];
                j--;
            }
            else{
                lps[j]=0;
                cout<<"i = "<<i<<"   j = "<<j<<"   lps["<<j<<"] = "<<lps[j]<<endl;
            }
        }
    }
}

bool kmp(string pattern, string text, int* lps){
    bool flag = false;
    int m = pattern.length();
    int n = text.length();
    int i = 0, j = 0;
    while ((n-i) >= (m-j)){
        if(pattern[j]==text[i]){
            cout<<"Comparing pattern["<<j<<"] and text["<<i<<"] - Match"<<endl; 
            i++; j++;
        }
        if(j==m){
            cout<<"\nPattern found at "<<(i-j)<<"th position\n\n";
            j = lps[j-1];
            flag = true;
        }
        else if(i<n && pattern[j]!=text[i]){
            cout<<"Comparing pattern["<<j<<"] and text["<<i<<"] - Mismatch"<<endl;
            if(j!=0){
                cout<<"Reset pattern["<<j<<"] to lps["<<j-1<<"]="<<lps[j-1]<<endl; 
                j = lps[j-1];
            }
            else{
                cout<<"Reset text from "<<i<<" to "<<i+1<<endl;
                i++;
            }
        }
    }
    return flag;
}

int main(){
    string pattern, text;
    cout<<"Enter pattern : ";
    cin>>pattern;
    cin.ignore();
    cout<<"Enter text : ";
    getline(cin, text);
    int *lps;
    lps = new int[pattern.length()];
    build_lps(lps, pattern);
    cout<<"LPS Table = ";
    for(int i=0; i<pattern.length(); i++){
        cout<<lps[i];
    }
    cout<<"\n\n";
    bool res = kmp(pattern, text, lps);
    if(!res){
        cout<<"\nPattern not found"<<endl;
    }
    return 0;
}