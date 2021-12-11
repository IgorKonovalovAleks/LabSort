#include "sorts.h"


void swap(int* arr, int i, int j) {

	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;

}

void merge(int n1, int n2, int* left, int* right, int* res) {

	int i = 0, j = 0;
	for (; i < n1 && j < n2;) {
		if (left[i] < right[j]) {
			res[i + j] = left[i];
			i++;
		}
		else {
			res[i + j] = right[j];
			j++;
		}
	}
	if (n2 != j) {
		for (; j < n2; j++) {
			res[i + j] = right[j];
		}
	}
	else if (n1 != i) {
		for (; i < n1; i++) {
			res[i + j] = left[i];
		}
	}


	for (int i = 0; i < n1 + n2; i++) {
		left[i] = res[i];
	}

}


void bubble_sort(int n, int* arr) {

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {

			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
			}

		}
	}


}


void ins_sort(int n, int* arr) {
	
	
	for (int i = 0; i < n; i++) {
		int m = arr[i];
		int mi = i;
		for (int j = i; j < n; j++)
			if (arr[j] < m) {
				mi = j;
				m = arr[j];
			}

		swap(arr, i, mi);
	}
}


void merge_sort_rec(int n, int* arr, int* res) {

	if (n == 1) {
		return;
	}

	merge_sort_rec(n / 2, arr, res);
	merge_sort_rec(n - n / 2, arr + n / 2, res + n / 2);

	merge(n / 2, n - n / 2, arr, arr + n / 2, res);

}

void merge_sort(int n, int* arr) {

	int* tmp = (int*)malloc(sizeof(int) * n);
	merge_sort_rec(n, arr, tmp);
	free(tmp);
}

void refresh(int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
}


void quick_sort(int n, int* arr) {
	if (n == 1 || n == 0)
		return;

	int f = arr[n / 2], j = 0, k = n - 1;

	while (true) {
		while (arr[j] < f) {
			j++;
		}
		while (arr[k] > f) {
			k--;
		}
		if (j >= k) {
			break;
		}
		swap(arr, j++, k--);

	}

	quick_sort(j, arr);
	quick_sort(n - j - 1, arr + j + 1);

}





void test(void (*fPtr)(int, int*), int* a, int n) {

	unsigned int start, end;

	for (int i = 0; i < 5; i++) {
		start = clock();
		(*fPtr)(n, a);
		end = clock();

		printf("%d ", end - start);
		refresh(a, n);
	}

}



