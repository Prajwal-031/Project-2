//Implement Search Functionality
//Branch name: implement-search-functionality

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Singly Linked List Node Structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function prototypes
void printll();
void ins_beg();
void ins_end();
void ins_aft();
void ins_bef();
void del_beg();
void del_mid();
void del_end();
int search_node();

// Function to search for a node in singly linked list
int search_node() {
    if(head == NULL) {
        printf("List is empty. Cannot search.\n");
        return -1;
    }

    int key, position = 0;
    printf("Enter the data to search: ");
    scanf("%d", &key);

    struct node *ptr = head;
    while(ptr != NULL) {
        position++;
        if(ptr->data == key) {
            printf("Data %d found at position %d\n", key, position);
            return position;
        }
        ptr = ptr->next;
    }

    printf("Data %d not found in the list\n", key);
    return -1;
}

// Function to print the list
void printll() {
    struct node *ptr = head;
    if(head == NULL) {
        printf("The list is empty\n");
        return;
    }

    printf("The list is:\n");
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to insert at beginning
void ins_beg() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the new node: \n");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head = new_node;

    printll();
}

// Function to insert at end
void ins_end() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    printf("Enter the data of the new node: \n");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    printll();
}

// Function to insert after a node
void ins_aft() {
    struct node *ptr, *preptr;
    int pos;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node after which the new node is to be inserted: \n");
    scanf("%d", &pos);
    printf("Enter the data of the new node: ");
    scanf("%d", &new_node->data);
    preptr = head;
    ptr = preptr->next;
    while (preptr->data != pos) {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    new_node->next = ptr;
    preptr->next = new_node;

    printll();
}

// Function to insert before a node
void ins_bef() {
    struct node *ptr, *preptr;
    int pos;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node before which the new node is to be inserted: \n");
    scanf("%d", &pos);
    printf("Enter the data of the newnode \n");
    scanf("%d", &new_node->data);
    preptr = head;
    ptr = preptr->next;
    while (ptr->data != pos) {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    new_node->next = preptr->next;
    preptr->next = new_node;
    printll();
}

// Function to delete from beginning
void del_beg() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr;
    ptr = head;
    head = ptr->next;
    free(ptr);

    printll();
}

// Function to delete a specific node
void del_mid() {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr, *preptr;
    int data;
    printf("Enter the data of the node to be deleted \n");
    scanf("%d", &data);
    preptr = head;
    ptr = preptr->next;
    while (preptr->next->data != data) {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);

    printll();
}

// Function to delete from end
void del_end() {
    if(head == NULL) {
        printf("The list is empty");
        return;
    }

    struct node *ptr, *preptr;
    preptr = head;
    ptr = preptr->next;
    while (ptr->next != NULL) {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = NULL;
    free(ptr);

    printll();
}

// Main function for singly linked list operations
int sll() {
    int opt;
    while (1) {
        printf("\n---------Operations on Singly Linked list---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node\n");
        printf("4. Insertion before the specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Search for a node\n");
        printf("10. Exit\n");

        printf("Select the operation to be performed\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                ins_beg();
                break;
            case 2:
                ins_end();
                break;
            case 3:
                ins_aft();
                break;
            case 4:
                ins_bef();
                break;
            case 5:
                del_beg();
                break;
            case 6:
                del_mid();
                break;
            case 7:
                del_end();
                break;
            case 8:
                printll();
                break;
            case 9:
                search_node();
                break;
            case 10:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}

// Doubly Linked List Node Structure
struct node1 {
    int data;
    struct node1 *next;
    struct node1 *prev;
};

struct node1 *start = NULL;

// Function prototypes for doubly linked list
void printll1();
void ins_beg1();
void ins_end1();
void ins_aft1();
void ins_bef1();
void del_beg1();
void del_end1();
void del_mid1();
int search_node1();

// Function to search for a node in doubly linked list
int search_node1() {
    if(start == NULL) {
        printf("List is empty. Cannot search.\n");
        return -1;
    }

    int key, position = 0;
    printf("Enter the data to search: ");
    scanf("%d", &key);

    struct node1 *ptr = start;
    while(ptr != NULL) {
        position++;
        if(ptr->data == key) {
            printf("Data %d found at position %d\n", key, position);
            return position;
        }
        ptr = ptr->next;
    }

    printf("Data %d not found in the list\n", key);
    return -1;
}

// Function to print the doubly linked list
void printll1() {
    struct node1 *ptr;
    ptr = start;

    if(start == NULL) {
        printf("The list is empty\n");
        return;
    }

    printf("The list is: ");
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to insert at beginning of doubly linked list
void ins_beg1() {
    int data;
    struct node1 *new_node = (struct node1*)malloc(sizeof(struct node1));
    printf("Enter the data of the new node\n");
    scanf("%d", &new_node->data);
    new_node->prev = NULL;
    new_node->next = start;

    if(start != NULL) {
        start->prev = new_node;
    }

    start = new_node;
    printll1();
}

// Function to insert at end of doubly linked list
void ins_end1() {
    struct node1 *new_node = (struct node1*)malloc(sizeof(struct node1));
    struct node1 *ptr;
    printf("Enter the data of the new node\n");
    scanf("%d", &new_node->data);

    new_node->next = NULL;

    if(start == NULL) {
        new_node->prev = NULL;
        start = new_node;
    } else {
        ptr = start;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev = ptr;
    }

    printll1();
}

// Function to insert after a node in doubly linked list
void ins_aft1() {
    struct node1* new_node = (struct node1*)malloc(sizeof(struct node1));
    struct node1 *ptr;
    int pos;
    ptr = start;
    printf("Enter the data of the node after which new node has to be inserted\n");
    scanf("%d", &pos);
    printf("Enter the data of the new node\n");
    scanf("%d", &new_node->data);

    while(ptr != NULL && ptr->data != pos) {
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        printf("Node with data %d not found\n", pos);
        free(new_node);
        return;
    }

    new_node->next = ptr->next;
    new_node->prev = ptr;

    if(ptr->next != NULL) {
        ptr->next->prev = new_node;
    }

    ptr->next = new_node;
    printll1();
}

// Function to insert before a node in doubly linked list
void ins_bef1() {
    struct node1* new_node = (struct node1*)malloc(sizeof(struct node1));
    struct node1 *ptr;
    int pos;
    printf("Enter the data of the node before which the new node is inserted\n");
    scanf("%d", &pos);
    printf("Enter the data of the new node\n");
    scanf("%d", &new_node->data);

    ptr = start;

    if(ptr == NULL) {
        printf("List is empty\n");
        free(new_node);
        return;
    }

    // If inserting before first node
    if(ptr->data == pos) {
        new_node->next = start;
        new_node->prev = NULL;
        start->prev = new_node;
        start = new_node;
        printll1();
        return;
    }

    while(ptr != NULL && ptr->data != pos) {
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        printf("Node with data %d not found\n", pos);
        free(new_node);
        return;
    }

    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;

    printll1();
}

// Function to delete from beginning of doubly linked list
void del_beg1() {
    if(start == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct node1 *ptr;
    ptr = start;

    if(start->next == NULL) {
        // Only one node
        start = NULL;
    } else {
        start = ptr->next;
        start->prev = NULL;
    }

    free(ptr);
    printll1();
}

// Function to delete from end of doubly linked list
void del_end1() {
    if(start == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct node1 *ptr = start;

    // If only one node
    if(ptr->next == NULL) {
        start = NULL;
        free(ptr);
        printll1();
        return;
    }

    // Traverse to last node
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->prev->next = NULL;
    free(ptr);
    printll1();
}

// Function to delete a specific node from doubly linked list
void del_mid1() {
    if(start == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct node1 *ptr = start;
    int data;
    printf("Enter the data of the node to be deleted\n");
    scanf("%d", &data);

    // If deleting first node
    if(ptr->data == data) {
        del_beg1();
        return;
    }

    while(ptr != NULL && ptr->data != data) {
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }

    // If deleting last node
    if(ptr->next == NULL) {
        ptr->prev->next = NULL;
    } else {
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
    }

    free(ptr);
    printll1();
}

// Main function for doubly linked list operations
int dll() {
    int opt = 0;
    while (opt != 10) {
        printf("\n---------Operations on Doubly Linked list---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node\n");
        printf("4. Insertion before the specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Search for a node\n");
        printf("10. Exit\n");

        printf("Select the operation to be performed\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                ins_beg1();
                break;
            case 2:
                ins_end1();
                break;
            case 3:
                ins_aft1();
                break;
            case 4:
                ins_bef1();
                break;
            case 5:
                del_beg1();
                break;
            case 6:
                del_mid1();
                break;
            case 7:
                del_end1();
                break;
            case 8:
                printll1();
                break;
            case 9:
                search_node1();
                break;
            case 10:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}

// Circular Singly Linked List Node Structure
struct node2 {
    int data;
    struct node2 *next;
};

struct node2 *start2 = NULL;

// Function prototypes for circular singly linked list
void printll2();
void ins_beg2();
void ins_end2();
void ins_aft2();
void ins_bef2();
void del_beg2();
void del_mid2();
void del_end2();
int search_node2();

// Function to search for a node in circular singly linked list
int search_node2() {
    if(start2 == NULL) {
        printf("List is empty. Cannot search.\n");
        return -1;
    }

    int key, position = 0;
    printf("Enter the data to search: ");
    scanf("%d", &key);

    struct node2 *ptr = start2;
    do {
        position++;
        if(ptr->data == key) {
            printf("Data %d found at position %d\n", key, position);
            return position;
        }
        ptr = ptr->next;
    } while(ptr != start2);

    printf("Data %d not found in the list\n", key);
    return -1;
}

// Function to print the circular singly linked list
void printll2() {
    if (start2 == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct node2 *ptr = start2;
    printf("The list is: ");

    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start2);

    printf("\n");
}

// Function to insert at beginning of circular singly linked list
void ins_beg2() {
    struct node2 *new_node = malloc(sizeof(struct node2));
    printf("Enter the data of newnode\n");
    scanf("%d", &new_node->data);

    if (start2 == NULL) {
        start2 = new_node;
        new_node->next = start2;
    } else {
        struct node2 *temp = start2;
        while (temp->next != start2) {
            temp = temp->next;
        }
        new_node->next = start2;
        start2 = new_node;
        temp->next = start2;
    }

    printll2();
}

// Function to insert before a node in circular singly linked list
void ins_bef2() {
    struct node2 *new_node = malloc(sizeof(struct node2));
    struct node2 *ptr, *preptr;
    int pos;
    printf("Enter the data of node before which you need to insert the new node\n");
    scanf("%d", &pos);
    printf("Enter the data of the newnode\n");
    scanf("%d", &new_node->data);

    if (start2 == NULL) {
        printf("List is empty\n");
        free(new_node);
        return;
    }

    // If inserting before first node
    if (start2->data == pos) {
        ins_beg2();
        free(new_node);
        return;
    }

    preptr = start2;
    ptr = start2->next;

    while (ptr != start2 && ptr->data != pos) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == start2 && ptr->data != pos) {
        printf("Node with data %d not found\n", pos);
        free(new_node);
        return;
    }

    new_node->next = ptr;
    preptr->next = new_node;
    printll2();
}

// Function to insert after a node in circular singly linked list
void ins_aft2() {
    struct node2 *new_node = malloc(sizeof(struct node2));
    struct node2 *ptr;
    int pos;
    printf("Enter the data of the node after which you need to insert the new node\n");
    scanf("%d", &pos);
    printf("Enter the data of the newnode\n");
    scanf("%d", &new_node->data);

    if (start2 == NULL) {
        printf("List is empty\n");
        free(new_node);
        return;
    }

    ptr = start2;

    do {
        if(ptr->data == pos) {
            new_node->next = ptr->next;
            ptr->next = new_node;
            printll2();
            return;
        }
        ptr = ptr->next;
    } while(ptr != start2);

    printf("Node with data %d not found\n", pos);
    free(new_node);
}

// Function to insert at end of circular singly linked list
void ins_end2() {
    struct node2 *new_node = malloc(sizeof(struct node2));
    printf("Enter the data of newnode\n");
    scanf("%d", &new_node->data);

    if (start2 == NULL) {
        start2 = new_node;
        new_node->next = start2;
    } else {
        struct node2 *ptr = start2;
        while (ptr->next != start2) {
            ptr = ptr->next;
        }
        new_node->next = start2;
        ptr->next = new_node;
    }

    printll2();
}

// Function to delete from beginning of circular singly linked list
void del_beg2() {
    if (start2 == NULL) {
        printf("List is empty\n");
        return;
    }

    // If only one node
    if (start2->next == start2) {
        free(start2);
        start2 = NULL;
        printll2();
        return;
    }

    struct node2 *ptr = start2;
    while (ptr->next != start2) {
        ptr = ptr->next;
    }

    struct node2 *temp = start2;
    start2 = start2->next;
    ptr->next = start2;
    free(temp);

    printll2();
}

// Function to delete a specific node from circular singly linked list
void del_mid2() {
    if (start2 == NULL) {
        printf("List is empty\n");
        return;
    }

    int data;
    printf("Enter the data of the node to be deleted\n");
    scanf("%d", &data);

    // If deleting first node
    if (start2->data == data) {
        del_beg2();
        return;
    }

    struct node2 *ptr = start2;
    struct node2 *preptr = NULL;

    do {
        preptr = ptr;
        ptr = ptr->next;

        if(ptr->data == data) {
            preptr->next = ptr->next;
            free(ptr);
            printll2();
            return;
        }
    } while(ptr != start2);

    printf("Node with data %d not found\n", data);
}

// Function to delete from end of circular singly linked list
void del_end2() {
    if (start2 == NULL) {
        printf("List is empty\n");
        return;
    }

    // If only one node
    if (start2->next == start2) {
        free(start2);
        start2 = NULL;
        printll2();
        return;
    }

    struct node2 *ptr = start2;
    struct node2 *preptr = NULL;

    while (ptr->next != start2) {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = start2;
    free(ptr);
    printll2();
}

// Main function for circular singly linked list operations
int scll() {
    int opt = 0;

    while (opt != 10) {
        printf("\n---------Operations on Circular Singly Linked list---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node\n");
        printf("4. Insertion before the specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Search for a node\n");
        printf("10. Exit\n");

        printf("Select the operation to be performed\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                ins_beg2();
                break;
            case 2:
                ins_end2();
                break;
            case 3:
                ins_aft2();
                break;
            case 4:
                ins_bef2();
                break;
            case 5:
                del_beg2();
                break;
            case 6:
                del_mid2();
                break;
            case 7:
                del_end2();
                break;
            case 8:
                printll2();
                break;
            case 9:
                search_node2();
                break;
            case 10:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}

// Main function
int main() {
    printf("Welcome to the Linked List Operations Program!\n");
    printf("Select the type of linked list you want to work with:\n");
    printf("1. Singly Linked List\n");
    printf("2. Doubly Linked List\n");
    printf("3. Circular Singly Linked List\n");
    printf("Select an option\n");

    int opt;
    scanf("%d", &opt);
    switch(opt) {
        case 1:
            printf("You selected Singly Linked List.\n");
            sll();
            break;
        case 2:
            printf("You selected Doubly Linked List.\n");
            dll();
            break;
        case 3:
            printf("You selected Circular Singly Linked List.\n");
            scll();
            break;
        default:
            printf("Invalid option. Please select a valid option.\n");
    }

    return 0;
}
