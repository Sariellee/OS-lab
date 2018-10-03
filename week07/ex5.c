#include <stdio.h>

int main() {
	char *s; // no need for second-order pointer
	char foo[] = "Hello World";
	s = foo; // not *s = foo
	printf("s is %s\n",s);
	s[0] = *foo;
	printf("s[0] is %c\n",s[0]); // outputting a char, so %c
	return(0);
}