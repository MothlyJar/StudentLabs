#include <iostream>
using std::cin;
using std::cout;

short* get_i_with_zeros(short** table, short rows, short columns, short& k) { // создать прям тут масив zeros
	short* zeros = (short*)calloc(rows, sizeof(short));
	for (short i = 0; i < rows; ++i) {
		for (short j = 0; j < columns; ++j) {
			if (table[i][j] == 0) {
				zeros[k] = i;
				++k;
				break;
			}
		}
	}
	return zeros;
}
void see(short** table, short rows, short columns) {
	for (short i = 0; i < rows; ++i) { // посмотреть, что там
		cout << '\n';
		for (short j = 0; j < columns; ++j) {
			cout << table[i][j] << ' ';
		}
	}
	cout << '\n';
}

int main() {
	short rows = 2;
	short columns = 2;

	short** table = (short**)calloc(rows,sizeof(short*)); // строки таблиицы
	for (short i = 0; i < rows; i++) {
		table[i] = (short*)malloc(columns*sizeof(short)); // в каждой ячейке строки по столбцу
	}

	for (short i = 0; i < rows; i++) { // получаем значения
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

	see(table, rows, columns);

	short new_rows = table[0][0] + rows, new_columns = table[0][1] + columns;

	table = (short**)realloc(table, new_rows * sizeof(short*)); //обозначить большее кол-во строк
	for (short i = 0; i < rows; ++i) {
		table[i] = (short*)realloc(table[i], new_columns * sizeof(short)); // добавить колонки к тем строкам, которые уже были
	}
	for (short i = rows; i < new_rows; ++i) { // выделить место для колонок в совсем новых строках 
		table[i] = (short*)calloc(new_columns, sizeof(short));
	}

	see(table, new_rows, new_columns);

	table[new_rows - 2][new_columns - 2] = table[0][0]; //a
	table[new_rows - 2][new_columns - 1] = table[0][1]; //b
	table[new_rows - 1][new_columns - 2] = table[1][0]; //c
	table[new_rows - 1][new_columns - 1] = table[1][1]; //d
	for (short i = 0; i < new_rows; ++i) { // заполняем таблицу
		for (short j = 0; j < new_columns; ++j) {
			if ((i == new_rows - 1 and (j == new_columns - 1 or j == new_columns - 2)) or (i == new_rows - 2 and (j == new_columns - 1 or j == new_columns - 2))) {
				continue;
			}
			else {
				table[i][j] = table[new_rows - 1][new_columns - 2] * i + table[new_rows - 1][new_columns - 1] * j;
			}
		}
	}

	see(table, new_rows, new_columns);

	short k = 0;
	short* zeros = get_i_with_zeros(table, new_rows, new_columns, k);
	for (short i = 0; i < new_rows; ++i) { // чекаем
		cout << zeros[i] << ' ';
	}
	cout << '\n';

	for (short current_i_with_zero = k; current_i_with_zero > 0; --current_i_with_zero) {
		for (short i = zeros[current_i_with_zero]; i < new_rows - 1; ++i) {
			for (short i_next = i + 1; i_next < new_rows; ++i_next) {
				short* temp = table[i];
				table[i] = table[i_next];
				table[i_next] = temp;
			}
		}
	}

	/*for (short y = k; y >= 0; y--) {
		for (short i = zeros[y]; i < new_rows-1; ++i) {
			for (short ij = i+1; ij < new_rows; ++ij) {
				short* t = table[i];
				table[i] = table[ij];
				table[ij] = t;
			}
			
		}		
	}*/
	
	new_rows -= k;
	table = (short**)realloc(table, new_rows * sizeof(short*));
	

	see(table, new_rows, new_columns);

	for (short i = 0; i < new_rows; i++) {
		free(table[i]);
	}
	free(table);
	free(zeros);
	//----------------------------------------------------------------------------------
	cout << '\n' << "Pt2\n";
	short* ai = new short;
	short* bi = new short;
	cin >> *ai >> *bi;
	*ai *= 2;
	cout << *ai << ' ' << * bi << '\n';
	short t = *ai;
	*ai = *bi;
	*bi = t;
	cout << *ai << ' '  << *bi;
	delete ai;
	delete bi;
}
