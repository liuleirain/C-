/*
** 把一个关键词转换成打乱的字母。用于加密。和解密。
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "9-13.c"
#include "9-14.c"

#define TRUE 1
#define FALSE 0

int prepare_key(char* key);

int main()
{
  char key[50] = "TRAILBLAZERS";
  char data[50] = "Attact at dawn";
  if (prepare_key(key))
  {
    encrypt(data, key);
    printf("Encrypt:%s\n", data);
    decrypt(data, key);
    printf("Decrypt:%s\n", data);
  }
  else
    printf("密钥必须是字符组成！");
  return 0;
}

int prepare_key(char* key)
{
  register char* keyp;
  register char* dup;
  register int character;

  /*
  ** 确保密钥不是空的
  */
  if (*key == '\0') return FALSE;

  /*
  ** 首先，将单词转换为大写(小写也一样好，只要我们保持一致)。
  */
  for (keyp = key; (character = *keyp) != '\0'; keyp++)
  {
    if (!isupper(character))
    {
      if (!islower(character)) return FALSE;
      *keyp = toupper(character);
    }
  }


  /*
  ** 现在从一个单词中删除所有的重复字符
  */
  for (keyp = key; (character = *keyp) != '\0'; dup = ++keyp)
  {
    while ((dup = strchr(dup + 1, character)) != NULL)
    {
      strcpy(dup, dup + 1);
    }
  }

  /*
  ** 现在把剩下的字母加到键上。这利用了上面的循环让keyp指向结束的NULL字节这一事实。
  */
  for (character = 'A'; character <= 'Z'; character += 1)
  {
    if (strchr(key, character) == NULL)
    {
      *keyp++ = character;
      *keyp = '\0';
    }
  }
  return TRUE;
}