#include "pch.h"
#include <math.h>
#include <iostream>
using namespace std;
void sort_func(int* orig_array, int a_size) {
	int tmp_size_1 = (a_size / 2 + fmod(a_size, 2));
	int tmp_size_2 = floor(a_size / 2);
	int* tmp_array1 = new int[tmp_size_1];
	for (int i = 0; i < tmp_size_1; i++) {
		tmp_array1[i] = orig_array[i];
	}
	int* tmp_array2 = new int[tmp_size_2];
	int l = tmp_size_1;
	for (int i = 0; i < tmp_size_2; i++) {
		tmp_array2[i] = orig_array[l];
		l++;
	}
	if (tmp_size_1 > 1) {
		sort_func(tmp_array1, tmp_size_1);
	}
	if (tmp_size_2 > 1) {
		sort_func(tmp_array2, tmp_size_2);
	}
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < tmp_size_1 || j < tmp_size_2) {
		if ((tmp_array1[i] < tmp_array2[j] && i < tmp_size_1) || j == tmp_size_2) {
			orig_array[k] = tmp_array1[i];
			k++;
			i++;
		}
		else {
			orig_array[k] = tmp_array2[j];
			k++;
			j++;
		}
	}
}

int main() {
	int size;
	cin >> size;
	int *array_to_sort = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> array_to_sort[i];
	}
	sort_func(array_to_sort, size);
	for (int k = 0; k < size; k++) {
		cout << array_to_sort[k]<< "    ";
	}
	delete[] array_to_sort;
	return 0;
}
