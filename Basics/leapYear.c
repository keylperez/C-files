#include<stdio.h>
#include<string.h>

int leapTest(int Year);

int main() {
  int year;
  int leapYear;
	printf("intput a year:\t");
  scanf("%d", &year);
  leapYear = leapTest(year);
  if (leapYear == 1){
    printf("\nLeap year");
  }
  else{
    printf("\nNot a leap year");
  }
  return 0;
}

int leapTest(int Year){
  if(Year%4 == 0){
    if(Year%100 != 0){
      return 1;
    }
    if(Year%400 == 0){
      return 1;
    }
  }
  return 0;
}
