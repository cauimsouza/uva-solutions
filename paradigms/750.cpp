#include <stdio.h>
#include <stdlib.h>

int num_sol;

void BTRecursion(int, int*, int);

int main()
{
	int test_cases, dataSet = 0;
	scanf("%d", &test_cases);
	while(test_cases--){
		if(dataSet++) printf("\n");
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		int column, row;
		scanf("%d%d", &row, &column);

		int *rows = new int[10];
		rows[column] = row;
		num_sol = 1;
		BTRecursion(1, rows, column);

		delete[]rows;
	}

	return 0;
}

/**
 * Recursive procedure to solve the problem
 * @param column     current column
 * @param rows       rows[i] is the i-th colums' row
 * @param column_idx fixed queen' column
 */
void BTRecursion(int column, int *rows, int column_idx){
	if(column > 8){ // base case, we already filled the board with 8 queens!
		printf("%2d     ", num_sol++);
		for(int i = 1; i <= 8; i++) printf(" %d", rows[i]);
		printf("\n");
		return;
	}
	if(column == column_idx){ // this column is the fixed queen's column, go on
		BTRecursion(column + 1, rows, column_idx);
		return;
	}

	for(int i = 1; i <= 8; i++){ // try to put a new queen at position (i,column)
		bool itsFree = true;
		for(int j = 1; itsFree && j < column; j++){
			if(rows[j] == i || (column - j == abs(rows[j] - i))  )
				itsFree = false;
		}
		if(itsFree && (abs(column - column_idx) != abs(i - rows[column_idx])) && rows[column_idx] != i){
			rows[column] = i;
			BTRecursion(column + 1, rows, column_idx);
		}
	}
}