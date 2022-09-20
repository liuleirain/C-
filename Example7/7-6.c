#include <stdio.h>
#include <string.h>
#define MAX_LEN 128

static char *digits[] ={
  "", "ONE ", "TWO ", "THREE ", "FOUR ", "FIVE ", 
  "SIX ", "SEVEN ", "EIGHT ", "NINE ", "TEN ",
  "ELEVEN ", "TWELVE ", "THIRTEEN ",
  "FOURTEEN ", "FIFTEEN ", "SIXTEEN ",
  "SEVENTEEN ", "EIGHTEEN ", "NINETEEN" 
};

static char *tens[] ={
  "", "", "TWENTY ", "THIRTY ", "FORTY ",
  "FIFTY ", "SIXTY ", "SEVENTY ", "EIGHTY ",
  "NINETY ",
};

static char *magnitudes[] = {
  "", "THOUSAND ", "MILLION ", "BTLLION "
};

void written_amount(unsigned int amount, char *buffer);
static void do_one_group(unsigned int amount, char *buffer, char **magnitude);

int main(void){
  int amount = 16312;
  char buffer[500];
  written_amount(amount, buffer);
  return 0;
}

static void do_one_group(unsigned int amount, char *buffer, char **magnitude){
  int value;
  value = amount / 1000;
  if(value > 0)
    do_one_group(value, buffer, magnitude + 1);
  amount = amount % 1000;
  value = amount / 100;
  if(value > 0){
    strcat(buffer, digits[value]);
    strcat(buffer, "HUNDRED ");
  }
  value = amount % 100;
  if(value >= 20){
    strcat(buffer, tens[value / 10]);
    value = value % 10;
  }
  if(value > 0){
    strcat(buffer, digits[value]);
  }
  if(amount > 0){
    strcat(buffer, *magnitude);
  }
}

void written_amount(unsigned int amount, char * buffer){
  if(amount == 0)
    strcpy(buffer, "ZERO ");
  else
  {
    do_one_group(amount, buffer, magnitudes);
  }
  printf("the string of number is %s\n", buffer);
}