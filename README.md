
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


Merge Sort(합병 정렬)

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

![merge](https://user-images.githubusercontent.com/39542989/82017084-535fe400-96bd-11ea-8a1a-7071652ab0e5.gif)

분할정복을 이용한다. 어려운 용어가 아니다. 데이터가 담겨있는 배열을 각각이 크기가 1이 될때까지 분할 하고, 
작은 것을 앞, 큰 것을 뒤에 붙여 다시 원래의 길이로 합쳐가는 과정이다. 
해당 알고리즘은 그림으로 보는 것이 편할 것 같다.

![merge](https://user-images.githubusercontent.com/39542989/82017087-53f87a80-96bd-11ea-9f9f-941a8a8cba77.png)

쉽게 말해, 배열을 반으로 쪼개고, 1개로 쪼개지면 쪼개지기 이전 단계의 다른 쪼개진 배열 조각과 정렬해 윈래의 길이로 합쳐가는 과정이다. 
