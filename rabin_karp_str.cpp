#include <iostream>
using namespace std;

bool rk_string(string text, string pattern, int prime){
    int pat_hash = 0, text_hash = 0;
    string t = "";
    for(int i=0; i<pattern.length(); i++){
        pat_hash += (int(pattern[i])-96)*(int)pow(prime,i);
        text_hash += (int(text[i])-96)*(int)pow(prime,i);
        t += text[i];
    }
    cout<<"Pattern hash value : "<<pat_hash<<endl;
    bool flag = false;
    for(int i=0; i<=text.length()-pattern.length(); i++){
        cout<<"Text hash value for "<<t<<" : "<<text_hash<<endl;
        if(pat_hash == text_hash && pattern == t){
            cout<<"\nPattern found at "<<i<<"\n\n";
            flag = true;
        }
        if(i<=text.length()-pattern.length()){
            t = t.substr(1);
            t += text[i+pattern.length()];
            text_hash = (text_hash - int(text[i]-96))/prime + (int(text[i+pattern.length()])-96)*(int)pow(prime, pattern.length()-1);
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
    int prime;
    cout<<"Enter prime number for hashing : ";
    cin>>prime;
    bool res = rk_string(text, pattern, prime);
    if(!res){
        cout<<"\n Pattern not found\n";
    }
    return 0;
}