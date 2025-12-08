#include <stdio.h>
#include <string.h>

#define FILE_NAME "students.txt"
#define TEMP "temp.txt"

// 4. Search Student
void searchStudent() {
    FILE *fp = fopen(FILE_NAME, "r");
    char line[200], id[20];
    int found = 0;

    printf("Enter ID to Search: ");
    scanf("%s", id);

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        if(strcmp(id, s.id) == 0) {
            printf("FOUND: %s | %s | %s | %s | %s\n",
                   s.name, s.id, s.phone, s.room, s.fees);
            found = 1;
        }
    }

    if(!found) printf("Student Not Found.\n");
    fclose(fp);
}

// 5. Edit Student
void editStudent() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen(TEMP, "w");
    char line[200], id[20];
    int found = 0;

    printf("Enter ID to Edit: ");
    scanf("%s", id);

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        if(strcmp(id, s.id) == 0) {
            printf("New Phone: "); scanf("%s", s.phone);
            printf("New Room: ");  scanf("%s", s.room);
            found = 1;
        }

        fprintf(temp, "%s,%s,%s,%s,%s\n",
                s.name, s.id, s.phone, s.room, s.fees);
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename(TEMP, FILE_NAME);

    if(found) printf("Student Updated.\n");
}

// 6. Delete Student
void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen(TEMP, "w");
    char line[200], id[20];
    int found = 0;

    printf("Enter ID to Delete: ");
    scanf("%s", id);

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        if(strcmp(id, s.id) != 0)
            fprintf(temp, "%s,%s,%s,%s,%s\n",
                    s.name, s.id, s.phone, s.room, s.fees);
        else found = 1;
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename(TEMP, FILE_NAME);

    if(found) printf("Deleted Successfully.\n");
}
