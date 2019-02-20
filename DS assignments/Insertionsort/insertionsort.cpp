using namespace std;
#include<iostream>
 
#include <math.h> 

void insertionSort(int arr[], int n)
{
	int i, tem, j;
	for (i = 1; i < n; i++)
	{
		tem = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > tem)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = tem;
	}
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	int arr[10];
	int n,m;
	cout << "enter no of elements" << endl;
	cin >> n;
	cout << "enter the elements";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	insertionSort(arr, n);
	printArray(arr, n);
	cin >> m;
	return 0;
}