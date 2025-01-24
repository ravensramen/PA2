//name, description, u know the deal

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct duration {
	int min, seconds;

}Duration;

//define structure for record data
typedef struct record{
	char Artist[20];
	char AlbumTitle[30];
	char SongTitle[30];
	char Genre[20];
	Duration duration;
	int TimesPlayed;
	int Rating;
}Record;

typedef struct node {
	Record record; //record struct data
	struct Node *pNext; //pointer to next song node
	struct Node *pPrev;
}Node;

int displayMenu(void);

void loadMusic(void);
Node* createNode(char* input_data);
