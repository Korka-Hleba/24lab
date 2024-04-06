#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <math.h>
#include "Object.h"

void PieChart(Object* objects, size_t length, int fieldIndex)
{
    float total = 0;
    int screen_size_x, screen_size_y;
    getmaxyx(stdscr, screen_size_y, screen_size_x);
    int colors[] = {COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_YELLOW, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE};
    int color_index = 0;

    if (fieldIndex == 2)
    {
      for (size_t i = 0; i < length; i++)
      {
        total += (float)objects[i].intNum;
      }

    float start_angle = 0.0;
    for (size_t i = 0; i < length; i++)
    {
        float slice_angle = (360.0 * ((float)objects[i].intNum / total));
        float end_angle = start_angle + slice_angle;

        attron(COLOR_PAIR(colors[color_index % 7]));
        for (int angle = (int)start_angle; angle < (int)end_angle; angle++)
        {
            int x = screen_size_x / 2 + cos(angle * M_PI / 180) * (screen_size_x / 4);
            int y = screen_size_y / 2 + sin(angle * M_PI / 180) * (screen_size_y / 4);
            mvaddch(y, x, 'o');
        }

        color_index++;
        start_angle = end_angle;
    }
    int legend_y = screen_size_y / 2 + screen_size_y / 4 + 1;
    for (size_t i = 0; i < length; i++)
    {
        attron(COLOR_PAIR(colors[i % 7]));
        mvprintw(legend_y + i, 1, "%s", objects[i].text);
    }

    }
      if (fieldIndex == 1){
      for (size_t i = 0; i < length; i++) {
        total += (float)objects[i].floatNum;
    }

    float start_angle = 0.0;
    for (size_t i = 0; i < length; i++)
    {
        float slice_angle = (360.0 * ((float)objects[i].floatNum / total));
        float end_angle = start_angle + slice_angle;

        attron(COLOR_PAIR(colors[color_index % 7]));
        for (int angle = (int)start_angle; angle < (int)end_angle; angle++)
        {
            int x = screen_size_x / 2 + cos(angle * M_PI / 180) * (screen_size_x / 4);
            int y = screen_size_y / 2 + sin(angle * M_PI / 180) * (screen_size_y / 4);
            mvaddch(y, x, 'o');
        }

        color_index++;
        start_angle = end_angle;
    }
    int legend_y = screen_size_y / 2 + screen_size_y / 4 + 1;
    for (size_t i = 0; i < length; i++)
    {
        attron(COLOR_PAIR(colors[i % 7]));
        mvprintw(legend_y + i, 1, "%s", objects[i].text);
    }

    }


    refresh();
    getch();
}
