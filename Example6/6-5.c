#include <stdio.h>
#include <limits.h>
#define MAX 10000

void Eratosthenes(char is_prime[], int n);
unsigned character_offset(unsigned bit_number);
unsigned bit_offset(unsigned bit_number);
void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
int test_bit(char bit_array[], unsigned bit_number);

int main(void) {
  int i, j, count = 0, flag = 0;
  char is_prime[MAX];
  for (i = 0; i < (MAX - 1) * CHAR_BIT; i++) {
    set_bit(is_prime, i);
    count++;
  }
  is_prime[MAX - 1] = '\0';
  printf("The prime range is 2 to %d\n", (MAX - 1) * CHAR_BIT);
  Eratosthenes(is_prime, count);
  count = 0;
  for (i = 2, j = 0; i < (MAX - 1) * CHAR_BIT; i++, j++) {
    if (test_bit(is_prime, j)) {
      printf("%10d ", i);
      count++;
      flag = 1;
    }
    if (count % 10 == 0 && flag == 1) {
      putchar('\n');
      flag = 0;
    }
  }
  putchar('\n');
  return 0;
}

void Eratosthenes(char is_prime[], int n) {
  int i, j, k, l;
  for (i = 2, k = 0; i < n; i++, k++) {
    for (j = i + 1, l = k + 1; j < n; j++, l++) {
      if (j % i == 0 && test_bit(is_prime, l)) {
        clear_bit(is_prime, l);
      }
    }
  }
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
int test_bit(char bit_array[], unsigned bit_number) {
  if (bit_array[character_offset(bit_number)] & 1 << bit_offset(bit_number)) return 1;
  else return 0;
}