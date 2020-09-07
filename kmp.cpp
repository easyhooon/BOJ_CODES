#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			//일치 하지 않으면 j를 한칸 앞으로 
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			//일치하면 i와 j 둘다 ++1 
			//일치하지 않으면 i만 ++1
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern) {
	//구한 테이블을 가져옴
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		//한글자라도 일치하는게 있나 j > 0
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			//전체 문자가 매칭이 된 경우
			if (j == patternSize - 1) {
				printf("%d번째에서 찾았습니다. \n", i - patternSize + 2);
				//j 값을 그 만큼 갱신
				j = table[j];
				//테이블의 마지막 -> 접두사와 접미사의 최대 일치 길이
			}
			//단순히 매칭만 이루어진 경우
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