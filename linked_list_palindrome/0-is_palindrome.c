#include "lists.h"
#include <stdlib.h>

/**
 * reverse_list - reverses a linked list
 * @head: pointer to the first node
 * Return: pointer to the new head
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: double pointer to the first node
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *second_half, *reversed;
    listint_t *first_half = *head;

    if (!head || !*head || !(*head)->next)
        return 1;

    /* Find middle */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse second half */
    second_half = reverse_list(slow);
    reversed = second_half;

    /* Compare both halves */
    while (reversed)
    {
        if (first_half->n != reversed->n)
        {
            reverse_list(second_half);
            return 0;
        }
        first_half = first_half->next;
        reversed = reversed->next;
    }

    /* Restore original list */
    reverse_list(second_half);

    return 1;
}

