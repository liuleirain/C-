
/*I/O函数的声明和原型*/

/*打开库存文件。以文件名作为唯一的参数，并返回一个布尔值:如果成功则为TRUE，否则为FALSE*/
int open_file(char const* filename);

/*关闭库存文件。*/
void close_file(void);

/*返回文件中最后一个零件的编号。*/
Part_number last_part_number(void);

/*返回下一个可用的零件号*/
Part_number next_part_number(void);

/*读取库存记录。将零件编号和指向零件结构的指针作为参数。如果零件存在则返回TRUE，否则返回FALSE*/
int read_part(Part_number part_number, Part* part);

/*写库存记录。以零件号和指向零件结构的指针作为参数*/
void write_part(Part_number part_number, Part const* part);