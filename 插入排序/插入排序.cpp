#include<iostream>
using namespace std;

void insertsort(int a[],int n)
{
	for(int i=1;i<n;i++)//��һ��Ԫ����Ϊ���źã��ӵڶ���Ԫ�ؿ�ʼ����嵽��ȷλ�� 
	if(a[i]<a[i-1])//�����һ��Ԫ�ر�ǰ���Ԫ��С
	{
		int j=i-1;//��ʱ�жϵ�i��Ԫ����ǰ������Ԫ�صĴ�С��Ȼ�󻻳�j�����ж�
		int x=a[i];//����i��Ԫ�ظ���Ϊ���Ԫ�� 
		while(j>=0&&x<a[j])//�ұ��Ԫ�ص���ȷλ�ã��ȱ��Ԫ�ش��Ԫ�����κ���
		{
			a[j+1]=a[j]; 
			j--;
		 } 
		 a[j+1]=x;//�ѱ��Ԫ�ز��뵽��ȷλ�� 
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
	cout<<"��ʼ����"<<" "; 
	print(a,10);
	insertsort(a,10);
	cout<<"��������"<<" ";
	print(a,10);
	system("pause");
}
