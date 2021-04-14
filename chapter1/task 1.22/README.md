## Задача(Task) 1.22 ##

- **(RU)** Напишите программу, печатающую символы входного потока так, чтобы строки текста не выходили правее n-й
  позиции. Это значит, что каждая строка, длина которой превышает n, должна печататься с переносом на следующие строки.
  Место переноса следует " искать" после последнего символа, отличного от символа-разделителя, расположенного левее n-й
  позиции. Позаботьтесь о том, чтобы ваша программа вела себя разумно в случае очень длинных строк, а также когда до n-й
  позиции не встречается ни одного символа пробела или табуляции.

- **(EN)** Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character
  that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines,
  and if there are no blanks or tabs before the specified column.

Example:
```
input stream:

12345 1234 1234567890 back in USSR write in C!

result:

12345 1234 
1234567890 
back in 
USSR write 
in C!
```