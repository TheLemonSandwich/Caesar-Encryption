#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	string encrpyt;
	int ascii;
	bool capital = false;
	int key;
	int arr[100][2];
	int counter = 0;
	cout << "Line To Encrpt: ";
	getline(cin, line);
	cout << "Key Value: ";
	cin >> key;
	for (int i = 0; i < line.length(); i++)
	{
		if ((int(line.at(i)) >= 65 && int(line.at(i)) <= 90) || (int(line.at(i)) >= 97 && int(line.at(i)) <= 122))
		{
			ascii = int(line.at(i));
			if (ascii >= 65 && ascii <= 90)
				capital = true;
			else capital = false;
			if (capital && (ascii + key) > 90)
				ascii = 65 + key - (90 - ascii);
			else if (!capital && (ascii + key) > 122)
				ascii = 97 + key - (122 - ascii);
			else ascii += key;
			encrpyt += char(ascii);
		}
		else if (int(line.at(i)) >= 48 && int(line.at(i)) <= 57)
		{
			arr[counter][0] = i;
			arr[counter++][1] = char(line.at(i));
			encrpyt += '?';
		}
		else encrpyt += line.at(i);
	}
	arr[counter][0] = -1;
	arr[counter][1] = '?';
	cout << "Encrypted Data: " << encrpyt << endl;
	cout << "\n\nDigital Locs:-\n\n";
	for (int i = 0; i < counter; i++)
	{
		if (arr[i][0] == -1)
			break;
		cout << arr[i][0] << "\t" << char(arr[i][1]) << endl;
	}


	system("pause");
}