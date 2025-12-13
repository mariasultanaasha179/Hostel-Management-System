#ifndef HOSTEL_H
#define HOSTEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char id[20];
    char phone[20];
    char room[20];
    char fees[20];
} Student;

typedef struct {
    char username[50];
    char password[50];
} User;

void userRegistration();
int userLogin();
void addStudent();
void viewAll();

void searchStudent();
void editStudent();
void deleteStudent();

void payFees();
void showDefaulters();
void changePassword();

void assignRoom();
void checkRoomCapacity();

#endif