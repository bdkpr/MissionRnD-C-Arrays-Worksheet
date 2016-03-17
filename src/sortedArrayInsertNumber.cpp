/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

void swap(int *, int, int);
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i, j;
	if (Arr == NULL || len<0)
		return NULL;
	for (i = 0; i < len - 1; i++){		//validity
		if ((Arr[i]>Arr[i + 1])){
			return NULL;
		}
	}
	for (i = 0; i < len; i++){
		if (Arr[i] > num){
			swap(Arr, i, len);
			Arr[i] = num;
			return Arr;
		}
	}
	if (i == len){
		Arr[i] = num;
		return Arr;
	}
	else{
		return NULL;
	}
}
void swap(int *Arr, int ind, int len){
	Arr = (int *)realloc(Arr, (len + 1)*(sizeof(int)));
	for (int i = len; i >= ind; i--){
		Arr[i] = Arr[i - 1];
	}
}