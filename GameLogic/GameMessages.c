#include "GameMessages.h"
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

MessageList listOfMessages;

char CreateMessageList()
{
	listOfMessages.size = 0;
	listOfMessages.mb = NULL;
}

char getFirstMessageWithDelete()
{
	if(listOfMessages.size == 0)
	{
		return 0;
	}
	MessageBlock* first = listOfMessages.mb;
	MessageBlock* second = first->next;
	
	listOfMessages.mb = second;
	listOfMessages.size--;
	
	char res = first->message;
	
	printf("%d\n", res);
	free(first);
	return res;
}

char addMessage(char add)
{
	if(listOfMessages.size == 0)
	{
		MessageBlock* newone = (MessageBlock*)malloc(sizeof(MessageBlock));
		newone->message = add;
		newone->next = NULL;
		listOfMessages.mb = newone;
		listOfMessages.size = 1;
		return 0;
	}
	
	MessageBlock* list = listOfMessages.mb;
	for(int i = 0; i < listOfMessages.size - 1; i++)
	{
		list = list->next;
	}
	
	MessageBlock* newone = (MessageBlock*)malloc(sizeof(MessageBlock));
	newone->message = add;
	newone->next = NULL;
	
	list->next = newone;
	
	listOfMessages.size++;
	return 0;
}



char QuitMessage()
{
	addMessage(1);
}


char LoadScene(char number)
{
	addMessage(number);
}