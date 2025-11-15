#include <iostream>
using std::cin;
using std::cout;

void get_numbers(short** table_parameters) { // получаем базовые значения в таблицу
	for (short i = 0; i < 2; i++) {
		for (short j = 0; j < 2; j++) {
			switch (i) {
			case 0: //значения первого столца положительны
				if (j == 0) { cout << "How many rows we need to add: "; }
				else { cout << "How many columns we need to add: "; }
				do { cin >> table_parameters[i][j]; } while (table_parameters[i][j] <= 0); break;
			case 1:
				if (j == 0) { cout << "Rows filling ratio: "; }
				else { cout << "Columns filling ratio: "; }
				cin >> table_parameters[i][j]; break;
			}
		}
	}
}
short count_i0(short** changed_table_parameters, short* t, short a, short b) {
	short k = 0;
	for (short i = 0; i < 2 + a; i++) {
		for (short j = 0; j < 2 + b; j++) {
			if (changed_table_parameters[i][j] == 0) {
				t[i] = i;
				k++;
			}
		}
	}
	return k;
}

int main() {
	short** table_parameters = (short**)calloc(2,sizeof(short*)); //создаём это нечто: строка, как таблица ссылок на столбцы
	for (short i = 0; i < 2; i++) {
		table_parameters[i] = (short*)malloc(2*sizeof(short)); // и туда фигачим столбцы
	}

	get_numbers(table_parameters);

	for (short i = 0; i < 2; i++) { // посмотрим, то там у нас лежит
		cout << '\n';
		for (short j = 0; j < 2; j++) {
			cout << table_parameters[i][j] << ' ';
		}
	}
	cout << '\n';

	short& a = table_parameters[0][0]; short& b = table_parameters[0][1]; short& c = table_parameters[1][0]; short& d = table_parameters[1][1];
	short** changed_table_parameters = (short**)calloc((2 + a), sizeof(short*)); // создание копии
	for (short i = 0; i < 2+a; i++) {
		changed_table_parameters[i] = (short*)malloc((2 + b)* sizeof(short));
	}
	for (short i = 0; i < 2 + a; i++) { //заполнение копии
		for (short j = 0; j < 2 + b; j++) {
			changed_table_parameters[i][j] = (i * c) + (j * d);
		}
	}
	changed_table_parameters[2 + a-1][2 + b-1] = d;
	changed_table_parameters[1 + a-1][2 + b-1] = b;
	changed_table_parameters[2 + a-1][1 + b-1] = c;
	changed_table_parameters[1 + a-1][1 + b-1] = a;

	for (short i = 0; i < 2 + a; i++) { // проверка, что там
		cout << '\n';
		for (short j = 0; j < 2 + b; j++) {
			cout << changed_table_parameters[i][j] << ' ';
		}
	}
	cout << '\n';

	
	short* t = (short*)calloc(2 + a, sizeof(short)); // получение строк с 0
	short k = count_i0(changed_table_parameters, t, a, b);
	for (short i = 0; i < 2 + a; i++) {
		cout << t[i] << ' ';
	}
	cout << '\n';

	short** final_table = (short**)calloc((2 + a - k), sizeof(short*)); // создание финала
	for (short i = 0; i < 2 + a - k; i++) {
		final_table[i] = (short*)malloc((2 + b) * sizeof(short));
	}
	for (short i = 0; i < 2 + a - k; i++) { //заполнение финала с выпилом строк с 0
		if (i == t[i]) { continue; }
		for (short j = 0; j < 2 + b; j++) {
			final_table[i][j] = changed_table_parameters[i][j];
		}
	}
	free(t);
	for (short i = 0; i < 2 + a - k; i++) { // ну и последний раз смотрим что там
		cout << '\n';
		for (short j = 0; j < 2 + b; j++) {
			cout << final_table[i][j] << ' ';
		}
	}
	
	for (short i = 0; i < 2 + a - k; i++) {
		free(final_table[i]);
	}
	free(final_table);
	for (short i = 0; i < 2 + a; i++) {
		free(changed_table_parameters[i]);
	}
	free(changed_table_parameters);
	for (short i = 0; i < 2; i++) {
		free(table_parameters[i]);
	}
	free(table_parameters);
}