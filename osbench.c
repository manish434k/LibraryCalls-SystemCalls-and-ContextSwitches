#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>



void LibCallCost()
{
	int i = 0;
    int excTime = 0;
    int n= 1000;
    char buf[10];	
	struct timeval  tv1, tv2;

    FILE *fp;

    /* Open file for both reading */
    fp = fopen("file.txt", "r");

    gettimeofday(&tv1, NULL); /*timer start*/

    for(i=0; i<n; i++)

    {

        // (fd=0) for stdin

        /* Read data */

        fread(buf,sizeof(char), 10, fp);

        //printf("buffer val:%s  :%d",buf);

    }

    gettimeofday(&tv2, NULL); /*timer end*/

    fclose(fp);

    //exicution time

    excTime = (tv2.tv_usec - tv1.tv_usec);

    printf ("%d Library calls were executed in %d usecs for an average of %d usecs/call.\n",

                n, excTime, (excTime/n) );
}

void sysCallCost()
{
	char buf[10];
    int n=1000;	
	int excTime=0;
	int i = 0;	
	struct timeval  tv1, tv2;
		   
	gettimeofday(&tv1, NULL); /*timer start*/
    for(i=0; i<n; i++)
    {
        // (fd=0) for stdin
        /* Read data, read BUFSIZE byte*/
       read(0, buf, BUFSIZ);
    }
    gettimeofday(&tv2, NULL); /*timer end*/

    //exicution time
    excTime = (tv2.tv_usec - tv1.tv_usec);

    printf ("%d Syatem calls were executed in %d usecs for an average of %d usecs/call.\n",

                n, excTime, (excTime/n) );
}

int main()
{

    LibCallCost();
	sysCallCost();	
	getch();

return 0;

}


