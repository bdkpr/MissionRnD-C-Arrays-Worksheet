/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

void sel_sort(struct student *, int);
struct student {
	char *name;
	int score;
};
struct student ** topKStudents(struct student *students, int len, int K) {
	int i, j;

	if ((students == NULL || len<0) || K <= 0)				//validity check
		return NULL;

	struct student **k_top = (student **)malloc(K*sizeof(student*));
	if (K >= len){									//if K value is greater than or equal to length
		for (i = 0; i < len; i++){
			k_top[i] = &students[i];
		}
		return k_top;
	}
	else{											//if K value less than length
		sel_sort(students, len);
		for (K = len - K, i = 0; K < len; K++, i++){
			k_top[i] = (struct student *)malloc(sizeof(struct student));
			k_top[i] = &students[K];
		}
		return k_top;
	}
}
void sel_sort(struct student *stu, int len){	//sorting the data according to scores
	int i, j, min;
	struct student *temp = (struct student *)malloc(sizeof(student));
	char str_temp[31];
	for (i = 0; i < len; i++){
		min = i;
		for (j = i + 1; j < len; j++){
			if (stu[min].score>stu[j].score){
				min = j;
			}
		}
		if (i != min){
			temp[0] = stu[i];
			stu[i] = stu[min];
			stu[min] = temp[0];
		}
	}
}
