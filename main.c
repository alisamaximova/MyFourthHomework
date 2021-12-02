#define D_CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>
#include <stdbool.h>
#define MAX 20

// #pragma warning (push)
// #pragma warning (disable:6540)

int inarr[MAX] = { 0 };
int i, e;
void InsertionSort(int mass[], int );
void printArray(int arr[], int );

void InsertionSort(int mass[], int n) // Сортировка вставками
{
  int Element, location;
  for ( i = 1; i < n; i++) // Для i от 1 до n, i++
  {
        Element = mass[i]; // Element принимает значение i-ого элемента массива
        location = i - 1; // location  принимает значение i - 1
        while (location >= 0 && mass[location] > Element) // Пока location больше или равен 0 и элемент mass больше ELement
        {
            mass[location + 1] = mass[location]; // Следующий элемент массива mass принимает значение текущего
            inarr[location + 1] = inarr[location]; // Следующий элемент массива inarr принимает значение текущего
            location = location - 1; // location принимает значение location - 1
        }
        mass[location + 1] = Element; // Следующий элемент массива mass принимает значение переменной Element 
        inarr[location + 1] = inarr[i]; // Следующий элемент массива inarr принимает значение текущего элемента массива
  }
}

void printArray(int arr[], int n) // Вывод отсортированного массива вершин 
{
  for ( i = n - 1; i > 1; i--) // Для i, равного n - 1 и i больше нуля, i-- 
    printf("| %d |", arr[i]); // Выводим значения
    printf("\n"); // Переход на новую строчку
}

