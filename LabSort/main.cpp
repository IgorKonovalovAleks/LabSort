#include <stdio.h>
#include "sorts.h"
using namespace std;

const int n1 = 30000;
const int n2 = 10000000;
const int n3 = 1500000;
const int n4 = 2000000;




int main() {
	

	srand(time(nullptr));

	
	int* a = (int*)malloc(n1 * sizeof(int));
	int* b = (int*)malloc(n1 * 2 * sizeof(int));
	int* c = (int*)malloc(n1 * 3 * sizeof(int));
	int* d = (int*)malloc(n1 * 4 * sizeof(int));
	refresh(a, n1);
	refresh(b, n1 * 2);
	refresh(c, n1 * 3);
	refresh(d, n1 * 4);
	
	//int e[16] = { 1, 4, 5, 2, 3, 2, 7, 6, 3, 0, 14, 8, 128371, 1783618, 781236, 882 };
	//quick_sort(16, e);
	//for (int i = 0; i < 16; i++) {
	//	printf("%d ", e[i]);
	//}
	
	printf("Bubble sort 30000 elements:\n");
	test(&bubble_sort, a, n1);
	printf("\nBubble sort 2x elements:\n");
	test(&bubble_sort, b, n1 * 2);
	printf("\n3x:\n");
	test(&bubble_sort, c, n1 * 3);
	printf("\n4x:\n");
	test(&bubble_sort, d, n1 * 4);
	
	printf("\nselect sort 30000 elements:\n");
	test(&select_sort, a, n1);
	printf("\nselect sort 2x elements:\n");
	test(&select_sort, b, n1 * 2);
	printf("\n3x:\n");
	test(&select_sort, c, n1 * 3);
	printf("\n4x:\n");
	test(&select_sort, d, n1 * 4);
	
	
	free(a);
	free(b);
	free(c);
	free(d);
	a = (int*)malloc(n2 * sizeof(int));
	b = (int*)malloc(n2 * 2 * sizeof(int));
	c = (int*)malloc(n2 * 3 * sizeof(int));
	d = (int*)malloc(n2 * 4 * sizeof(int));

	refresh(a, n2);
	refresh(b, n2 * 2);
	refresh(c, n2 * 3);
	refresh(d, n2 * 4);

	printf("\nMerge sort 10000000 elements:\n");
	test(&merge_sort, a, n2);
	printf("\nMerge sort 2x elements:\n");
	test(&merge_sort, b, n2 * 2);
	printf("\n3x:\n");
	test(&merge_sort, c, n2 * 3);
	printf("\n4x:\n");
	test(&merge_sort, d, n2 * 4);

	printf("\nQuick sort 10000000 elements:\n");
	test(&quick_sort, a, n2);
	printf("\nQuick sort 2x elements:\n");
	test(&quick_sort, b, n2 * 2);
	printf("\n3x:\n");
	test(&quick_sort, c, n2 * 3);
	printf("\n4x:\n");
	test(&quick_sort, d, n2 * 4);

	

	
	free(a);
	free(b);
	free(c);
	free(d);
	return 0;
}

