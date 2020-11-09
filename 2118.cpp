#include <bits/stdc++.h>

using namespace std;

const int MAX = 50000;

int sum[MAX+1];
int n, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ans = 0;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    for(int i = 1; i <= n; i++) {

        int l = i, r = n;

        while (l <= r) {
            int m = (l + r) / 2;
            int a = sum[m] - sum[i - 1];
            int b = sum[n] - a;

            if (a < b) l = m + 1;
            else r = m - 1;

            ans = max(ans, min(a, b));
        }
    }

    cout << ans << '\n';

    return 0;
}