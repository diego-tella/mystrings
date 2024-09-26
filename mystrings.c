#include <stdio.h>

#define FALSE 0
#define TRUE 1  

int test_empty(char *string[])
{
	if(string == '\0')
	{
		printf("[+] Pass one argument!\n");
		return 0;

	}
	else
	{
		return 1;
	}
}


int main (int argc, char *argv[])
{

	unsigned char ascii_visible[] = {
        0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 
        0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 
        0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 
        0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
        0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 
        0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E         
    };
     int array_size = sizeof(ascii_visible) / sizeof(ascii_visible[0]);

	if(test_empty(argv[1]) == FALSE)
	{
		return 0;
	}

	FILE *file;
    unsigned char byte, next_byte;

    file = fopen(argv[1], "rb");
    if(file == NULL){
    	printf("No valid file\n ");
    	return 0;
    }
    int cont = 0;
    while (fread(&byte, sizeof(byte), 1, file) == 1) {
        for (int i = 0; i < array_size ; i++)
        {
        	if(ascii_visible[i] == byte){
        		printf("%c", byte);
        		if (fread(&next_byte, sizeof(next_byte), 1, file) == 1) {
	        		if (next_byte == 0x00) {
	            		printf("\n");
	        		} else {
	            		fseek(file, -1, SEEK_CUR);
	        		}
    			}
        	}
        }
    }


	return 0;
}
