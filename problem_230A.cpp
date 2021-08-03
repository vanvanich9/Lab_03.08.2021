#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            if(x[j - 1] > x[j]) {
                swap(x[j - 1], x[j]);
                swap(y[j - 1], y[j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(s > x[i]) s += y[i];
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
