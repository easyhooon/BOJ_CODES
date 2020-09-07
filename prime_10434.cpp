#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int mat[10001]; //1부터 10000까지의 수를 저장
vector<int> v;	//일반 소수를 저장
set<int> happy; //행복한 소수를 저장

void HappyPrime()
{
	//에라토스테네스의 체를 이용한 소수 판별
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

	//행복한 소수의 조건인 각 자리수의 합이 결론적으로 1이 되는지 확인하는 과정을 구현,
	//과정을 하나하나 셋에 저장하였다가 중복값이 나오면, 행복한 소수의 조건을 벗어남
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
				{ //중복된 수가 있으면
					break;
				}
				else
				{
					st.insert(num);
				}
				s = to_string(num); //각자리의 제곱의 합이 s가 됨
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
		{ //happy 셋에 발견되면 Yes
			cout << a << ' ' << b << "Yes\n";
		}
		else
		{
			cout << a << ' ' << b << " NO\n";
		}
	}
}