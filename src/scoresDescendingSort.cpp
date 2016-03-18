/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct student {
	char name[10];
	int score;
};

void sorting(struct student *, int);

void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len<0)
		return NULL;

	sorting(students, len);

}
void sorting(struct student *std, int len){		//selection sort
	int i, j,max;
	struct student *temp = (struct student *)malloc(sizeof(struct student));
	char str_temp[10];
	for (i = 0; i<len; i++){
		max = i;
		for (j = i + 1; j<len; j++){
			if (std[max].score<std[j].score){
				max = j;
			}
		}
		if (i != max){
			temp[0] = std[i];
			std[i] = std[max];
			std[max] = temp[0];
		}
	}
}
