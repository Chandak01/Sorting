#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int h)
{
	int i=l;
	int j=m+1;
	int k=0;
	int c[h-l+1];
	while(i<=m && j<=h)
	{
		if(a[i]<=a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	}
	while(i<=m)
		c[k++]=a[i++];
	while(j<=h)
		c[k++]=a[j++];
	for(i=0;i<k;i++)
		a[l++]=c[i];
	return;
}

void sort(int a[],int l, int h)
{
	if(l<h)
	{
		int m = l+(h-l)/2;
		sort(a,l,m);
		sort(a,m+1,h);
		merge(a,l,m,h);
	}
	return;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,0,n-1);
	//sorted array
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}