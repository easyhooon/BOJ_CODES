#include <bits/stdc++.h>

using namespace std;

int N, M, cnt;
vector<int> A;

int binarySearch(int low, int high, int target)
{
	if (low > high)
		return cnt;
	else
	{
		int mid = (low + high) / 2;
		if (A[mid] == target) {
			cnt++;
			binarySearch(low, mid - 1, target);
			binarySearch(mid + 1, high, target);
		}
		else if (A[mid] > target)
			return binarySearch(low, mid - 1, target);
		else
			return binarySearch(mid + 1, high, target);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		A.push_back(num);
	}

	sort(A.begin(), A.end()); 

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cnt = 0;
		int num;
		cin >> num;
		cout << binarySearch(0, N - 1, num) << ' '; 
	}
	return 0;
}
