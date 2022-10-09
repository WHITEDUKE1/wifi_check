#include <string>
#include <fstream>
#include <iostream>


using namespace std;


void save_wlan() {
	system("chcp 1251 && netsh wlan show profiles >> file.txt");
}

void save_password(string item) {

	string my_str = "chcp 1251 && netsh wlan show profiles \"" + item + "\" key=clear >> file1.txt ";

	system(my_str.c_str());

}

int save_name_wlan() {
	string path = "file.txt";

	ifstream fin;
	fin.open(path);
	string str2;
	string str;

	if (!fin.is_open()) {}
	else {
		while (!fin.eof())
		{
			getline(fin, str);
			int first = str.find_first_of(":");
			if (first != -1 && first != 36) {
				int first1 = str.size();
				string my_str2 = str.substr(first + 2, first1);
				cout << my_str2;
				save_password(my_str2);

			}

		}
	}

	fin.close();

	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");

	save_name_wlan();

	system("pause");


	return 0;
}
