#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Left rotate array by one place
// Space complex : O(n), extra space in the algo :O(1); time complex : O(n)
int left_rotate_by_one(int Array[], int len)
{
    int temp = Array[0];
    for (int i = 0; i < len; i++)
    {
        Array[i] = Array[i + 1];
    }
    Array[len - 1] = temp;

    for (int i = 0; i < len; i++)
    {
        cout << Array[i] << endl;
    }
    return 0;
}
// Optimal solution : reverse whole array
 //              revrse(array-(len-k))
 //  reverse(remaining ele)
int left_Rotate_by_k_places(int array[], int len, int places)
{
    int rotations = places % len;
    // Reverse using pointers
    reverse(array, array + len);
    reverse(array, array + (len - rotations));
    reverse((array + len - rotations), array + len); 
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
//Move zeros to the end
//Two poiner approach [1,0,  2,3,0,0,2,4,5]
//                       ^   ^
//                     j=| i=|
int Move_Zero(int array[],int len){
    int j = -1; // random value
    for (int i = 0; i <len; i++)
    {
        if (array[i]==0){
            j = i;
            break; // finding first zero'th number index to store in j 
        }
    }
    for (int i = j+1;i<len;i++){
        if (array[i]!=0){// initizlies i after j(j+1), as j = index of number having zero
                        // approach : if find i number which is non zero replace with j number index;
                        //then increase j 
            swap(array[i],array[j]);
            j++;
        }
    }
    for (int i = 0; i <= len-1; i++)
    {
        cout << array[i] << " ";
    }
    return 0;


}
int main()
{
    int array[9] = {1, 0,1,2,0,12,3,0,1};
    Move_Zero(array,9);
    return 0;
}