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
void string_copy(char *, char *);

void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len<0)
		return NULL;


	sorting(students, len);

}
void sorting(struct student *std, int len){		//selection sort
	int i, j, temp, max;
	char str_temp[10];
	for (i = 0; i<len; i++){
		max = i;
		for (j = i + 1; j<len; j++){
			if (std[max].score<std[j].score){
				max = j;
			}
		}
		if (i != max){
			temp = std[i].score;
			std[i].score = std[max].score;
			std[max].score = temp;

			string_copy(std[i].name, str_temp);
			string_copy(std[max].name, std[i].name);
			string_copy(str_temp, std[max].name);
		}
	}
}

void string_copy(char *source, char *desti){
	int i;
	for (i = 0; source[i] != '\0'; i++){
		desti[i] = source[i];
	}
	desti[i] = '\0';
}