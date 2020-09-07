//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N, R, C;
//int cnt;
//
//void Z(int size, int y, int x){
//	//제일 작은 크기, 2 == (1 << 1)
//	if (size == 2){
//		if (y == R && x == C){
//			cout << cnt << "\n";
//			return;
//		}
//		cnt++;
//
//		if (y == R && x + 1 == C){
//			cout << cnt << "\n";
//			return;
//		}
//		cnt++;
//
//		if (y + 1 == R && x == C){
//
//			cout << cnt << "\n";
//			return;
//		}
//		cnt++;
//
//		if (y + 1 == R && x + 1 == C){
//
//			cout << cnt << "\n";
//			return;
//		}
//		cnt++;
//
//		return; //해당 2 * 2 블럭에 R, C가 없을 경우
//	}
//	//1사분면
//	Z(size / 2, y, x);
//
//	//2사분면
//	Z(size / 2, y, x + size / 2);
//
//	//3사분면
//	Z(size / 2, y + size / 2, x);
//
//	//4사분면
//	Z(size / 2, y + size / 2, x + size / 2);
//
//}
//
//int main(void){
//
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> N >> R >> C;
//
//	Z(1 << N, 0, 0);
//
//	return 0;
//}
#include <bits/stdc++.h>

using namespace std;

int N, R, C, ans, s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> R >> C;

	while (N)
	{
		int idx;
		s = pow(2, N) / 2;
		if (C < s && R < s)
			idx = 0; //2사분면
		else if (C >= s && R < s)
			idx = 1; //1사분면
		else if (C < s && R >= s)
			idx = 2; //3사분면
		else if (C >= s && R >= s)
			idx = 3; //4사분면

		C %= s;
		R %= s; //C와 R을 다음 사각형으로 세팅

		ans += pow(s, 2) * idx; //ans에 s^2*idx를 계속 더해줌

		N--;
	}

	cout << ans << '\n';

	return 0;
}