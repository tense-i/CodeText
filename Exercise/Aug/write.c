/* #include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int show_file_type(struct stat *s)
{
    switch (s->st_mode & S_IFMT)
    {
    case S_IFDIR:
        printf("该文件为目录\n");
        break;
    case S_IFREG:
        printf("该文件为普通文件\n");
        break;
    default:
        break;
    }
}

void FileType(struct stat *s)
{
    if (S_ISREG(s->st_mode))
        printf("Its a directory\n");
    if (s->st_mode & S_IRUSR)
    {
        printf("R\n");
    }
}
int main()
{
    int ret = -1;
    struct stat s;
    ret = stat("example.txt", &s);
    if (ret == -1)
    {
        perror("stat");
        return 1;
    }
    show_file_type(&s);
    return 0;
}
 */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    const int num = 2;
    *(int *)&num = 4;
    printf("num = %d\n", num);
    return 0;
}