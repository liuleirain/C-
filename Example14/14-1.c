#include <stdio.h>

#define OPTION_DETAILED 1

void print_ledger_long(int x) {
  printf("ledger long: %d\n", x);
}

void print_ledger_detailed(int x) {
  printf("ledger detailed: %d\n", x);
}

void print_ledger_default(int x) {
  printf("ledger default: %d\n", x);
}

void print_ledger(int x) {
#ifdef OPTION_LONG
#       define OK 1
  print_ledger_long(x);
#endif

#ifdef OPTION_DETAILED
#       define OK 1
  print_ledger_detailed(x);
#endif

#ifdef OK
  print_ledger_default(x);
#endif
}

int main() {
  print_ledger(5);
  return 0;
}