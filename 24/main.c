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

    printf("Enter the number of objects: ");
    refresh();
    scanf("%zu", &num);

    objects = (Object*)malloc(num * sizeof(Object));
    char filename = "data.txt";

    for (size_t i = 0; i < num; i++)
    {
        AddElem(objects, &size);
    }

    Table(objects, size);

    Sort(objects, size, 1, SortFloat);

    Table(objects, size);


    printf("enter an index:\n");
    size_t index;
    scanf("%zu", &index);

    RemoveElem(objects, &size, index);
    Table(objects, size);

    int choose_d;
    int choose_f;
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


    // ∆дем нажати€ клавиши перед закрытием
    getch();
    endwin();
    return 0;
}
