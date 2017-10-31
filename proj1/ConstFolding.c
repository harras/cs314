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

int buffer_is_free(Instruction* i){				// this is gross but
	Instruction *tail = LastInstruction(i);// I swear it makes sense
	if(i->next == tail){		
		if(i->next->next == tail){
			return 1;
		}
		return 0;
	}
	return 0;
} 

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	Instruction *A, *B, *C, *temp;
	temp = head;
	while(buffer_is_free(temp) == 1)
		A = temp->next;
		B = temp->next->next;
		C = temp->next->next->next;
		
		//Consider errors that may arise this iterative process. Edge
		//cases. Looks like it may skip a check...?
	}
	

	if (head) 
		PrintInstructionList(stdout, head);
	
	return EXIT_SUCCESS;
}