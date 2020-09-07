#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	bool operator <(Student &student) { // < 왼쪽이 오른쪽 보다 작다. 
		return this->score < student.score;
	} // 즉, 다른학생과 비교할때 내 점수가 더 낮다면, 우선순위가 높다.
};

int main(void) {
	Student students[] = {
		Student("나동빈", 90),
		Student("이상욱", 93),
		Student("박한울", 97),
		Student("강종구", 87),
		Student("이태일", 92)
	};
	sort(students, students + 5);
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}