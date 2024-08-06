#include <iostream>
using namespace std;

bool rk_number(string text, string pattern, int q, int d = 10){
    int n = text.length();
    int m = pattern.length();
    int h = (int)pow(d, m-1) % q;
    int p = 0, t = 0;
    bool flag = false;
    for(int i=0; i<m; i++){
        p = (d * p + int(pattern[i])-48)%q;
        t = (d * t + int(text[i])-48)%q;
        cout<<"i = "<<i+1<<" ~ p = "<<p<<" t = "<<t<<endl;
    }
    cout<<"\n";
    for(int s=0; s<=n-m; s++){
        if(p==t && text.substr(s, m) == pattern){
            cout<<"\nPattern found at "<<s<<"\n\n";
            flag = true;
        }
        if(s<=n-m){
            t = (d*(t-((int(text[s])-48)*h))+int(text[s+m])-48)%q;
            cout<<"s = "<<s+1<<" ~ t = "<<t<<endl;
        }
    }
    return flag;
}

int main(){
    int q;
    string text, pattern;
    cout<<"Enter pattern : ";
    cin>>pattern;
    cout<<"Enter text : ";
    cin>>text;
    cout<<"Enter divisor : ";
    cin>>q;
    bool res = rk_number(text, pattern, q);
    if(!res){
        cout<<"\nPattern not found\n";
    }
    return 0;
}