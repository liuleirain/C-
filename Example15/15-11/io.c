/*函数访问库存文件。*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "part.h"
#include "io.h"

/*用于库存文件的流。part_number数组包含使用的最大零件号和第一个被删除的零件号。后者可以更有效地添加新零件，避免了扫描整个文件以查找先前删除的条目。这些都是静态的，因为所有需要if的函数都在这个模块中。*/
static FILE* inv_file;
static Part_number part_number[2];
static enum position { LAST, NEXT }pos;

/*将最后一个和下一个零件号写入文件*/
static void write_part_numbers(void) {
  fseek(inv_file, 0, SEEK_SET);
  fwrite(part_number, sizeof(Part_number), 2, inv_file);
}

/*打开库存文件*/
int open_file(char const* filename) {
  /*尝试打开文件*/
  inv_file = fopen(filename, "r+b");
  if (inv_file == NULL) {

    /*它失败了。如果是因为该文件不存在，请尝试创建它*/
    if (errno == ENOENT) {
      inv_file = fopen(filename, "w+b");
      if (inv_file != 0) {
        part_number[LAST] = 0;
        part_number[NEXT] = 1;
        write_part_numbers();
      }
    }
    /*如果我们不能打开(或创建)文件。打印一条信息。*/
    if (inv_file == NULL)
      perror(filename);
  }
  else
    /*文件打开，读取零件编号数据*/
    fread(part_number, sizeof(Part_number), 2, inv_file);
  /*返回是否能够打开文件的状态。*/
  return inv_file != NULL;
}

/*关闭库存文件*/
void close_file(void) {
  fclose(inv_file);
}

/*返回文件中最后一个零件的编号*/
Part_number last_part_number(void) {
  return part_number[LAST];
}

/*返回下一个要使用的零件号*/
Part_number next_part_number(void) {
  Part part;
  /*如果“next”零件号在现有零件的范围内，则从该点开始读取文件以查找第一个被删除的零件。否则(或如果没有发现被删除的零件)，请在目前为止使用的最后一个零件后立即返回零件号*/
  while (part_number[NEXT] <= part_number[LAST]) {
    if (!read_part(part_number[NEXT], &part))
      break;
    part_number[NEXT] += 1;
  }
  write_part_numbers();
  return part_number[NEXT];
}

/*从库存文件读取一个零件*/
int read_part(Part_number p, Part* part) {
  /*如果零件号合法，请尝试读取文件。然后通过检查非空的描述来验证该零件是否被删除。*/
  if (p > 0 && p <= part_number[LAST]) {
    fseek(inv_file, p * sizeof(Part), SEEK_SET);
    if (fread(part, sizeof(Part), 1, inv_file) != 1) {
      perror("Connot read part");
      exit(EXIT_FAILURE);
    }
    return *part->description != '\0';
  }
  return FALSE;
}

/*将一个零件写入库存文件。如果这个零件在旧的“最后”零件之后，更新“最后的零件号”。*/
void write_part(Part_number p, Part const* part) {
  /*确保零件编号是合法的(一个全新的零件可能有下一个数字超过“part_number[LAST]”)。*/
  if (p > 0 && p <= part_number[LAST] + 1) {
    fseek(inv_file, p * sizeof(Part), SEEK_SET);
    if (fwrite(part, sizeof(Part), 1, inv_file) != 1) {
      perror("Cannot write part");
      exit(EXIT_FAILURE);
    }

    /*更新零件号状态。如果零件号大于part_number[LAST]，我们刚刚创建了一个新零件。*/
    if (p > part_number[LAST]) {
      part_number[LAST] = p;
      write_part_numbers();
    }

    /*如果描述为空，表示正在删除该零件。*/
    if (part->description[0] == '\0' && p < part_number[NEXT]) {
      part_number[NEXT] = p;
      write_part_numbers();
    }
  }
}