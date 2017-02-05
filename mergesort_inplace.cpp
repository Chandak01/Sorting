#include <iostream>
using namespace std;

void mergeinpl(int a[], int l, int m, int h)
{
	int i=l;
	int j=m+1;
	while(l<=m || j<=h)
	{
		if(a[l]<=a[j])
			l++;
		else
		{
			int temp = a[j];
			int k;
			for(k=j;k>l;k--)
				a[k] = a[k-1];
			a[k] = temp;
			l++;
			j++;
		}
	}
}

void sort(int a[],int l,int h)
{
	if(l<h)
	{
		int m = l + (h-l)/2;
		sort(a,l,m);
		sort(a,m+1,h);
		mergeinpl(a,l,m,h);
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
	sort(a,0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}