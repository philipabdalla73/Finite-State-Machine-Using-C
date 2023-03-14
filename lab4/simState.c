#include <stdlib.h>
#include <stdio.h>
#include<string.h> 

struct LinkedList{
    char state[2];
    struct LinkedList* next0;
    struct LinkedList* next1;
    int deleted;// 0 - Not deleted, 1 - deleted,
	int idNum;
	int reached;
 };

void print1(struct LinkedList* list[], int length)
{
    
	for(int i = 0; i<length; i++){
		if((*list[i]).deleted == 0)
			printf("%s %s %s\n", (*list[i]).state, (*list[i]).next0->state, (*list[i]).next1->state);
	}
}
void identifyGarbage(struct LinkedList* list[], int length, struct LinkedList* current_State)
{   
	struct LinkedList* nextAndPrevMatrix[8][2];
	for(int i = 0; i < length; i++){
		nextAndPrevMatrix[i][0] = (*list[i]).next0;
		nextAndPrevMatrix[i][1] = (*list[i]).next1;
	}
	int starting_state_index = (*current_State).idNum;
	(*list[starting_state_index]).reached = 1;
	
	for(int k = 0; k < length; k++){
		for(int i = 0; i<length; i++){
			if((*list[i]).reached){
				for(int j = 0; j < 2; j++){
					struct LinkedList* nextState = nextAndPrevMatrix[i][j];
					if(!((*list[(*nextState).idNum]).reached)){
						(*list[(*nextState).idNum]).reached = 1;
					}
				}//end inner for(j)
			}
		}//end for(i)
	}//end for(k)
}

