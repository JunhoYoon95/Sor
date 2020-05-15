
# 정렬 알고리즘 5가지 (C++)

  c++, Java, Python 등 프로그래밍 및 자료구조, 이산수학, 화일처리 등에서 배우는 정렬 알고리즘에 대해 다룰 것이다. 항상 정렬 알고리즘을 배우고, 직접 구현을 해도 항상 머리속에 남질 않는다. 
코드로 아무리 봐도 머리속에 남지 않는 경우가 많아, 시각적인 애니메이션과 함께 설명을 하려 한다. 
정렬 알고리즘은 한 번 정도는 확실하게 익히고 갈 필요성이 있다.

많은 정렬 알고리즘들이 존재하지만 가장 기본적인 5가지 정렬 알고리즘에 대해서 다룰 것이다.

## 목차 
>1. merge sort (합병 정렬)
>2. insertion sort (삽입 정렬)
>3. selection sort (선택 정렬)
>4. bubble sort (버블 정렬)
>5. quick sort (퀵 정렬)


### 1. Merge Sort(합병 정렬)

```cpp
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
```
