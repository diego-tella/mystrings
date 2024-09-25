#include <stdio.h>

#define FALSE 0
#define TRUE 1  

int test_empty(char *string[])
{
	if(string == '\0')
	{
		printf("[+] Pass one argument!");
		return 0;

	}
	else
	{
		return 1;
	}
}


int main (int argc, char *argv[])
{
	if(test_empty(argv[1]) == FALSE)
	{
		return 0;
	}

	FILE *file;
    unsigned char byte;

    file = fopen(argv[1], "rb");

    while (fread(&byte, sizeof(byte), 1, file) == 1) {
        printf("%02X ", byte);
    }


	return 0;
}


