#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "Object.h"

void BarChart(Object *objects, size_t length, int selectedField)
{
    const int maxHeight = 20;
    int maxValue = 0;

    for (size_t i = 0; i < length; i++)
    {
        switch(selectedField)
        {
            case 1:
                if (objects[i].floatNum > maxValue)
                {
                    maxValue = objects[i].floatNum;
                }
                 clear();
                for (size_t i = 0; i < length; i++)
                {
                    int barHeight = (int)((objects[i].floatNum / maxValue) * maxHeight);
                    attron(COLOR_PAIR(i + 1));
                    for (size_t j = 0; j < barHeight; j++)
                    {
                        mvaddch(maxHeight - j, i*10, '|  ');
                    }
                    mvprintw(maxHeight + 1, i*10, "%s", objects[i].text);
                    attroff(COLOR_PAIR(i + 1));
                }

                break;
            case 2:
                if (objects[i].intNum > maxValue)
                {
                    maxValue = objects[i].intNum;
                }
                 clear();
                for (size_t i = 0; i < length; i++)
                {
                    int barHeight = (int)(((float)objects[i].intNum / maxValue) * maxHeight);
                    attron(COLOR_PAIR(i + 1));
                    for (size_t j = 0; j < barHeight; j++)
                    {
                        mvaddch(maxHeight - j, i*10, '|  ');
                    }
                    mvprintw(maxHeight + 1, i*10, "%s", objects[i].text);
                    attroff(COLOR_PAIR(i + 1));
                }

                break;
            default:
                printf("Invalid field selected.\n");
                return;
        }
    }


    refresh();
}
