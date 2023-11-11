/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                       https://github.com/nach131                       ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <unistd.h>
#include <stdio.h>

int main(int n, char **file)
{
	if (access(file[1], F_OK) != -1)
		printf("El archivo existe.\n");
	else
		printf("El archivo no existe.\n");
}
