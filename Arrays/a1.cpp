#include <iostream>
using namespace std;
// If decleared array outside the main with n size then whole array will be filled with 0
//  id declared array inside the main with n size then whole array will be filled with garbage values
//  max size/len  of array is 10^6 inside the main
// max size/len of array is  10^7 outside the main

// 1) Largest element in the arra
int Largest(int array[], int len)
{
    int max = array[0];
    for (int i = 1; i < len; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
    // TIME  COMPLEXITY : O(N) => optimal
}
// 2) Second largest element
//  Better solution : O(n)
int Second_largest(int array[], int len)
{
    int max = array[0];
    for (int i = 1; i < len; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    int sec_largest = 0;
    for (int i = 0; i < len; i++)
    {
        if (array[i] > sec_largest && array[i] != max)
        {
            sec_largest = array[i];
        }
    }
    return sec_largest;
}
// OPTIMAL :
int Second(int array[], int len)
{
    int second = INT_FAST32_MIN;
    int max = array[0];
    for (int i = 0; i < len; i++)
    {
        if (array[i] > max)
        {
            second = max;
            max = array[i];
        }
        else if (array[i] < max && array[i] > second)
        {
            second = array[i];
        }
    }
    return second;
}

// min
int Min(int array[], int len)
{
    int min = INT_FAST16_MAX;
    for (int i = 0; i < len; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
    }
    return min;
}
// Second min
int SMin(int array[], int len)
{
    int min = INT_FAST16_MAX;
    int sec = INT8_MIN;
    for (int i = 0; i < len; i++)
    {
        if (min > array[i])
        {
            sec = min;
            min = array[i];
        }
        else if (array[i] > min && array[i] < sec)
        {
            sec = array[i];
        }
    }
    return sec;
}
bool check_sort(int array[], int len)
{
    bool ans = true;
    for (int i = 0; i <= len / 2; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}
//Unique ele
int unique(int array[],int len){
    int index = 0;
    for(int i =1 ; i<len;i++ ){
        if (array[index]!=array[i])
        {
            array[index+1] = array[i];
        }
    }
    return index+1;
}

int main(){
    int array[5] = {1, 2, 1, 1, 1};
    cout<<unique(array,5);
}
    
