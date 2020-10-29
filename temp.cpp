#include <bits/stdc++.h>


using namespace std;

char* makeStr(int len)
{
	char* str = new char[len];
	return str;
}

class Temp
{
private:
	char* digits;


public:
	//getter
	char* getDigits() { return digits; };

	//setter
	void setDigits(char* _digits) { strcpy_s(digits, 20, _digits); };

};

int main()
{

	Temp temp;
	char* s1 = "Hello";

	temp.setDigits(s1);

	cout << temp.getDigits() << '\n';

	free(s1);

	return 0;

}