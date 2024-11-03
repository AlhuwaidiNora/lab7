#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int bookID;
    char title[100];
    char author[50];
    int year;
    float price;
} Book;

Book books[MAX_BOOKS];
int N = 0;

void loadBookData() {
    FILE *file = fopen("books.dat", "rb");
    if (file) {
        N = fread(books, sizeof(Book), MAX_BOOKS, file);
        fclose(file);
        printf("Loading existing data from books.dat...\n");
    }
}

void saveBookData() {
    FILE *file = fopen("books.dat", "wb");
    if (file) {
        fwrite(books, sizeof(Book), N, file);
        fclose(file);
        printf("Saving data to books.dat...\n");
    }
}

void inputBookData() {
    printf("Enter book details:\n");
    printf("ID: ");
    scanf("%d", &books[N].bookID);
    getchar();  // Clear newline
    printf("Title: ");
    fgets(books[N].title, sizeof(books[N].title), stdin);
    books[N].title[strcspn(books[N].title, "\n")] = 0;  // Remove newline
    printf("Author: ");
    fgets(books[N].author, sizeof(books[N].author), stdin);
    books[N].author[strcspn(books[N].author, "\n")] = 0;  // Remove newline
    printf("Year: ");
    scanf("%d", &books[N].year);
    printf("Price (SAR): ");
    scanf("%f", &books[N].price);
    N++;
    saveBookData();
}

void displayBookData() {
    printf("Book Details:\n");
    for (int i = 0; i < N; i++) {
        printf("ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f SAR\n",
               books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
    }
}

void findBookByID() {
    int id;
    printf("Enter book ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < N; i++) {
        if (books[i].bookID == id) {
            printf("Found Book - ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f SAR\n",
                   books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

void calculateTotalValue() {
    float totalValue = 0;
    for (int i = 0; i < N; i++) {
        totalValue += books[i].price;
    }
    printf("Total Value of Books: %.2f SAR\n", totalValue);
}

int main() {
    loadBookData();
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for Book by ID\n");
        printf("4. Calculate Total Value of Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputBookData();
                break;
            case 2:
                displayBookData();
                break;
            case 3:
                findBookByID();
                break;
            case 4:
                calculateTotalValue();
                break;
            case 5:
                saveBookData();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

