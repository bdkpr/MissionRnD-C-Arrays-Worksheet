/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void quick_sort(int *, int, int);
int removeArrayDuplicates(int *Arr, int len)
{
	if ((Arr == NULL) || (len<0))
		return -1;
	int i, j;
	quick_sort(Arr, 0, len - 1);
	for (i = 1, j = 0; i < len; i++){
		if (Arr[j] != Arr[i]){
			Arr[++j] = Arr[i];
		}
	}
	return j + 1;
}

void quick_sort(int *inp_arr, int low, int upp)
{
	int pivot, i, j;
	if (low<upp) //until there is a single element 
	{
		pivot = inp_arr[low]; //taking the pivot element
		i = low + 1;
		j = upp;
		while (1)  //finding it's final position
		{
			while (pivot>inp_arr[i] && i <= upp)
				i++;
			while (pivot<inp_arr[j])
				j--;
			if (i<j)
			{
				inp_arr[i] += inp_arr[j];
				inp_arr[j] = inp_arr[i] - inp_arr[j];
				inp_arr[i] -= inp_arr[j];
			}
			else
				break;
		}
		inp_arr[low] = inp_arr[j]; //placing the elemnt in it's final position
		inp_arr[j] = pivot;
		quick_sort(inp_arr, low, j - 1); //applying the same quick sort for both left and right sub array
		quick_sort(inp_arr, j + 1, upp);
	}

}