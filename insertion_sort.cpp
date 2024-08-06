#include <iostream>
using namespace std;

int main()
{
    int a[] = {2,4,1,5,3};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i = 1; i<n;i++)
    {
        int key = a[i]; int j=i-1;
        while(a[j]>key && j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }    
    for (int i = 0 ; i < n ; i++)
    cout << a[i] <<" ";
}