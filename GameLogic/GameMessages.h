#pragma once

typedef struct MessageBlock
{
	char message;
	struct MessageBlock* next;
}MessageBlock;	

typedef struct MessageList
{
	struct MessageBlock* mb;
	int size;
}MessageList;

char CreateMessageList();
char getFirstMessageWithDelete();
char addMessage(char add);