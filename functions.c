///describe me

#include "header.h"

/////

int displayMenu(void) {
	int choice = 0;

	printf("1. Store music from my file\n2. Display my library\n3. Edit my library\n4. Rate a record\n5. Play a record\n6. Exit\n");
	scanf("%d", &choice);
	return choice;
}

void loadMusic(FILE* input) {
	Node* pHead = NULL; // Initialize pHead to NULL (important!)
	initList(&pHead); // Initialize the list

	char buffer[100]; // Buffer to save each line
	while (fgets(buffer, sizeof(buffer), input) != NULL) { // Read file line by line
		doublyLinkList(&pHead, buffer); // Add nodes to the list
	}

	//
	//printList(pHead); // Print the list to verify data //DEBUG, USE ME LATER ;)
	system("cls");
	printf("All records have been entered. woop woop!\n");
}



Node* createNode(char* buffer) {
	Node* new_node = (Node*)malloc(sizeof(Node)); // Allocate memory for each node

	if (new_node == NULL) { // New node failed to allocate
		printf("failed to save record data.\n");
		return NULL;
	}

	//// Debugging: print the token values
	//printf("Parsing: %s\n", buffer);

	strcpy(new_node->record.Artist, myStrtok(buffer, ','));
	strcpy(new_node->record.AlbumTitle, myStrtok(NULL, ','));
	strcpy(new_node->record.SongTitle, myStrtok(NULL, ','));
	strcpy(new_node->record.Genre, myStrtok(NULL, ','));

	// Extract and convert duration to integers
	char* dur = myStrtok(NULL, ',');
	Duration song_duration = convertDuration(dur); // Function to save duration in struct form
	new_node->record.duration = song_duration;

	char* timesPlayed = myStrtok(NULL, ',');
	new_node->record.TimesPlayed = atoi(timesPlayed);

	char* recordRating = myStrtok(NULL, ',');
	new_node->record.Rating = atoi(recordRating);

	// Debugging: print out the created record data
	//printf("Created node: Artist=%s, AlbumTitle=%s, SongTitle=%s, Genre=%s, Duration=%d:%d, TimesPlayed=%d, Rating=%d\n",
	//	new_node->record.Artist, new_node->record.AlbumTitle, new_node->record.SongTitle,
	//	new_node->record.Genre, new_node->record.duration.min, new_node->record.duration.seconds,
	//	new_node->record.TimesPlayed, new_node->record.Rating);

	return new_node;
}


char* myStrtok(char* buffer, char delim) {
	static char* ptr = NULL; // Keeps track of where we are in the buffer
	char* token = NULL;

	if (buffer != NULL) {
		ptr = buffer;  // Reset ptr to the start of the new string
	}

	if (ptr == NULL) {
		return NULL; // No input buffer provided
	}

	// Skip any leading spaces or delimiters
	while (*ptr == ' ' || *ptr == delim) {
		ptr++;
	}

	if (*ptr == '\0') {
		return NULL; // End of string reached
	}

	token = ptr; // Mark the beginning of the token

	// Check for quotes at the beginning of the token (for multi-word names)
	if (*ptr == '\"') {
		ptr++; // Skip the opening quote
		token = ptr; // Now the token starts after the quote
		while (*ptr != '\"' && *ptr != '\0') {
			ptr++; // Keep moving the pointer until we hit the closing quote
		}
		if (*ptr == '\"') {
			*ptr = '\0'; // Null-terminate the string at the quote
			ptr++; // Move past the closing quote
		}
	}
	else {
		// Otherwise, just move the pointer until the delimiter is found
		while (*ptr != delim && *ptr != '\0') {
			ptr++;
		}

		if (*ptr != '\0') {
			*ptr = '\0'; // Null-terminate the token at the delimiter
			ptr++; // Move past the delimiter for the next token
		}
	}

	return token; // Return the extracted token
}

Duration convertDuration(char* input) {
	Duration duration = { 0,0 };
	char* token = strtok(input, ":");

	if (token != NULL) {
		duration.min = atoi(token);
	}
	token = (strtok(NULL, ":"));
	if(token!=NULL){
		duration.seconds = atoi(token); 
	}
	return duration;
}

void initList(Node** pList) {
	*pList = NULL;
}

void doublyLinkList(Node** pList,char* buffer) { //sends new node to list in order
	Node* pCur = *pList;
	Node* pMem = createNode(buffer); //create node w/input data
	
	//case 1, empty list
	if (pCur == NULL) {
		*pList = pMem; //pMem is new head
		pMem->pPrev = NULL; //no previous
		pMem->pNext = NULL;  //null initialize end ptr

	}

	//case 2, list not empty
	else { //need to find end of list
	while (pCur->pNext != NULL) {
		pCur = pCur->pNext; // Move to the next node
		}
		pCur->pNext = pMem; // Set current node's next to new node
		pMem->pPrev = pCur; // Set new node's prev to current node
		pMem->pNext = NULL; // New node will be the last, so its next is NULL
	}
}

	//list is now edited to be in order


void printList(Node* pList) {
	Node* pCur = pList;

	// Traverse the list
	while (pCur != NULL) {
		// Print the record fields (or add more fields as needed)
		printf("Artist: %s\n", pCur->record.Artist);
		printf("Album Title: %s\n", pCur->record.AlbumTitle);
		printf("Song Title: %s\n", pCur->record.SongTitle);
		printf("Genre: %s\n", pCur->record.Genre);
		printf("Duration: %d:%d\n", pCur->record.duration.min, pCur->record.duration.seconds);
		printf("Times Played: %d\n", pCur->record.TimesPlayed);
		printf("Rating: %d\n", pCur->record.Rating);

		// Check the previous node
		if (pCur->pPrev != NULL) {
			printf("Previous Node Artist: %s\n", pCur->pPrev->record.Artist);
		}
		else {
			printf("This is the first node, no previous node.\n");
		}

		// Check the next node
		if (pCur->pNext != NULL) {
			printf("Next Node Artist: %s\n", pCur->pNext->record.Artist);
		}
		else {
			printf("This is the last node, no next node.\n");
		}

		// Move to the next node
		pCur = pCur->pNext;

		printf("-------------\n");
	}
}
