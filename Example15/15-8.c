/*
**打印指定文件的十六进制转储。如果没有给出filenmae参数，则打印标准输入的转储。
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>

#define BUFFER_SIZE 64

/*
**函数转储流的内容
*/
void dump(FILE* stream) {
  unsigned int offset;
  unsigned char data[16];
  int len;
  char buffer[BUFFER_SIZE];

  /*
  **初始化将用于输出的缓冲区
  */
  memset(buffer, ' ', BUFFER_SIZE - 1);
  buffer[45] = '*';
  buffer[62] = '*';
  buffer[BUFFER_SIZE - 1] = '\0';

  offset = 0;
  while ((len = fread(data, 1, 16, stream)) > 0) {
    char* hex_ptr;
    char* char_ptr;
    int i;

    /*
    **开始使用偏移量构建输出缓冲区
    */
    sprintf(buffer, "%06X ", offset);
    *(buffer + 7) = ' ';
    /*
    **准备指向缓冲区的十六进制和字符部分的指针，并将它们初始化为空格
    */
    hex_ptr = buffer + 8;
    char_ptr = buffer + 46;
    memset(hex_ptr, ' ', 35);
    memset(char_ptr, ' ', 16);

    /*
    **现在将数据转换为两个输出表单，并将其存储在缓冲区中
    */
    for (int i = 0; i < len; i++) {
      /*
      **将下一个字符转换为十六进制。必须用空格覆盖sprintf插入的NUL
      */
      sprintf(hex_ptr, "%02X", data[i]);
      hex_ptr += 2;
      *hex_ptr = ' ';

      /*
      **在一行的十六进制部分的每组4个值之间留下一个空格。
      */
      if (i % 4 == 3)
        hex_ptr++;

      /*
      **如果字符是可打印的，就把它放在该行的char部分，否则就放一个点进去。
      */
      if (isprint(data[i]) || data[i] == ' ')
        *char_ptr++ = data[i];
      else
        *char_ptr++ = '.';
    }

    /*
    **打印该行，然后通过循环更新下一次的偏移量。
    */
    puts(buffer);
    offset += len;
  }
}

/*
**主程序。转储文件(如果有参数)或stdin。
*/
int main(int argc, char** argv) {
  if (argc <= 1)
    dump(stdin);
  else {
    FILE* stream;
    stream = fopen(argv[1], "rb");
    if (stream == NULL) {
      perror(argv[1]);
      exit(EXIT_FAILURE);
    }
    dump(stream);
    if (fclose(stream) != 0) {
      perror(argv[1]);
      exit(EXIT_FAILURE);
    }
  }
  return EXIT_SUCCESS;
}