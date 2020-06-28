#include <stdlib.h> // malloc
#include <stdio.h>
#include <string.h> // strdup, strcmp

// User structure type definition
typedef struct 
{
	char	*token;
	int		freq;
} tTOKEN;

////////////////////////////////////////////////////////////////////////////////
// LIST type definition
typedef struct node
{
	tTOKEN		*dataPtr;
	struct node	*link;
} NODE;

typedef struct
{
	int		count;
	NODE	*pos;
	NODE	*head;
	NODE	*rear;
} LIST;

////////////////////////////////////////////////////////////////////////////////
// Prototype declarations

static int _insert(LIST *pList, NODE *pPre, tTOKEN *dataInPtr);
//static void _delete(LIST *pList, NODE *pPre, NODE *pLoc, tTOKEN **dataOutPtr);
static int _search(LIST *pList, NODE **pPre, NODE **pLoc, char *pArgu);

/* Allocates dynamic memory for a list head node and returns its address to caller
	return	head node pointer
			NULL if overflow
*/
LIST *createList( void)
{
	LIST*list;
	list = (LIST*)malloc(sizeof(LIST));
	if (list != NULL)
	{
		list->head = NULL;
		list->pos = NULL;
		list->rear = NULL;
		list->count = 0;

	}
	return list;
}

/* Deletes all data in list and recycles memory
	return	NULL head pointer
*/
LIST *destroyList(LIST *pList)
{
	NODE*deleteP;

	if (!(pList == NULL))
	{
		while ((pList->count) > 0)
		{
			deleteP = pList->head;
			pList->head = pList->head->link;
			pList->count--;

			free(deleteP->dataPtr->token);
			free(deleteP->dataPtr);
			free(deleteP);
		}
		free(pList);
	}
	return NULL;
}

/* Inserts data into list
	return	-1 if overflow
			0 if successful
			1 if duplicated key
*/
int addNode( LIST *pList, tTOKEN *dataInPtr)
{
	NODE*pPre;
	NODE*pLoc;

	int found = _search(pList, &pPre, &pLoc, dataInPtr->token);

	if (found)
		return 1;
		

	int succes = _insert(pList, pPre, dataInPtr);

	if (!(succes))
		return (-1);

	return 0;
}

/* Removes data from list
	return	0 not found
			1 deleted

int removeNode( LIST *pList, char *keyPtr, tTOKEN **dataOut); */

/* interface to search function
	Argu	key being sought
	dataOut	contains found data
	return	1 successful
			0 not found
*/
//int searchList( LIST *pList, char *pArgu, tTOKEN **pDataOut);

/* returns number of nodes in list

int listCount( LIST *pList); */

/* returns	1 empty
			0 list has data

int emptyList( LIST *pList); */

//int fullList( LIST *pList);

/* prints data from list */

void printList(LIST *pList) 
{
		NODE*pLoc;
		pLoc = pList->head;

		do
		{
			if (pLoc != NULL)
			{
				printf("%s\t", pLoc->dataPtr->token);
				printf("%d\n", pLoc->dataPtr->freq);
				pLoc = pLoc->link;
			}

		} while (pLoc != NULL);

		//if (pLoc == NULL)
			//printf("NULL\n");
}

/* internal insert function
	inserts data into a new node
	return	1 if successful
			0 if memory overflow
*/
static int _insert( LIST *pList, NODE *pPre, tTOKEN *dataInPtr)
{
	NODE*pNew;

	if (!(pNew = (NODE*)malloc(sizeof(NODE))))
		return 0;

	pNew->dataPtr = dataInPtr;
	pNew->link = NULL;

	
	if (pPre == NULL)
	{
		pNew->link = pList->head;
		pList->head = pNew;
	}
	else
	{
		pNew->link = pPre->link;
		pPre->link = pNew;
	}
	(pList->count)++;
	return 1;
}

/* internal delete function
	deletes data from a list and saves the (deleted) data to dataOut

static void _delete( LIST *pList, NODE *pPre, NODE *pLoc, tTOKEN **dataOutPtr); */

/* internal search function
	searches list and passes back address of node
	containing target and its logical predecessor
	return	1 found
			0 not found
*/
static int _search( LIST *pList, NODE **pPre, NODE **pLoc, char *pArgu)
{
	*pPre = NULL;
	*pLoc = pList->head;

	if (pList->count == 0)
		return 0;

	while (*pLoc != NULL && ( 0 < strcmp(pArgu, (*pLoc)->dataPtr->token) ) )
	{
		*pPre = *pLoc;
		*pLoc = (*pLoc)->link;
	}

	if (*pLoc != NULL && strcmp(pArgu, (*pLoc)->dataPtr->token) == 0)
	{
		(*pLoc)->dataPtr->freq = (*pLoc)->dataPtr->freq + 1;
		return 1;
	}

	if ((*pLoc) == NULL)
	{
		return 0;
	}
	else
	{
		if (!strcmp( pArgu, (*pLoc)->dataPtr->token ))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 1;


}

/* Allocates dynamic memory for a token structure, initialize fields(token, freq) and returns its address to caller
	return	token structure pointer
			NULL if overflow
*/
tTOKEN *createToken(char *str)
{
	tTOKEN*Token;
	Token = (tTOKEN*)malloc(sizeof(tTOKEN));

	Token->token = strdup(str);
	Token->freq = Token->freq + 1;
}
	



/* Deletes all data in token structure and recycles memory
	return	NULL head pointer
*/
tTOKEN *destroyToken( tTOKEN *pToken)
{
	free(pToken->token);
	free(pToken);
	
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////
int main( void)
{
	LIST *list;
	char str[1024];
	tTOKEN *pToken;
	int ret;
	
	// creates a null list
	list = createList();
	if (!list)
	{
		printf( "Cannot create list\n");
		return 100;
	}
	
	while(scanf("%s", str) == 1)
	{
		pToken = createToken(str);
		
		// insert function call
		ret = addNode(list, pToken);
		
		if (ret == 1) // duplicated 
			destroyToken(pToken);
	}
	// print function call
	printList(list);
	
	destroyList(list);
	
	return 0;
}
