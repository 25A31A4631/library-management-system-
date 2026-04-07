#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book 
{
    int id;
    char title[50];
    char author[50];
    int issued; // 0 = available, 1 = issued
};

struct Book library[MAX];
int count = 0;

// Add book
void addBook()
{
    printf("\nEnter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Title: ");
    scanf(" %[^\n]", library[count].title);

    printf("Enter Author: ");
    scanf(" %[^\n]", library[count].author);

    library[count].issued = 0;
    count++;

    printf("Book added successfully!\n");
}

// Display books
void displayBooks()
{
    printf("\nLibrary Books:\n");
    for (int i = 0; i < count; i++) {
        printf("\nID: %d", library[i].id);
        printf("\nTitle: %s", library[i].title);
        printf("\nAuthor: %s", library[i].author);
        printf("\nStatus: %s\n", library[i].issued ? "Issued" : "Available");
    }
}

// Search book
void searchBook()
{
    int id, found = 0;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
{
        if (library[i].id == id) {
            printf("\nBook Found!");
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s\n", library[i].author);
            found = 1;
            break;
        }
    }

    if (!found)
{
        printf("Book not found!\n");
    }
}

// Issue book
void issueBook() 
{
    int id;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
{
        if (library[i].id == id)
{
            if (library[i].issued
) {
                printf("Book already issued!\n");
            } 
else
{
                library[i].issued = 1;
                printf("Book issued successfully!\n");
            }
            return;
        }
    }
    printf("Book not found!\n");
}

// Return book
void returnBook()
{
    int id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (!library[i].issued) {
                printf("Book was not issued!\n");
            } else {
                library[i].issued = 0;
                printf("Book returned successfully!\n");
            }
            return;
        }
    }
    printf("Book not found!\n");
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
