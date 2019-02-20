using namespace std;
#include<iostream>



void selectionsort(int arr[],int n){

	int loc,i,j=0,temp;
	for (i = 0; i < n-1; i++) {
		loc = i; j = i + 1;
		while (j < n) {
			if (arr[loc] > arr[j])
				loc = j;
			j++;

		}
		temp = arr[i];
		arr[i] = arr[loc];
		arr[loc] = temp;
	}

}
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main() {
	int arr[10],n,m;
	cout << "enter no of elements" << endl;
	cin >> n;
	cout << "enter the elements";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
		 selectionsort(arr, n);
		 printArray(arr, n);
		 cin >> m;
		 return 0;

}