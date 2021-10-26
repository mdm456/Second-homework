#include <iostream>
#include <math.h>
//cutingsort.cpp计数排序 
using namespace std;

bool coutingSort(int array[], size_t arrLen) {
    if (arrLen < 2) {
        return true;
    }

    //Find maximum and minimal value
    int max = array[0];//记录数列的最大值 
    int min = array[0];//记录数列的最小值 

    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        else if (max < array[i]) {
            max = array[i];
        }
    }

    // Create counting buckets
    int *countingBuckets = new int[max - min + 1]();//计算数列最大值最小值得差值 

    // Count number of values in array
    for (size_t j = 0; j < arrLen; ++j)
    {
        ++countingBuckets[array[j] - min];//统计元素个数 
    }

    // Accumulate coutingBuckets to find the last ordered location of value in array
    for (size_t k = 1; k < (max - min + 1); ++k)
    {
        countingBuckets[k] += countingBuckets[k-1];
    }

    //Traverse the array in reversed order
    int *tempArray = new int[arrLen]();
    for (int l = arrLen - 1; l >= 0; --l)//倒序遍历原始数组，从统计数组中找到正确位置 
    { 
        tempArray[--countingBuckets[array[l] - min]] = array[l];
    }

    for (size_t m = 0; m < arrLen; ++m)
    {
        array[m] = tempArray[m];
    }

    delete [] countingBuckets;
    delete [] tempArray;

    
    return true;
}

void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int array[10] = {9,30,3,32,5,10,12,14,16,20};
    int arrayLen = sizeof(array)/sizeof(int);
    cout<<"排序前："<<endl;
    printArray(array, arrayLen);
    coutingSort(array, arrayLen);
    cout<<"\n\n计数排序后："<<endl;
    printArray(array, arrayLen);
}
