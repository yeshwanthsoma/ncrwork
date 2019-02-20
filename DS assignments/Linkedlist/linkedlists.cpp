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
	void insert_first(int a);
	void insert_last(int a);
	void insert_pos(int a, int b);
	void delete_first();
	void delete_last();
	void travel_forw();
	struct node* getpoi();
	void travel_back(struct node *);
};
linked::linked() {
	start = NULL;
}
void linked::insert_first(int a) {
	struct node *temp;
	temp = new node;
	if (start == NULL) {
		temp->val = a;
		temp->next = NULL;
		start = temp;
	}
	else {
		temp->val = a;
		temp->next = start;
		start = temp;
	}
}
void linked::insert_last(int a) {
	struct node *temp,*curr;
	temp = new node;
	temp->val = a;
	curr = start;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
}
void linked::travel_forw() {
	struct node * temp;
	temp = start;
	cout << "The LL is ";
	while (temp != NULL) {
		
		cout << temp->val<<" ";
		temp = temp->next;
	}
	cout << endl;
}
void linked::insert_pos(int a, int b) {
	struct node *curr;
	curr = start;
	while (curr->val != a) {
		curr = curr->next;
	}
	struct node* temp=NULL;

	temp->next = curr->next;
	temp->val = b;
	curr->next = temp;
}
void linked::delete_first() {
	struct node *temp;
	temp = start;
	cout << "The popped element is " << start->val<<endl;
	start = temp->next;
	delete temp;
}
void linked::delete_last() {
	struct node *temp;
	temp = start;
	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	cout << "The popped element is " << temp->next->val<<endl;
	temp->next = NULL;

}
void linked::travel_back(struct node *temp) {

	if(temp!= NULL) {
		travel_back(temp->next);
		cout << temp->val<<" ";
	}
}
struct node* linked::getpoi() {
	return start;
}
int main() {
	linked a;
	int  b, c,d,e;

	while (1) {
		cout << "Enter the value:"<<endl;
		cout << "1.Insert at first" << endl << "2.Insert at last" << endl << "3.Insert at pos" << endl << "4.Delete at first" << endl << "5.delete at last" << endl << "6.travel forward" << endl <<"7.Reverse LL"<<endl<< "8.exit" << endl;
		cin >> b;
		switch (b) {
		case 1: cout << "enter the value:";
			cin >> c;
			a.insert_first(c); break;
		case 2: cout << "enter the value ";
			cin >> c;
			a.insert_last(c); break;
		case 3: cout << "enter the data and inserting value";
				cin >> c; cin >> d;
				a.insert_pos(c, d); break;
		case 4:  a.delete_first(); break;
		case 5:	 a.delete_last(); break;
		case 6: a.travel_forw(); break;
		case 7:cout << "Reverse LL is ";
			a.travel_back(a.getpoi()); break;
		case 8: exit(1);
				
		}
	}
	return 0;
}

