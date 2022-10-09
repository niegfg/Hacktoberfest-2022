#include<iostream>

using namespace std;

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

void printsubarray(int arr[], int n){

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         // cout << arr[j] << ", ";

    //         // cout << "(" << i <<"," << j << "); ";

    //         for(int k = i; k<=j; k++){
    //             // cout << "(" << i << ", " << j << "); ";
    //             cout << arr[k] << ", ";

    //         }
    //         cout<<endl;
    //     }
    // }

    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(arr[k], sum+arr[k]);
        best = max(best, sum);
    }
    cout << best << "\n";
}

int main(){
    int arr[] = {1, 2, -3, 4, -5};
    int n = sizeof(arr)/sizeof(int);

    printsubarray(arr, n);

    return 0;
}