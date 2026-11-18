#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char department[20];
    int available;
};

int main(void) {
    struct Book books[50] = {
        {1, "Mathematics Basics", "Maths", 1},
        {2, "Advanced Algebra", "Maths", 1},
        {3, "Physics Concepts", "Physics", 1},
        {4, "Mechanics", "Physics", 1},
        {5, "Organic Chemistry", "Chemistry", 1},
        {6, "Chemical Reactions", "Chemistry", 1}
    };

    int count = 6;
    int choice, id, i;
    char department[20];

    printf("1. Student\n");
    printf("2. Admin\n");
    printf("Enter your role: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (choice == 1) {
        printf("Enter department (Maths/Physics/Chemistry): ");
        scanf("%19s", department);

        printf("\nBooks in your department:\n");
        for (i = 0; i < count; i++) {
            if (strcmp(books[i].department, department) == 0) {
                printf("%d. %s - %s\n",
                       books[i].id, books[i].name,
                       books[i].available ? "Available" : "Issued");
            }
        }

        printf("\nEnter Book ID to borrow: ");
        scanf("%d", &id);

        for (i = 0; i < count; i++) {
            if (books[i].id == id) {
                if (strcmp(books[i].department, department) != 0) {
                    printf("Access denied! This book belongs to another department.\n");
                } else if (!books[i].available) {
                    printf("Book is already issued.\n");
                } else {
                    books[i].available = 0;
                    printf("Book borrowed successfully!\n");
                }
                break;
            }
        }

        if (i == count) {
            printf("Book not found!\n");
        }
    } else if (choice == 2) {
        printf("\nWelcome Admin!\n");
        printf("All department books:\n");

        for (i = 0; i < count; i++) {
            printf("%d. %s (%s) - %s\n",
                   books[i].id, books[i].name, books[i].department,
                   books[i].available ? "Available" : "Issued");
        }

        if (count >= 50) {
            printf("Book storage is full. Cannot add another book.\n");
            return 0;
        }

        printf("\nEnter new Book ID: ");
        scanf("%d", &books[count].id);
        printf("Enter Book Name: ");
        scanf(" %49[^\n]", books[count].name);
        printf("Enter Department (Maths/Physics/Chemistry): ");
        scanf("%19s", books[count].department);

        books[count].available = 1;
        count++;
        printf("New book added successfully!\n");
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
