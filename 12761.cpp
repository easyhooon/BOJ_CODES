#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000;
int d[MAX+1];

int a, b, n, m;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

     queue<int> q;

	memset(d, -1, sizeof(d));

	cin >> a >> b >> n >> m;

	d[n] = 0; 

	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();


        if (now == m) {
            cout << d[m] << '\n';
            return 0;
        }

		if (now * a <= MAX && d[now * a] == -1) {
			d[now * a] = d[now] + 1;
			q.push(now * a);
		}

        if (now * b <= MAX && d[now * b] == -1) {
			d[now * b] = d[now] + 1;
			q.push(now * b);
		}

        if (now + a <= MAX && d[now + a] == -1) {
			d[now + a] = d[now] + 1;
			q.push(now + a);
		}

        if (now - a >= 0 && d[now - a] == -1) {
			d[now - a] = d[now] + 1;
			q.push(now - a);
		}

        if (now + b <= MAX && d[now + b] == -1) {
			d[now + b] = d[now] + 1;
			q.push(now + b);
		}

        if (now - b >= 0 && d[now - b] == -1) {
			d[now - b] = d[now] + 1;
			q.push(now - b);
		}

		if (now + 1 <= MAX && d[now + 1] == -1) {
			q.push(now + 1);
		}

		if (now - 1 >= 0 && d[now - 1] == -1) {
			d[now - 1] = d[now] + 1;
			q.push(now - 1);
		}
	}

	return 0;
}
