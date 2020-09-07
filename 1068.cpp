#include <bits/stdc++.h>
using namespace std;

#define MAX 51

int n, num, root_node, node, result = 0;

vector<int> v[MAX];
//�⺻ �� (0)���� �ʱ�ȭ�� MAX���� ���Ҹ� ������ vector v�� ����

bool check[MAX];

void bfs(int start)
{
	check[start] = true;
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		node = q.front();
		q.pop();

		int child_count = 0;
		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];

			if (!check[next])
			{
				child_count++;
				check[next] = true;
				q.push(next);
			}
		}
		//�ڽ��� ������ result�� ��� 1����
		if (child_count == 0)
		{
			result++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num != -1)
		{
			v[num].push_back(i);
			v[i].push_back(num);
		}
		else
		{
			root_node = i;
		}
	}

	cin >> num;
	check[num] = true;

	if (!check[root_node])
		bfs(root_node);

	cout << result << endl;
	return 0;
}
