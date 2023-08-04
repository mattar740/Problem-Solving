#include <iostream>
using namespace std;

// Define the structure of a node
struct node
{
    int data;
    struct node *next;
};

// Function to insert a new node at the beginning of a linked list
void insertAtFront(node **head, int newValue)
{
    // Create a new node
    node *newNode = new node();
    // Set the data value of the new node
    newNode->data = newValue;
    // Set the next pointer of the new node to point to the current head of the list
    newNode->next = *head;
    // Set the head pointer of the list to point to the new node
    *head = newNode;
}

// Function to insert a new node at the end of a linked list
void insertAtEnd(node **head, int newValue)
{
    // Create a new node
    node *newNode = new node();
    // Set the data value of the new node
    newNode->data = newValue;
    // Set the next pointer of the new node to NULL
    newNode->next = NULL;

    // If the list is empty, the new node will be the head node
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Find the last node in the list
    node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    // Insert the new node after the last node (at the end of the list)
    last->next = newNode;
}

// Function to insert a new node after a given node
void insertAfter(node *previous, int newValue)
{
    // Check if the previous node is NULL, as a new node cannot be inserted after a NULL node.
    if (previous == NULL)
    {
        cout << "Previous node cannot be NULL.\n";
        return;
    }

    // Create a new node
    node *newNode = new node();
    // Set the data value of the new node
    newNode->data = newValue;

    // Insert the new node after the previous node
    newNode->next = previous->next;
    previous->next = newNode;
}

// Function to search for a node with a specific value in the linked list
node* search(node *head, int searchValue)
{
    // Traverse the list starting from the head node
    node *current = head;
    while(current != NULL)
    {
        // If the current node contains the search value, return a pointer to that node
        if(current->data == searchValue)
        {
            return current;
        }
        // Otherwise, move on to the next node in the list
        current = current->next;
    }
    // If the search value is not found in the list, return NULL
    return NULL;
}

// Function to print the values in a linked list
void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

// Function to delete a linked list
void deleteList(node *head)
{
    // If the head pointer is NULL, the list is already empty
    if (head == NULL)
        return;
    // Recursively delete the rest of the list
    deleteList(head->next);
    // Delete the current node
    delete head;
}

int main()
{
    // Create an empty linked list
    node *list = NULL;

    // Insert some nodes at the beginning of the list
    insertAtFront(&list, 1);
    insertAtFront(&list, 2);
    insertAtFront(&list, 3);

    // Insert some nodes at the end of the list
    insertAtEnd(&list, 4);
    insertAtEnd(&list, 5);
    insertAtEnd(&list, 6);

    // Insert a node after a given node
    insertAfter(list->next, 7);

    // Print the values in the list
    printList(list);

    // Search for a node with a specific value in the list
    node *result = search(list, 20);
    if (result == NULL)
    {
        cout << "Node not found.\n";
    }
    else
    {
        cout << "Node found: " << result->data << endl;
    }

    // Delete the list
    deleteList(list);
}

/*
the output will be:
    3
    2
    7
    1
    4
    5
    6
    Node not found.
*/