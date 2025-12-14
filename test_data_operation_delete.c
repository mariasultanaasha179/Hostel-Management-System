#include "hostel.h"
#include "data_operations.c"
#include <stdio.h>
#include <string.h>

#define TEST_FILE_NAME "students.csv"

void setup_students_csv() {
    FILE *fp = fopen(TEST_FILE_NAME, "w");
    if (fp != NULL) {
        fprintf(fp, "Munawar,1,013..,r1,Pending\n");
        fprintf(fp, "Upoma,2,013..,r2,Paid\n");
        fclose(fp);
    } else {
        printf("ERROR: Could not setup students.csv for testing!\n");
    }
}

int get_current_file_count() {
    FILE *fp = fopen(TEST_FILE_NAME, "r");
    if (fp == NULL) {
        return 0;
    }

    int count = 0;
    char line[500];
    while (fgets(line, sizeof(line), fp)) {
        count++;
    }

    fclose(fp);
    return count;
}

void test_delete_student_success() {
    printf("\n Test Deletion\n\n");
    setup_students_csv();

    int initial_count = get_current_file_count(); 
    printf("Initial student count: %d.\nID are: 1 , 2 \n\n2 ", initial_count);
    deleteStudent(); 

    int actual_count = get_current_file_count();
    int expected_count = initial_count - 1; 

    printf("\nDeletion Successful\n");
    printf("expected: %d actual: %d, success:%d\n",
        expected_count, actual_count, actual_count == expected_count);
}

int main() {
    test_delete_student_success();
    return 0;
}