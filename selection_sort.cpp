#include <iostream>
using namespace std;

int main()
{
    int a[] = {2,4,1,5,3};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i<n-1;i++)
    {
        int min = i;
        for(int j = i+1 ; j < n ; j++)
        {
            if (a[j]<a[min]){
            min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    for (int i = 0 ; i < n ; i++)
    cout << a[i] <<" ";
}