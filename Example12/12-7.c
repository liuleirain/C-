/*
** 在索引表中插入一个词。参数是一个指向列表中第一个节点的位置的指针，以及一个包含要插入的单词的字符串。如果字符串以字母开头并且已插入列表，则函数返回TRUE，否则返回FALSE
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0

/*
**保存单个单词的辅助节点的声明
*/
typedef struct WORD {
  char* word;
  struct WORD* next;
}Word;

/*
**位于单词列表上方的主节点的声明
*/
typedef struct LIST {
  char letter;
  struct LIST* next;
  Word* word_list;
}List;

int concordance_insert(List** listp, char* the_word) {
  int first_char;
  List* current_list;
  Word* current_word;
  Word** wordp;
  int comparison;
  Word* new_word;
  /*
  **获取单词的第一个字符并确保它是有效的
  */
  first_char = *the_word;
  if (!islower(first_char))
    return FALSE;

  /*
  **首先，找到以正确字母开头的单词表。如果它不存在，创建一个新的并添加它
  */
  while ((current_list = *listp) != NULL && current_list->letter < first_char)
    listp = &current_list->next;

  /*
  **如果当前列表为NULL或指向一个比我们想要的字母大的节点，我们必须创建一个新的单词列表并将其插入到主列表中。
  */
  if (current_list == NULL || current_list->letter > first_char) {
    List* new_list;
    new_list = (List*)malloc(sizeof(List));
    if (new_list == NULL)
      return FALSE;

    new_list->letter = first_char;
    new_list->word_list = NULL;
    new_list->next = current_list;
    *listp = new_list;
    current_list = new_list;
  }

  /*
  **当前列表现在指向指向正确单词列表的节点。在里面搜索我们的词
  */
  wordp = &current_list->word_list;
  while ((current_word = *wordp) != NULL) {
    comparison = strcmp(current_word->word, the_word);
    if (comparison >= 0)
      break;
    wordp = &current_word->next;
  }

  /*
  **如果当前单词不为NULL且比较为0，则该单词已经在列表中
  */
  if (current_word != NULL && comparison == 0)
    return FALSE;

  /*
  **为单词创建一个新节点
  */
  new_word = (Word*)malloc(sizeof(Word));
  if (new_word == NULL)
    return FALSE;

  new_word->word = malloc(strlen(the_word) + 1);
  if (new_word->word == NULL)
    return FALSE;

  strcpy(new_word->word, the_word);

  /*
  **将新节点链接到列表中
  */
  new_word->next = current_word;
  *wordp = new_word;

  return TRUE;
}

int main() {
  List* header = malloc(sizeof(List));
  header->letter = 'a';
  header->next = NULL;
  Word* word_header = malloc(sizeof(Word));
  word_header->next = NULL;
  word_header->word = "apple";
  header->word_list = word_header;

  concordance_insert(&header, "banana");
  concordance_insert(&header, "bear");
  concordance_insert(&header, "grapes");
  concordance_insert(&header, "hami_melon");
  concordance_insert(&header, "orange");

  List* current_list = header;
  while (current_list != NULL) {
    printf("%c:\n", current_list->letter);
    Word* current_word = current_list->word_list;
    while (current_word != NULL) {
      printf("%s\n", current_word->word);
      current_word = current_word->next;
    }

    printf("===================\n");
    current_list = current_list->next;
  }

  return 0;
}