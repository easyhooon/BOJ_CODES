#include <iostream>
using namespace std;

int N;
int vx[15 + 1], vy[15 + 1];

int go(int y, int x)
{

	//가지치기(back tracking)
	for (int i = 0; i < y; i++)
	{
		//직선 겹침
		if (y == vy[i])
			return 0; //가로위치 겹침
		if (x == vx[i])
			return 0; //세로위치 겹침
		if (abs(x - vx[i]) == abs(y - vy[i]))
			return 0; //대각선위치 겹침
	}

	//종료 조건
	if (y == N - 1)
	{
		//말단에서 퀸 배열이 성공적인지 체크
		//만약 성공적이라면 1리턴
		return 1;
	}

	//말의 위치를 기억
	vy[y] = y, vx[y] = x;

	int r = 0;
	for (int i = 0; i < N; i++)
	{
		r += go(y + 1, i);
	}
	return r;
}

int main(void)
{
	cin >> N;

	int r = 0;
	for (int i = 0; i < N; i++)
	{
		r += go(0, i);
	}
	cout << r;
	return 0;
}