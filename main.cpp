
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int first[] = {9,2,5,1,6,7,3,8,4,0};
    
    int size = 10;
    cout << "기존의 배열 : " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << first[i] << " ";
    }
    cout << endl;
    
    
    cout << "\n정렬 후의 배열 : " << endl;
    sort(first,first+size);
    for(int i = 0; i < size; i++)
    {
        cout << first[i] <<" ";
    }
    cout << endl;
    
    cout << "\n정렬 후 역순 적용 : " << endl;
    reverse(first, first+size);
    for(int i = 0; i < size; i++)
    {
        cout << first[i] <<" ";
    }
    cout << endl;
    return 0;
}
