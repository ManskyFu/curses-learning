#include <stdio.h>
#include <curses.h>
#include <string.h>
#include <unistd.h>


int main(void) {
    char msg[]   = "Hello, World!";
    char blank[] = "             ";
    int   ldir   = +1,
          cdir   = +1;
    int   line   = 1,
          col    = 1;
    int   color  = 0;

    initscr();
    clear();
    while (1) {
        move(line, col);
        if (color)
            standout();
        addstr(msg);
        if (color)
            standend();
        refresh();
        sleep(1);
        move(line, col);
        addstr(blank);

        color = !color;   //chang color

        ldir  = (line == LINES - 1 || line == 0) ? (-ldir) : ldir;  //change line direction
        cdir  = (col + strlen(msg) == COLS - 1 || col == 0) ? (-cdir) : cdir;//change col direction

        line += ldir;    
        col  += cdir;   // elarge
    }
    endwin();

    return 0;
}
