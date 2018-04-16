#include <stdio.h>
#include <stdlib.h>

void display(int no);
void sortPrograms(int no);
void optStorage(int no);
void init(int no);

int a[15], b[15];

void sortPrograms(int no)
{
	int i, j, temp;
	for (i = 0; i < no - 1; i++)
	{
		for (j = 0; j < no - i - 1; j++)
		{
			if (a[j + 1] < a[j])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	display(no);
}

void display(int no)
{
	for (int i = 0; i < no; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void init(int no)
{
	for (int i = 0; i < no; ++i)
	{
		b[i] = 0;
	}
}

void optStorage(int no)
{
	int sum = 0, pSum = 0;
	//check the below code. working for some inputs, hence created v2.
	for (int i = 0; i < no; ++i)
	{
		pSum = pSum + a[i];
		sum = pSum + a[i];
		b[i] = sum;
	}
	printf("Total length is: %d\n", b[no - 1]);
	printf("Mean time is: %f\n", b[no - 1] / (float)no);
}

int main(int argc, char const *argv[])
{
	int no;
	printf("Enter no. of programs: \n");
	scanf("%d", &no);
	printf("Enter the lengths:\n");
	for (int i = 0; i < no; ++i)
	{
		scanf("%d", &a[i]);
	}
	printf("Original list is: ");
	display(no);
	printf("Sorted list is: ");
	sortPrograms(no);
	init(no);
	optStorage(no);
	return 0;
}
