#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <dos.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using namespace std;
int GLOBAL_LENGTH = 4;

int** init_matrix() {
	int** matrix;
	matrix = new int* [GLOBAL_LENGTH];
	for (int i = 0; i < GLOBAL_LENGTH; i++) {
		matrix[i] = new int[GLOBAL_LENGTH];
	}
	return matrix;
}

void delete_matrix(int** matrix_to_delete) {
	for (int i = 0; i < GLOBAL_LENGTH; i++) {
		delete[] matrix_to_delete[i];
	}
	delete[] matrix_to_delete;
}

void draw_field(int** matrix_to_draw) {
	system("CLS");
	cout << endl;
	for (int i = 0; i < GLOBAL_LENGTH; i++) {
		for (int j = 0; j < GLOBAL_LENGTH; j++) {
			cout << setw(4) << matrix_to_draw[i][j] << " ";
		}
		cout << endl;
	}
}

void init_game(int** matrix) {
	srand(time(0));
	for (int i = 0; i < GLOBAL_LENGTH; i++) {
		for (int j = 0; j < GLOBAL_LENGTH; j++) {
			matrix[i][j] = 0;
		}
	}
	for (int k = 0; k < 2; k++) {
		int i = rand() % 4;
		int j = rand() % 4;
		if (matrix[i][j] == 0) {
			matrix[i][j] = 2;
		}
		else k--;
	}
}

void move_left(int** field) {
	for (int i = 0; i < GLOBAL_LENGTH; i++) {
		for (int j = 1; j < GLOBAL_LENGTH; j++) {
			if (field[i][j - 1] == 0) {
				field[i][j - 1] = field[i][j];
				field[i][j] = 0;
				for (int k = j; k > 0; k--) {
					if (field[i][k - 1] == 0) {
						field[i][k - 1] = field[i][k];
						field[i][k] = 0;
					}
				}
			}
		}
	}
	for (int i = 0; i < GLOBAL_LENGTH; i++) {
		for (int j = 1; j < GLOBAL_LENGTH; j++) {
			if (field[i][j] == field[i][j - 1]) {
				field[i][j - 1] *= 2;
				field[i][j] = 0;
				for (int f = 0; f < GLOBAL_LENGTH; f++) {
					for (int l = 1; l < GLOBAL_LENGTH; l++) {
						if (field[f][l - 1] == 0) {
							field[f][l - 1] = field[f][l];
							field[f][l] = 0;
							for (int k = l; k > 0; k--) {
								if (field[f][k - 1] == 0) {
									field[f][k - 1] = field[f][k];
									field[f][k] = 0;
								}
							}
						}
					}
				}
				j++;
			}
		}
	}
}

