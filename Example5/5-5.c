#include <stdio.h>

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit);

int main(void) {
  printf("Original value: 0x%x, value to store: 0x%x, return value: 0x%x\n", 0x0, 0x1, store_bit_field(0x0, 0x1, 4, 4));
  printf("Original value: 0x%x, value to store: 0x%x, return value: 0x%x\n", 0x0, 0x1, store_bit_field(0xffff, 0x123, 15, 4));
  printf("Original value: 0x%x, value to store: 0x%x, return value: 0x%x\n", 0x0, 0x1, store_bit_field(0xffff, 0x123, 13, 9));

  return 0;
}

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit) {
  int mask = 1;
  unsigned int i = starting_bit - ending_bit;
  while (i) {
    mask |= 1;
    mask <<= 1;
    i--;
  }
  mask <<= ending_bit;


  original_value &= ~mask;
  value_to_store <<= ending_bit;
  value_to_store &= mask;
  original_value |= value_to_store;

  return original_value;
}