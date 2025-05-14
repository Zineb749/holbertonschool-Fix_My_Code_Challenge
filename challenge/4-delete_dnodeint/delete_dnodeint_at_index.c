#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    unsigned int p = 0;

    if (*head == NULL)  // Check for an empty list
    {
        return (-1);
    }

    tmp = *head;

    // Traverse to the node at the specified index
    while (tmp != NULL && p < index)
    {
        tmp = tmp->next;
        p++;
    }

    // If the index is out of bounds (node not found)
    if (tmp == NULL)
    {
        return (-1);
    }

    // Case 1: Deleting the first node
    if (tmp->prev == NULL)
    {
        *head = tmp->next;  // Update head to the next node
        if (*head != NULL)  // If there's a node after the head, set its prev to NULL
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        // Case 2: Deleting any node except the first
        if (tmp->next != NULL)
        {
            tmp->next->prev = tmp->prev;  // Link next node's prev to previous node
        }
        tmp->prev->next = tmp->next;  // Link previous node's next to next node
    }

    free(tmp);  // Free the memory of the deleted node
    return (1);
}
