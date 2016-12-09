#include <sys/ioctl.h>
#include <stdio.h>

typedef struct size size;
struct 		size
{
	int		row;
	int		col;
};

int 		main() {

	while(42) {
		struct 	size 	termsize;
    	struct winsize 	w;
    	ioctl(0, TIOCGWINSZ, &w);
    	termsize.row = w.ws_row;
    	termsize.col = w.ws_col;
    	printf("%d\n", termsize.row);
    	printf("%d\n", termsize.col);
    	//printf("lines %d\n", w.ws_row);
    	//printf("columns %d\n", w.ws_col);
	}
	return 0;
}