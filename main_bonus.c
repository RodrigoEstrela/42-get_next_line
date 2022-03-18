#include "get_next_line_bonus.h"
int main()
{
	int fd = open(/*"put file 1 here"*/, O_RDWR);
	int a = fd;
	
	printf("%s", get_next_line(fd));
	
	fd = open(/*"put file 2 here"*/, O_RDWR);
	
	printf("%s", get_next_line(fd));
	
	printf("%s", get_next_line(a));
}
