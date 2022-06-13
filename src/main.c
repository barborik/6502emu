#include "includes.h"

int main(int argc, char* argv[])
{
	flags();

	cpu_init();
	cpu_load();
	cpu_exec();
	return 0;
}
