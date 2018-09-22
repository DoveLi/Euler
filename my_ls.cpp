/*************************************************************************
    > File Name: my_ls.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年09月22日 星期六 20时42分05秒
 ************************************************************************/



#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int exe_c;
char *file_owner;
char *file_group;
char *now_owner;
char *now_group;
void get_file_owner(struct stat info){

        struct passwd *usr_info;
        usr_info = getpwuid(info.st_uid);
        file_owner = usr_info->pw_name;
        struct group *grp_info;
        grp_info = getgrgid(info.st_gid);
        file_group  = grp_info->gr_name;
        struct passwd *now_usr_info;
        now_usr_info = getpwuid(getuid());
        now_owner = now_usr_info->pw_name;
        struct group *now_grp_info;
        now_grp_info = getgrgid(getgid());
        now_group = now_grp_info->gr_name;
}
void change_color(struct stat info) {

        if (S_ISDIR(info.st_mode)){

                        printf("\033[34m\033[1m");
                }
        else if (S_ISREG(info.st_mode)) {

                    if ((!strcmp(now_owner, file_owner) && info.st_mode & S_IXUSR) || (!(strcmp(now_group, file_group)) && info.st_mode & S_IXGRP) || (info.st_mode & S_IXOTH)) {

                                    printf("\033[32m\033[1m");
                                    exe_c = 1;
                                }
                }
}
void print_permission(struct stat info) {

            if (S_ISDIR(info.st_mode)){

                            printf("d");
                        }
            else if (S_ISREG(info.st_mode)) {

                            printf("-");
                        }
            if (info.st_mode & S_IRUSR)
                printf("r");
            else
                printf("-");
            if (info.st_mode & S_IWUSR)
                printf("w");
            else
                printf("-");
            if (info.st_mode & S_IXUSR)
                printf("x");
            else
                printf("-");
            if (info.st_mode & S_IRGRP)
                printf("r");
            else
                printf("-");
            if (info.st_mode & S_IWGRP)
                printf("w");
            else
                printf("-");
            if (info.st_mode & S_IXGRP)
                printf("x");
            else
                printf("-");
            if (info.st_mode & S_IROTH)
                printf("r");
            else
                printf("-");
            if (info.st_mode & S_IWOTH)
                printf("w");
            else
                printf("-");
            if (info.st_mode & S_IXOTH)
                printf("x");
            else
                printf("-");
            printf("  ");
}
int main(int argc, char* argv[]){

        int permission;
        char* now = NULL;
        if (argc == 1) {

                    now = (char*)malloc(sizeof(char));
                    *now = '.';
                    permission  = 0;
                }else {

                            for (int i = 1; i < argc; ++i) {

                                            if (!strcmp(argv[i], "-a")){

                                                                if (permission == 3)
                                                                    continue;
                                                                else if (permission == 2)
                                                                    permission = 3;
                                                                else
                                                                    permission = 1;
                                                            }else if (!strcmp(argv[i], "-l")) {

                                                                                if (permission == 3) {

                                                                                                        continue;
                                                                                                    }
                                                                                else if (permission == 1)
                                                                                    permission = 3;
                                                                                else
                                                                                    permission = 2;
                                                                            }else if (!strcmp(argv[i], "-al") || !strcmp(argv[i], "-la")) {

                                                                                                permission = 3;
                                                                                            }else if (i == argc - 1){

                                                                                                                now = argv[i];
                                                                                                            }
                                        }
                            if (now == NULL) {

                                            now = ".";            
                                        }
                        }
        DIR *dir;
        struct dirent *ptr;
        dir = opendir(now);
        int cnt = 0;
        while ((ptr = readdir(dir)) != NULL){

                    if ((permission == 0 || permission == 2) && (cnt == 0 || cnt == 1)) {

                                    ++cnt;
                                    continue;
                                }
                    char newfile[100] = {
                        0};
                    exe_c = 0;
                    struct stat info;
                    sprintf(newfile,"%s/%s", now, ptr->d_name);
                    stat(newfile,&info);
                    get_file_owner(info);
                    change_color(info);
                    if (permission == 2 || permission == 3) {

                                    print_permission(info);
                                    printf("%-2d  ",info.st_nlink);
                                    printf("%-4s  ", file_owner);
                                    printf("%-4s  ", file_group);
                                    printf("%-4lld  ",info.st_size);
                                    struct tm* t = localtime(&info.st_ctime);
                        printf("%04d-%02d-%02d %02d:%02d:%02d  ", t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
                                    printf("%s\n", ptr->d_name);
                                }
                    if (permission == 0 || permission == 1) {

                                    printf("%-5s\t", ptr->d_name);
                                }
                    if (S_ISDIR(info.st_mode) || exe_c) {

                                    printf("\033[0m");
                                }
                }
    if (permission == 0 || permission == 1) {

                printf("\n");
            }
        return 0;
    }
