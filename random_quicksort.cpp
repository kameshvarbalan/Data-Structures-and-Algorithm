#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 
	for (int j = low; j <= high - 1; j++) 
	{
		if (arr[j] <= pivot) {
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

int partition_r(int arr[], int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);
	return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high){
		int mid = partition_r(arr, low, high);
		quickSort(arr, low, mid - 1);
		quickSort(arr, mid + 1, high);
	}
}

int main()
{
	int n;
    cout<<"Enter number of elements in the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
	quickSort(arr, 0, n - 1);
	cout<<"\nSorted Array : ";
	for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	return 0;
}