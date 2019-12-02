/*
�������б� ���ڰ��а�
21622113 �����

BubbleSort �� ���� �����Ͽ����ϴ�.
SelectionSort �� ���� �����Ͽ����ϴ�.
InsertionSort �� ���� �����Ͽ����ϴ�.
MergeSort �� http://milvus.tistory.com/m/69?category=370375 �� �����Ͽ����ϴ�.
Quick Sort �� https://blog.naver.com/ndb796/221226813382 �� �����Ͽ����ϴ�.
Heap Sort �� https://blog.naver.com/hyjine/221148959183 �� �����Ͽ����ϴ�.
Bin Sort �� http://wansuk.tistory.com/34 �� �����Ͽ����ϴ�.
Radix Sort �� http://wansuk.tistory.com/33 �� �����Ͽ����ϴ�
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h> // �ð� ������ ���� library

#define parent(x) (x-1)/2

int a[1000]; // �迭����, �� 100 �� ���� 100000 �� ���� �׽�Ʈ�� �Ͽ����ϴ�.
int count = sizeof(a) / sizeof(int); // �迭�� ���� 
void BubbleSort(int input[]);
void SelectionSort(int input[]);
void InsertionSort(int input[]);
int ShellSort(int input[]);
void Merge(int input[], int start, int mid, int end);
void MergeSort(int input[], int start, int end);
void QuickSort(int input[], int start, int end);
void BinSort(int input[], int n);
void RadixSort(int input[], int n);
void MakeHeapSort(int input[], int k, int n);
void Build_Heap(int input[], int n);
void HeapSort(int input[], int n, int k);
void CheckArray(void);

int main(void)
{
	while(1){ // �������� �ð� ������ ���� while ������ ���� �ݺ��ϰ� �س����ϴ�.
		printf("%d�� ���� �ð� : ", count);
		int i;
		clock_t start, end;
		srand((unsigned)time(NULL)); // �� �ð� �ٸ� rand ���� �������� Time ���� rand �� �ο�.
		for (i = 0; i < count; i++)
		{
			a[i] = rand() % (count);
		}
		start = clock();
		//BubbleSort(a);
		//SelectionSort(a);
		//InsertionSort(a);
		//ShellSort(a);
		//MergeSort(a, 0, count - 1);
		//QuickSort(a, 0, count - 1);
		//BinSort(a, count);
		RadixSort(a, count);
		//HeapSort(a, count, count);
		end = clock();
		printf("%.6lf ��\n", (double)(end - start) / 1000); // �� ������ ǥ���ϱ� ���� 1000 ���� �������ϴ�.
	//	CheckArray();
	}
	return 0;
}

void BubbleSort(int input[])
{
	int i, temp;
	while (count != 0) // �迭�� ������ŭ �ݺ��ϱ� ���� while �� ó��
	{
		for (i = 1; i < count; i++)
		{
			if (input[i - 1] > input[i]) // ���� �پ��ִ� �迭�� ����.
			{
				temp = input[i - 1];
				input[i - 1] = input[i];
				input[i] = temp; // ū ���ڰ� �տ� ���� �� swap.
			}
		}
		count--; // �迭�� �ѹ� ���ϰ� ���� �� �ڿ� ���� �����ϰ� �ٽ� �ǽ��ϱ� ���� count-- ó��.
	}
}

void SelectionSort(int input[])
{
	int i, j, temp, min;
	for (i = 0; i < count - 1; i++)
	{
		min = i; // �� �տ� �迭���� �ּҶ�� ����.
		for (j = i + 1; j < count; j++)
		{
			if (input[j] < input[min])
				min = j;
		}
	temp = input[i];
	input[i] = input[min];
	input[min] = temp; // ���� ���ڰ� ������ ������ swap.
	}
}

int ShellSort(int input[])
{
	int i = 0, j = 0, k = 0;
	int h = 0;
	int temp = 0;

	for (h = count/2; h > 0; h /= 2) // ���� gap �� �迭�� ������ 1/2, �״����� 1/4, 1/8 �����Ͽ� ���������� gap �� 1�� �ɶ����� �ݺ�.
	{
		for (i = 0; i < h; i++)
		{
			for (j = i + h; j < count; j += h) // gap �� �°� ���� swap.
			{
				temp = input[j];
				k = j;

				while (k > h - 1 && input[k - h] > temp)
				{
					input[k] = input[k - h];
					k -= h;
				}

				input[k] = temp;
			}
		}
	}
}

void InsertionSort(int input[])
{
	int i, j, temp;
	for (i = 1; i < count; i++)
	{
		temp = input[i];
		j = i;

		while (j > 0 && input[j - 1] > temp) // �迭 i ���� ���� �������� �� ������ ũ�� �ڷ� �а�
		{
			input[j] = input[j - 1];
			j = j - 1; // ��� �ϳ��ϳ� �и鼭 �ݺ�.
		}
		input[j] = temp; // ���������� temp �� ���� ���� ��Ȳ�϶� �� �տ� �迭 i ���� ������ swap.
	}
}

void Merge(int input[], int start, int mid, int end) {
	int* tmp = (int*)malloc(sizeof(int)*(end - start + 1)); // �迭�� �� �������ϹǷ� ���� �޸� �Ҵ�.
	int tmp_index = 0; // ó�� ������ 0
	int p = start, q = mid + 1;
	int i;

	for (i = tmp_index; i <= end - start; i++) {
		while (p <= mid && q <= end) {
			if (input[p]>input[q]) {
				tmp[tmp_index] = input[q];
				q++;
			}
			else {
				tmp[tmp_index] = input[p];
				p++;
			}
			tmp_index++;
		}

		if (p>mid) {
			while (q <= end) {
				tmp[tmp_index] = input[q];
				q++;
				tmp_index++;
			}
		}
		else {
			while (p <= mid) {
				tmp[tmp_index] = input[p];
				p++;
				tmp_index++;
			}
		}
	}

	for (i = start; i <= end; i++) {
		input[i] = tmp[i - start];
	}

	free(tmp); // ���� �޸� �Ҵ��� �� ����.
}

void MergeSort(int input[], int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2; // �߰��� ����

	MergeSort(input, start, mid); // input �迭�������� start, mid ���̸�ŭ ������ MergeSort �ǽ�
	MergeSort(input, mid + 1, end); // input �迭�������� mid+1, end ���̸�ŭ ������ MergeSort �ǽ� (���̰� ���������� ���)

	Merge(input, start, mid, end); // ������ ���� MergeSort ����Լ��� �ǽ�.
}

void QuickSort(int input[], int start, int end) {
	if (start >= end)
		return 0;
	int key = start; // ó�� pivot �� start ��
	int i = start + 1, j = end, temp;
	while (i <= j) {
		while (i <= end && input[i] <= input[key]) {
			i++;
		}
		while (j > start && input[j] >= input[key]) {
			j--;
		}
		if (i > j) {
			temp = input[j];
			input[j] = input[key];
			input[key] = temp;
		}
		else {
			temp = input[i];
			input[i] = input[j];
			input[j] = temp;
		}
	}
	QuickSort(input, start, j - 1);
	QuickSort(input, j + 1, end);
}

void BinSort(int input[], int n) {
	int i, j = 0;
	int* count = (int*)malloc(sizeof(int)*n);  // �迭�� �� �������ϹǷ� ���� �޸� �Ҵ�.
	for (i = 0; i<n; i++)
		count[i] = 0; // �� �迭�� 0���� �ʱ�ȭ.
	for (i = 0; i<n; i++)
		count[input[i]]++; // �� ���� �ش��ϴ� �迭�� ���� ++
	for (i = 0; i<n; i++)
	{
		for (; count[i]>0; count[i]--) // ���ڻ��¿� �迭���� 0 ���� ū ���鿡 ���Ͽ�
		{
			input[j++] = i; // ���� �迭�� ���������� �ش� ���ڸ� ���
		}
	}
}

void RadixSort(int input[], int n)
{
	int i, b[1000], m = 0, exp = 1;
	for (i = 0; i < n; i++)
	{
		if (input[i] > m)
			m = input[i];
	}
	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (i = 0; i < n; i++)
			bucket[input[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[input[i] / exp % 10]] = input[i];
		for (i = 0; i < n; i++)
			input[i] = b[i];
		exp *= 10;
	}
}

void MakeHeapSort(int input[], int k, int n)
{
	int left, right, largest, temp;
	left = (2 * k) + 1;
	right = (2 * k) + 2;
	if ((left<n) && (input[left]>input[k]))
		largest = left;
	else
		largest = k;

	if ((right<n) && (input[right]>input[largest]))
		largest = right;

	if (largest != k)
	{
		temp = input[k];
		input[k] = input[largest];
		input[largest] = temp;
		MakeHeapSort(input, largest, n);
	}
}

void Build_Heap(int input[], int n)
{
	int k;
	for (k = n / 2 - 1; k >= 0; k--)
		MakeHeapSort(input, k, n);
}

void HeapSort(int input[], int n, int k)
{
	Build_Heap(input, n);
	int temp;
	int last_row;
	int count = 0;
	for (last_row = n - 1; last_row>0; last_row--)
	{
		if (count == k)
			break;
		temp = input[0];
		input[0] = input[last_row];
		input[last_row] = temp;
		n--;
		count++;
		MakeHeapSort(input, 0, n);
	}
}

	void CheckArray(void)
	{
		int i;
		for (i = 0; i < sizeof(a) / 4; i++)
			printf("%d ", a[i]);
		printf("\n");
	}