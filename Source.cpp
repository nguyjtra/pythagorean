#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
bool check(ll a[], int n, ll x) {
    ll right = n - 1;
    ll left = 0;
    while (left <= right) {
        ll mid = (right + left) / 2;
        if (x == a[mid]) return true;
        else if (x > a[mid]) {
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return false;
}

int main() {
    int n; cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        ll k; cin >> k;
        a[i] = k * k;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (check(a, n, a[i] + a[j])) { cout << "YES"; return 0; }
        }
    }
    cout << "NO";
    return 0;
}