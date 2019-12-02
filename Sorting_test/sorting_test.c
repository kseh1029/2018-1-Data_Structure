/*
영남대학교 전자공학과
21622113 김승현

BubbleSort 는 직접 구현하였습니다.
SelectionSort 는 직접 구현하였습니다.
InsertionSort 는 직접 구현하였습니다.
MergeSort 는 http://milvus.tistory.com/m/69?category=370375 를 참고하였습니다.
Quick Sort 는 https://blog.naver.com/ndb796/221226813382 를 참고하였습니다.
Heap Sort 는 https://blog.naver.com/hyjine/221148959183 를 참고하였습니다.
Bin Sort 는 http://wansuk.tistory.com/34 를 참고하였습니다.
Radix Sort 는 http://wansuk.tistory.com/33 를 참고하였습니다
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h> // 시간 측정을 위한 library

#define parent(x) (x-1)/2

int a[1000]; // 배열정의, 총 100 개 부터 100000 개 까지 테스트를 하였습니다.
int count = sizeof(a) / sizeof(int); // 배열의 개수 
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
	while(1){ // 연속적인 시간 측정을 위해 while 문으로 무한 반복하게 해놨습니다.
		printf("%d개 정렬 시간 : ", count);
		int i;
		clock_t start, end;
		srand((unsigned)time(NULL)); // 매 시간 다른 rand 값이 나오도록 Time 으로 rand 값 부여.
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
		printf("%.6lf 초\n", (double)(end - start) / 1000); // 초 단위로 표시하기 위해 1000 으로 나눴습니다.
	//	CheckArray();
	}
	return 0;
}

void BubbleSort(int input[])
{
	int i, temp;
	while (count != 0) // 배열의 갯수만큼 반복하기 위해 while 로 처리
	{
		for (i = 1; i < count; i++)
		{
			if (input[i - 1] > input[i]) // 서로 붙어있는 배열을 비교함.
			{
				temp = input[i - 1];
				input[i - 1] = input[i];
				input[i] = temp; // 큰 숫자가 앞에 있을 때 swap.
			}
		}
		count--; // 배열을 한번 비교하고 나서 맨 뒤에 값은 제외하고 다시 실시하기 위해 count-- 처리.
	}
}

void SelectionSort(int input[])
{
	int i, j, temp, min;
	for (i = 0; i < count - 1; i++)
	{
		min = i; // 맨 앞에 배열값을 최소라고 가정.
		for (j = i + 1; j < count; j++)
		{
			if (input[j] < input[min])
				min = j;
		}
	temp = input[i];
	input[i] = input[min];
	input[min] = temp; // 작은 숫자가 앞으로 가도록 swap.
	}
}

int ShellSort(int input[])
{
	int i = 0, j = 0, k = 0;
	int h = 0;
	int temp = 0;

	for (h = count/2; h > 0; h /= 2) // 최초 gap 을 배열의 갯수의 1/2, 그다음은 1/4, 1/8 으로하여 최종적으로 gap 이 1이 될때까지 반복.
	{
		for (i = 0; i < h; i++)
		{
			for (j = i + h; j < count; j += h) // gap 에 맞게 비교후 swap.
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

		while (j > 0 && input[j - 1] > temp) // 배열 i 안의 값을 기준으로 그 값보다 크면 뒤로 밀고
		{
			input[j] = input[j - 1];
			j = j - 1; // 계속 하나하나 밀면서 반복.
		}
		input[j] = temp; // 최종적으로 temp 가 가장 작은 상황일때 맨 앞에 배열 i 안의 값으로 swap.
	}
}

void Merge(int input[], int start, int mid, int end) {
	int* tmp = (int*)malloc(sizeof(int)*(end - start + 1)); // 배열을 또 만들어야하므로 동적 메모리 할당.
	int tmp_index = 0; // 처음 시작은 0
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

	free(tmp); // 동적 메모리 할당한 것 삭제.
}

void MergeSort(int input[], int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2; // 중간값 정의

	MergeSort(input, start, mid); // input 배열기준으로 start, mid 사이만큼 새로이 MergeSort 실시
	MergeSort(input, mid + 1, end); // input 배열기준으로 mid+1, end 사이만큼 새로이 MergeSort 실시 (차이가 없을때까지 재귀)

	Merge(input, start, mid, end); // 실제로 받은 MergeSort 재귀함수를 실시.
}

void QuickSort(int input[], int start, int end) {
	if (start >= end)
		return 0;
	int key = start; // 처음 pivot 은 start 로
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
	int* count = (int*)malloc(sizeof(int)*n);  // 배열을 또 만들어야하므로 동적 메모리 할당.
	for (i = 0; i<n; i++)
		count[i] = 0; // 새 배열을 0으로 초기화.
	for (i = 0; i<n; i++)
		count[input[i]]++; // 각 값의 해당하는 배열에 값을 ++
	for (i = 0; i<n; i++)
	{
		for (; count[i]>0; count[i]--) // 숫자새는용 배열에서 0 보다 큰 값들에 대하여
		{
			input[j++] = i; // 실제 배열에 순차적으로 해당 숫자를 기록
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