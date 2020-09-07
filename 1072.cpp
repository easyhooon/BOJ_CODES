#include <bits/stdc++.h>

using namespace std;

/*int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int count = 0;
	long long temp;
	double x, y, z;
	cin >> x >> y;


	while (true) {
		z = y / x;
		z = long long(floor(z * 100));
		if (z == 99) {
			printf("-1");
			return 0;
		}
		if(count == 0) temp = z;

		if (z != temp) break;
		//이분탐색으로 구현해야..
		y++;
		x++;
		count++;
	}

	cout << count;

}*/
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long x, y;

	cin >> x >> y;

	int Z = (y * 100) / x;

	if (Z >= 99)
	{
		cout << -1 << "\n";
		return 0;
	}

	int left = 0, right = INT_MAX;
	int result = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		//이분탐색 결과 확률
		int temp = (100 * (y + mid)) / (x + mid);

		//조건
		if (Z >= temp)
		{
			result = mid + 1; //한 쪽에만 이게 있어
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << result << "\n";

	return 0;
}
