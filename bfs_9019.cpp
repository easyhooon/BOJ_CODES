#include <bits/stdc++.h>

using namespace std;

bool visited[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{

		int n1, n2;
		cin >> n1 >> n2;

		queue<pair<int, string>> q;
		q.push(make_pair(n1, ""));

		bool visited[10000] = { 0 };
		visited[n1] = true;

		while (!q.empty())
		{
			int num = q.front().first;
			string str = q.front().second;
			q.pop();

			if (num == n2)
			{
				cout << str << "\n";
				break;
			}

			int newNum;

			// D
			newNum = (2 * num) % 10000;
			if (!visited[newNum])
			{
				q.push(make_pair(newNum, str + "D"));
				visited[newNum] = true;
			}

			// S
			newNum = (num - 1) < 0 ? 9999 : num - 1;
			if (!visited[newNum])
			{
				q.push(make_pair(newNum, str + "S"));
				visited[newNum] = true;
			}

			// L
			newNum = (num % 1000 / 100) * 1000 + (num % 1000 % 100 / 10) * 100 + (num % 10) * 10 + (num / 1000);
			if (!visited[newNum])
			{
				q.push(make_pair(newNum, str + "L"));
				visited[newNum] = true;
			}

			// R
			newNum = (num % 10) * 1000 + (num / 1000) * 100 + (num % 1000 / 100) * 10 + (num % 1000 % 100 / 10);
			if (!visited[newNum])
			{
				q.push(make_pair(newNum, str + "R"));
				visited[newNum] = true;
			}
		}
	}
	return 0;
}
