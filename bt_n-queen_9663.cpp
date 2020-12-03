#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;
int n;
int vx[MAX + 1], vy[MAX + 1];

int bt(int y, int x)
{
	//����ġ��(back tracking)
	for (int i = 0; i < y; i++)
	{
		//���� ��ħ
		if (y == vy[i])
			return 0; //������ġ ��ħ->����
		if (x == vx[i])
			return 0; //������ġ ��ħ->����
		if (abs(x - vx[i]) == abs(y - vy[i]))
			return 0; //�밢����ġ ��ħ->����
	}

	//���� ����
	if (y == n - 1)
	{
		//���������� �� �迭�� ���������� üũ
		//����
		return 1;
	}

	//���� ��ġ ������ ���
	vy[y] = y, vx[y] = x;

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += bt(y + 1, i);
	}
	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += bt(0, i);
	}
	cout << ans << '\n';

	return 0;
}