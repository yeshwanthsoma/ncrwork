using namespace std;
#include<iostream>
struct node {
	int val;
	struct node *next;

};

class linked {
	struct node *start;
public:
	linked();

	void insert_last(int a);

	void selfadjusting(int a);
	void travel_forw();
	struct node* getpoi();
	void travel_back(struct node *);
};
linked::linked() {
	start = NULL;
}

void linked::selfadjusting(int a) {
	struct node*temp, *temp1;
	temp = start;
	if (start != NULL) {
		while (temp->next->val != a) {
			temp = temp->next;
		}
		temp1 = temp->next;
		temp->next = temp->next->next;
		temp1->next = start;
		start = temp1;
		travel_forw();
	}
}
void linked::insert_last(int a) {
	struct node *temp, *curr;
	temp = new node;
	temp->val = a;
	curr = start;
	if (start == NULL) {
		temp->next = NULL;
		start = temp;
	}
	else {
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
		temp->next = NULL;
	}
}
void linked::travel_forw() {
	struct node * temp;
	temp = start;
	cout << "The LL is ";
	while (temp != NULL) {

		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}



void linked::travel_back(struct node *temp) {

	if (temp != NULL) {
		travel_back(temp->next);
		cout << temp->val << " ";
	}
}
struct node* linked::getpoi() {
	return start;
}
int main() {
	linked a;
	int  b, c, d, e;

	while (1) {
		cout << "Enter the value:" << endl;
		cout << "1.Insert at last" << endl << "2.travel forward" << endl << "3.selfadjusting " << endl << "4.exit" << endl;
		cin >> b;
		switch (b) {

		case 1: cout << "enter the value ";
			cin >> c;
			a.insert_last(c); break;

		case 2: a.travel_forw(); break;
		case 3:cout << "enter the element value:" << endl;
			cin >> c;
			a.selfadjusting(c); break;
		case 4: exit(1);

		}
	}
	return 0;
}

