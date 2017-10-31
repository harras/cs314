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

	Instruction *tail;
	tail = LastInstruction(head);

	if((head != tail && head->next != tail){
		Instruction *instrA, *instrB, *instrC;
		instrA = head;
		instrB = head -> next;
		instrC = head -> next -> next;
		do{
			if(isLoad(instrA) && isLoad(instrB) && isOp(instrC)){
				//what do I do?
			}
			else{
				//idk what to do here...
			}
		}while(instrC != tail)


	if (head) 
		PrintInstructionList(stdout, head);
	
	return EXIT_SUCCESS;
}

int isOp(Instruction *instr){
	if(instr->opcode==ADD || instr->opcode==SUB || instr->opcode==MUL)
		return 1;
	return 0;
}

int isLoad(Instruction *instr){
	if(instr->opcode==LOADI) //possibly need to add something for checking for constant
		return 1;
	return 0;
}