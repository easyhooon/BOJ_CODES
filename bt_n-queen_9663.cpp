#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;
int n;
int vx[MAX + 1], vy[MAX + 1];

int bt(int y, int x)
{
	//가지치기(back tracking)
	for (int i = 0; i < y; i++)
	{
		//직선 겹침
		if (y == vy[i])
			return 0; //가로위치 겹침->실패
		if (x == vx[i])
			return 0; //세로위치 겹침->실패
		if (abs(x - vx[i]) == abs(y - vy[i]))
			return 0; //대각선위치 겹침->실패
	}

	//종료 조건
	if (y == n - 1)
	{
		//마지막으로 퀸 배열이 성공적인지 체크
		//성공
		return 1;
	}

	//말의 위치 정보를 기억
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