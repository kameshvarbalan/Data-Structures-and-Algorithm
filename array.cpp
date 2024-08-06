#include <iostream>
using namespace std;

const int MAX = 5;

class Array
{
    private:
    int arr[MAX];

    public:
    void insert(int pos , int num);
    void del(int pos);
    void reverse();
    void display();
    void search(int num);
};

void Array::insert(int pos , int num)
{
    for (int i = MAX-1 ; i>= pos ; i--)
    arr[i] = arr[i-1];
    arr[pos]=num;
}

void Array::del(int pos)
{
    for (int i = pos ; i < MAX-1 ; i++)
    arr[i] = arr[i+1];
    arr[MAX-1] = 0;
}

void Array::reverse()
{
    for (int i = 0 ; i < MAX/2 ; i++)
    {
        int temp = arr[i];
        arr[i] = arr[MAX-1-i];
        arr[MAX-i-1] = temp;
    }
}

void Array::search(int num)
{
    for (int i = 0; i < MAX ; i++)
    {
        if (arr[i] == num){
            cout <<"\n The element is present at " << i+1 <<"th position\n";
            return;
        }
        if (i==MAX)
        cout<<"The element is not present in the array";
    }
}

void Array::display()
{
    cout <<endl ; 
    for (int i = 0 ; i < MAX ; i++)
    cout <<" " <<arr[i];
}

int main()
{
    Array a;
    a.insert(0,15);
    a.insert(1,11);
    a.insert(2,12);
    a.insert(3,13);
    a.insert(4,14);
   

    a.display();
    a.del(3); a.del(2);
    a.display();
    a.insert(2,2); a.insert(3,5);
    a.display();

    a.reverse();
    a.search(15);
    a.display();

    return 0;
}