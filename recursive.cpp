#include <iostream>

using namespace std;

void recursive(int n)
{
	if (n == 0) return;
	printf("%d", n);
	recursive(n - 1);
}

int main(void) {
	recursive(4);
}