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

void InsertionSort(int mass[], int n) // ���������� ���������
{
  int Element, location;
  for ( i = 1; i < n; i++) // ��� i �� 1 �� n, i++
  {
        Element = mass[i]; // Element ��������� �������� i-��� �������� �������
        location = i - 1; // location  ��������� �������� i - 1
        while (location >= 0 && mass[location] > Element) // ���� location ������ ��� ����� 0 � ������� mass ������ ELement
        {
            mass[location + 1] = mass[location]; // ��������� ������� ������� mass ��������� �������� ��������
            inarr[location + 1] = inarr[location]; // ��������� ������� ������� inarr ��������� �������� ��������
            location = location - 1; // location ��������� �������� location - 1
        }
        mass[location + 1] = Element; // ��������� ������� ������� mass ��������� �������� ���������� Element 
        inarr[location + 1] = inarr[i]; // ��������� ������� ������� inarr ��������� �������� �������� �������� �������
  }
}

void printArray(int arr[], int n) // ����� ���������������� ������� ������ 
{
  for ( i = n - 1; i > 1; i--) // ��� i, ������� n - 1 � i ������ ����, i-- 
    printf("| %d |", arr[i]); // ������� ��������
    printf("\n"); // ������� �� ����� �������
}

int main(void) {
	char c;
    int mass[MAX][MAX];
    int size = 0, i = 0, j = 0, u = 0;
    printf("Enter the num verticles: "); // ������� ���������� ������ 
    scanf("%i", &size); // ��������� ���������� 
    c = getchar();
    for (i; i < size; i++) // ���� ��� i, i ������ ���������� ������, i++
    {
      for (j; j < size; j++) // ���� ����������� ��� j
      {
        if ((i == j) && (size == 1)) // ���� i ����� j � ������� ����� ����, �� �����
        {
          printf("Connect between  %i and %i: ", i + 97, j + 97); // "����� ����� �������� i � i:"
          while ((c = getchar()) != '\n') // ���� � �� ����� ����� ������ 
          {
               mass[i][j] = c - '0'; // ������� ������� [i][j] ����� �������� � � '0' � ��������� ASCII
               mass[j][i] = c - '0'; // ������� ������� [j][i] ����� �������� � � '0' � ��������� ASCII
          }
        }
        else // �����
        {
           printf("Connect between  %c and %c: ", i + 97, j + 97); // "����� ����� �������� c � c:" � ��������� ASCII
            while ((c = getchar()) != '\n') // ���� � �� ����� ����� ������
            {
            	mass[i][j] = c - '0'; // ������� ������� [i][j] ����� �������� � � '0' � ��������� ASCII
                mass[j][i] = c - '0'; // ������� ������� [j][i] ����� �������� � � '0' � ��������� ASCII
            }
        }
      }
      u++; // ���������� �������� ���������� u
      j = u; // ����������� �������� u ���������� j
    }  
    FILE* file; // ������ � ������ ������� .dot
    file = fopen("graph.dot", "w"); // ��������� ���� ������� .dot
    fprintf(file, "graph HomeWork4 {\n"); // � ����� ������� .dot ���������� ������ ����� ��� ���������� ����� 
    
    for (e = 97; e < (97 + size); e++) // ��� �, ������� � 97, � � ������ 97 + ���������� ������ �����, e++
    {
    	fprintf(file, "%c;\n", e); // ������� ��� ������� �����
	}	
    u = 0; // ���������� ��������� �������� 0 
    j = 0;
    i = 0;   
    for (i; i < size; i++) // ��� i �� 0 �� ���������� ������ �����, i++
    {
        for (j; j < size; j++) // ��� i �� 0 �� ���������� ������ �����, i++
        {
            if (mass[i][j] == 1) // ���� ������� ������� ����� 1
            {
            	fprintf(file, "%c -- %c;\n", (i + 97), (j + 97)); // ���������� � ���� ������� .dot ����� ����� ����� �������� ���������
            }
        }
      u++; // ����������� �������� ���������� u
      j = u; // ����������� �������� u ���������� j
    }
	int y = 0; 
    fprintf(file, "}"); // ���������� ����� ���� � ����� ������� .dot
    fclose(file); // ��������� ����
    system("dot -Tpng graph.dot -o graph.png"); // ������� �����. ���� �� ��� - ����������� ����������� �����, ������ - ��� ��� GV
	system("graph.dot");
    system("graph.png");  
    printf("\nEnter deleted edge like:a-b\n"); // "�������� �����, ������� ������ ������� � ���� ������� ������"    
	char x; 
    c = getchar();
    getchar();
    x = getchar();
    getchar();
    printf("Delete %c and %c\n",c, x); // ������� �������  
    char ar[1000];
    char buf[MAX];
    if ((c > 96) && (c - 97 < size) && (x > 96) && (x - 97 < size)) // ���� � ������ 96, � � - 97 ������ ���������� ������ �����,
    {                                                               // � � ������ 96, � � - 97 ������ ���������� ������ ����� 
        FILE* file; 
        file = fopen("graph.dot", "r"); // ��������� ���� ������� .dot ��� ��������������
        char w;
        int r = 0;
        for (r; r < 11; r++) // ��� r �� 0 �� 11, r++ (��� ��� � ��������� ASCII)
        {
            w = getc(file); // w ��������� ��������� �������� ������
            ar[r] = w; //
        }
        int q = 0;
        bool check = false; // �������� ������� ���������� ��������� �������� "����"
        for (y = 0; !feof(file); y++) // ��� y = 0, ���� �� ����� �����, y++
        {
            if ((w != '\n') && (check == false)) // ���� w �� ����� ����� ������� � �������� check ��������� �������� "����"
            {
                buf[q] = w; // ������� ������� ��������� �������� w
                q++; // ����������� �������� ���������� q

                if ((w == c) || (w == x)) // ���� w ����� � ��� w ����� �
                    check = true; // ������ ���������� check ��������� �������� "������"
                    w = getc(file); // w ��������� ��������� �������� ������
            }
            if ((w == '\n') && (check == false)) // ���� w ����� ����� ������ � check ��������� �������� "����"
            {
                buf[q] = w; // ������� ������� ��������� �������� w
                q++; // ����������� �������� ���������� q
                int t = q; // ����������� ���������� t �������� q
                q = 0; // q ��������� ��������, ������ 0
                int l = 0; // l ��������� ��������, ������ 0   
                for (r; l < t; r++, q++, l++) // ��� r, l ������ t, r++, q++, l++
                    ar[r] = buf[q]; // ������� ������� ar ��������� �������� �������� ������� q 
                    q = 0; // q ��������� �������� 0 
                    w = getc(file); // w ��������� ��������� �������� ������
            }
            if (check == true) // ���� �������� check - "������"
            {
                q = 0; // q ��������� �������� 0
                while (w != '\n') // ���� w �� ����� ������
                    w = getc(file); // w ��������� ��������� �������� ������
                    check = false; // ������ ���������� check ��������� �������� "����"
            }
        }
      ar[r] = '\0';
      
      FILE* refile; // ��������� ����� .dot
      refile = fopen("graph1.dot", "w"); // ��������� ���� ������� .dot
      for (y = 0; ar[y] != '\0'; y++) // ��� y = 0, y-�� ������� ������� ar �� ����� NULL, y++
      {
        if ((ar[y - 1] == '\n') && (ar[y] == '\n')) // ���� �������� ����������� �������� ������� �� ����� ����� ������
													// � y-�� ������� �� ����� ����� ������
          ;
        else
          fprintf(refile, "%c", ar[y]);
      }
      fprintf(refile, "}"); // �������� ��������� ������� ���� � ����� ������� .dot
      fclose(file); // ��������� ����
      fclose(refile); // ��������� ��������������� ���� 
    }
    int* arrsort; // ���������� ���������
    arrsort = (int*)malloc((size + 1) * sizeof(int)); // �������� ����������� ������ 
    for (y = 0; y < size; y++) // ��� y �� 0 �� ���������� ������, y++
    {
        arrsort[y] = 0; // �������� �������� ������� - 0 
    }
    FILE* refile;
    refile = fopen("graph1.dot", "r"); // �������������� � �������� ����� ������� .dot
    char w = getc(file); // ���������� w ��������� ��������� �������� ������
    for (y = 0; y < size - 2; y++) // ��� y �� 0 �� ���������� ������ - 2, y++
    {
        while (w != '\n') // ���� w �� ����� �������� �� ����� ������
            w = getc(file); // w ��������� �������� ���������� �������� ������
            w = getc(file); // w ��������� �������� ���������� �������� ������
    }
    for (y = 0; !feof(file); y++) // ��� y = 0, ���� �� ����� �����, y++
    {
        w = getc(file); // w ��������� ��������� �������� ������
        arrsort[w - 97]++; // ����������� �������� �������� ������� 
    }
    arrsort[size] = '\0'; // ������� ������� arrsort ��������� �������� NULL
    fclose(refile); // ��������� ����
    for (i = 0; i < size; i++) // ��� i �� 0 �� ���������� ������, i++
    {
        inarr[i] = i + 1; // ������� ������� ��������� �������� i + 1
    }
    InsertionSort(arrsort, size); // ���������� ���������
    printf("\nSorted mass \n"); // �������� "��������������� ������:"
    for (i = size - 2; i > 0; i--) // ��� i ������� ���������� ������ ����� - 2 � i ������ 0, i--
    {
        c = inarr[i] + 97; // ���������� � ��������� �������� �������� ������� inarr + 96
        printf("| %c |", c); // ������� ��������
    }
    printf("\n");
    printArray(arrsort, size); // ������� ������
    system("dot -Tpng graph1.dot -o graph1.png"); // ������� ���� ������� .dot ��� GV � ����������� ����������� ����� 
    system("graph1.dot");
    system("graph1.png"); 
    return 0;
}

