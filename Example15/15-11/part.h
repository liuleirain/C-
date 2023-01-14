/*
简单库存系统的声明
*/

/*
零件结构包含关于一个零件的所有信息，除了决定零件在文件中存储位置的零件号。部分描述最长不超过20个字符。
*/
#define MAX_DESCRIPTION 20
#define DESCRIPTION_FIELD_LEN (MAX_DESCRIPTION + 1) 

typedef unsigned long Part_number;
typedef unsigned short Quantity;
typedef double Value;

typedef struct {
  char description[DESCRIPTION_FIELD_LEN];
  Quantity quantity;
  Value total_value;
}Part;

/*
布尔常量
*/
#define TRUE 1
#define FALSE 0