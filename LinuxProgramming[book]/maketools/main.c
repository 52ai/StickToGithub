#include <stdlib.h>
#include "a.h"
extern void function_two();
extern void function_three();

int main(int argc, char const *argv[])
{
	function_two();
	function_three();
	return 0;
}