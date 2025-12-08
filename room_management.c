#include <stdio.h>
#include <string.h>

#define FILE_NAME "students.txt"

// 7. Assign Room
void assignRoom() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    char id[20], newRoom[10], line[200];
    int found = 0;

    printf("Enter Student ID: ");
    scanf("%s", id);
    printf("Enter New Room: ");
    scanf("%s", newRoom);

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        if(strcmp(id, s.id) == 0) {
            strcpy(s.room, newRoom);
            found = 1;
        }

        fprintf(temp, "%s,%s,%s,%s,%s\n",
                s.name, s.id, s.phone, s.room, s.fees);
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if(found) printf("Room Assigned.\n");
    else printf("ID Not Found.\n");
}

// 8. Check Room Capacity
void checkRoomCapacity() {
    FILE *fp = fopen(FILE_NAME, "r");
    char room[10], line[200];
    int count = 0;

    printf("Enter Room Number: ");
    scanf("%s", room);

    while(fgets(line, sizeof(line), fp)) {
        Student s;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s",
               s.name, s.id, s.phone, s.room, s.fees);

        if(strcmp(room, s.room) == 0)
            count++;
    }

    printf("Room %s has %d students.\n", room, count);
    fclose(fp);
}
