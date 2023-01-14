/*
主程序为简单的库存系统。打开目录文件并执行主事务处理循环
*/
#include <stdio.h>
#include <stdlib.h>
#include "part.h"
#include "io.h"
#include "process.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: inventory inv-filename\n");
    return EXIT_FAILURE;
  }
  if (open_file(argv[1])) {
    while (process_request());
    close_file();
  }
  return EXIT_SUCCESS;
}