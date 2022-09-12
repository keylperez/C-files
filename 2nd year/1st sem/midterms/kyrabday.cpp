#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Date {
  int month;
  int day;
  int year;
} Date;

void foo(Date* sPtr);

int main() {

  Date birthday;
  Date* sPtr;
  sPtr = &birthday;

  foo(sPtr);

  printf("Birthday: %d/%d/%d", birthday.month, birthday.day, birthday.year);

  return 0;

}

void foo(Date* sPtr) {

  *sPtr = {5, 5, 2001};
}
