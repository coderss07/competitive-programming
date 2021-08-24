  
#include<stdio.h>
#include<malloc.h>
int tempSIZE;
void mergeSort(int * arr,int i,int m,  int n,int *cmps,int *invs)
{
	printf("\nCalled merge sort F = %d || L = %d || mid = %d",i,n,m);
	system("pause");
	int ti = i, j = m+1;
	int * ar = (int *)malloc((n-i+1)*sizeof(int));
	int l = 0;
	while(ti<=m&&j<=n)
	{
		(*(cmps))++;
		if(arr[ti]<arr[j])
		{
			ar[l] = arr[ti];
			printf("\n 1 => %d %d", arr[i],arr[j]);
			printf("\n 1.a => %d",ar[l]);
			l++;ti++;
		}
		else
		{
			(*(invs))++;
			printf("\n 2 => %d %d", arr[ti],arr[j]);
			ar[l] = arr[j];
			printf("\n 2.a => %d",ar[l]);
			l++;j++;
		}
	system("pause");	
	}
	while(ti<=m)
	{
		(*(cmps))++;
		ar[l] = arr[ti];
		l++;ti++;
	}
	while(j<=n)
	{
		(*(cmps))++;
		(*(invs))++;
		ar[l] = arr[j];
		l++;j++;
	}
	printf("\nConsider only this Topp\n");
	for(ti=0;ti<(n-i+1);ti++)
	{
		printf("%d ",ar[ti]);
	}
	printf("\nConsider only this bott\n");
	int tk = 0;
	for(ti=i;tk<(n-i+1);ti++,tk++)
	{
		arr[ti] = ar[tk];
	}
	for(i=0;i<tempSIZE;i++)
	{
		printf("%d ",arr[i]);
	}
}
void mergeDivide(int *arr, int F, int L,int *cmp,int *inv)
{
	if(F<L)
	{
		int mid = (F+L)/2; 
		printf("\nIN divide F = %d || L = %d || mid = %d",F,L,mid);
		printf("\n calling first merge");
		printf("\n Is it working?");
		system("pause");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
		printf("\n***AFTER THIS?***");
		system("pause");
		mergeDivide(arr,F,mid,cmp,inv);
		printf("\nIN divide F = %d || L = %d || mid = %d",F,L,mid);
		printf("\n calling second merge");
		system("pause");
		mergeDivide(arr,mid+1,L,cmp,inv);
		printf("\nIN divide F = %d || L = %d || mid = %d",F,L,mid);
		printf("\n calling mergeSort");
		system("pause");
		mergeSort(arr,F,mid,L,cmp,inv);
	}
}
int main()
{
//	int ti,i,n= 10;
//	int arr[10] = {10,9,8,7,6,5,4,3,2,1};
	
//	for(ti=0;ti<n;ti++)
//	{
//		
//		printf("%d ",arr[ti]);
//	}
//	printf("\n");
//	mergeDivide(arr,0,n-1);
//	printf("\n?IN the end \n");
//	for(i=0;i<n;i++)
//	{
//		printf("%d ",arr[i]);
//	} 
	int noc,i,**arr,*noe,*rep,j,*cmps,*invs;
	scanf("%d",&noc);
	arr = (int **)malloc(noc*sizeof(int *));
	rep = (int *)malloc(noc*sizeof(int));
	cmps = (int *)malloc(noc*sizeof(int));
	invs = (int *)malloc(noc*sizeof(int));
	noe = (int *)malloc(noc*sizeof(int));
	for(i = 0;i<noc;i++)
	{
		scanf("%d",noe+i);
		tempSIZE = *(noe+i);
		*arr = (int *)malloc((*(noe+i))*sizeof(int));
//		printf("\nGOOD 1");
		for(j=0;j<*(noe+i);j++)
		{
			scanf("%d",*(arr+i)+j);
		}
		*(cmps+i) = 0;
		*(invs+i) = 0;
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
//		printf("\nFILLING STACK MEMORY...");
		printf("\nBelow array is from main\n");
		for(j=0;j<*(noe+i);j++)
		{
			printf("%d ",*(*(arr+i)+j));
		}
		printf("\nAbove array was from main\n");
		system("pause");
		mergeDivide(*(arr+i),0,*(noe+i)-1,cmps+i,invs+i);
//		*(rep+i) = 0;
//		printf("\n");
//		for(j=0;j<noe;j++)
//		{
//			printf("%d ",*(arr+j));
//		}
//		for(j=0;j<noe-1;j++)
//		{
//			printf("\nrep = %d ",*(rep+i));
//			printf("\n %d == %d",arr[j],arr[j+1]);
//			system("pause");
//			if(arr[j] == arr[j+1])
//			{
//				*(rep+i) = 1;
//				break;
//			}
//		}
//		free(arr);
	printf("\nAt the end of main\n");
		for(j=0;j<*(noe+i);j++)
		{
			printf("%d ",*(*(arr+i)+j));
		}
	}
	for(i = 0;i<noc;i++)
	{
		printf("\n");
		for(j=0;j<*(noe+i);j++)
		{
			printf("%d ",*(*(arr+i)+j));
		}
		printf("\ncomparisons = %d",*(cmps+i));
		printf("\ninversions = %d",*(invs+i));
//		if(*(rep+i) == 1)
//			printf("\nYES");
//		else
//			printf("\nNO");
	}
	return 0;
}