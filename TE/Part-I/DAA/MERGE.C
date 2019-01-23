#include<stdio.h>
#include<conio.h>

static int arr[] = {2, 5, 8, 3, 7, 9};

void merging(int l, int m, int h)
{
	int n1 = m+1, n2 = (h-m)+1;
	int *L, *R;
	int i;

	L = (int *)calloc(sizeof(int), n1);
	R = (int *)calloc(sizeof(int), n2);

	for(i=l;i<m-1;i++)
		L[i] = arr[i];
	for(i=m;i<h;i++)
		R[i] = arr[i];


	for(i=l;i<m-1;i++)
		printf("%d  ", L[i]);
	printf("\n");
	for(i=m;i<h;i++)
		printf("%d  ", R[i]);

}


void mergeSort(int low, int high)
{
	int mid;

	if(low < high)			//termination condition
	{
		mid = (high + low)/2;
		mergeSort(low, mid);
		mergeSort(mid+1, high);
		merging(low, mid, high);
	}
}

void main()
{
	int low,mid,high;
	int i,j;
	clrscr();
	low = 0; high = 6;
	mergeSort(low, high);
	getch();

}