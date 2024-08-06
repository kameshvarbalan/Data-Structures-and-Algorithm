#include <iostream>
#include <string>
using namespace std;

long karatsuba(long x, long y){
    if (x<10 && y<10){
        return x*y;
    }
    int size = max(to_string(x).length(), to_string(y).length());
    int n = ceil(size/2.0);

    long power = (long)pow(10, n);
    long xh = (long)x/power;
    long xl = (long)x%power;
    long yh = (long)y/power;
    long yl = (long)y%power;

    
    long a = karatsuba(xh, yh);
    long d = karatsuba(xl, yl);
    long e = karatsuba(xh+xl, yh+yl) - a - d;
    long answer = (long)pow(10, 2*n)*a+pow(10, n)*e+d;
    
    cout<<"X = "<<x<<" "<<"Y = "<<y<<endl;
    cout<<"xh = "<<xh<<" "<<"xl = "<<xl<<" "<<"yh = "<<yh<<" "<<"yl = "<<yl<<endl<<"\n";
    cout<<"a = "<<a<<" "<<"d = "<<d<<" "<<"e = "<<e<<endl;
    cout<<"Ans = "<<answer<<"\n\n";
    return answer;
}

int main(){
    long x,y;
    cout<<"Enter x : ";
    cin>>x;
    cout<<"Enter y : ";
    cin>>y;
    cout<<"\n";
    long answer = karatsuba(x, y);
    cout<<"\nProduct = "<<answer<<endl;
    return 0;
}