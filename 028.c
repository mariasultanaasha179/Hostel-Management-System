#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define FILE_NAME "students.txt"

// 1. Secure Login
void secureLogin() {
    char input[20], savedPass[20];
    FILE *fp = fopen("password.txt", "r");

    if(!fp) {
        fp = fopen("password.txt", "w");
        fprintf(fp, "admin123");
        fclose(fp);
        strcpy(savedPass, "admin123");
    } else {
        fscanf(fp, "%s", savedPass);
        fclose(fp);
    }

    printf("Enter system password: ");
    scanf("%s", input);

    if(strcmp(input, savedPass) != 0) {
        printf("Access Denied!\n");
        exit(0);
    }
}

// 2. Add Student
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

// 3. View All Records
void viewAll() {
    FILE *fp = fopen(FILE_NAME, "r");
    char line[200];

    printf("\n%-15s %-10s %-12s %-8s %-10s\n",
           "Name", "ID", "Phone", "Room", "Fees");
    printf("------------------------------------------------------\n");

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        printf("%-15s %-10s %-12s %-8s %-10s\n",
               s.name, s.id, s.phone, s.room, s.fees);
    }

    fclose(fp);
}

// MAIN MENU (Functionality 12)
int main() {
    secureLogin();

    int ch;
    do {
        printf("\n--- HOSTEL MANAGEMENT SYSTEM ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Edit Student\n");
        printf("5. Delete Student\n");
        printf("6. Assign Room\n");
        printf("7. Check Room Capacity\n");
        printf("8. Pay Fees\n");
        printf("9. Show Defaulters\n");
        printf("10. Change Password\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: addStudent(); break;
            case 2: viewAll(); break;
            case 3: searchStudent(); break;
            case 4: editStudent(); break;
            case 5: deleteStudent(); break;
            case 6: assignRoom(); break;
            case 7: checkRoomCapacity(); break;
            case 8: payFees(); break;
            case 9: showDefaulters(); break;
            case 10: changePassword(); break;
        }

    } while(ch != 0);

    printf("Data Saved. Exiting...\n");
    return 0;
}
