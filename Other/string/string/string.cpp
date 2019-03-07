using namespace std;
#include<iostream>
#include<string>


char * strCon(string str, string str1, char* res)
{
	int i = 0, count = 0;
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	count = i;
	i = 0;
	while (str1[i] != '\0')
	{
		res[count] = str1[i];
		i++;
		count++;
	}
	res[count] = '\0';
	return res;
}

string strRev(string str, int len)
{
	int counter = 0;
	char temp = 0;
	for (counter = 0; counter <= len / 2; counter++)
	{
		temp = str[counter];
		str[counter] = str[len - counter];
		str[len - counter] = temp;
	}
	return str;
}

bool strCmp(string str, string str1)
{
	int flag = 0;
	int i = 0;
	while (str[i] != '\0' || str1[i] != '\0')
	{
		if (str[i] != str1[i])
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (str1[i] == '\0'&&str[i] == '\0'&&flag == 0)
		return 1;
	else
		return 0;
}


char * strCpy(string str, char *res)
{
	int count = 0;
	while (str[count] != '\0')
	{
		res[count] = str[count];
		count++;
	}
	return res;
}



int main()
{
	int choice;
	cout << "enter your choice: " << endl;
	cout << "1.String Reverse" << endl << "2.String concatination" << endl << "3.string copy" << endl << "4.string compare" << endl;
	cin >> choice;
	if (choice == 1 && sizeof(choice) == 4)
	{
		string str;
		int Len_String = 0;
		cin.ignore();
		cout << "enter the string: ";
		getline(cin, str);
		cout << "you have entered: " << str << endl << endl;
		for (Len_String = 0; str[Len_String] != '\0'; Len_String++);
		str = strRev(str, Len_String - 1);
		cout << "the reversed string is: ";
		cout << str;
	}
	else if (choice == 2 && sizeof(choice) == 4)
	{
		cin.ignore();
		string string1, string2;
		char *res;
		int len = 0, count = 0;
		cout << "enter the first string : ";
		getline(cin, string1);
		cout << "enter the second string  : ";
		getline(cin, string2);
		for (len = 0; string1[len] != '\0'; len++);
		count = len;
		for (len = 0; string2[len] != '\0'; len++);
		count = count + len;
		res = new char[count];
		res = strCon(string1, string2, res);
		cout << "the resultant string after concatinating " << string1 << " and " << string2 << " is: ";
		cout << res << endl;
		
	}
	else if (choice == 3 && sizeof(choice) == 4)
	{
		cin.ignore();
		string str;
		char * res = NULL;
		int length = 0,p=0;
		cout << "enter the string : ";
		getline(cin, str);
		for (length = 0; str[length] != '\0'; length++)
			p++;
		res = new char[p];
		res = strCpy(str, res);
		cout << "the string is copied " << str << endl;
		delete(res);
	}
	else if (choice == 4 && sizeof(choice) == 4)
	{
		cin.ignore();
		string str, str1;
		cout << "enter the first string : ";
		getline(cin, str);
		cout << "enter the second string  : ";
		getline(cin, str1);
		bool Result;
		Result = strCmp(str, str1);
		if (Result)
			cout << "strings are equal" << endl;
		else
			cout << "strings are not equal" << endl;
	}
	else
	{
		cout << "invalid choice " << endl;
		cout << "enter input again.." << endl;
	}
	
	int z;
	cin >> z;
	return 0;

}