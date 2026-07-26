#include "search.h"
#include <ctype.h>

int search(char *filename)
{
    DIR *dir = opendir("/proc");
    struct dirent *x;

    if (dir == NULL)
        return -1;

    while ((x = readdir(dir)) != NULL)
    {
  
      pid_t pid = atoi(x->d_name);

        char path[256];
        char name[256];

        snprintf(path, sizeof(path), "/proc/%d/comm", pid);

        FILE *fp = fopen(path, "r");
        if (fp == NULL)
            continue;

        if (fgets(name, sizeof(name), fp) != NULL)
        {
            name[strcspn(name, "\n")] = '\0';

            if (strcmp(name, filename) == 0)
            {
                fclose(fp);
                closedir(dir);
                return pid;
            }
        }

        fclose(fp);
    }

    closedir(dir);
    return -1;
}

void banner(void)
{
    printf(
"████████╗██████╗  █████╗  ██████╗███████╗██╗████████╗\n"
"╚══██╔══╝██╔══██╗██╔══██╗██╔════╝██╔════╝██║╚══██╔══╝\n"
"   ██║   ██████╔╝███████║██║     █████╗  ██║   ██║   \n"
"   ██║   ██╔══██╗██╔══██║██║     ██╔══╝  ██║   ██║   \n"
"   ██║   ██║  ██║██║  ██║╚██████╗███████╗██║   ██║   \n"
"   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚══════╝╚═╝   ╚═╝   \n"
"\n"
"=============================================================\n"
"              Linux Process Inspector / TraceIt\n"
"=============================================================\n"
" Author : TraceByte\n"
" Version: 1.0\n"
" Platform: Linux\n"
"-------------------------------------------------------------\n"
" Search running processes\n"
" Read information from /proc/<pid>\n"
" Display cmdline, exe, cwd, root, status, memory...\n"
"=============================================================\n\n");
}