#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/wait.h> 

#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>

// #define IWLISTELF "/mnt/sd/dlna_upnp/networkconfig/nettools/iwlist"
#define IWLISTELF "./iwlist"
#define IWLISTARGS "wlan0 scanning"

int iwlist(void)
{
#if 1
	system(IWLISTELF " " IWLISTARGS " > /tmp/tmpname");
#else
	system("date > /tmp/tmpname");
	system("echo \"-----------\" >> /tmp/tmpname");
	system("ls -l >> /tmp/tmpname");
	system("echo \"-----------\" >> /tmp/tmpname");
	system("date >> /tmp/tmpname");
	system("echo \"-- WHO AM I? ---------\" >> /tmp/tmpname");
	system("whoami >> /tmp/tmpname");
	system("echo \"-----------\" >> /tmp/tmpname");
#endif
}



int main(int argc, char *argv[])
{
	int fd;
	FILE *fp;
	char tmpssid[32]="/tmp/tmpname";
	pid_t  cpid;
	int status;
	char line[256];



	
#if 0	
	printf("Content type: text/html\n\n");

	printf("iPhone4\n");
	printf("iPhone5\n");
	printf("iPhone6\n");
	printf("iPhone7\n");
#else
	printf("Content type: text/html\n\n");
	iwlist();
	fp = fopen(tmpssid, "r");
	while(fgets(line, sizeof(line), fp)){
			char *p=line;
			const int LINE_MAX = 256;
			/* format like ESSID..."..."xxx */
			while(strncmp(p, "ESSID", 5)){
				p++;
				if( p-line > LINE_MAX || *p == 0) { p = NULL; break;}
			}
			if(p){
				/* looking for " in line[]. */
				while(*p && *p++ != '\"'){
					if(p-line > LINE_MAX) break;
				}

				/* print line  */
				while(*p && *p!='\"'){
					if(p-line > LINE_MAX) break;
					putchar(*p);
					p++;
				}
				putchar('\n');
			}
			
			
		}
	fclose(fp); 
#if 0
	printf("*JDL MUSIC BOX*");
#endif
#endif
	return 0;
}

