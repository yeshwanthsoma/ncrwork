using namespace std;
#include<iostream>



void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

 
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		
		if (swapped == false)
			break;
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("n");
}


int main()
{
	int arr[10];
	int n;
	cout << "enter no of elements" << endl;
	cin >> n;
	cout << "Enter elements: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	
	int a;
		cin >> a;
		return 0;
}