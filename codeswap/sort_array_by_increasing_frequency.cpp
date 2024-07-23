#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int>& arr){
    int maxElementInArray = *max_element(arr.begin(), arr.end());
    vector<int> countArray(maxElementInArray+1);

    // calculate frequencies
    for(auto &number: arr)
        countArray[number]++;

    // calculate prefix sum of frequencies
    for(int i=1; i<=maxElementInArray; i++)
        countArray[i] += countArray[i-1];

    vector<int> sortedArray(arr.size(), 0);

    for(int i=0; i<arr.size(); i++){
        int currentIndex = i;
        int sortedIndex = countArray[arr[currentIndex]]-1;
        // place the current element in its sorted index
        sortedArray[sortedIndex] = arr[currentIndex];
        // decrement count of current element
        countArray[arr[currentIndex]]--;
    }

    return sortedArray;
}

void printArray(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1, 9, 3, 4, 5, 0, 1, 2, 0 ,3, 6, 9, 1, 3, 5, 6 ,8};
    vector<int> sortedArray = countSort(arr);
    printArray(sortedArray);
    return 0;
}