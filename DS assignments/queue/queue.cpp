using namespace std;
#include<iostream>
struct queue {
	int rear, front, size;
	int *que;
};
class queue_ {
	queue q;
public:
	queue_();
	bool underflow();
	bool overflow();
	void enqueue(int a);
	void getsize(int a);
	int dequeue();
	void display();

};

queue_::queue_() {
	q.rear = q.front = -1;
	q.size = 0;
	q.que = NULL;
}
void queue_::getsize(int a) {
	q.que = new int[a];
	q.size = a;
}
bool queue_::underflow() {
	return((q.rear == -1) && (q.front == -1));
}
bool queue_::overflow() {
	return(q.rear == q.size - 1);
}
void queue_::enqueue(int a) {
	if (!overflow()) {
		if ((q.front == -1) && (q.rear == -1)) {
			q.front++;
			q.rear++;
			q.que[q.rear] = a;
		}
		else {
			q.rear++;
			q.que[q.rear] = a;
		}
	}
	else
		cout << "overflow"<<endl;

}
int queue_::dequeue() {
	int a=-999;
	if (!underflow()) {
		if (q.front == q.rear) {
			a = q.que[q.front];
			q.front = q.rear = -1;
		}
		else {
			a = q.que[q.front];
			q.front++;

		}
	}
	else
		cout << "underflow"<<endl;
	return a;
}
void queue_::display() {
	int i;
	for (i = q.front; i <= q.rear; i++) {
		cout << q.que[i]<<endl;
	}
}
int main() {
	queue_ a;
	int b,c,d;
	cout << "enter the size:" << endl;
	cin >> b;
	a.getsize(b);
	while (1) {
		cout << "Enter the value:";
		cout << "1.enqueue" << endl << "2.dequeue" << endl << "3.display" << endl;
		cin >> d;
		switch (d) {
		case 1:cout << "Enter the value"; cin >> c;
				a.enqueue(c); break;
		case 2:b=a.dequeue();
			cout << "we have popped" << b << endl;
			break;
		case 3:cout << "the elements are" << endl;
			a.display();break;
		default: exit(1);
		}
	}
	return 0;
	cin >> c;
}
