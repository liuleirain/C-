/*库存系统的交易解码和处理*/

#include <stdio.h>
#include <string.h>
#include "part.h"
#include "io.h"
#include "process.h"

/*这些函数实现各种事务。它们是静态的，因为它们只由本模块后面出现的事务解压缩函数调用。*/

/*总计*/
static void total(void) {
  Part_number p;
  Part part;
  Value total_value;

  /* 读取每个部分并将其值加到总数中 */
  total_value = 0;
  for (p = last_part_number(); p > 0; p--)
    if (read_part(p, &part))
      total_value += part.total_value;

  printf("Total value of inventory = %.2f\n", total_value);
}

/*新零件*/
static void new_part(char const* description, Quantity quantity, Value price_each) {
  Part part;
  Part_number part_number;

  /*  将参数复制到Part结构中  */
  strcpy(part.description, description);
  part.quantity = quantity;
  part.total_value = quantity * price_each;

  /*  获取当前未使用的最小零件号，并写入该零件的信息  */
  part_number = next_part_number();
  write_part(part_number, &part);
  printf("%s is part number %lu\n", description, part_number);
}

/*买卖*/
static void buy_sell(char request_type, Part_number part_number, Quantity quantity, Value price_each) {
  Part part;
  if (!read_part(part_number, &part))
    fprintf(stderr, "No such part\n");
  else {
    if (request_type == 'b') {
      /* 买 */
      part.quantity += quantity;
      part.total_value += quantity * price_each;
    }
    else {
      /*销售:确保我们有足够的东西可以卖。如果是，计算销售的利润*/
      Value unit_value;

      if (quantity > part.quantity) {
        printf("Sorry, only %hu in stock\n", part.quantity);
        return;
      }
      unit_value = part.total_value / part.quantity;
      part.quantity -= quantity;
      part.total_value -= quantity * unit_value;
      printf("Total profit:$%.2f\n", quantity * (price_each - unit_value));
    }
    write_part(part_number, &part);
  }
}

/*删除*/
static void delete(Part_number part_number) {
  Part part;
  if (!read_part(part_number, &part))
    fprintf(stderr, "No such part\n");
  else {
    part.description[0] = '\0';
    write_part(part_number, &part);
  }
}

/*打印*/
static void print(Part_number part_number) {
  Part part;
  if (!read_part(part_number, &part))
    fprintf(stderr, "No such part\n");
  else {
    printf("Part number %lu\n", part_number);
    printf("Description: %s\n", part.description);
    printf("Quantity on hand: %hu\n", part.quantity);
    printf("Total value: %.2f\n", part.total_value);
  }
}

/*打印全部*/
static void print_all(void) {
  Part_number p;
  Part part;
  printf("Part number Description           Quantity  Total value\n");
  printf("----------- --------------------- --------- -----------\n");
  for (p = 1; p <= last_part_number(); p++)
    if (read_part(p, &part))
      printf("%11lu %-*.*s %10hu %11.2f\n", p, MAX_DESCRIPTION, MAX_DESCRIPTION, part.description, part.quantity, part.total_value);
}

/*解码和处理一个事务*/
int process_request(void) {
  char request[MAX_REQUEST_LINE_LENGTH];
  char request_type[10];
  char description[DESCRIPTION_FIELD_LEN];
  Part_number part_number;
  Quantity quantity;
  Value price_each;
  char left_over[2];

  /*提示并读取请求。如果到达文件末尾，则返回FALSE以停止主事务循环*/
  fputs("\nNext request? ", stdout);
  if (fgets(request, MAX_REQUEST_LINE_LENGTH, stdin) == NULL)
    return FALSE;

  /*查看它是什么类型的请求并解码参数。注意，试图从每个请求中提取一个额外的字符串(left_over)，以确保用户不会输入太多数据。*/
  /*“end”和“total”不带参数*/
  if (sscanf(request, "%10s %1s", request_type, left_over) == 1 &&
    (strcmp(request_type, "end") == 0 || strcmp(request_type, "total") == 0)) {
    if (request_type[0] == 'e')
      /*end'请求:返回FALSE停止主事务循环*/
      return FALSE;
    else
      total();
  }
  /*“new”:需要说明，数量，成本。它使用下一个可用的零件号。*/
  else if (sscanf(request, "new %[^,],%hu,%lf %1s",
    description, &quantity, &price_each, left_over) == 3) {
    new_part(description, quantity, price_each);
  }
  /*“buy”和“sell”:分别要求零件数量、数量、价格。*/
  else if (sscanf(request, "%10s %lu,%hu,%lf %1s", request_type,
    &part_number, &quantity, &price_each, left_over) == 4 &&
    (strcmp(request_type, "buy") == 0
      || strcmp(request_type, "sell") == 0)) {
    buy_sell(request_type[0], part_number, quantity, price_each);
  }
  /*“delete”和“print”:需要零件号*/
  else if (sscanf(request, "%10s %lu %1s", request_type, &part_number,
    left_over) == 2 &&
    (strcmp(request_type, "delete") == 0
      || strcmp(request_type, "print") == 0)) {
    if (request_type[0] == 'd')
      delete(part_number);
    else
      print(part_number);
  }
  /*"print all":不带参数。*/
  else if (sscanf(request, "print %10s %1s", request_type, left_over) == 1
    && strcmp(request_type, "all") == 0) {
    print_all();
  }
  /*如果没有其他工作，它一定是一个错误。如果输入行不是空的，打印一条错误消息。*/
  else {
    if (sscanf(request, "%10s", request_type) == 1)
      fprintf(stderr, "Invalid request: %s\n", request_type);
  }
  /*返回TRUE，以便主事务循环继续进行*/
  return TRUE;
}
