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
			if (minus == true) //flag ���̳ʽ��� �ѹ� ���� ���ĺ��ʹ� ��� �� �� ����
				result += -stoi(temp);
			else
				result += stoi(temp); //���̳ʽ��� ��������, ������ �� �ۿ� ����
			temp = "";				  //temp �ʱ�ȭ - ��ȣ�� ������ result ������ ������ ""����
			if (a[i] == '-')
				minus = true; //flag
			continue;
		}
		temp += a[i]; // int temp�� �ƴ� string temp, +a[i]�� ���ָ� a+b�� �ƴ� "ab"�� �� ����
	}
	printf("%d", result);
	return 0;
}