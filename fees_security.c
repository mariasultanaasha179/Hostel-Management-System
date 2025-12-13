#include "hostel.h"
#define FILE_NAME "students.csv"
#define TEMP "temp.csv"
#define USER_FILE "users.csv"


void payFees() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen(TEMP, "w");

    char id[20], line[200];
    int found = 0;

    printf("Enter ID to Mark Paid: ");
    scanf("%s", id);

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        if(strcmp(id, s.id) == 0) {
            strcpy(s.fees, "Paid");
            found = 1;
        }

        fprintf(temp, "%s,%s,%s,%s,%s\n",
                s.name, s.id, s.phone, s.room, s.fees);
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename(TEMP, FILE_NAME);

    if(found) printf("Fees Updated.\n");
}

void showDefaulters() {
    FILE *fp = fopen(FILE_NAME, "r");
    char line[200];

    printf("\n--- Fee Defaulters (Pending) ---\n");

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        if(strcmp(s.fees, "Pending") == 0)
            printf("%s (%s)\n", s.name, s.id);
    }

    fclose(fp);
}

void changePassword() {
    char currentUsername[50], oldPass[50], newPass[50];
    User fileUser;
    char line[100];
    int found = 0;

    printf("Enter your Username: ");
    scanf("%s", currentUsername);
    printf("Enter Current Password: ");
    scanf("%s", oldPass);
    printf("Enter New Password: ");
    scanf("%s", newPass);

    FILE *fp = fopen(USER_FILE, "r");
    FILE *temp = fopen(TEMP, "w");

    if (fp == NULL) {
        printf("Error: User database not found. Cannot change password.\n");
        return;
    }
    
    if (temp == NULL) {
        fclose(fp);
        printf("Error creating temporary file.\n");
        return;
    }

    while(fgets(line, sizeof(line), fp)) {
        char temp_line[100];
        strcpy(temp_line, line);

        temp_line[strcspn(temp_line, "\n")] = 0;

        char *token = strtok(temp_line, ",");
        if (token != NULL) {
            strcpy(fileUser.username, token);
            token = strtok(NULL, ",");
            if (token != NULL) {
                strcpy(fileUser.password, token);
            } else {

                fprintf(temp, "%s", line);
                continue;
            }
        } else {
            fprintf(temp, "%s", line);
            continue;
        }

        if(strcmp(currentUsername, fileUser.username) == 0 &&
           strcmp(oldPass, fileUser.password) == 0) {
            
            fprintf(temp, "%s,%s\n", currentUsername, newPass);
            found = 1;
        } else {
             fprintf(temp, "%s,%s\n", fileUser.username, fileUser.password);
        }
    }

    fclose(fp);
    fclose(temp);
    
    remove(USER_FILE);
    rename(TEMP, USER_FILE);

    if(found) {
        printf("Password Changed Successfully for user %s.\n", currentUsername);
    } else {
        printf("Error: Username or Current Password incorrect.\n");
    }
}