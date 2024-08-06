#include <iostream>
#include <algorithm>
using namespace std;

struct Item{
    double weight, profit;
};

bool compare_ratio(Item a, Item b){
    return (a.profit/a.weight) > (b.profit/b.weight);
}

void knapsack_ratio(int capacity, Item arr[], int n){
    sort(arr, arr+n, compare_ratio);
    double profit = 0.0;
    cout<<"Weight\tProfit"<<endl;
    for(int i=0; i<n;i++){
        if(arr[i].weight<=capacity){
            profit += arr[i].profit;
            capacity -= arr[i].weight;
            cout<<arr[i].weight<<"\t\t"<<arr[i].profit<<endl;
        }
        else{
            double fraction = arr[i].profit / arr[i].weight;
            profit += fraction*capacity;
            cout<<arr[i].weight<<"\t\t"<<fraction*capacity<<endl;
            break;
        }
    }
    cout<<"Profit = "<<profit<<endl;
}

int main(){
    int n, capacity;
    cout<<"Capacity of KnapSack : ";
    cin>>capacity;
    cout<<"Total number of items : ";
    cin>>n;
    Item arr[n];
    for(int i=0;i<n;i++){
        cout<<"Weight and profit of item "<<i+1<<" : ";
        cin>>arr[i].weight>>arr[i].profit;
    }
    cout<<"\nBy Ratio\n";
    knapsack_ratio(capacity, arr, n);
    return 0;
}