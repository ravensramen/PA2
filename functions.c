///describe me

#include "header.h"

/////

int displayMenu(void) {
	int choice = 0;
	printf("Velcome! Enter your choice if you dare >:))\n");
	printf("1.\n2.\n3.\n4.\n");
	scanf("%d", &choice);
	return choice;
}

void loadMusic(void) {

	char buffer [100]; //buffer to save each line
	

}

Node* createNode(char *input_data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
		if (new_node == NULL) {
			return NULL; //
		}
		strncpy(new_node->record.Artist, strtok(input_data, ","), sizeof(new_node->record.Artist) - 1); 

		new_node->pNext = NULL; //initially set pointers to null
		new_node->pPrev = NULL;

		return new_node;
}
