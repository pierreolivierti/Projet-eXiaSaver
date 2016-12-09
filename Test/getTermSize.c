#include <sys/ioctl.h>
#include <stdio.h>

int main()
{
	while(42) {
    	struct winsize w;
    	ioctl(0, TIOCGWINSZ, &w);
    	printf("lines %d\n", w.ws_row);
    	printf("columns %d\n", w.ws_col);
	}
	return 0;
}