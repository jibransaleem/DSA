#include <iostream>
#include <vector>
using namespace std;
// sort an array with zeros and ones
// first appraoch is to count all zeros ,ones and twos and then make a new seprate array with ones and twos:time Complexity (2n) and space complex is (On)
// Too optimize this code we will use ducth national flag algorithim : Time complex (n) and space complex is O(3)
//DNF ALGO
void arrange(vector <int> numbers){
    int low = 0 ;
    int mid = 0 ;
    int high = numbers.size()-1;
    while(high>=mid){
        if (numbers[mid]==0){
            swap(numbers[mid],numbers[low]);
            low++;
            mid++;
        }
        else if (numbers[mid]==1){
            mid++;
        }
        else if (numbers[mid]==2){
            swap(numbers[mid],numbers[high]);
            high--;
        }
    }
    for (int i : numbers){
        cout << i << " ";
    }
}
//moores voting algo
int majority(vector <int> numbers){
    int freq= 0;
    int answer = 0;
        for (int i =0 ; i<numbers.size();i++){
            if (freq==0){
                answer = numbers[i];
            }
            else if(answer==numbers[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
        return answer;
   
}
//kadanes algo
int max_Sum_subarray(vector <int> numbers){
    int sum = 0 ; 
    int ans = INT16_MIN;
    for (int i : numbers){
        sum+=i;
        ans = max(sum,ans);
        if( sum<0 ){
        sum = 0;
    }
    }
    
    return ans;

}
int main(){
    vector <int> numbers = {2, -4};
    cout<< max_Sum_subarray(numbers);
    return 0 ;
}