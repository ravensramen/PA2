//describe me

#include "header.h"

int main() {
	printf("Welcome to bootleg spotify - spootify!\n");

	printf("Here are your options, enter the coresponding number to make a choice: \n\n");
	
	FILE* input = fopen("musicPlayList.csv", "r");
	Node* pHead = NULL;
	int choice = 0;

	do {
		choice = displayMenu();
		switch (choice) {
		case 1:
			//function 1
			//Load function
			loadMusic(input,&pHead); //send library to be read into structs
			system("pause");
			system("cls"); //clear console after each run 
			continue;
		case 2:
			printList(pHead);
			//function 2 DISPLAY
			continue;
		case 3:
			//function 3 EDIT
			continue;
		case 4:
			//function 4 RATE
			continue;
		case 5:
			//function 5 PLAY
			continue;
		case 6:
			//function 6 EXIT
			break;

		}
		
	} while (choice != 6);

	//CLOSE FILE

	return 1;
}
