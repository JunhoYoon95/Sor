#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int main() {

    vector<int> first = {9,2,5,1,6,7,3,8,4,0};
    
    cout << "기존의 배열 : " << endl;
    for(int i = 0; i < first.size(); i++)
    {
        cout << first[i] << " ";
    }
    cout << endl;
    
    
    cout << "\n정렬 후의 배열 : " << endl;
    sort(first.begin(),first.end());
    for(int i = 0; i < first.size(); i++)
    {
        cout << first[i] <<" ";
    }
    cout << endl;
    
    cout << "\n정렬 후 역순 적용 : " << endl;
    reverse(first.begin(), first.end());
    for(int i = 0; i < first.size(); i++)
    {
        cout << first[i] <<" ";
    }
    cout << endl;
    return 0;
}
