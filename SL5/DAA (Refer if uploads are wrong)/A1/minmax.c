#include <stdio.h>
#include <stdlib.h>

int a[15], min, max;

void minmax(int i, int j)
{
	int max1, min1, mid;

	//if there is 1 element
	if (i == j)
	{
		min = max = a[i];
	}
	else
	{
		//if there are 2 elements
		if (i == j - 1)
		{
			if (a[i] < a[j])
			{
				min = a[i];
				max = a[j];
			}

			else
			{
				min = a[j];
				max = a[i];
			}
		}

		else
		{
			//if there are more than 2 elements 
			mid = (i + j)/2;

			//sorting left sub list
			minmax(i, mid);
			max1 = max;
			min1 = min;

			//sorting left sub list
			minmax(mid+1, j);
			
			if (max < max1)
			{
				max = max1;
			}
			if (min > min1)
			{
				min = min1;
			}

		}
	}
}


int main(int argc, char const *argv[])
{
	
	int no;
	printf("Enter no. of elements: \n");
	scanf("%d", &no);
	printf("Enter the nos.\n");
	for (int i = 0; i < no; ++i)
	{
		scanf("%d", &a[i]);
	}

	//initializing min and max elements to a random no.
	min = a[0];
	max = a[0];
	
	//passing the 1st and last element of array
	minmax(0, no-1);
	printf("Max element is: %d\n", max);
	printf("Min element is: %d\n", min);
	return 0;
}
