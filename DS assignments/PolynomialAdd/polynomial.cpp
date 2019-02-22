using namespace std;
#include<iostream>

struct node {
	int val;
	int pow;
	struct node *next;
};

class linkedlist {
	struct node *start;
public:
	linkedlist();
	void insert(int val,int pow);
	void display();
	friend void add(linkedlist one, linkedlist two);
};
linkedlist::linkedlist() {
	start = NULL;

}
void linkedlist::insert(int val,int pow) {
	struct node *temp,*curr;
		temp = new node;
		if (start == NULL) {
			temp->val = val;
			temp->pow = pow;
			temp->next = NULL;
			start = temp;
		}
		else {
			temp->val = val;
			temp->pow = pow;
			curr = start;
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = temp;
			temp->next = NULL;
		}


}
void linkedlist::display() {
	struct node * temp;
	temp = start;
	cout << "The LL is ";
	while (temp != NULL) {

		cout << temp->val<<"X"<<temp->pow<<" ";
		temp = temp->next;
	}
	cout << endl;
}
void add(linkedlist one, linkedlist two) {
	struct node *temp,*temp1,*curr1,*curr=NULL;
	temp = one.start;
	temp1 = two.start;
	while (temp != NULL && temp1 != NULL) {
		if (temp->pow == temp1->pow) {
			temp->val = temp->val + temp1->val;
			temp = temp->next;
			temp1 = temp1->next;
			}
			
		else if (temp->pow > temp1->pow) {
			temp = temp->next;
		}
		else {
			curr1 = temp1;
			temp1=temp1->next;
			curr = one.start;
			
			if (temp == one.start) {
				curr1->next = one.start;
				one.start = temp;
				}
			else {
				while (curr->next != temp)
					curr = curr->next;

				curr1->next = temp;
				curr->next = curr1;
			}
		}
	
	
	
	}
	if (temp1 != NULL) {
		curr = one.start;
		while (curr->next != NULL) {
			curr = curr->next;
		}

		curr->next = temp1;
	}
	one.display();

}


int main() {
	int e = 0, flag, input, val, pow, p;
	linkedlist a[2];
	while (e != 2) {
		flag = 0;
		while (1) {
			cout << "Enter the value:" << endl;
			cout << "1.Insert" << endl << "2.diaplay" << endl << "3.break" << endl;
			cin >> input;
			switch (input) {
			case 1: cout << "enter the value:"<<endl;
				cin >> val;
				cout << endl<<"entert the power"  ;
				cin >> pow;
				a[e].insert(val,pow); break;
			case 2: a[e].display(); break;
			case 3: flag = 1;

			}
			if (flag == 1) {
				break;
			}
		}
		e++;
	}
	cout << endl << "The final poly is ";
	add(a[0], a[1]);
	cin >> p;
}