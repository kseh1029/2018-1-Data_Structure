## [Sorting Test 에 대한 C 파일](Sorting_test/sorting_test.c)



# Ⅰ. 과제 목적 및 측정 환경

1) 수업시간에 배운 Sorting Algorthem을 직접 코딩하고 측정하면서 각각의 소팅 방식의 Complexity 와 작동방식에 대해 숙지한다.

2) 시간측정은 Intel i5-4670 3.40GHz를 사용중인 PC에서 실시하였음.

3) C++, 파이썬에 대해 무지하여 C 프로그래밍으로 구현하였음.

# Ⅱ. 시간측정 결과

![https://blog.kakaocdn.net/dn/ej2UbW/btqLwMpDYSd/2gFW9injwQj7vb7o3wp2Yk/img.png](https://blog.kakaocdn.net/dn/ej2UbW/btqLwMpDYSd/2gFW9injwQj7vb7o3wp2Yk/img.png)

![https://blog.kakaocdn.net/dn/dSMwA3/btqLwLEigFP/c046uwI4GIKYujKUeUQKz0/img.png](https://blog.kakaocdn.net/dn/dSMwA3/btqLwLEigFP/c046uwI4GIKYujKUeUQKz0/img.png)

# Ⅲ. 소팅 분석

1) Bubble Sort

**① 소스코드**

void BubbleSort(int input[])

{

int i, temp;

while (count != 0)

{

for (i = 1; i < count; i++)

{

if (input[i - 1] > input[i])

{

temp = input[i - 1];

input[i - 1] = input[i];

input[i] = temp;

}

}

count--;

}}

**② 분석**

Bubble Sort 는 배열에서 바로 옆에 있는 값과 비교하여 더 큰 값을 뒤로 보내는 정렬방법이다.

구현은 가장 쉽지만 가장 비효율적이며 N 개의 아이템을 N-1 번 비교하며 Worst Case 일 때 N-1 번 교환 하게 되고 이러한 패턴을N 번 반복하게 되므로 Complexity 는

![https://blog.kakaocdn.net/dn/bYcPph/btqLxuI3up7/kurB7wEoyNSHzRFKYBSWR1/img.jpg](https://blog.kakaocdn.net/dn/bYcPph/btqLxuI3up7/kurB7wEoyNSHzRFKYBSWR1/img.jpg)

이다.

이 소팅방식은 Swap을 엄청 많이 하게 된다.

메모리를 사용하지 않으며 Stable 하다.

![https://blog.kakaocdn.net/dn/mHYMh/btqLyLw3dlf/xcDGKHjsbZlGllt4Jo3Bo1/img.png](https://blog.kakaocdn.net/dn/mHYMh/btqLyLw3dlf/xcDGKHjsbZlGllt4Jo3Bo1/img.png)

실제로 배열을 만들어서 소팅을 해보니 급격하게 시간이 오래 걸리는 비효율적인 소팅방식이었다.

2) Selection Sort

**① 소스코드**

void SelectionSort(int input[])

{

int i, j, temp, min;

for (i = 0; i < count - 1; i++)

{

min = i;

for (j = i + 1; j < count; j++)

{

if (input[j] < input[min])

min = j;

}

temp = input[i];

input[i] = input[min];

input[min] = temp;

}}

**② 분석**

Selection Sort 는 배열에서 가장 작은 값을 제일 앞으로 보내는 알고리즘이다.

Bubble Sort 와 비교하는 횟수는 동일하지만 실제로 Swap 은 Bubble Sort 에 비해 적게 일어난다.

즉 Swap 은 배열을 처음부터 끝까지 비교할 동안 1 번씩만 일어나므로 적게 일어난다고 볼 수 있다.

하지만 여전히 Complexity 는

![https://blog.kakaocdn.net/dn/csLlju/btqLwKlapqk/AWSCS3xGdblQv290ratNjk/img.jpg](https://blog.kakaocdn.net/dn/csLlju/btqLwKlapqk/AWSCS3xGdblQv290ratNjk/img.jpg)

이다.

메모리를 사용하지 않으며 Stable 하다.

![https://blog.kakaocdn.net/dn/xpnaO/btqLyMJxFBE/aakngFTWkNsAXczgk9zCw1/img.png](https://blog.kakaocdn.net/dn/xpnaO/btqLyMJxFBE/aakngFTWkNsAXczgk9zCw1/img.png)

실제로 배열을 만들어서 소팅을 해보니 Bubble Sort 보다는 빨랐지만 여전히 빠르다고는 할 수 없을정도로 느렸다.

3) Insertion Sort

**① 소스코드**

void InsertionSort(int input[])

{

int i, j, temp;

for (i = 1; i < count; i++)

{

temp = input[i];

j = i;

while (j > 0 && input[j - 1] > temp)

{

input[j] = input[j - 1];

j = j - 1;

}

input[j] = temp;

}}

**② 분석**

Insertion Sort 는 앞으로 스캔을 하며 이미 Sorting 된 값이 있다고 가정하고 Selection Sort를 하는방식 이다. 따라서 필요할 때에만 위치를 바꾸게 되는 소팅방식이다. 즉 데이터가 이미 거의 정렬된 상태에 한해서는 빠르지만 Worst Case 의 경우는 Selection Sort 와 거의 비슷하다.

Complexity 는

![https://blog.kakaocdn.net/dn/ShW6x/btqLzW50BdD/w3zNCOpG0IKlEIqoeJ9AGK/img.jpg](https://blog.kakaocdn.net/dn/ShW6x/btqLzW50BdD/w3zNCOpG0IKlEIqoeJ9AGK/img.jpg)

이다.

메모리를 사용하지 않으며 Stable 하다.

![https://blog.kakaocdn.net/dn/Ki7bS/btqLAzo4XP0/3vdC6jq5jCaGJYGFa8kYk0/img.png](https://blog.kakaocdn.net/dn/Ki7bS/btqLAzo4XP0/3vdC6jq5jCaGJYGFa8kYk0/img.png)

실제로 배열을 만들어서 소팅을 해보니 Worst Case 인 경우는 랜덤된 숫자를 배열에 넣었을 때 거의 일어나지 않아서 인지 Selection Sort 에비해 빠른편이였다.

4) Shell Sort

**① 소스코드**

int ShellSort(int input[])

{

int i = 0, j = 0, k = 0;

int h = 0;

int temp = 0;

for (h = count/2; h > 0; h /= 2)

{

for (i = 0; i < h; i++)

{

for (j = i + h; j < count; j += h)

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

}}

![https://blog.kakaocdn.net/dn/MyuC9/btqLzXwZIbJ/rEcyNHWzqAXc7kktkLL7g1/img.png](https://blog.kakaocdn.net/dn/MyuC9/btqLzXwZIbJ/rEcyNHWzqAXc7kktkLL7g1/img.png)

실제로 배열을 만들어서 소팅을 해보니 이때동안 비교한 소팅과는 다르게 시간 단축이 엄청나게 되었다

5) Merge Sort

**① 소스코드**

void Merge(int input[], int start, int mid, int end) {

int* tmp = (int*)malloc(sizeof(int)*(end - start + 1));

int tmp_index = 0;

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

free(tmp);

}

void MergeSort(int input[], int start, int end) {

if (start >= end) return;

int mid = (start + end) / 2;

MergeSort(input, start, mid);

MergeSort(input, mid + 1, end);

Merge(input, start, mid, end);

}

**② 분석**

Merge Sort 는 Recursion을 이용하여 배열을 절반씩 나누어서 최종적으로 배열의 값이 1개일 때 까지 나 누고, 나누어진 sublist 들 끼리 비교를 하며 합쳐가는 소팅방식이다. 정확히 반으로 나눠 sublist를 비교하 며 합쳐가므로

![https://blog.kakaocdn.net/dn/cYkzYK/btqLxvOJrxM/j00U62iKZEeHLwH5cjXZpK/img.jpg](https://blog.kakaocdn.net/dn/cYkzYK/btqLxvOJrxM/j00U62iKZEeHLwH5cjXZpK/img.jpg)

의 교환을 총

![https://blog.kakaocdn.net/dn/cQqoyN/btqLvGKbsvY/1X0SYqefQCupxdrNjTbaM0/img.jpg](https://blog.kakaocdn.net/dn/cQqoyN/btqLvGKbsvY/1X0SYqefQCupxdrNjTbaM0/img.jpg)

번 하므로 Worst Case 에도 Complexity 가

![https://blog.kakaocdn.net/dn/diwrvn/btqLzGvqa1k/67qlDj71VqWgIToFiDa3uK/img.jpg](https://blog.kakaocdn.net/dn/diwrvn/btqLzGvqa1k/67qlDj71VqWgIToFiDa3uK/img.jpg)

으로 상당히 빠른 소팅방식이다.

이 때 갭 사이즈는 소수로 만드는 것이 좋다. 그렇지 않은 수를 갭으로 둔다면, 통계적으로 비교하고 교환하 는 상황이 갭이 줄었을 때에도 더 많이 일어날 가능성이 크기 때문이다.

메모리를 사용하며 Stable 하다.

실제로 배열을 만들어서 소팅을 해보니 코드는 복잡했지만 빠른 시간내에 오름차순으로 정렬이 되었다.

![https://blog.kakaocdn.net/dn/vIeqn/btqLBMBuDec/IMznoJDO6lokkbTcW8uPwK/img.png](https://blog.kakaocdn.net/dn/vIeqn/btqLBMBuDec/IMznoJDO6lokkbTcW8uPwK/img.png)

6) Quick Sort

**① 소스코드**

void QuickSort(int input[], int start, int end) {

if (start >= end)

return 0;

int key = start;

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

**② 분석**

Quick Sort 는 정렬을 할 때 대표적으로 사용되는 빠른 알고리즘이다. Merge Sort 와 비슷하게 반으로 나 눠가면서 값을 비교하는 것이 특징인데 차이점은 Merge Sort 는 배열을 정확하게 절반씩 절반씩 recursion 하게 나눈다음 비교하면서 합쳐가는 반면에Quick Sort 는 Pivot을 중심으로 나눠서 비교하는 차이가 있다.

따라서 QuickSort 함수안에 Pivot 중심으로 왼쪽배열, 오른쪽배열을 다시 Recursion 해주는 방식으로 구성 해야하며 최종적으로Recursion 의 끝은 배열의 값이 1개일 때 return을 시켜줘야 한다. 그렇지 않으면 무 한 반복에 빠지게 될 것이다. Quick Sort 의 평균Complexity 는

![https://blog.kakaocdn.net/dn/baQArT/btqLwLxysfj/rL9ZKLmpVpSzw3adrLxUI0/img.jpg](https://blog.kakaocdn.net/dn/baQArT/btqLwLxysfj/rL9ZKLmpVpSzw3adrLxUI0/img.jpg)

) 으로 Merge Sort 와 비슷하

나 Worst Case 에는

![https://blog.kakaocdn.net/dn/MAN13/btqLBMO14oL/Rw5pIBA386wqU219gkCJwk/img.jpg](https://blog.kakaocdn.net/dn/MAN13/btqLBMO14oL/Rw5pIBA386wqU219gkCJwk/img.jpg)

으로 상당히 느리게 된다.

만약 이미 소팅된 배열을 Quick Sort 한다면 Worst Case 가 될 것이다.

메모리는 사용하지 않으며 Not Stable 하다.

실제로 배열을 만들어서 소팅을 해보니 빠른 시간내에 소팅이 되었다.

![https://blog.kakaocdn.net/dn/bvyp9x/btqLzYJxa3c/aOKq1hYEnqUMKun9LWB4q1/img.png](https://blog.kakaocdn.net/dn/bvyp9x/btqLzYJxa3c/aOKq1hYEnqUMKun9LWB4q1/img.png)

7) Heap Sort

**① 소스코드**

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

**② 분석**

Heap Sort 는 Merge Sort, Quick Sort 만큼 빠른 소팅 알고리즘이며 Tree 알고리즘을 이용하여 정렬을 한다. Tree 알고리즘을 사용하면 최솟값이나 최댓값을 빠르게 찾아낼 수 있어서 소팅에 큰 도움이 된다. 이 때 Max Heap, Min Heap 두가지가 있는데 Max Heap 은 모든 Parent 가 모든 Child 보다 큰 상황이다. Heap Sort를 하려면 힙을 Make 하는 알고리즘을 만들어야 한다. 그렇지 않으면 몇몇의 Parent 기준으로는 Max Heap 일 지라도 어떤 Parent 기준으로는 Max Heap 이 아닐 수도 있다.

각각의 Parent 가 2개의 Child를, 그 Child 는 Parent 가 되어 2개의 Child를 가져 Complxity 가

![https://blog.kakaocdn.net/dn/bOm0Qh/btqLxuoMkNN/Upk0dWGyxRj3QMer0dUdL0/img.jpg](https://blog.kakaocdn.net/dn/bOm0Qh/btqLxuoMkNN/Upk0dWGyxRj3QMer0dUdL0/img.jpg)

이다. 여기서 모든 데이터를 기준으로 힙을 Make 하려면 N번 반복해야 하므로 전체 트리를 힙 구 조로 만들면

![https://blog.kakaocdn.net/dn/cIIloC/btqLxv2htTM/dkB6hQlJEFLCdVk9mf3jO1/img.jpg](https://blog.kakaocdn.net/dn/cIIloC/btqLxv2htTM/dkB6hQlJEFLCdVk9mf3jO1/img.jpg)

이 된다.

메모리를 사용하지만 Not Stable 하다.

![https://blog.kakaocdn.net/dn/cpY0JV/btqLwKFqakB/0KE2nqQPKMMoguV2voqugk/img.png](https://blog.kakaocdn.net/dn/cpY0JV/btqLwKFqakB/0KE2nqQPKMMoguV2voqugk/img.png)

8) Bin Sort

**① 소스코드**

void BinSort(int input[], int n) {

int i, j = 0;

int* count = (int*)malloc(sizeof(int)*n);

for (i = 0; i<n; i++)

count[i] = 0;

for (i = 0; i<n; i++)

count[input[i]]++;

for (i = 0; i<n; i++)

{

for (; count[i]>0; count[i]--)

{

input[j++] = i; //

}

}

}

**② 분석**

Bin Sort 는 Radix Sort를 만들기 위한 기본적인 Sorting 이라고 볼 수 있다. 각각의 데이터를 Hash Table을 만들어서 값을 부여한다. 이때 단점으로는 Hash Table 이 Bin Sort 의 데이터의 최대값만큼 만들 어지므로 최악의 경우에는 엄청나게 큰 메모리를 사용하게 될 수도 있다. 이러한 문제를 해결하기 위해서 Bucket Sort 라는 방식으로 Bin 으로 나누어진 것을 다시 Sort 하면서 해결이 된다.

![https://blog.kakaocdn.net/dn/SQzor/btqLzG3o3FI/glWzJQSyKWpTs4a7j7cwm1/img.png](https://blog.kakaocdn.net/dn/SQzor/btqLzG3o3FI/glWzJQSyKWpTs4a7j7cwm1/img.png)

메모리를 사용하며 Stable 한 것이 특징이다.

이 때 Complexity 는

![https://blog.kakaocdn.net/dn/bLvj4w/btqLwe01H7l/nufO0hS7AaEbZ78ryKgrh0/img.jpg](https://blog.kakaocdn.net/dn/bLvj4w/btqLwe01H7l/nufO0hS7AaEbZ78ryKgrh0/img.jpg)

이 되며

![https://blog.kakaocdn.net/dn/lC2Ct/btqLzWY8oCt/VjEfWWtKtvMa901xx3zcok/img.jpg](https://blog.kakaocdn.net/dn/lC2Ct/btqLzWY8oCt/VjEfWWtKtvMa901xx3zcok/img.jpg)

은 linear 검사로 인해 생긴 Complexity 이다.

9) Radix Sort

**① 소스코드**

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

**② 분석**

Radix Sort 는 데이터를 비교하지 않고도 정렬하는 방법이다. 입력 데이터에 대해 어떤 비교 연산을 하지

않는다는 것은 굉장히 빠른 속도로 Sorting 할 수 있다는 것 이다. 리스트의 있는 아이템의 자리수로 해싱을

하여 Bin Sort를 반복하는것이며 자리수 별로 소팅을 한다.

base 가 크면 클수록 소팅의 속도가 빨라지는 것을 확인할 수 있다.

이 때 Complexity 는

![https://blog.kakaocdn.net/dn/cxxCaY/btqLvFYRJ37/DsMdvuQlUu8n7aShECqfNk/img.jpg](https://blog.kakaocdn.net/dn/cxxCaY/btqLvFYRJ37/DsMdvuQlUu8n7aShECqfNk/img.jpg)

부터

![https://blog.kakaocdn.net/dn/phWng/btqLBN8eRxu/myAdFQfemddKJZkElEhRNK/img.jpg](https://blog.kakaocdn.net/dn/phWng/btqLBN8eRxu/myAdFQfemddKJZkElEhRNK/img.jpg)

까지 상당히 빠른 소팅방식이다.

![https://blog.kakaocdn.net/dn/exB44X/btqLwMpEpUT/iJtai1O4FZEDfdwOCv0221/img.png](https://blog.kakaocdn.net/dn/exB44X/btqLwMpEpUT/iJtai1O4FZEDfdwOCv0221/img.png)

메모리를 사용하며 Stable 한 것이 특징이다. 메모리와 Complexity 가 Trade-off 관계임을 확인할 수 있다.

# Ⅳ. 고찰

이번 과제를 통해 9 가지의 소팅 방법에 대해 알아보았다. 평소 프로그래밍 언어를 배우면서 구현을 하는것에만 신경을 썼었다. 하지만 이번 과제를 통해 효율적인 프로그래밍을 위해서는 복잡도가 낮게 설계해야할 뿐만 아니라 메모리와 복잡도는 Trade-Off 관계를 가짐을 알게 되었다. 이러한 구현을 위해서는 코딩을 할 때 단순히 Swap을 반복하는 방식으로 구현해서는 안된다. 즉 단순하게 코딩하는게 아닌 기술적인 요소가 필요했다.

이 과제에서 Rand() 함수를 사용해서 데이터를 랜덤으로 부여했는데 시간함수를 사용하지 않고 했더니 시간이 일정하게 나와서 시간함수를 사용해, 모든 배열이 무작위로 나오게 한 뒤 평균을 측정하였다.

첫 번째로 Bubble Sort 는 가장 단순한 소팅 방식이였다. 자료구조와 알고리즘 수업을 듣지 않더라도 충분히 생각해볼 수 있는 소팅 방식이였기에 손쉽게 코딩을 할 수 있었다. 하지만 예상한대로 메모리도 사용하지 않고 수많은 Swap을 하기 때문에 속도가 가장 느렸다. 10000 개의 배열까지는 속도가 그렇게 느리지 않았기 때문에 적은 데이터와 적은 배열을 다룰 때에는 어려움 없이 이 소팅방법을 사용해도 문제는 없을 것 같다. 하지만 많은 데이터를 다루기에는 상당히 비효율적이다.

두 번째로 Selection Sort 는 Bubble Sort 와 다를 것 없이 코딩이 간단했다. Bubble Sort처럼 무조건 Swap을 해나가는게 아니라 한번 For 문이 반복할 때 마다 1번만 Swap 하는 방식으로 바꿔주면 됐다. 1번씩만 Swap을 하기 때문에 복잡도가 낮아질거라고 생각했는데 실제로는 복잡도는 똑같았으며 시간은 조금 줄어들었다. 그래도 Bubble Sort 에 비해서는 엄청나게 개선된 소팅 방식이라고 본다.

세 번째로 Insertion Sort 는 이미 소팅이 거의 다 되었을 때 사용하는 것이 좋다고 생각이 들었다. 그 이유는 애초에 이 소팅 방식은 앞에서부터 스캔하면서 이미 소팅이 되었다라고 가정하고 진행을 하기 때문이다. 만약 소팅이 대부분 되어있다면 상당히 빠르지만 그렇지 않다면 앞에서 진행한 두 소팅방식과 다를 바 없이 느렸다.

과제를 진행할때에는 그래도 대부분이 소팅이 된 상태로 랜덤값이 나온 덕분인지 Selection Sort 보다는 2배는 빨랐다.

네 번째로 Shell Sort 는 소팅할 배열을 gap 의 개수로 나눠서 소팅을 진행하였다. 따라서 기술적으로 gap을 중심으로 둔 뒤 gap 기준으로 왼쪽, 오른쪽을 변수로 둬서 for 문으로 비교, swap 하는 방식으로 하면 비교횟수도 줄뿐만 아니라 swap 횟수도 적기 때문에 책에서 배운데로 구현이 가능하다. 물론 앞에 소팅 방식과 비교하면 어려운 편이지만 앞의 소팅방식과는 비교도 안 될 정도로 상당히 빠른 구현이 가능했다. 물론 정확한 복잡도는 수식으로 알 수 없지만 통계적으로는 앞에서 한 3가지 소팅방식보다는 빠르다고 확인할 수 있다.

다섯 번째로 Merge Sort 는 배열의 중심을 기준으로 두 배열로 나누고, 이 나누어진 배열을 중심으로 또 두 개의 배열로 나누고를 반복해 각 배열마다 1개의 데이터만 가질 때 까지 Recursion 함수를 이용해서 나눠가게 구현을 하면 된다. 재귀 함수를 사용하기 때문에 Merge 라는 함수가 있다면 이 함수를 함수안에서 또 부르도록 만들어야 하며 만약 데이터 사이즈가 1이랑 같으면 재귀를 멈추도록 설계하여야 한다. 그리고 나서 다시 합치면서 비교를 하므로 모든 배열을 선형 스캔하지 않기 때문에 상당히 소팅속도가 빨랐다. Shell Sort 에 비해서 구현이 더 까다롭고 재귀함수를 다루기 때문에 탈출을 시켜주는 것을 고려해야 하지만 결과는 상당히 좋아서 앞으로 소팅할일이 있다면 대부분 Merge Sort 로 구현해도 상관이 없다는 생각이 들었다.

여섯 번째로 Quick Sort 는 Merge Sort와 비슷한 방식으로 구현을 할 수 있는데, 차이점은 배열의 가운데를 중심으로 배열을 나누는게 아니라 pivot 값을 정하고 pivot 보다 작고 큰 값을 최대한 swap을 다하고, 더 이상 할 게 없을 때 배열을 나누는 방식이다. 그래서 평균적으로는 Merge Sort 와 비슷한 복잡도를 가지지만 최악의 경우에는 Bubble, Selection, Insertion 같은 느린 소팅방식이랑 다를게 없는 꼴이 되었다. 또한 Stable 하지 못하기 때문에 같은 값이더라도 고유한 기능이 있다고 쳤을 땐 Quick Sort는 해서는 안 될 것 같다.

일곱 번째로 Heap Sort 는 Tree 알고리즘이라고 생각하고 선형 배열을 다루는 방식이다. 여기서는 Max heap, Min heap 두 가지 방법이 있는데 책에서는 Max Heap을 중심으로 다뤘으므로 Max heap 이 되도록 구현을 했다. 배열에서 n 번째, 2n 번째, 2n+1 번째 의 데이터가 소팅되도록 정렬을 한다면 Heap Sorting을 할 수 있으며 항상 MaxHeap을 유지하는 함수를 만들어서 확인을 해 주는 것이 중요하다. 처음에는 이미 선형인 배열을 어떻게 Tree 로 생각해야하는지 고민이 많았는데 생각보다는 단순한 방법이였으며 이러한 트릭을 이용해서 배열을 진행하는 방식이 정말 신기했다.

마지막으로 Bin Sort와 Radix Sort는 Hash table을 이용하여 정렬을 하는 방식이다. Bin Sort 의 단점은 아무래도 엄청나게 큰 데이터가 있다고 치면 그만큼의 Hash Table을 만들어야 하므로 메모리 낭비가 엄청 심하지만 Bucket Sort는 Collision 이 발생할지라도, 그것을 감수하고 특정한 개수의 해시 테이블내에서 배열하도록 해준 방법이다. Bucket Sort에서 특정 개수를 정해서 소팅하는 것을 Radix Sort 라고 볼 수 있으며 Radix Sort는 해시테이블이 8개, 16개, 32개로 각각 실험해 봤을 때 해시테이블이 32개일 때 가장 빠른 것을 알 수 있었다. 주로 우리는 10진법을 사용하기에 숫자를 소팅할 때 해시테이블을 10개로 두고 진행을 하며, 알파벳 같은 경우는 해시테이블을 26개로 두고 진행을 하게 된다. 물론 대문자 까지 고려할 땐 52개가 필요하다. 따라서 사전 프로그램이나 검색 엔진에서 오름차순, 내림차순으로 정렬을 한다면 Radix Sort를 사용하는 것이 상당히 유리하다는 생각이 들었다.

내가 만약 프로그래밍을 하면서 소팅을 하게 된다면 간단한 개수의 소팅을 할 때에는 Bubble Sort로 손쉽게 코딩해서 사용을 할 것 같고, 수 많은 숫자를 소팅할 때에는 Merge Sort를 사용할 것 같다. 물론 한글이나 알파벳을 오름/내림 차순으로 정렬할 때에는 Radix Sort를 사용할 것 같다.

이처럼 수 많은 소팅 방법을 비교해가면서 가장 나에게 맞는 소팅방법을 찾게 되었다. 이 과제로 인해서 나의 프로그래밍의 식견을 넓힐 수 있어서 상당히 좋았다.
