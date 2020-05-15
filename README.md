
# 정렬 알고리즘 5가지 (C++)

  c++, Java, Python 등 프로그래밍 및 자료구조, 이산수학, 화일처리 등에서 배우는 정렬 알고리즘에 대해 다룰 것이다. 항상 정렬 알고리즘을 배우고, 직접 구현을 해도 항상 머리속에 남질 않는다. 
코드로 아무리 봐도 머리속에 남지 않는 경우가 많아, 시각적인 애니메이션과 함께 설명을 하려 한다. 
정렬 알고리즘은 한 번 정도는 확실하게 익히고 갈 필요성이 있다.

많은 정렬 알고리즘들이 존재하지만 가장 기본적인 5가지 정렬 알고리즘에 대해서 다룰 것이다.

## 목차 
1. merge sort (합병 정렬)
2. insertion sort (삽입 정렬)
3. selection sort (선택 정렬)
4. bubble sort (버블 정렬)
5. quick sort (퀵 정렬)


### Merge Sort(합병 정렬)

~~~c
#include<iostream>

using namespace std;

int N,arr[1000001];
int *arr2;

void merge(int left, int right)
{
  int mid = (left + right) / 2;
  int i = left;
  int j = mid + 1;
  int k = left;
  
  while (i <= mid && j <= right){
    if (arr[i] <= arr[j])
    {
      arr2[k++] = arr[i++]; 
    }else
			arr2[k++] = arr[j++];
	  }
    
  int tmp = i>mid ? j : i;
  
  while(k<=right) 
    arr2[k++] = arr[tmp++];
  
  for (int i=left;i<=right;i++) arr[i] = arr2[i];
}

