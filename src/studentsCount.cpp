
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

int binary_search(int *, int, int);
void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	if (Arr == NULL || len<0 || score<0)
		return NULL;
	else if (len == 1){
		if (Arr[0] == score)
			*lessCount = *moreCount = 0;
		else if (Arr[0] < score){
			*lessCount = 1;
			*moreCount = 0;
		}
		else{
			*lessCount = 0;
			*moreCount = 1;
		}

	}
	else
	{
		int i, st_ind, no_dup, j;
		i = binary_search(Arr, len, score);
		if (i < 0){
			return NULL;
		}
		else{
			no_dup = 0;
			st_ind = i;
			for (; score == Arr[i] && i >= 0; i--){
				st_ind = i;
			}
			for (; score == Arr[i + 1] && i < len; i++){
				no_dup++;
			}
			*moreCount = len - (st_ind + no_dup);
			*lessCount = len - (*moreCount + no_dup);
		}
	}
}
int binary_search(int *Arr, int len, int score){
	int mid, lb, ub;
	lb = 0;
	ub = len - 1;
	while (lb <= ub){
		mid = (lb + ub) / 2;
		if (Arr[mid] == score){
			return mid;
		}
		else if (mid>0 && mid<len&&Arr[mid - 1]<score&&Arr[mid + 1]>score){
			return mid;
		}
		else if (Arr[mid] < score){
			lb = mid + 1;
		}
		else if (Arr[mid]>score){
			ub = mid - 1;
		}
	}
	return -1;
}