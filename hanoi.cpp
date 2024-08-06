#include <iostream>
using namespace std;

void hanoi(int n, char from, char mid, char end)
{
    if (n==0)
    return;
    else{
        hanoi(n-1,from,end,mid);
        cout<< "Move disc " << n << " from " << from <<" to "<<end <<endl;
        hanoi(n-1,mid,from,end);
    }
}

int main() {
    int n = 3;
    hanoi(n,'A','B','C');
    return 0;
}