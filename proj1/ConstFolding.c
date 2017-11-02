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
#include "InstrUtils.h"
#include "Utils.h"

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	int flag = 0;	
	Instruction *A, *B, *C;
	
	A = head;
	if(head->next)
		B = head->next;	
	if(head->next->next)
		C = head->next->next;
	
	
	while(C){ 
		if(A->opcode == LOADI && B->opcode == LOADI){
			switch(C->opcode){
				case ADD:
					A->opcode = LOADI;
					A->field1 = A->field1 + B->field1;
					A->field2 = C->field3;
					flag = 1;
					break;				
				case SUB:
					A->opcode = LOADI;
					A->field1 = A->field1 - B->field1;
					A->field2 = C->field3;
					flag = 1;
					break;	
				case MUL:
					A->opcode = LOADI;
					A->field1 = A->field1 * B->field1;
					A->field2 = C->field3;
					flag = 1;
					break;	
				default:
					break;
			}
			if(flag == 1){
				A->next = C->next;
				C->next->prev = A;
				free(B);
				free(C);
				flag = 0;
			}
		}
		if(A->next)
			A = A->next;
		if(A->next)
			B = A->next;
		if(B->next)
			C = B->next;
		else 
			break;
	}

	if (head)
		PrintInstructionList(stdout, head);
	
	return EXIT_SUCCESS;
}