void partition(int left,int right){
  int mid;
  if (left < right){
		mid = (left + right) / 2; 
    partition(left, mid);
    partition(mid + 1, right);
    merge(left, right);
	}
}
int main(){
  scanf("%d",&N);
	arr2 = new int[N];
  
  for (int i=0;i<N;i++) 
    scanf("%d",&arr[i]);
  
  partition(0, N - 1);
  
  for (int i=0;i<N;i++) 
    printf("%d\n",arr[i]) ;
}
~~~
분할정복을 이용한다. 어려운 용어가 아니다. 데이터가 담겨있는 배열을 각각이 크기가 1이 될때까지 분할 하고, 
작은 것을 앞, 큰 것을 뒤에 붙여 다시 원래의 길이로 합쳐가는 과정이다. 
해당 알고리즘은 그림으로 보는 것이 편할 것 같다.
![merge](https://user-images.githubusercontent.com/39542989/82017084-535fe400-96bd-11ea-8a1a-7071652ab0e5.gif)

쉽게 말해, 배열을 반으로 쪼개고, 1개로 쪼개지면 쪼개지기 이전 단계의 다른 쪼개진 배열 조각과 정렬해 윈래의 길이로 합쳐가는 과정이다. 

![merge](https://user-images.githubusercontent.com/39542989/82017087-53f87a80-96bd-11ea-9f9f-941a8a8cba77.png)

### Insertion sort (삽입 정렬) 
~~~ c
#include<iostream>
#include<algorithm>

using namespace std;

int arr[8]={8,6,5,3,1,2,7,4};
// 예시로 하나 만들어둠
int main()
{
    int key=0;
    for(int i=1;i<8;i++)
    {
        key=arr[i];
        int index= i;

        while(index> 0 && (arr[index-1]>key))
        {
            arr[index]=arr[index-1];
            index--;
        }
        arr[index]=key;
    }
    for(int i=0;i<8;i++)
        cout<<arr[i]<<" ";
}
~~~
삽입 정렬은 배열의 앞부터 탐색하면서 가장 작은 값 순서로 해당 값을 삽입하는 방식이다.
![insertion](https://user-images.githubusercontent.com/39542989/82017083-522eb700-96bd-11ea-9e63-dcd961ac4fa7.gif)


### Selection sort(선택 정렬)

~~~ c
#include <algorithm>
#include <iostream> 

using namespace std;

int main() { 
	const int length = 5; 
	int array[length] = { 30, 50, 20, 10, 40 };
	for (int startIndex = 0; startIndex < length - 1; ++startIndex) 
	{ 
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex) 
		{ 
			if (array[currentIndex] < array[smallestIndex]) 
			smallestIndex = currentIndex; 
		}
		
		std::swap(array[startIndex], array[smallestIndex]); 
	} 
	for (int index = 0; index < length; ++index) 
		cout << array[index] << ' '; 

	return 0; 
}

~~~
선택정렬은 인덱스(지금 배열에서 어디를 보고 있는지)를 하나씩 증가시켜가며 남은 배열 중 가장 작은 값과 현재 인덱를 바꿔주는 정렬이다.
![selection](https://user-images.githubusercontent.com/39542989/82017094-55c23e00-96bd-11ea-9090-604c90f8e10d.gif)

### Bubble sort(버블 정렬)
~~~cpp
#define SWAP(x,y) {int t = ;, x = y; y = t;}
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[7] = {10,9,4,6,5,1,7}; // 예시
	int i, j;
	
	for(i = 1; i < 7; i++){
		for(j = 0; j < 7-i; j++){
			if(a[j] > a[j+1]){
				SWAP(a[j], a[j+1]);
			}
		}
	}
	for(i = 0; i < 7; i++){
		cout << a[i];
	}
	return 0;
}
~~~
버블 정렬은 배열의 시작 부터 인덱스(지금 배열에서 보고 있는 위치)의 값과 바로 다음 인덱스의 값과 비교해 앞의 값이 뒤의 값보다 큰 경우면(정렬이 되지 않은 경우면) 두 위치를 바꾸는 정렬이다. 이 정렬 방법은 가장 큰 값부터 순서대로 맨 뒤로 보내는 방식이다.
![bubble](https://user-images.githubusercontent.com/39542989/82017081-5064f380-96bd-11ea-89cf-a5c13cd65fac.gif)

### Quick sort(퀵 정렬)
~~~cpp
#include <iostream>
using namespace std;
//퀵정렬
int n,cnt, quick[10000001];

void quickSort(int i, int j)
{
	if(i>=j) return;
	int pivot = quick[(i+j)/2];
	int left = i;
	int right = j;
	
	while(left<=right)
	{
		while(quick[left]<pivot) left++;
		while(quick[right]>pivot) right--;
		if(left<=right)
		{
			swap(quick[left],quick[right]);
			left++; right--;
		}
	}
	quickSort(i,right);
	quickSort(left,j);
}

int main() 
{
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&quick[i]);

	quickSort(0,n-1);

	for(int j = 0; j < n; j++) 
		printf("%d\n",quick[j]);
}
~~~
분할정복, pivot, left, right을 사용하는 정렬이라고 볼 수 있다.
기준을 정하여 배열을 분할하고, 분할된 배열들을 정렬하고, 다시 붙이는(정복) 방식의 정렬이다.

![quick](https://user-images.githubusercontent.com/39542989/82017089-54911100-96bd-11ea-9fdf-698e87e327df.gif)

배열 가장 왼쪽을 pivot 을 지정하고 위치상 pivot 보다 뒤에 위치한 배열값들 중, pivot 바로 뒤의 값부터 pivot에서 먼 쪽으로 가면서 pivot 보다 작은 위치(몇 번째의 값인지 숫자)를 left, 가장 오른쪽 끝에서 pivot 쪽으로 오면서 pivot 보다 값이 작은 위치를 right 라고 할 것이다.

![quick2](https://user-images.githubusercontent.com/39542989/82017090-54911100-96bd-11ea-968c-df5c35f3f768.gif)

1. pivot 뒤의 배열중 가장 왼쪽 부터 확인하여 pivot 보다 작은 값으로 left 를 정한다.(left가 존재하지 않는다면 더 이상 보지 않아도 된다.)
 
2. left가 설정 되었다면 pivot 뒤의 값들 중 가장 오른쪽 부터 확인하여(left 보다 뒤의 값 중) pivot 보다 값이 작은 위치를 right 로 지정(동일하게 right 가 존재하지 않는다면 더 이상 보지 않아도 됨.)
 
3. left 와 right 모두 존재한다면 두 값을 바꾼다. 두 위치의 값을 바꿔준 후 left 를 더 뒤로 가며 다음 left를 찾는다. -> 1,2를 반복.
 
값을 바꾼 후 left를 한 칸 옮기려 할 때에 right와 같은 위치가 되려 한다면 left의 값과 pivot의 값을 교환한다.
 
1 - 3 의 정렬 한 번이 끝났다면 pivot은 자신의 위치를 찾은 것이다. 그럼 이 자리를 잡은 pivot을 기준으로 왼쪽, 오른쪽으로 분리하여 각각에서 1 - 3을 반복하며 위치를 하나씩 잡아준다. -> 분할정복
 
해당 과정을 재귀적으로 실행하여 정렬을 하는 것이 퀵정렬 이다.

![quick3](https://user-images.githubusercontent.com/39542989/82017093-5529a780-96bd-11ea-9712-5ff0b7ef7a6c.jpg)

### 정렬의 시간 복잡도 / 공간 복잡도

![bigo](https://user-images.githubusercontent.com/39542989/82017077-4d6a0300-96bd-11ea-99c6-586ddb461793.png)
