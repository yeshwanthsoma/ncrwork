#include<iostream>
#include<string.h>
using namespace std;
class time {
	int hour, min, sec;
public:
	time(int a) {
		hour = min = sec = 0;
	}
	time() {

	}
	time(int a, int b,int c) {
		hour = a;
		min = b;
		sec = c;
	}
	void display1() {
		cout << hour << ":" << min << ":" << sec;
	}
	void add(time &t1, time &t2) {
		hour = t1.hour + t2.hour;
		min = t1.min + t2.min;
		sec = t1.sec + t2.sec;
	}

	
};

int main() {
	time t1(2, 3, 4),t2(1,2,3);
	time t3;
	t3.add(t1, t2);
	t3.display1();
	getchar();
	return 0;

}