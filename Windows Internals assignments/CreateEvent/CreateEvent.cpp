using namespace std;
#include<Windows.h>
#include<iostream>

int main() {
	HANDLE event1;
	event1 = CreateEvent(NULL,
						FALSE,
						TRUE,
					TEXT("the first event")

	);

	if (event1 == NULL) {
		cout << "Event creation failed";
	}
	else {
		cout << "event is created";
	}
	int a;
	cin >> a;

}