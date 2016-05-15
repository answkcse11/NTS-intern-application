#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define	EMPLOYEE_NUMBER_LENGTH	7

int main(int argc, char** argv) {
	//Variable declaration
	char**	employee;
	char	buffer[6], revbuffer[6];
	unsigned int 	*tempNumber, *score;
	int 	i, j, count;

	//Check invalid parameters
	if(argc != 2) {
		printf("You can use only one parameter for unsigned integer number\n");
		printf("Example : ~> RecordMaker 3");
		return 0;
	} else {
		count = atoi(argv[1]);
		if(count <= 0) {
			printf("You can use only one parameter for unsigned integer number\n");
			printf("Example : ~> RecordMaker 3");
			return 0;
		}
	}

	//Memory allocaiton
	employee = (char**)malloc(sizeof(char*)*count);
	for(i=0; i<count; i++)
		employee[i] = (char*)malloc(sizeof(char)*(EMPLOYEE_NUMBER_LENGTH+1));
	score = (unsigned int*)malloc(sizeof(unsigned int)*count);
	tempNumber = (unsigned int*)malloc(sizeof(unsigned int)*count);

	//Set Random function seed
	srand(time(NULL));

	for(i=0; i<count; i++) {
		//Create Employee Numbers and remove duplication
		tempNumber[i] = (((rand() << 15) | rand()) & 0x0001869F)+1;
		for(j=0; j<i; j++) {
			if(tempNumber[i] == tempNumber[j]) {
				i--;
				continue;
			}
		}
		memset(employee[i], '0', EMPLOYEE_NUMBER_LENGTH);
		ltoa(tempNumber[i], buffer, 10);
		strcpy(revbuffer, strrev(buffer));
		memcpy(employee[i], "NT", 2);
		for(j=0; revbuffer[j] != '\0'; j++)
			employee[i][EMPLOYEE_NUMBER_LENGTH-j-1] = revbuffer[j];
		employee[i][EMPLOYEE_NUMBER_LENGTH] = '\0';\

		//Create Employee's score
		score[i] = rand()%100;

		//Print all information
		printf("%s %u\n", employee[i], score[i]);
	}
	return 0;
}	