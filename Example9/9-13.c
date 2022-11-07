
void encrypt(char* data, char const* key)
{
  register int character;

  /*
  ** 每次处理一个字符。这取决于键都是大写的
  */
  for (;(character = *data) != '\0'; data++)
  {
    if (islower(character))
      *data = tolower(key[character - 'a']);
    else if (isupper(character))
      *data = key[character - 'A'];
  }

}

