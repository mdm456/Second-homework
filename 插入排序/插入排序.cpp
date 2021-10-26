#include<iostream>
using namespace std;

void insertsort(int a[],int n)
{
	for(int i=1;i<n;i++)//第一个元素视为已排好，从第二个元素开始把其插到正确位置 
	if(a[i]<a[i-1])//如果第一个元素比前面的元素小
	{
		int j=i-1;//此时判断第i个元素与前面所有元素的大小，然后换成j继续判断
		int x=a[i];//将第i个元素复制为标记元素 
		while(j>=0&&x<a[j])//找标记元素的正确位置，比标记元素大的元素依次后移
		{
			a[j+1]=a[j]; 
			j--;
		 } 
		 a[j+1]=x;//把标记元素插入到正确位置 
	 } 
}
void print(int a[],int n)
{
	for(int j=0;j<n;j++)
	{
		cout<<a[j]<<" ";
	}
	cout<<endl;
}
int main(){
	int a[10]={1,4,2,6,7,23,12,21,33,26};
	cout<<"初始排序："<<" "; 
	print(a,10);
	insertsort(a,10);
	cout<<"最终排序："<<" ";
	print(a,10);
	system("pause");
}
