#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, d, temp1, temp2, temp3, result1, result2;

	cin >> a >> b;

	cin >> c >> d;

	temp2 = lcm(b, d);
	temp1 = a * (temp2 / b) + c * (temp2 / d);

	temp3 = gcd(temp1, temp2);

	result1 = temp1 / temp3;
	result2 = temp2 / temp3;
	

	cout << result1 << " " << result2 << '\n';

}