void move_right(int** field) {
	for (int i = 0; i < GLOBAL_LENGTH; i++) {
		for (int j = GLOBAL_LENGTH - 2; j >= 0; j--) {
			if (field[i][j + 1] == 0) {
				field[i][j + 1] = field[i][j];
				field[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < GLOBAL_LENGTH; i++) {
		for (int j = GLOBAL_LENGTH - 2; j >= 0; j--) {
			if (field[i][j] == field[i][j + 1]) {
				field[i][j + 1] *= 2;
				field[i][j] = 0;
				for (int f = 0; f < GLOBAL_LENGTH; f++) {
					for (int l = GLOBAL_LENGTH - 2; l >= 0; l--) {
						if (field[f][l + 1] == 0) {
							field[f][l + 1] = field[f][l];
							field[f][l] = 0;
							for (int k = l; k > 0; k--) {
								if (field[f][k + 1] == 0) {
									field[f][k + 1] = field[f][k];
									field[f][k] = 0;
								}
							}
						}
					}
					j--;
				}
			}
		}
	}
}

void move_up(int** field) {

	for (int j = 0; j < GLOBAL_LENGTH; j++) {
		for (int i = 1; i < GLOBAL_LENGTH; i++) {
			if (field[i - 1][j] == 0) {
				field[i - 1][j] = field[i][j];
				field[i][j] = 0;
				for (int k = i; k > 0; k--) {
					if (field[k - 1][j] == 0) {
						field[k - 1][j] = field[k][j];
						field[k][j] = 0;

					}
				}
			}
		}
	}
	for (int j = 0; j < GLOBAL_LENGTH; j++) {
		for (int i = 1; i < GLOBAL_LENGTH; i++) {
			if (field[i][j] == field[i - 1][j]) {
				field[i - 1][j] *= 2;
				field[i][j] = 0;
				for (int f = 0; f < GLOBAL_LENGTH; f++) {
					for (int l = 1; l < GLOBAL_LENGTH; l++) {
						if (field[l - 1][f] == 0) {
							field[l - 1][f] = field[l][f];
							field[l][f] = 0;
							for (int k = l; k > 0; k--) {
								if (field[l - 1][k] == 0) {
									field[l - 1][k] = field[l][k];
									field[l][k] = 0;
								}
							}
						}
					}
				}
				i++;
			}
		}
	}
}

void move_down(int** field) {

	for (int j = 0; j < GLOBAL_LENGTH; j++) {
		for (int i = GLOBAL_LENGTH - 2; i >= 0; i--) {
			if (field[i + 1][j] == 0) {
				field[i + 1][j] = field[i][j];
				field[i][j] = 0;
				for (int k = i; k < GLOBAL_LENGTH - 1; k++) {
					if (field[k + 1][j] == 0) {
						field[k + 1][j] = field[k][j];
						field[k][j] = 0;

					}
				}
			}
		}
	}
	for (int j = 0; j < GLOBAL_LENGTH; j++) {
		for (int i = GLOBAL_LENGTH - 2; i >= 0; i--) {
			if (field[i][j] == field[i + 1][j]) {
				field[i + 1][j] *= 2;
				field[i][j] = 0;
				for (int f = 0; f < GLOBAL_LENGTH; f++) {
					for (int l = GLOBAL_LENGTH - 2; l >= 0; l--) {
						if (field[l + 1][f] == 0) {
							field[l + 1][f] = field[l][f];
							field[l][f] = 0;
							for (int k = l; k > 0; k--) {
								if (field[l+1][k] == 0) {
									field[l + 1][k] = field[l][k];
									field[l][k] = 0;
								}
							}
						}
					}
				}
				i--;
			}
		}
	}
}

bool check_previous_state(int** prev_state, int** current_state) {
	for (int i = 0; i < GLOBAL_LENGTH; i++) {
		for (int j = 0; j < GLOBAL_LENGTH; j++) {
			if (prev_state[i][j] != current_state[i][j]) {
				return 1;
			}
		}
	}
	return 0;
}

void update_previous_state(int **previous_state, int** current_state) {
	for (int i = 0; i < GLOBAL_LENGTH; i++) {
		for (int j = 0; j < GLOBAL_LENGTH; j++) {
			previous_state[i][j] = current_state[i][j];
		}
	}
}

void apply_rules(int** field, int** previous_state) {
	label1:
	char key = _getch();
	switch (key) {
	case 65: move_left(field); break;
	case 87: move_up(field); break;
	case 68: move_right(field); break;
	case 83: move_down(field); break;
	default: goto label1;
	}
	if (check_previous_state(previous_state, field)) {
		int i, j;
		do {
			label2:
			i = rand() % GLOBAL_LENGTH;
			j = rand() % GLOBAL_LENGTH;
			if (field[i][j] == 0) {
				field[i][j] = 2;
			}
			else goto label2;
		} while (field[i][j] == 0);
	}
	else goto label1;
}

bool field_full(int** field) {
	for (int i = 0; i < GLOBAL_LENGTH; i++) {
		for (int j = 0; j < GLOBAL_LENGTH; j++) {
			if (field[i][j] == 0) { return 0; }
		}
	}
	return 1;
}
bool check_borders(int position, int hernya) {
	return (position + hernya >= 0) && (position + hernya < GLOBAL_LENGTH);
}

bool check_same_neighbours(int x_position, int y_position, int** current_state) {
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (check_borders(x_position, i) && check_borders(y_position, j)) {
				if (!(i == 0 && j == 0) && (i+j==-1 || i+j==1)) {
					if (current_state[x_position][y_position] == current_state[x_position + i][y_position + j])  return 1;
				}
			}
		}
	}
	return 0;
}

bool game_end(int** field) {
	if (field_full(field)) {
		for (int i = 0; i < GLOBAL_LENGTH; i++) {
			for (int j = 0; j < GLOBAL_LENGTH; j++) {
				if (check_same_neighbours(i, j, field)) {
					return 0;
				}
			}
		}
	}
	else return 0;
	return 1;
}

void game_loop() {
	int** game_field = init_matrix();
	int** previous_state = init_matrix();
	init_game(game_field);
	while (!game_end(game_field)) {
		draw_field(game_field);
		apply_rules(game_field, previous_state);
		update_previous_state(previous_state, game_field);
	}
	cout << "YOU ARE LOSER";
	delete_matrix(game_field);
	delete_matrix(previous_state);
}

int main() {
	cout << "enter field size";
	cin >> GLOBAL_LENGTH;
	game_loop();
	return 0;
}
