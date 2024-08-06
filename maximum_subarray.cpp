#include <iostream>
using namespace std;

int maxCross(int arr[], int low, int mid, int high){
    int maxMidL = INT_MIN, maxMidR=INT_MIN;
    int sum = 0;
    for(int i = mid; i>=low; i--){
        sum+= arr[i];
        maxMidL = max(maxMidL, sum);
    }
    sum = 0;
    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];
        maxMidR = max(maxMidR, sum);
    }
    return maxMidL + maxMidR;
}

int maxSubarray(int arr[], int low, int high){
    if (low==high){
        return arr[low];
    }
    int mid = (low+high)/2;
    int left = maxSubarray(arr, low, mid);
    int right =  maxSubarray(arr, mid+1, high);
    int middle = maxCross(arr, low, mid, high);
    cout<<left<<' '<<middle<<' '<<right<<endl;
    return max(left, max(right, middle));
    //return max(maxSubarray(arr, low, mid), max(maxSubarray(arr, mid+1, high), maxCross(arr, low, mid, high)));
}

int main(){
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<" : ";
        cin>>arr[i];
    }
    int maxSum = maxSubarray(arr, 0, n-1);
    cout<<"Maximum sum = "<<maxSum<<endl;
    return 0;
}