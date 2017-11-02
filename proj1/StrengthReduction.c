/*
 *********************************************
 *  314 Principles of Programming Languages  *
 *  Fall 2017                                *
 *  Author: Uli                              *
 *  Student Version                          *
 *********************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "InstrUtils.h"
#include "Utils.h"

bool is_power(int n){	//Technically only powers not including 1
	return((n>=2) && ((n & (n-1)) == 0));
}

int lg(int n){
	int counter = 0;	
	
	if(is_power(n)){
		while(n != 1){
			n = n >> 1;
			counter++;		
		}
		return counter;
	}
	return -1;
}

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	int flag = 0;
	Instruction *A, *B;
	
	A = head;
	if(head->next)
		B = head->next;

	while(B){	
		if(A->opcode == LOADI && is_power(A->field1)
			&& B->field2 == A->field2){
			switch(B->opcode){
				case MUL:
					A->opcode = LSHIFTI;
					A->field2 = lg(A->field1);
					A->field1 = B->field1;
					A->field3 = B->field3;
					flag = 1;
					break;
				case DIV:
					A->opcode = RSHIFTI;
					A->field2 = lg(A->field1);
					A->field1 = B->field1;
					A->field3 = B->field3;
					flag = 1;
					break;
				default:
					break;	
			}
			if(flag == 1){
				A->next = B->next;
				B->next->prev = A;
				free(B);
				flag = 0;			
			}
		}
		if(A->next)
			A = A->next;
		if(A->next)
			B = A->next;
		else
			break;
	}

	if (head) 
		PrintInstructionList(stdout, head);
	
	return EXIT_SUCCESS;
}

