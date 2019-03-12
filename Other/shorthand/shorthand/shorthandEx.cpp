using namespace std;
#include<iostream>
#include<string>


char * shorthand(string str, int size, int outsize)
{
	char *outp;
	outp = new char[outsize];
	int out = 0, i;
	for (i = 0; i < size; i++)
	{
		if (str[i + 1] != '-'&&str[i] != '-')
		{
			outp[out] = str[i];
			out++;
		}
		if (str[i] == '-')
		{
			if ((str[i + 1] - str[i - 1]) > 0)
			{
				outp[out++] = str[i - 1];
				for (int j = 0; j < (str[i + 1] - str[i - 1] - 1); j++)
				{
					outp[out++] = str[i - 1] + j + 1;
				}
			}
			else
			{
				cout << "this is invalid as it is given in reverse order ";
				getchar();
				return NULL;

			}

		}
	}
	return outp;
}

int main()
{
	string str;
	cout << "enter the shorthand form" << endl;
	getline(cin, str);
	int length;
	int counter = 0;
	for (counter = 0; str[counter] != '\0'; counter++);
	length = counter;
	//length = strlen(&str[0]);
	cout << endl;
	if (str[0] == '-' || str[length - 1] == '-')
	{
		cout << "invalid sentence " << endl;
		return 0;
	}
	int OSenSize = 0, indicator = 0;
	for (counter = 0; counter < length; counter++)
	{
		if (str[counter] == '-')
		{
			if (str[counter + 1] == '-')
			{
				cout << "invalid sentence entered" << endl;
				cout << "entered sentence is :";
				for (int counter1 = 0; counter1 < length; counter1++)
				{
					cout << str[counter1];
				}
				cout << endl << endl;
				cout << "process terminated" << endl;
				return 0;
			}

			else if (((65 <= str[counter - 1] && 90 >= str[counter - 1]) && !(65 <= str[counter + 1] && 90 >= str[counter + 1])) ||
				((97 <= str[counter - 1] && 122 >= str[counter - 1]) && !(97 <= str[counter + 1] && 122 >= str[counter + 1])))
			{
				cout << "entered expression contains invalid short hand notations" << endl;
				cout << "process terminated" << endl;
				return 0;
			}


			 if ((str[counter + 1] > 32 && str[counter + 1] < 48) || (str[counter + 1] > 57 && str[counter + 1] < 65)|| 
				(str[counter - 1] > 32 && str[counter - 1] < 48) || (str[counter - 1] > 57 && str[counter - 1] < 65))
			{
				cout << "short hand notation contains invalid symbols" << endl;
				cout << "process terminated" << endl;
				return 0;
			}
			else
			{
				if ((str[counter + 1] - str[counter - 1]) > 0)
					OSenSize = OSenSize + (int)(str[counter + 1] - str[counter - 1]);
				else
					OSenSize = OSenSize + (int)(-1 * (str[counter + 1] - str[counter - 1]));
				indicator++;
			}
		}
	}
	OSenSize = length + OSenSize - (2 * indicator);
	char *outp;
	outp = new char[OSenSize];
	outp = shorthand(str, length, OSenSize);
	cout << "the expanded short hand : ";
	if (outp != NULL) {
		for (counter = 0; counter < OSenSize; counter++)
		{
			cout << outp[counter];
		}
	}
	int z;
	cin >> z;
	return 0;
}