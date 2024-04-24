#include<iostream>
using namespace std;
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the number you want to add in array: ";
        cin>>array[i];
    }
    cout<<"Original array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    reverseArray(array, n);
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    return 0;
}