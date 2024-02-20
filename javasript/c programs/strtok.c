#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "This is a separated word by spaces";
	char delim[] = " ";
	char *trunk;

	trunk = strtok(str, delim);
	printf("%s\n", trunk);

	trunk = strtok(NULL, delim);
	printf("%s\n",trunk);

	 trunk = strtok(NULL, delim);
	 printf("%s\n",trunk);

	 if (trunk == NULL)
		 printf("\n last part is null");
	 else
		 printf("\n it is not null");

	return (0);
}
