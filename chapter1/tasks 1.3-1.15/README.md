# Глава № 1 #
Решение задач из первой главы

Первую задачу "Hello world", опустил

Решение второй задачи:
```с
#include <stdio.h>
int main(void)
{
  printf("alert (0x07) - added in C89: '\a'\n");
  printf("backspace (0x08): ' \b'\n");
  printf("horizontal tab (0x09): '\t'\n");
  printf("newline (0x0A): '\n'\n");
  printf("vertical tab (0x0B):'\v'\n");
  printf("formfeed (0x0C): '\f'\n");
  printf("carriage return (0x0D): '\r'\n");
  printf("double quote: (0x22)'\"'\n");
  printf("single quote (0x27): '\''\n");
  printf("question mark (0x3F): '\?'\n");
  printf("backslash (0x5C): '\\'\n");
  printf("octal number (nnn): '\101'\n");

  /* *
   * ASCII  Hexadecimal
   *   A        41
   * */
  printf("hexdecimal number (xhh): '\x41'\n");
  printf("escape character (0x1B): '\e'\n");

  /* *
   * ASCII  Decimal Octal
   *   A       65    101
   * */
  printf("using format string as escape sequence: %d\n", ('\101'));

  /* *
   * warning: universal character names are only valid in C++ and C99
   * printf("unicode character (UTF-32[hex]: Uhhhhhhhh): '\U00000023'\n");
   * printf("unicode character (UTF-16[hex]: Uhhhh): '\u0023'\n");
   * */

  return 0;

}
``` 
