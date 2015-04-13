/* debug.h DEBUG HEADER FILE 
 *
 * Usage: 
 * 		#define DEBUG will use macros. 
 * 		printing to stederr.
 */
#ifndef __debug_h__
#define __debug_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#ifdef DEBUG
	#define errno_msg() (errno == 0 ? "No" : strerror(errno))
	#define basePrint(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
	#define errorNoPrint(M, ...) fprintf(stderr, "ERROR %s: %d: errno: %s " M "\n", __FILE__, __LINE__, errno_msg(), ##__VA_ARGS__)
	#define writeOut(M, ...) { FILE *f = fopen("DEBUG_OUTPUT", "a"); fprintf(f, "%s: %d: " M "\n", __FILE__, __LINE__ , ##__VA_ARGS__); fclose(f); }
#else
	#define basePrint(M, ...)
	#define errorNoPrint(M, ...)
	#define writeOut(M, ...)
#endif

#define boolCheck(A, M, ...) if (A) { basePrint(M, ##__VA_ARGS__); errno=0; }
#define errNoPrint(M, ...) { errorNoPrint(M, ##__VA_ARGS__); errno=0; }
#define debug(M, ...) { basePrint(M, ##__VA_ARGS__); }
#define checkMem(A, ...) if (!(A)) { basePrint("No Memory", ##__VA_ARGS__); }

#endif

const char* getPid(const int pid)
{
    char* name = (char*)calloc(1024,sizeof(char));
    if(name){
        sprintf(name, "/proc/%d/cmdline",pid);
        FILE* f = fopen(name,"r");
        if(f){
            size_t size;
            size = fread(name, sizeof(char), 1024, f);
            if(size>0){
                if('\n'==name[size-1])
                    name[size-1]='\0';
            }
            fclose(f);
        }
    }
    return name;
}
