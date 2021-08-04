#include <bits/stdc++.h>
using namespace std;

set<int> towns;
int minLen = 1e9;
int n;

void findWays(vector<vector<int>> &matrix, int wayLen, int cnt, int lastVertex) {
    if(cnt == n) {
        minLen = min(minLen, wayLen + matrix[lastVertex][0]);
        return;
    }
    set<int> saveTowns = towns;
    for(auto &i : saveTowns) {
        towns.erase(i);
        findWays(matrix, wayLen + matrix[lastVertex][i], cnt + 1, i);
        towns.insert(i);
    }
}


int main() {
    cin >> n;
    if(n < 0) {
        cout << "Error!";
        return 0;
    }
    vector<vector<int>> matrix(n, vector<int> (n, 0));
    for(auto &i : matrix)
        for(auto &j : i)
            cin >> j;
    for(int i = 0; i < n; i++)
        towns.insert(i);
    findWays(matrix, 0, 0, 0);
    if(minLen == 1e9) minLen = 0;
    cout << minLen;
}
