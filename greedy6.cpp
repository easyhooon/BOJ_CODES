#include <iostream>
#include <string>

using namespace std;

string a;

int main(void)
{
	cin >> a;
	int result = 0;
	string temp = "";
	bool minus = false;
	for (int i = 0; i <= a.size(); i++)
	{
		if (a[i] == '+' || a[i] == '-' || a[i] == '\0')
		{
			if (minus == true) //flag 마이너스를 한번 만난 이후부터는 계속 뺄 수 있음
				result += -stoi(temp);
			else
				result += stoi(temp); //마이너스를 만나기전, 더해줄 수 밖에 없음
			temp = "";				  //temp 초기화 - 부호를 만나면 result 연산을 만나고 ""으로
			if (a[i] == '-')
				minus = true; //flag
			continue;
		}
		temp += a[i]; // int temp가 아닌 string temp, +a[i]를 해주면 a+b가 아닌 "ab"가 됨 유용
	}
	printf("%d", result);
	return 0;
}