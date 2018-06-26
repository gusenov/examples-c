#include <stdio.h>

#define STRUCT_ARRAY_SIZE 4
#define STRING_BUFFER_SIZE 128

typedef struct User {
 char fname[STRING_BUFFER_SIZE];
 char lname[STRING_BUFFER_SIZE];
} Data;

Data input(void) {
 Data data;
 printf("First & last name -> ");
 scanf("%s%s", data.fname, data.lname);
 return data;
}

int main() {
 printf("sizeof (Data) = %zu\n", sizeof (Data));  // sizeof (Data) = 256
  
 Data data[STRUCT_ARRAY_SIZE];

 for (int i = 0; i < STRUCT_ARRAY_SIZE; i++) {
  data[i] = input();
 }
 
 for (int i = 0; i < STRUCT_ARRAY_SIZE; i++) {
  printf("First & last name: %s %s\n", data[i].fname, data[i].lname);
 }

 return 0;
}

