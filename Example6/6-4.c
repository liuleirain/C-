#include <stdio.h>
#define MAX 1000
void Eratosthenes(char is_prime[], int n);

int main(void) {
  int i, j, count = 0;
  int flag = 0;
  char is_prime[MAX];

  for (i = 2; i < MAX; i++) {
    is_prime[count] = '1';
    count++;
  }
  is_prime[i] = '\0';
  printf("The prime range is 2 to %d\n", MAX);
  Eratosthenes(is_prime, MAX);
  count = 0;
  for (i = 2, j = 0; i < MAX; i++, j++) {
    if (is_prime[j] == '1') {
      printf("%4d ", i);
      count++;
      flag = 1;
    }
    if (flag == 1 && count % 20 == 0) {
      putchar('\n');
      flag = 0;
    }
  }

  putchar('\n');

  return 0;
}

void Eratosthenes(char is_prime[], int n) {
  char* p_is_prime = is_prime;
  char* p_temp = NULL;
  int i, j;

  for (i = 2; i < n; i++) {
    p_temp = p_is_prime + 1;
    for (j = i + 1; j < n; j++, p_temp++) {
      if (j % i == 0 && *p_temp == '1') {
        *p_temp = '0';
      }
    }
    p_is_prime++;
  }
}