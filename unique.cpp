#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    if(n < 0) {
        cout << "The negative size of array cannot be created!";
        return 0;
    }
    for(auto &i : arr)
        cin >> i;
    stable_sort(arr.begin(), arr.end());
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1]) {
            cout << "This array is not unique!";
            return 0;
        }
    }
    cout << "This array is unique!";
}
