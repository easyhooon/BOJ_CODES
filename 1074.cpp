//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N, R, C;
//int cnt;
//
//void Z(int size, int y, int x){
//	//���� ���� ũ��, 2 == (1 << 1)
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
//		return; //�ش� 2 * 2 ���� R, C�� ���� ���
//	}
//	//1��и�
//	Z(size / 2, y, x);
//
//	//2��и�
//	Z(size / 2, y, x + size / 2);
//
//	//3��и�
//	Z(size / 2, y + size / 2, x);
//
//	//4��и�
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
			idx = 0; //2��и�
		else if (C >= s && R < s)
			idx = 1; //1��и�
		else if (C < s && R >= s)
			idx = 2; //3��и�
		else if (C >= s && R >= s)
			idx = 3; //4��и�

		C %= s;
		R %= s; //C�� R�� ���� �簢������ ����

		ans += pow(s, 2) * idx; //ans�� s^2*idx�� ��� ������

		N--;
	}

	cout << ans << '\n';

	return 0;
}