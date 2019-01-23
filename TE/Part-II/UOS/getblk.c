/*
 * Author :		Nilesh Pandit <nileshpandit009@gmail.com>
 * Description :	This program demonstrates the Get Block
 * 			(getblk) algorithm
 */

#include<stdio.h>
#include<stdlib.h>

#define ASSIGNED	1
#define FREE		0

#define TOTAL_BLOCKS	4

struct node {
	struct node	*prev;
	unsigned int	buffer;
	unsigned int	status;
	struct node	*next;
};

struct node *freelist = NULL, *blk[TOTAL_BLOCKS] = {NULL, NULL, NULL, NULL};

void init_lists()
{
	int i;

	// initialise freelist pointer
	freelist = (struct node *)malloc(sizeof(struct node));
	freelist->prev = freelist;
	freelist->next = freelist;

	// initialise blk pointers
	for (i=0; i<TOTAL_BLOCKS; i++) {
		blk[i] = (struct node *)malloc(sizeof(struct node));
		blk[i]->buffer = 0;
		blk[i]->prev = blk[i];
		blk[i]->next = blk[i];
	}
}

/*
 * insert_node() inserts the new node at the tail of the queue
 */
void insert_node(struct node *new_node, struct node *head)
{
	struct node *ptr1;
	ptr1 = head->prev;

	ptr1->next = new_node;
	new_node->next = head;
	head->prev = new_node;
	new_node->prev = ptr1;
}

/*
 * hash() creates a new node and assigns values to it
 * and hashes it to correct place
 */
void hash(unsigned int num, unsigned int status)
{
	int blkno;
	if ((blkno = num % TOTAL_BLOCKS) < TOTAL_BLOCKS) {
		struct node *new = (struct node *)malloc(sizeof(struct node));
		new->buffer = num;
		new->status = status;
		// insert new node in hash queue
		insert_node(new, blk[blkno]);
		// if block is free then insert into freelist
		if (status == FREE) {
			struct node *new_free = (struct node *)malloc(sizeof(struct node));
			*new_free = *new;
			insert_node(new_free, freelist);
		}
	} else {
		printf("\n\nInvalid buffer number!!!\n");
		return;
	}
}

void input()
{
	unsigned int buf_num, buf_status;
	unsigned short flag = 0;
	struct node *ptr;

	printf("\n\nEnter buffer number : ");
	scanf("%u", &buf_num);
	printf("\nEnter status of buffer (0 - free, 1 - assigned) : ");
	scanf("%u", &buf_status);

	ptr = blk[buf_num % TOTAL_BLOCKS];
	do {
		if ((ptr->buffer == buf_num)
				&& (ptr != blk[buf_num % TOTAL_BLOCKS]))
			flag = 1;
		ptr = ptr->next;
	} while (ptr != blk[buf_num % TOTAL_BLOCKS]);
	if (flag == 0)
		hash(buf_num, buf_status);
	else
		printf("\n\nBuffer %d already exists\n", buf_num);
}

void remove_node(struct node **head, unsigned int search_val)
{
	struct node **dp1 = head, **dp2 = head, *delete;

	do {
		dp1 = &(*dp1)->next;
		dp2 = &(*dp2)->prev;
	} while ((*dp1 != *head) && (*dp1)->buffer != search_val);

	if (*dp1 == NULL || *dp2 == NULL)
		return;

	delete = *dp1;
	*dp1 = delete->next;
	*dp2 = delete->prev;
	delete->next = NULL;
	delete->prev = NULL;

	free(delete);
}

void scenario1(struct node *buf_ptr)
{
//	struct node *tmp, *ptr = freelist;
	if (buf_ptr->status == ASSIGNED)
		printf("\n\nRequested Buffer is Locked\n");
	else {
		remove_node(&freelist, buf_ptr->buffer);
		buf_ptr->status = ASSIGNED;
		printf("\n\nBuffer %u allocated\n", buf_ptr->buffer);
	}
}

void scenario2(unsigned int buffno)
{
	unsigned int buf;
	struct node *new;

	printf("\nCannot find the requested buffer!!!");

	if (freelist->next == freelist)
		printf("\nCannot allocate new buffer");
	else {
		printf("\nAllocating new buffer from free list");

		new = (struct node *)malloc(sizeof(struct node));
		new->buffer = buffno;
		new->status = ASSIGNED;
		insert_node(new, blk[buffno % TOTAL_BLOCKS]);

		printf("\nBuffer %u allocated\n", new->buffer);

		buf = freelist->next->buffer;
		remove_node(&freelist, buf);
		remove_node(&blk[buf % TOTAL_BLOCKS], buf);

		printf("\n%d removed from freelist\n", buf);
	}
}

void search_and_alloc(unsigned int buffno)
{
	int block = buffno % TOTAL_BLOCKS;
	struct node *ptr = blk[block];

	while (ptr->next != blk[block] && ptr->buffer != buffno)
		ptr = ptr->next;
	if (ptr->next == blk[block]
			&& ptr->buffer != buffno)	// Block not found
		scenario2(buffno);
	else						// Block found
		scenario1(ptr);
}

void display_free_busy()
{
	int i;
	struct node *ptr;

	// Display free
	ptr = freelist;
	printf("\nFree list --> ");
	do {
		if (ptr != freelist)
			printf("%u  ", ptr->buffer);
		ptr = ptr->next;
	} while (ptr->next != freelist->next);

	// Display busy
	printf("\nBusy list --> ");
	for (i=0; i<TOTAL_BLOCKS; i++) {
		ptr = blk[i];
		do {
			if (ptr->status == ASSIGNED)
				printf("%u  ", ptr->buffer);
			ptr = ptr->next;
		} while (ptr->next != blk[i]->next);
	}
}

void display()
{
	int i;
	struct node *ptr = NULL;

	// Display hash table
	for (i=0; i<TOTAL_BLOCKS; i++) {
		ptr = blk[i];
		printf("\nblk[%d] --> ", i);
		do {
			if (ptr != blk[i])
				printf("%u  ", ptr->buffer);
			ptr = ptr->next;
		} while (ptr->next != blk[i]->next);
	}

	// Display free list and busy list
	display_free_busy();
}

int main(void)
{
	// main code here
	int ch = 0;
	unsigned int bn = 0;

	init_lists();

	while (1) {
		printf("\n\nEnter your choice\n");
		printf("1. Insert\n2. Display\n\
3. Search and allocate\n4. Exit\n");
		scanf("%d", &ch);

		switch (ch) {
			case 1:
				input();
			break;

			case 2:
				display();
			break;

			case 3:
				printf("\nEnter buffer number : ");
				scanf("%u", &bn);
				search_and_alloc(bn);
			break;

			case 4:
				exit(0);
			break;

			default:
				printf("\n\nInvalid choice.\n");
		}
	}
}

