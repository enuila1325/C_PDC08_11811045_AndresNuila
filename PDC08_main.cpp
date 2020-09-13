#include <curses.h>

int main()
{
    bool fin = true;
    int _switch = 1;
    int MaxX, MaxY;
    initscr();
    getmaxyx(stdscr, MaxY, MaxX);
    if (!has_colors())
    {
        endwin();
        return 1;
    }
    WINDOW *ventana = newwin(MaxY, MaxX, 0, 0);
    WINDOW *_subventana1 = subwin(ventana, MaxY - 2, (MaxX / 4) - 2, 1, 1);
    WINDOW *_subventana2 = subwin(ventana, MaxY - 2, (MaxX / 4) - 2, 1, (MaxX / 4) + 1);
    WINDOW *_subventana3 = subwin(ventana, MaxY - 2, (MaxX / 4) - 2, 1, (2 * (MaxX / 4) + 1));
    WINDOW *_subventana4 = subwin(ventana, MaxY - 2, (MaxX / 4) - 2, 1, (3 * (MaxX / 4) + 1));
    refresh();
    cbreak();
    noecho();
    nonl();
    intrflush(ventana, FALSE);
    keypad(ventana, TRUE);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_WHITE);
    wbkgd(ventana, COLOR_PAIR(1));
    wbkgd(_subventana1, COLOR_PAIR(1));
    wbkgd(_subventana2, COLOR_PAIR(1));
    wbkgd(_subventana3, COLOR_PAIR(1));
    wbkgd(_subventana4, COLOR_PAIR(1));
    touchwin(ventana);
    wrefresh(ventana);
    while (fin)
    {
        if (getch() == 27)
        {
            fin = false;
        }
        else
        {
            switch (_switch)
            {
            case 1:
            {
                wclear(_subventana4);
                box(_subventana1, ACS_VLINE, ACS_HLINE);
                touchwin(_subventana1);
                wrefresh(_subventana1);
                touchwin(_subventana4);
                wrefresh(_subventana4);
                _switch++;
            }
            break;
            case 2:
            {
                wclear(_subventana1);
                box(_subventana2, ACS_VLINE, ACS_HLINE);
                touchwin(_subventana1);
                wrefresh(_subventana1);
                touchwin(_subventana2);
                wrefresh(_subventana2);
                _switch++;
            }
            break;
            case 3:
            {
                wclear(_subventana2);
                box(_subventana3, ACS_VLINE, ACS_HLINE);
                touchwin(_subventana2);
                wrefresh(_subventana2);
                touchwin(_subventana3);
                wrefresh(_subventana3);
                _switch++;
            }
            break;
            case 4:
            {
                wclear(_subventana3);
                box(_subventana4, ACS_VLINE, ACS_HLINE);
                touchwin(_subventana3);
                wrefresh(_subventana3);
                touchwin(_subventana4);
                wrefresh(_subventana4);
                _switch = 1;
            }
            break;
            default:
                break;
            }
        }
    }
    endwin();
    return 0;
}