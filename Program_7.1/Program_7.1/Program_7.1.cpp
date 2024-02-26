#include <iostream>
#include <string>

using namespace std;

string deliting(string str) {
	bool is_odd = false;
	int i = 0;
	while (str[i] != '\0') {
		if ((!is_odd) && (str[i] == 32)) {
			is_odd = true;
			str.erase(i, 1);
		}
		if ((is_odd) && (str[i] == 32)) {
			is_odd = false;
			++i;
		}
		if ((is_odd) && (str[i] != 32)) {
			str.erase(i, 1);
		}
		if ((!is_odd) && (str[i] != 32)) {
			++i;
		}
	}
	return str;
}

int deliting(int* mas, int n) {
	int is_deleted = 0;
	for (int i = 0; i < n; ++i) {
		if (*(mas+i) % 2 == 0) {
			for (int j = i; j < n - 1; ++j) {
				*(mas + j) = *(mas + j + 1);
			}
			++is_deleted;
		}
	}
	return is_deleted;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int nav, dels;
	string str;

	int mas[100] = {};
	int n;

	cout << "Выберете тип: \n1. Строка \n2. Массив целых чисел \nВведите номер: ";
	cin >> nav;
	switch (nav) {
	case 1:
		cout << "Введите строку: ";
		cin.ignore();
		getline(cin, str);

		str = deliting(str);

		cout << "Полученная строка: " << endl;
		cout << str;
		break;
	case 2:
		cout << "Введите длину массива: ";
		cin >> n;

		cout << "Вводите элементы массива: " << endl;
		for (int i = 0; i < n; ++i) {
			cin >> mas[i];
		}

		dels = deliting(&mas[0], n);

		cout << "Полученный массив: " << endl;
		for (int i = 0; i < n - dels; ++i) {
			cout << mas[i] << ' ';
		}
		break;
	}
	return 0;
}