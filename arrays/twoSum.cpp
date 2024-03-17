#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Enter array length: " << endl;
    int length; cin >> length; 
    cout << "Enter array numbers separated by spaces:" << endl;
    vector<int> array(length);
    for(int i=0; i<length; i++)
        cin >> array[i];

    cout << "Enter target sum: " << endl;
    int target; cin >> target;

    unordered_set<int> numberSet;
    for(auto num: array) numberSet.insert(num);
    for(int i=0; i<length; i++){
        bool complementExists = numberSet.count(target-array[i]);
        if(complementExists){
            cout <<  "Two Sum exists" << endl;
            return 0;
        }
    }
    cout <<  "Two Sum doesnt exist" << endl;
    return 0;
}