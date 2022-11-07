static char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

void decrypt(char* data, char const* key)
{
  register int character;
  register char* dup;

  /*
  ** 每次处理一个字符。这取决于键都是小写的。
  */
  for (; (character = *data) != '\0'; data++)
  {
    if (islower(character))
      *data = alphabet[(dup = strchr(key, toupper(character))) - key];
    else if (isupper(character))
    {
      *data = toupper(alphabet[strchr(key, character) - key]);
    }
  }
}