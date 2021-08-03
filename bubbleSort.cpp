#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr) {
    const int sizeArray = (int)arr.size();
    for(int i = 0; i < sizeArray; ++i) {
        for(int j = 1; j < sizeArray; ++j) {
            if(arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
    bubbleSort(arr);
    for(auto &i : arr) cout << i << ' ';
}
