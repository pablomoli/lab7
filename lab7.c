#include <stdio.h>
#include <stdlib.h>

int bubble(int arr[], int n, int f[]);
void print(int a[], int f[]);
void reset(int n[]);
int selection(int arr[], int n, int freq[]);

int main(int argc, char const *argv[])
{

	int a1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
	int a2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
	int n = sizeof(a1) / sizeof(a1[0]);
	int freq[98] = {0};

	printf("\n=== Bubble Sort Array 1 ===\n");
	int total = bubble(a1, n, freq);
	print(a1, freq);
	printf("Total: %d\n", total);
	reset(freq);

	printf("=== Bubble Sort Array 2 ===\n");
	total = bubble(a2, n, freq);
	print(a2, freq);
	printf("Total: %d\n", total);
	reset(freq);

	int A1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
	int A2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

	printf("=== Selection Sort Array 1 ===\n");
	total = selection(A1, n, freq);
	print(A1, freq);
	printf("Total: %d\n", total);
	reset(freq);

	printf("=== Selection Sort Array 2 ===\n");
	total = selection(A2, n, freq);
	print(A2, freq);
	printf("Total: %d\n", total);
	reset(freq);

	return 0;
}

int bubble(int arr[], int n, int freq[])
{

	int i, j, temp, total = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				freq[arr[j]]++;
				freq[arr[j + 1]]++;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				total++;
			}
		}
	}
	return total;
}

void print(int a[], int f[])
{
	for (int i = 0; i < 9; i++)
	{
		printf("%d:%d\n", a[i], f[a[i]]);
	}
}

void reset(int n[])
{
	for (int i = 0; i < 98; i++)
	{
		n[i] = 0;
	}
}

int selection(int arr[], int n, int freq[])
{
	int i, j, min_idx, temp, total = 0;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
		if (i != min_idx)
		// counts swap of same element otherwise
		{
			freq[arr[i]]++;
			freq[arr[min_idx]]++;
			total++;
		}
	}
	return total;
}