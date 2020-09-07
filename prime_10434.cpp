#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int mat[10001]; //1���� 10000������ ���� ����
vector<int> v;	//�Ϲ� �Ҽ��� ����
set<int> happy; //�ູ�� �Ҽ��� ����

void HappyPrime()
{
	//�����佺�׳׽��� ü�� �̿��� �Ҽ� �Ǻ�
	for (int i = 1; i <= 10000; i++)
	{
		mat[i] = i;
	}
	for (int i = 2; i <= 10000; i++)
	{
		if (mat[i] == 0)
		{
			continue;
		}
		v.push_back(mat[i]);
		for (int j = i + i; j <= 10000; j += i)
		{
			mat[j] = 0;
		}
	}

	//�ູ�� �Ҽ��� ������ �� �ڸ����� ���� ��������� 1�� �Ǵ��� Ȯ���ϴ� ������ ����,
	//������ �ϳ��ϳ� �¿� �����Ͽ��ٰ� �ߺ����� ������, �ູ�� �Ҽ��� ������ ���
	for (int i = 0; i < v.size(); i++)
	{
		string s = to_string(v[i]);
		set<int> st;
		while (1)
		{
			int num = 0;
			for (int j = 0; j < s.size(); j++)
			{
				num = num + (s[j] - '0') * (s[j] - '0');
			}
			if (num == 1)
			{
				happy.insert(v[i]);
				break;
			}
			else
			{
				if (st.find(num) != st.end())
				{ //�ߺ��� ���� ������
					break;
				}
				else
				{
					st.insert(num);
				}
				s = to_string(num); //���ڸ��� ������ ���� s�� ��
			}
		}
	}
}

int main()
{
	int n;
	int a, b;
	HappyPrime();

	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		if (happy.find(b) != happy.end())
		{ //happy �¿� �߰ߵǸ� Yes
			cout << a << ' ' << b << "Yes\n";
		}
		else
		{
			cout << a << ' ' << b << " NO\n";
		}
	}
}