int main(void) {
	char c;
    int mass[MAX][MAX];
    int size = 0, i = 0, j = 0, u = 0;
    printf("Enter the num verticles: "); // Введите количество вершин 
    scanf("%i", &size); // Сканируем количество 
    c = getchar();
    for (i; i < size; i++) // Цикл для i, i меньше количества вершин, i++
    {
      for (j; j < size; j++) // Цикл аналогичный для j
      {
        if ((i == j) && (size == 1)) // Если i равно j и вершина всего одна, то тогда
        {
          printf("Connect between  %i and %i: ", i + 97, j + 97); // "Ребро между вершиной i и i:"
          while ((c = getchar()) != '\n') // Пока с не равно концу строки 
          {
               mass[i][j] = c - '0'; // элемент массива [i][j] равен разности с и '0' в кодировке ASCII
               mass[j][i] = c - '0'; // элемент массива [j][i] равен разности с и '0' в кодировке ASCII
          }
        }
        else // иначе
        {
           printf("Connect between  %c and %c: ", i + 97, j + 97); // "Ребро между вершиной c и c:" в кодировке ASCII
            while ((c = getchar()) != '\n') // Пока с не равно концу строки
            {
            	mass[i][j] = c - '0'; // элемент массива [i][j] равен разности с и '0' в кодировке ASCII
                mass[j][i] = c - '0'; // элемент массива [j][i] равен разности с и '0' в кодировке ASCII
            }
        }
      }
      u++; // Увеличение значения переменной u
      j = u; // Присваиваем значение u переменной j
    }  
    FILE* file; // Работа с файлом формата .dot
    file = fopen("graph.dot", "w"); // Открываем файл формата .dot
    fprintf(file, "graph HomeWork4 {\n"); // В файле формата .dot записываем начало файла для построения графа 
    
    for (e = 97; e < (97 + size); e++) // Для е, начиная с 97, и е меньше 97 + количество вершин графа, e++
    {
    	fprintf(file, "%c;\n", e); // Выводим все вершины графа
	}	
    u = 0; // переменные принимают значение 0 
    j = 0;
    i = 0;   
    for (i; i < size; i++) // Для i от 0 до количества вершин графа, i++
    {
        for (j; j < size; j++) // Для i от 0 до количества вершин графа, i++
        {
            if (mass[i][j] == 1) // Если элемент массива равен 1
            {
            	fprintf(file, "%c -- %c;\n", (i + 97), (j + 97)); // Записываем в файл формата .dot связь между двумя смежными вершинами
            }
        }
      u++; // Увеличиваем значение переменной u
      j = u; // Присваиваем значение u переменной j
    }
	int y = 0; 
    fprintf(file, "}"); // Записываем конец кода в файле формата .dot
    fclose(file); // Закрываем файл
    system("dot -Tpng graph.dot -o graph.png"); // Создаем файлы. Один из них - графическое отображение графа, другой - код для GV
	system("graph.dot");
    system("graph.png");  
    printf("\nEnter deleted edge like:a-b\n"); // "Запишите ребро, которое хотите удалить в виде смежных вершин"    
	char x; 
    c = getchar();
    getchar();
    x = getchar();
    getchar();
    printf("Delete %c and %c\n",c, x); // Удалить вершины  
    char ar[1000];
    char buf[MAX];
    if ((c > 96) && (c - 97 < size) && (x > 96) && (x - 97 < size)) // Если с больше 96, и с - 97 меньше количества вершин графа,
    {                                                               // и х больше 96, и х - 97 меньше количества вершин графа 
        FILE* file; 
        file = fopen("graph.dot", "r"); // Открываем файл формата .dot для редактирования
        char w;
        int r = 0;
        for (r; r < 11; r++) // Для r от 0 до 11, r++ (все это в кодировке ASCII)
        {
            w = getc(file); // w принимает следующее значение строки
            ar[r] = w; //
        }
        int q = 0;
        bool check = false; // Значение булевой переменной принимает значение "ложь"
        for (y = 0; !feof(file); y++) // Для y = 0, пока не конец файла, y++
        {
            if ((w != '\n') && (check == false)) // Если w не равно концу строчки и значение check принимает значение "ложь"
            {
                buf[q] = w; // Элемент массива принимает значение w
                q++; // Увеличиваем значение переменной q

                if ((w == c) || (w == x)) // Если w равно с или w равно х
                    check = true; // Булева переменная check принимает значение "правда"
                    w = getc(file); // w принимает следующее значение строки
            }
            if ((w == '\n') && (check == false)) // Если w равно концу строки и check принимает значение "ложь"
            {
                buf[q] = w; // Элемент массива принимает значение w
                q++; // Увеличиваем значение переменной q
                int t = q; // Присваиваем переменной t значение q
                q = 0; // q принимает значение, равное 0
                int l = 0; // l принимает значение, равное 0   
                for (r; l < t; r++, q++, l++) // Для r, l меньше t, r++, q++, l++
                    ar[r] = buf[q]; // Элемент массива ar принимает значение элемента массива q 
                    q = 0; // q принимает значение 0 
                    w = getc(file); // w принимает следующее значение строки
            }
            if (check == true) // Если значение check - "правда"
            {
                q = 0; // q принимает значение 0
                while (w != '\n') // Пока w не конец строки
                    w = getc(file); // w принимает следующее значение строки
                    check = false; // Булева переменная check принимает значение "ложь"
            }
        }
      ar[r] = '\0';
      
      FILE* refile; // Изменение файла .dot
      refile = fopen("graph1.dot", "w"); // Открываем файл формата .dot
      for (y = 0; ar[y] != '\0'; y++) // Для y = 0, y-ый элемент массива ar не равен NULL, y++
      {
        if ((ar[y - 1] == '\n') && (ar[y] == '\n')) // Если значение предыдущего элемента массива не равен новой строке
													// и y-ый элемент не равен новой строке
          ;
        else
          fprintf(refile, "%c", ar[y]);
      }
      fprintf(refile, "}"); // Печатаем последний элемент кода в файле формата .dot
      fclose(file); // Закрываем файл
      fclose(refile); // Закрываем редактированный файл 
    }
    int* arrsort; // Сортировка вставками
    arrsort = (int*)malloc((size + 1) * sizeof(int)); // Выделяем динамическу память 
    for (y = 0; y < size; y++) // Для y от 0 до количества вершин, y++
    {
        arrsort[y] = 0; // Значение элемента массива - 0 
    }
    FILE* refile;
    refile = fopen("graph1.dot", "r"); // Редактирование и открытие файла формата .dot
    char w = getc(file); // Переменная w принимает следующее значение строки
    for (y = 0; y < size - 2; y++) // Для y от 0 до количество вершин - 2, y++
    {
        while (w != '\n') // Пока w не равно переходу на новую строку
            w = getc(file); // w принимает значение следующего элемента строки
            w = getc(file); // w принимает значение следующего элемента строки
    }
    for (y = 0; !feof(file); y++) // для y = 0, пока не конец файла, y++
    {
        w = getc(file); // w принимает следующее значение строки
        arrsort[w - 97]++; // Увеличиваем значение элемента массива 
    }
    arrsort[size] = '\0'; // Элемент массива arrsort принимает значение NULL
    fclose(refile); // Закрываем файл
    for (i = 0; i < size; i++) // Для i от 0 до количества вершин, i++
    {
        inarr[i] = i + 1; // Элемент массива принимает значение i + 1
    }
    InsertionSort(arrsort, size); // Сортировка вставками
    printf("\nSorted mass \n"); // Печатаем "Отсортированный массив:"
    for (i = size - 2; i > 0; i--) // Для i равного количетсво вершин графа - 2 и i больше 0, i--
    {
        c = inarr[i] + 97; // Переменная с принимает значение элемента массива inarr + 96
        printf("| %c |", c); // Выводим значение
    }
    printf("\n");
    printArray(arrsort, size); // Выводим массив
    system("dot -Tpng graph1.dot -o graph1.png"); // Создаем файл формата .dot для GV и графическое отображение графа 
    system("graph1.dot");
    system("graph1.png"); 
    return 0;
}

