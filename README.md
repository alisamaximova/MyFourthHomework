# The Fourth homework on the subject "Functional Logic and Theory of Algorithms"
## *Task condition (variant № 15):*
> Delete vertices adjacent to a given edge and 
> sort the remaining vertices in descending order of degree (sort by inserts)

### Project assembly:
The program is written in the Windows operating system, in the Dev-C++ application in the C programming language.


### Explanation of the algorithm of the code:

The user enters the number of vertices of the graph. 
Next, the program asks him for the edges between the vertices. 
If there is an edge between the vertices, then the user must enter "1", otherwise - "0".

```c
	printf("Enter the num verticles: ");
	scanf("%i", &size); 
	c = getchar();
	for (i; i < size; i++){ 
      		for (j; j < size; j++){ 
       			if ((i == j) && (size == 1)){ 
          			printf("Connect between  %i and %i: ", i + 97, j + 97); 
          			while ((c = getchar()) != '\n'){ 
               				mass[i][j] = c - '0'; 
               				mass[j][i] = c - '0'; 
          			}
        		}
        		else{ // иначе
           			printf("Connect between  %c and %c: ", i + 97, j + 97); 
            			while ((c = getchar()) != '\n'){ 
            				mass[i][j] = c - '0'; 
                			mass[j][i] = c - '0';
            			}
        		}
      		}
	u++; 
      	j = u; 
	}  
```

Next , a format file is created .dot for its further use in the graphical display of the graph we have introduced. 
After automatic generation, in the folder where our main.c is located, we will be able to see a graph in .png format.

![Screenshot](graph.png)
