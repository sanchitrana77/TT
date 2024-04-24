#include<iostream>
using namespace std;

void leftRotateArray(int arr[], int n, int d) {
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
}

int main(){
    int N = 6;
    int array[N]={1,2,3,4,5,6};
    cout<<"The original array is: ";
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    int d=2;

    leftRotateArray(array, N, d);

    cout << "Rotated Array: ";
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}