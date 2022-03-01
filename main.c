#include <stdio.h>
#include <unistd.h>

int main(){
	fclose(stdout);
	fprintf(stderr, "%d\n", printf("32"));
}