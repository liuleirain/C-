/*
**解析命令行参数，以便由调用者的函数进行处理。
*/
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define NUL '\0'

enum { NONE, FLAG, ARG };

/*
**确定参数是一个标志还是需要一个值。
*/
argtype(int ch, int* control) {
  while (*control != NULL)
    if (ch == *control++)
      return *control == '+' ? ARG : FLAG;
  return NONE;
}

/*
**处理参数。
*/
char** args(int argc, char** argv, char* control,
  void(*do_arg)(int, char*), void(*illegal_arg)(int)) {
  register char* argp;
  register int ch;
  register int skip_arg;

  while ((argp = *++argv) != NULL && *argp == '-') {
    skip_arg = FALSE;
    while (!skip_arg && (ch = *++argp) != NUL) {
      switch (argtype(ch, control)) {
      case FLAG:
        (*do_arg)(ch, NULL);
        break;
      case ARG:
        if (*++argp != NUL || (argp = *++argv) != NULL) {
          (*do_arg)(ch, argp);
          skip_arg = TRUE;
          break;
        }
        (*illegal_arg)(ch);
        return argv;
      case NONE:
        (*illegal_arg)(ch);
        break;
      }
    }
  }
  return argv;
}

void do_arg(int ch, char* value) {

}

void illegal_arg(int ch) {

}

int main(int argc, char** argv) {
  char* control = "x";
  void (*do_arg)(int, char*) = do_arg;
  void (*illegal_arg)(int) = illegal_arg;
  do_args(argc, argv, control, do_arg, illegal_arg);
  return 0;
}