# Задача(Task) 1.20 #

- **(RU)** Напишите программу detab, заменяющую символы табуляции во вводимом тексте нужным числом пробелов (до
  следующего "стопа" табуляции). Предполагается, что "стопы" табуляции расставлены на фиксированном расстоянии друг от
  друга, скажем, через n позиций. Как лучше задавать n - в виде значения переменной или в виде именованной константы?


- **(EN)** Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next
  tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?

Example Run:

```
clang -o detab  solution.c 

./detab 68
```

**Answer to the question:**

- **(EN)**  Of course, "n" must be variable so that the value can be changed at runtime, for example using a command
  line argument, without requiring recompilation.


- **(RU)** Конечно, n должно быть переменным, чтобы значение можно было изменить во время выполнения, например, с
  помощью аргумента командной строки, не требуя перекомпиляции.