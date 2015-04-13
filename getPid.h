/*
 * Use for diagnostics. Grabs PID of a process.
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

const char* get_process_name_by_pid(const int pid)
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

