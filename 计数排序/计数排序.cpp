#include <iostream>
#include <math.h>
//cutingsort.cpp�������� 
using namespace std;

bool coutingSort(int array[], size_t arrLen) {
    if (arrLen < 2) {
        return true;
    }

    //Find maximum and minimal value
    int max = array[0];//��¼���е����ֵ 
    int min = array[0];//��¼���е���Сֵ 

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
    int *countingBuckets = new int[max - min + 1]();//�����������ֵ��Сֵ�ò�ֵ 

    // Count number of values in array
    for (size_t j = 0; j < arrLen; ++j)
    {
        ++countingBuckets[array[j] - min];//ͳ��Ԫ�ظ��� 
    }

    // Accumulate coutingBuckets to find the last ordered location of value in array
    for (size_t k = 1; k < (max - min + 1); ++k)
    {
        countingBuckets[k] += countingBuckets[k-1];
    }

    //Traverse the array in reversed order
    int *tempArray = new int[arrLen]();
    for (int l = arrLen - 1; l >= 0; --l)//�������ԭʼ���飬��ͳ���������ҵ���ȷλ�� 
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
    cout<<"����ǰ��"<<endl;
    printArray(array, arrayLen);
    coutingSort(array, arrayLen);
    cout<<"\n\n���������"<<endl;
    printArray(array, arrayLen);
}
