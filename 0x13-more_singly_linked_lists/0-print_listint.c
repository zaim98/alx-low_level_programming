#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints elements of a singly linked list.
 * @h: Pointer to the head of the list.
 * Return: The number of elements in the list.
 **/
size_t print_listint(const listint_t *h)
{
	const listint_t *temp;
	unsigned int counter = 0;

	temp = h;
	while (temp)
	{
		printf("%d\n", temp->n);
		counter++;
		temp = temp->next;
	}
	return (counter);
}
