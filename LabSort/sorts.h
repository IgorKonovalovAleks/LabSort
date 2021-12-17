#pragma once
#include <malloc.h>
#include <random>
#include <ctime>

void swap(int* arr, int i, int j);

void bubble_sort(int n, int* arr);

void select_sort(int n, int* arr);

bool control(int n, int* arr, int* ptr);

void merge_sort(int n, int* arr);

void quick_sort(int n, int* arr);

void refresh(int* a, int n);

void test(void (*fPtr)(int, int*), int* a, int n);



