#include <bits/stdc++.h>

using namespace std;
int d[111111];
int board[111111];

int n, m;

queue<int> q;
queue<int> next_queue;

int main() {

	memset(d, -1, sizeof(d));

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	d[n] = 0; 

	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now * 2 <= 100000 && d[now * 2] == -1) {
			d[now * 2] = d[now];
			q.push(now * 2);
		}

		if (now + 1 <= 100000 && d[now + 1] == -1) {
			d[now + 1] = d[now] +1;
			next_queue.push(now +1);
		}

		if (now - 1 >= 0 && d[now - 1] == -1) {
			d[now - 1] = d[now] + 1;
			next_queue.push(now - 1);
		}

		if (q.empty()) {
			q = next_queue;
			next_queue = queue<int>(); //next_queue를 비워준다. 
		}
	}
	cout << d[m] << '\n';

	return 0;
}

