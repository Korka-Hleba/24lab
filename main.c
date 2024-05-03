#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "base.h"
#include "Object.h"

int main()
{
    Object* objects = NULL;
    size_t size = 0;
    size_t num;
    char filename;

    objects = (Object*)malloc(num * sizeof(Object));


    Table(objects, size);
    int choose_d;
    int choose_f;


    for (int i = 0; i < size; i++) {
        printf("Object %d: text=%s, decimal=%.2f, integer=%d\n", i+1, objects[i].text, objects[i].floatNum, objects[i].intNum);
    }
    //menue
    while(1)
    {
        int choice;
        int sorting;
        int order;
        printf("Choose an action: \n1.Add Element\n2.Save to file\n3.Read from file\n4.Sorting\n5.Printing Diagram\n6.Remove Element\n7.Print the table\n8.Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the number of objects: ");
                refresh();
                scanf("%zu", &num);
                for (size_t i = 0; i < num; i++)
                {
                    AddElem(&objects, &size);
                }
                break;

            case 2:
                Save(objects, size);
                break;
            case 3:
                Read(objects, size, filename);
                break;

            case 4:
                printf("Choose the field for sorting:\n1.text\n2.float\n3.integer\n");
                scanf("%d", &sorting);
                printf("Choose an order for sorting:\n1.increasing\n2.decreasing\n");
                scanf("%d", &order);
                switch(sorting)
                {
                    case 1:
                        if  (order == 1)
                        {
                            Sort(objects, size, 1, SortText);
                            Table(objects, size);
                        }
                        if (order == 2)
                        {
                            Sort(objects, size, 2, SortText);
                            Table(objects, size);

                        }
                        break;

                    case 2:
                        if  (order == 1)
                        {
                            Sort(objects, size, 1, SortFloat);
                            Table(objects, size);
                        }
                        if (order == 2)
                        {
                            Sort(objects, size, 2, SortFloat);
                            Table(objects, size);
                        }
                        break;
                    case 3:
                        if  (order == 1)
                        {
                            Sort(objects, size, 1, SortInt);
                            Table(objects, size);
                        }
                        if (order == 2)
                        {
                            Sort(objects, size, 2, SortInt);
                            Table(objects, size);
                        }
                        break;

                }
                break;

            case 5:
                printf("Choose the diagram:\n1. Bar Chart \n2. Pie Chart\n");
                scanf("%d", &choose_d);
                printf("Choose the field:\n1. float \n2. integer\n");
                scanf("%d", &choose_f);
                initscr();
                start_color();
                init_pair(1, COLOR_RED, COLOR_BLACK);
                init_pair(2, COLOR_GREEN, COLOR_BLACK);
                init_pair(3, COLOR_BLUE, COLOR_BLACK);
                init_pair(4, COLOR_YELLOW, COLOR_BLACK);
                init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
                init_pair(6, COLOR_CYAN, COLOR_BLACK);
                init_pair(7, COLOR_WHITE, COLOR_BLACK);


                switch(choose_d)
                {
                    case 1:
                        if (choose_f == 1)
                        {
                            BarChart(objects, size, 1);
                        }
                        if (choose_f == 2)
                        {
                            BarChart(objects, size, 2);
                        }

                        break;
                    case 2:
                        if (choose_f == 1)
                        {
                            PieChart(objects, size, 1);
                        }
                        if (choose_f == 2)
                        {
                            PieChart(objects, size, 2);
                        }

                        break;

                }

            break;

            case 6:
                printf("enter an index:\n");
                size_t index;
                scanf("%zu", &index);
                RemoveElem(objects, &size, index);
                Table(objects, size);
                break;

            case 7:
                Table(objects, size);
                break;

            case 8:
                return 0;
                break;

        }

    }

    getch();
    endwin();
    return 0;
}
