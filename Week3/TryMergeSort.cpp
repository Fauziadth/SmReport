#include <bits/stdc++.h>

using namespace std;

void merging (vector<int>&, vector<int>&, int, int);

void mergeSort(vector<int> &arr, vector<int> &temp, int leftStart, int rightEnd){
    if (leftStart >= rightEnd)return; //checking condition
    
    int mid = (leftStart + rightEnd)/2;
    mergeSort(arr, temp, leftStart, mid);
    mergeSort(arr, temp, mid+1, rightEnd);
    merging(arr, temp, leftStart, rightEnd);
}

void merging(vector<int> &arr, vector<int> &temp, int leftStart, int rightEnd){
    int leftEnd = (leftStart + rightEnd)/2;
    int rightStart = leftEnd + 1;
    
    int size = rightEnd - leftStart + 1;

    int ileft = leftStart; //index for array on the left side
    int iright = rightStart; //index for array on the right side
    int index = leftStart; //index for copying

    while (ileft <= leftEnd && iright <= rightEnd){
        if (arr[ileft] <= arr[iright]){
            temp[index] = arr[ileft];
            ileft++;
        } else {
            temp[index] = arr[iright];
            iright++;
        }
        index++;
    }
    
    //Copying back
    for (int i = 0; i < leftEnd - ileft + 1; i++){
        temp [index+i] = arr[ileft+i];
    }
    for (int i = 0; i < rightEnd - iright + 1; i++){
        temp [index+i] = arr[iright+i];
    }
    for (int i = leftStart; i < leftStart+size; i++){
        arr [i] = temp[i];
    }
}

// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) {
    unsigned long int min = 0, max = 0; //incase the number too large
    for (int i = 0; i<5-1; i++){
        min += arr[i];
    }
    for (int i = 1; i<5; i++){
        max += arr[i];
    }
    cout<<min<<" "<<max;

}

int main(){
    vector<int> arr(5);
    vector<int> temp(5);

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, temp, 0, arr.size()-1);

    miniMaxSum(arr);

    return 0;
}