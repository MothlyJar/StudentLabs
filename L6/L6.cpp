#include <iostream>
using std::cin;
using std::cout;

void get_numbers(short** table,short rows,short columns) { // получаем базовые значения в таблицу
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			switch (i) {
			case 0: // значения первой строки положительные
				if (j == 0) { cout << "How many rows we need to add: "; }
				else { cout << "How many columns we need to add: "; }
				do { cin >> table[i][j]; } while (table[i][j] <= 0); break;
			case 1:
				if (j == 0) { cout << "Rows filling ratio: "; }
				else { cout << "Columns filling ratio: "; }
				cin >> table[i][j]; break;
			}
		}
	}
}
void get_i_with_zeros(short** table, short* zeros, short rows, short columns, short k) {
	for (short i = 0; i < rows; ++i) {
		for (short j = 0; j < columns; ++j) {
			if (table[i][j] == 0) {
				zeros[k] = i;
				++k;
			}
		}
	}
}

int main() {
	short rows = 2;
	short columns = 2;

	short** table = (short**)calloc(rows,sizeof(short*)); // строки таблиицы
	for (short i = 0; i < rows; i++) {
		table[i] = (short*)malloc(columns*sizeof(short)); // в каждой ячейке строки по столбцу
	}

	get_numbers(table, rows,columns);

	for (short i = 0; i < rows; i++) { // посмотрим, что там у нас лежит
		cout << '\n';
		for (short j = 0; j < columns; j++) {
			cout << table[i][j] << ' ';
		}
	}
	cout << '\n';

	short a = table[0][0]; short b = table[0][1]; short c = table[1][0]; short d = table[1][1];
	short new_rows = a + rows, new_columns = b + columns;

	short** temp = (short**)realloc(table, new_rows * sizeof(short*)); //обозначить большее кол-во строк
	table = temp;
	for (short i = 0; i < rows; ++i) {
		temp[i] = (short*)realloc(table[i], new_columns * sizeof(short)); // добавить колонки к тем строкам, которые уже были
		table[i] = temp[i];
	}
	for (short i = rows; i < new_rows; ++i) { // выделить место для колонок в совсем новых строках 
		table[i] = (short*)calloc(new_columns, sizeof(short));
	}

	for (short i = 0; i < new_rows; ++i) { // посмотреть, что там
		cout << '\n';
		for (short j = 0; j < new_columns; ++j) {
			cout << table[i][j] << ' ';
		}
	}
	cout << '\n';

	for (short i = 0; i < new_rows; ++i) { // заполняем таблицу
		for (short j = 0; j < new_columns; ++j) {
			table[i][j] = c*i + d*j;
		}
	}
	table[new_rows-2][new_columns-2] = a;
	table[new_rows-2][new_columns-1] = b;
	table[new_rows-1][new_columns-2] = c;
	table[new_rows-1][new_columns-1] = d;

	for (short i = 0; i < new_rows; ++i) { // ещё раз посмотреть, что там
		cout << '\n';
		for (short j = 0; j < new_columns; ++j) {
			cout << table[i][j] << ' ';
		}
	}
	cout << '\n';

	short k = 0;
	short* zeros = (short*)calloc(new_rows,sizeof(short)); // получаем индесы строк с 0 в них
	get_i_with_zeros(table, zeros, new_rows, new_columns, k);
	for (short i = 0; i < new_rows; ++i) { // чекаем
		cout << zeros[i] << ' ';
	}

	for (short y = 0; y < k; ++y) {
		for (short i = new_rows; i > 0; --i) {

		}
	}
	//short** changed_table_parameters = (short**)calloc((2 + a), sizeof(short*)); // создание копии
	//for (short i = 0; i < 2+a; i++) {
	//	changed_table_parameters[i] = (short*)malloc((2 + b)* sizeof(short));
	//}
	//for (short i = 0; i < 2 + a; i++) { //заполнение копии
	//	for (short j = 0; j < 2 + b; j++) {
	//		changed_table_parameters[i][j] = (i * c) + (j * d);
	//	}
	//}
	//changed_table_parameters[2 + a-1][2 + b-1] = d;
	//changed_table_parameters[1 + a-1][2 + b-1] = b;
	//changed_table_parameters[2 + a-1][1 + b-1] = c;
	//changed_table_parameters[1 + a-1][1 + b-1] = a;

	//for (short i = 0; i < 2 + a; i++) { // проверка, что там
	//	cout << '\n';
	//	for (short j = 0; j < 2 + b; j++) {
	//		cout << changed_table_parameters[i][j] << ' ';
	//	}
	//}
	//cout << '\n';

	for (short i = 0; i < 2; i++) {
		free(table[i]);
	}
	free(table);
}