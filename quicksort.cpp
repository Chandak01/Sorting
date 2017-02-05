#include <iostream>
using namespace std;

void swap(int& x, int& y){
	int temp = x;
	x = y;
	y=temp;
}

int partition(int a[], int l,int h)
{
	int p = a[l];
	int index = l; //index of pivot
	int i = l+1;
	for(int j=l+1;j<=h;j++)
	{
		if(a[j]<p)
		{
			swap(a[i],a[j]);
			i++;
		}
	}

	swap(a[i-1],a[l]);
	return i-1;
}

void quicksort(int a[], int l, int h)
{
	if(l<h)
	{
		int pi = partition(a,l,h);
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,h);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	int i=0;
	for(i=0;i<n;i++)
		cin>>a[i];
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}