#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			//��ġ ���� ������ j�� ��ĭ ������ 
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			//��ġ�ϸ� i�� j �Ѵ� ++1 
			//��ġ���� ������ i�� ++1
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern) {
	//���� ���̺��� ������
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		//�ѱ��ڶ� ��ġ�ϴ°� �ֳ� j > 0
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			//��ü ���ڰ� ��Ī�� �� ���
			if (j == patternSize - 1) {
				printf("%d��°���� ã�ҽ��ϴ�. \n", i - patternSize + 2);
				//j ���� �� ��ŭ ����
				j = table[j];
				//���̺��� ������ -> ���λ�� ���̻��� �ִ� ��ġ ����
			}
			//�ܼ��� ��Ī�� �̷���� ���
			else {
				j++;
			}
		}
	}
}

int main(void) {
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	KMP(parent, pattern);
	return 0;
}