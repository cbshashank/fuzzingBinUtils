#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

/*
 *   print out string with a '--ECHO: ' prefix
 */
void echo(char *s, unsigned int l)
{
		unsigned char len = (unsigned char) l;
		char buf[512] = "--ECHO: ";

		strcat(buf, s);

		if (len >= 128) {
				fprintf(stderr, "argument too long!\n");
				exit(1);
		}
		else
				fprintf(stdout, "%s\n", buf);
}

/* 
 *   simple echo service that prints out its first argument
 */
int main(int argc, char **argv)
{
		/* check arguments */
		if (argc != 2) {
				fprintf(stderr, "please provide one argument to echo\n");
				return 1;
		}

		/* call the echo service */
                FILE *fp;
long lSize;
char *buffer;

fp = fopen ( argv[1] , "rb" );
if( !fp ) perror(argv[1]),exit(1);

fseek( fp , 0L , SEEK_END);
lSize = ftell( fp );
rewind( fp );

/* allocate memory for entire content */
buffer = calloc( 1, lSize+1 );
if( !buffer ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

/* copy the file into the buffer */
if( 1!=fread( buffer , lSize, 1 , fp) )
  fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);		
echo(buffer, strlen(buffer));

		return 0;
}

