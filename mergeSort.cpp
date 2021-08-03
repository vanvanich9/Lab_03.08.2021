#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &leftArr, vector<int> &rightArr, vector<int> &sortedArr) {
    const int sizeLeftArr = (int)leftArr.size();
    const int sizeRightArr = (int)rightArr.size();
    const int sizeSortedArr = (int)sortedArr.size();
    int l = 0, r = 0;
    while(l + r < sizeSortedArr) {
        if(r == sizeRightArr) {
            sortedArr[l + r] = leftArr[l];
            l++;
        } else if(l == sizeLeftArr) {
            sortedArr[l + r] = rightArr[r];
            r++;
        } else {
            if(leftArr[l] < rightArr[r]) {
                sortedArr[l + r] = leftArr[l];
                l++;
            } else {
                sortedArr[l + r] = rightArr[r];
                r++;
            }
        }
    }
}

void mergeSort(vector<int> &arr) {
    const int sizeArr = (int)arr.size();
    if(sizeArr == 1) return;
    vector<int> leftArr (sizeArr / 2), rightArr(sizeArr - sizeArr / 2);
    for(int i = 0; i < sizeArr / 2; ++i)
        leftArr[i] = arr[i];
    for(int i = sizeArr / 2; i < sizeArr; ++i)
        rightArr[i - sizeArr / 2] = arr[i];
    mergeSort(leftArr);
    mergeSort(rightArr);
    merge(leftArr, rightArr, arr);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
    mergeSort(arr);
    for(auto &i : arr) cout << i << ' ';
}
