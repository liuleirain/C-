#include <stdio.h>
#include <string.h>
#include <limits.h>

unsigned character_offset(unsigned bit_number);
unsigned bit_offst(unsigned bit_number);
void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
void test_bit(char bit_array[], unsigned bit_number);

int main(void) {
  char bit_a[5] = "AAAA";
  unsigned int num = 2;
  int value = 0;
  printf("Bit_array size of: %lu\n", sizeof(bit_a));
  printf("Source: \t%s\n", bit_a);
  set_bit(bit_a, num);
  printf("set_bit: \t%s\n", bit_a);
  clear_bit(bit_a, num);
  printf("clear_bit: \t%s\n", bit_a);
  assign_bit(bit_a, num, value);
  printf("assign_bit: \t%s\n", bit_a);
  test_bit(bit_a, num);

  return 0;
}

unsigned character_offset(unsigned bit_number) {
  return bit_number / CHAR_BIT;
}

unsigned bit_offset(unsigned bit_number) {
  return bit_number % CHAR_BIT;
}

void set_bit(char bit_array[], unsigned bit_number) {
  bit_array[character_offset(bit_number)] |= 1 << bit_offset(bit_number);
}

void clear_bit(char bit_array[], unsigned bit_number) {
  bit_array[character_offset(bit_number)] &= ~(1 << bit_offset(bit_number));
}

void assign_bit(char bit_array[], unsigned bit_number, int value) {
  if (0 != value) {
    set_bit(bit_array, bit_number);
  }
  else
    clear_bit(bit_array, bit_number);
}

void test_bit(char bit_array[], unsigned bit_number) {
  if (bit_array[character_offset(bit_number)] & 1 << bit_offset(bit_number) != 0) return 1;
  else return 0;
}