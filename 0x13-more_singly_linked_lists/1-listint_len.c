#include "lists.h"
/**
 * listint_len - Calculate the number of elements in a linked list.
 * @h: Pointer to the head of the linked list.
 * Return: The number of elements (size_t).
 **/

size_t listint_len(const listint_t *h)
{
	const listint_t *temp;
	unsigned int count = 0;

	temp = h;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
