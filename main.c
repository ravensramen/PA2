//describe me

#include "header.h"

int main() {
	printf("Welcome to bootleg spotify - spootify!\n");
	
	printf("Here are your options, enter the coresponding number to make a choice: \n");
	int choice = displayMenu();
	FILE* input = fopen("musicPlayList.csv", "r");


	switch (choice) {
	case 1:
		//function 1
		//Load function
		loadMusic(); //send library to be read into structs
		break;
	case 2: 
		//function 2
		break;
	case 3: 
		//function 3
		break;
	case 4:
		//function 4
		break;
	case 5:
		break;
	case 6:
		//function 1
		break;
	case 7:
		//function 2
		break;
	case 8:
		//function 3
		break;
	case 9:
		//function 4
		break;
	case 10:
		break;
	case 11:

		//exit funct
		break;

	}

	//CLOSE FILE

	return 1;
}
