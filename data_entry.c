#include "hostel.h"
#define FILE_NAME "students.txt"
#define USER_FILE "users.txt"

void userRegistration() {
    User newUser;

    FILE *fp = fopen(USER_FILE, "a");

    printf("\n--- User Registration ---\n");
    printf("Enter Username: ");
    scanf("%s", newUser.username);
    printf("Enter Password: ");
    scanf("%s", newUser.password);

    fprintf(fp, "%s,%s\n", newUser.username, newUser.password);
    fclose(fp);
    printf("Registration Successful. Please Login.\n");
}

int userLogin() {
    User inputUser, fileUser;
    FILE *fp = fopen(USER_FILE, "r");
    char line[100];
    int loggedIn = 0;

    if (fp == NULL) {
        printf("Error: User database not found. Please Register first.\n");
        return 0;
    }

    printf("\n--- System Login ---\n");
    printf("Username: ");
    scanf("%s", inputUser.username);
    printf("Password: ");
    scanf("%s", inputUser.password);

    while(fgets(line, sizeof(line), fp)) {
 
        if (sscanf(line, "%[^,],%s", fileUser.username, fileUser.password) == 2) {
             if(strcmp(inputUser.username, fileUser.username) == 0 &&
               strcmp(inputUser.password, fileUser.password) == 0) {
                loggedIn = 1;
                break;
            }
        }
    }

    fclose(fp);

    if (loggedIn) {
        printf("Login Successful. Welcome, %s!\n", inputUser.username);
    } else {
        printf("Invalid Username or Password.\n");
    }

    return loggedIn;
}


void addStudent() {
    Student s;
    FILE *fp = fopen(FILE_NAME, "a");

    printf("Enter Name: ");  scanf(" %[^\n]", s.name);
    printf("Enter ID: ");    scanf("%s", s.id);
    printf("Enter Phone: "); scanf("%s", s.phone);
    printf("Enter Room: ");  scanf("%s", s.room);

    strcpy(s.fees, "Pending");

    fprintf(fp, "%s,%s,%s,%s,%s\n",
            s.name, s.id, s.phone, s.room, s.fees);

    fclose(fp);
    printf("Student Added Successfully.\n");
}

void viewAll() {
    FILE *fp = fopen(FILE_NAME, "r");
    char line[200];

    printf("\n%-25s %-10s %-12s %-8s %-10s\n",
           "Name", "ID", "Phone", "Room", "Fees");
    printf("------------------------------------------------------------------\n");

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        printf("%-25s %-10s %-12s %-8s %-10s\n",
               s.name, s.id, s.phone, s.room, s.fees);
    }

    fclose(fp);
}