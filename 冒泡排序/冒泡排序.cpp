#include<iostream>
using namespace std;
int main()
{
	//����ð������ʵ����������
	int arr[10]={2,4,3,5,7,56,8,1,10,32};
	cout<<"����ǰ��"<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	//��ʼð������
	//�ܹ���������Ϊ Ԫ�ظ���-1
	for(int i=0;i<10;i++)
	{
		//�ڲ�ѭ���Աȣ�����=Ԫ�ظ���-��ǰ����-1 
		for(int j=0;j<10-i-1;j++)
		{
			//�����һ�����֣��ȵڶ������ִ󣬽����������� 
		if(arr[j]<arr[j+1])
		{
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
	} 
	//�����Ľ��
	cout<<"�����"<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	} 
	cout<<endl;
	system("pause");
	return 0; 
}
