#ifndef _G_STACK_H
#define _G_STACK_H
#include <assert.h>
#endif
#define GENERIC_STACK_DATA(STACK_TYPE, SUFFIX,STACK_SIZE) \
  static STACK_TYPE stack##SUFFIX[STACK_SIZE]; \
  static int top_element##SUFFIX = -1;
/*声明堆栈接口*/
#define GENERIC_STACK_INTERFACE(STACK_TYPE, SUFFIX) \
  int is_empty##SUFFIX(void); \
  int is_full##SUFFIX(void); \
  void push##SUFFIX(STACK_TYPE value); \
  void pop##SUFFIX(void); \
  STACK_TYPE top##SUFFIX(void);
/*创建堆栈函数的实现*/
#define GENERIC_STACK_ACHIEVEMENT(STACK_TYPE, SUFFIX, STACK_SIZE) \
  \
  int \
  is_empty##SUFFIX(void) \
  { \
    return top_element##SUFFIX == -1;\
  } \
  \
    int \
    is_full##SUFFIX(void) \
  { \
    return top_element##SUFFIX == STACK_SIZE - 1; \
  } \
    \
    void \
    push##SUFFIX(STACK_TYPE value) \
  { \
    assert(!is_full##SUFFIX()); \
    top_element##SUFFIX += 1; \
    stack##SUFFIX[top_element##SUFFIX] = value; \
  } \
    \
    void \
    pop##SUFFIX(void) \
  { \
    assert(!is_empty##SUFFIX()); \
    top_element##SUFFIX -= 1; \
  } \
    \
    STACK_TYPE top##SUFFIX(void) \
  { \
    assert(!is_empty##SUFFIX()); \
    return stack##SUFFIX[top_element##SUFFIX]; \
  }
