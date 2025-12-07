#include <stdio.h>
#include <string.h>
#include "functions.h"

#define FILE_NAME "students.txt"
#define TEMP "temp.txt"

// 9. Pay Fees
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
