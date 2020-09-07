#include <bits/stdc++.h>

using namespace std;

int white[1002], black[1002];
int dp[1002][16][16];
int idx; //0���� �ʱ�ȭ �Ǿ����� 

int napsack(int w, int b, int now)
{
	if (now == idx)
		return 0;

	int &ret = dp[now][w][b];

	if (ret != -1)
		return ret;

	if (w > 0)
		ret = max(ret, napsack(w - 1, b, now + 1) + white[now]);

	if (b > 0)
		ret = max(ret, napsack(w, b - 1, now + 1) + black[now]);

	ret = max(ret, napsack(w, b, now + 1));

	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	int w, b;
	while (cin >> w >> b)
	//Ƚ���� �������� ������ �Է��� �޴� ��� 
	//or scanf("%d %d", &w, &b) != EOF 
	{
		white[idx] = w;
		black[idx++] = b;
		//idx�� 1�� �ø��� ǥ��, �� ���� ���� 
	}

	cout << napsack(15, 15, 0) << '\n';
	return 0;
}