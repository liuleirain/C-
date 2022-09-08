#include <stdio.h>

unsigned int reverse_bits(unsigned int value);

int main(void) {
  unsigned int num = 25;

  printf("%u reverse bits is : %u\n", num, reverse_bits(num));


  return 0;
}

unsigned int reverse_bits(unsigned int value) {
  unsigned result;
  unsigned i;
  result = 0;

  for (i = 1; i != 0; i <<= 1) {
    result <<= 1;
    if (value & 1) {
      result |= 1;
    }
    value >>= 1;
  }

  return result;
}