int main(int argc, char * argv[])
{
    char input[10];
    struct LinkedList A;
    struct LinkedList B;
    struct LinkedList C;
    struct LinkedList D;
    struct LinkedList E;
    struct LinkedList F;
    struct LinkedList G;
    struct LinkedList H;
    struct LinkedList* currentState;
    struct LinkedList* listofStates[8];
    A.state[0] = 'A';
	A.state[1] = '\0';
    A.next0 = &A;
    A.next1 = &B;
    A.deleted = 0;
	A.idNum = 0;

    B.state[0] = 'B';
	B.state[1] = '\0';
    B.next0 = &F;
    B.next1 = &H;
    B.deleted = 0;
	B.idNum = 1;

    C.state[0] = 'C';
	C.state[1] = '\0';
    C.next0 = &E;
    C.next1 = &D;
    C.deleted = 0;
	C.idNum = 2;

    D.state[0] = 'D';
	D.state[1] = '\0';
    D.next0 = &A;
    D.next1 = &G;
    D.deleted = 0;
	D.idNum = 3;

    E.state[0] = 'E';
	E.state[1] = '\0';
    E.next0 = &C;
    E.next1 = &A;
    E.deleted = 0;
	E.idNum = 4;

    F.state[0] = 'F';
	F.state[1] = '\0';
    F.next0 = &D;
    F.next1 = &G;
    F.deleted = 0;
	F.idNum = 5;

    G.state[0] = 'G';
	G.state[1] = '\0';
    G.next0 = &H;
    G.next1 = &C;
    G.deleted = 0;
	G.idNum = 6;

    H.state[0] = 'H';
	H.state[1] = '\0';
    H.next0 = &F;
    H.next1 = &E;
    H.deleted = 0;
	H.idNum = 7;

    listofStates[0] = &A;
    listofStates[1] = &B;
    listofStates[2] = &C;
    listofStates[3] = &D;
    listofStates[4] = &E;
    listofStates[5] = &F;
    listofStates[6] = &G;
    listofStates[7] = &H;

	for(int i = 0; i<8; i++){
		(*listofStates[i]).deleted = 0;
		(*listofStates[i]).reached = 0;
	}

    currentState = &A;
    printf("%s\n", currentState->state);
    while(1){
	fgets(input, 6, stdin);
    if(input[0] == '0'){//goes to next state that is zero
	currentState = (*currentState).next0;
	printf("%s\n", currentState->state);
    }
    if(input[0] == '1'){//goes to next state that is one
	currentState = (*currentState).next1;
	printf("%s\n", currentState->state);
    }
    if(input [0] == 'c'){
		if(input[2] == '0'){
			if(input[4] == 'A'){
				(*currentState).next0 = &A;
			}
			if(input[4] == 'B'){
				(*currentState).next0 = &B; 
			}
			if(input[4] == 'C'){
				(*currentState).next0 = &C;
			}
			if(input[4] == 'D'){
				(*currentState).next0 = &D;
			}
			if(input[4] == 'E'){
				(*currentState).next0 = &E;
			}
			if(input[4] == 'F'){
				(*currentState).next0 = &F;
			}
			if(input[4] == 'G'){
				(*currentState).next0 = &G;
			}
			if(input[4] == 'H'){
				(*currentState).next0 = &H;
			}

		}//end of if(input[2] == '0')
		else{
			if(input[4] == 'A'){
				(*currentState).next1 = &A;
			}
			if(input[4] == 'B'){
				(*currentState).next1 = &B; 
			}
			if(input[4] == 'C'){
				(*currentState).next1 = &C;
			}
			if(input[4] == 'D'){
				(*currentState).next1 = &D;
			}
			if(input[4] == 'E'){
				(*currentState).next1 = &E;
			}
			if(input[4] == 'F'){
				(*currentState).next1 = &F;
			}
			if(input[4] == 'G'){
				(*currentState).next1 = &G;
			}
			if(input[4] == 'H'){
				(*currentState).next1 = &H;
			}

		}

	}//end of if(input [0] == 'c')


    if(input[0] == 'p'){//prints all non deleted states
	print1(listofStates, 8);
    }//end print command

	
	if(input[0] == 'd'){//deletes all states that are unreachable and not deleted yet
		
		if(input[2] == 'A'){
			if((*listofStates[0]).reached == 0 && (*listofStates[0]).deleted == 0){
				printf("Deleted\n");
				(*listofStates[0]).deleted = 1;
			}else{
				printf("Not deleted\n");
			}		
		}else if(input[2] == 'B'){
			if((*listofStates[1]).reached == 0 && (*listofStates[1]).deleted == 0){
				printf("Deleted\n");
				(*listofStates[1]).deleted = 1;
			}else{
				printf("Not deleted\n");
			}		
		}else if(input[2] == 'C'){
			if((*listofStates[2]).reached == 0 && (*listofStates[2]).deleted == 0){
				printf("Deleted\n");
				(*listofStates[2]).deleted = 1;
			}else{
				printf("Not deleted\n");
			}		
		}else if(input[2] == 'D'){
			if((*listofStates[3]).reached == 0 && (*listofStates[3]).deleted == 0){
				printf("Deleted\n");
				(*listofStates[3]).deleted = 1;
			}else{
				printf("Not deleted\n");
			}		
		}else if(input[2] == 'E'){
			if((*listofStates[4]).reached == 0 && (*listofStates[4]).deleted == 0){
				printf("Deleted\n");
				(*listofStates[4]).deleted = 1;
			}else{
				printf("Not deleted\n");
			}		
		}else if(input[2] == 'F'){
			if((*listofStates[5]).reached == 0 && (*listofStates[5]).deleted == 0){
				printf("Deleted\n");
				(*listofStates[5]).deleted = 1;
			}else{
				printf("Not deleted\n");
			}		
		}else if(input[2] == 'G'){
			if((*listofStates[6]).reached == 0 && (*listofStates[6]).deleted == 0){
				printf("Deleted\n");
				(*listofStates[6]).deleted = 1;
			}else{
				printf("Not deleted\n");
			}		
		}else if(input[2] == 'H'){
			if((*listofStates[7]).reached == 0 && (*listofStates[7]).deleted == 0){
				printf("Deleted\n");
				(*listofStates[7]).deleted = 1;
			}else{
				printf("Not deleted\n");
			}		
		}else{
			for(int i = 0; i < 8; i++){
			(*listofStates[i]).reached = 0;
			}//end for()
			identifyGarbage(listofStates, 8, currentState);
			char str[40] = "";
			int numDeleted = 0;
			for(int i = 0; i < 8; i++){
				if((*listofStates[i]).reached == 0 && (*listofStates[i]).deleted == 0){
					strcat(str, (*listofStates[i]).state);		
				    strcat(str, ", ");
					(*listofStates[i]).deleted = 1;
					numDeleted++;
				}
			}//end for()
			if(numDeleted>0){
				printf("Deleted: %s\n", str);
			}else{
				printf("No states deleted\n");
			}
		}
    }//end if() for Delete command
	if(input[0] == 'g'){
		for(int i = 0; i < 8; i++){
		(*listofStates[i]).reached = 0;
		}//end for()
		identifyGarbage(listofStates, 8, currentState);
		int reachedStates = 0;
		char str[40] = "";
		for(int i = 0; i < 8; i++){
			if((*listofStates[i]).reached == 0){		
				strcat(str, (*listofStates[i]).state);
				strcat(str, ", ");
				reachedStates++;
			}
		}//end for()
		if(reachedStates>0){
			printf("Grabage: %s\n", str);
		}else{
			printf("No Garbage\n");
		}
	}
    }//end while()

    
}

