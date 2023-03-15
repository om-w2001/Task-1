#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// A struct to store the birthdays
struct Birthday {
    char name[MAX_SIZE];
    char date[MAX_SIZE];
};

// Global variables
struct Birthday birthdays[MAX_SIZE];
int num_birthdays = 0;

// Function prototypes
void add_birthday();
void search_birthday();
void display_birthdays();
void display_monthly_birthdays();

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n\nBirthday List\n");
        printf("1. Add a birthday\n");
        printf("2. Search for a birthday\n");
        printf("3. Display all the birthdays\n");
        printf("4. Display monthly birthdays\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_birthday();
                break;
            case 2:
                search_birthday();
                break;
            case 3:
                display_birthdays();
                break;
            case 4:
                display_monthly_birthdays();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new birthday
void add_birthday() {
    printf("\nEnter the name: ");
    scanf("%s", birthdays[num_birthdays].name);
    printf("Enter the date (in dd/mm/yyyy format): ");
    scanf("%s", birthdays[num_birthdays].date);
    num_birthdays++;
    printf("Birthday added successfully!\n");
}

// Function to search for a birthday by name
void search_birthday() {
    char name[MAX_SIZE];
    printf("\nEnter the name: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_birthdays; i++) {
        if (strcmp(name, birthdays[i].name) == 0) {
            printf("%s's birthday is on %s.\n", name, birthdays[i].date);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Sorry, we don't have %s's birthday in our database.\n", name);
    }
}

// Function to display all the birthdays
void display_birthdays() {
    printf("\nBirthday List:\n");
    for (int i = 0; i < num_birthdays; i++) {
        printf("%s: %s\n", birthdays[i].name, birthdays[i].date);
    }
}

// Function to display monthly birthdays
void display_monthly_birthdays() {
    char month[MAX_SIZE];
    printf("\nEnter the month (in mm format): ");
    scanf("%s", month);
    printf("\nBirthdays in %s:\n", month);
    int found = 0;
    for (int i = 0; i < num_birthdays; i++) {
        if (strcmp(month, birthdays[i].date+3) == 0) {
            printf("%s: %s\n", birthdays[i].name, birthdays[i].date);
            found = 1;
        }
    }
    if (!found) {
        printf("No birthdays found in %s.\n", month);
    }
}