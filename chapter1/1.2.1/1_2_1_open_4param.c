/*
 * =====================================================================================
 *
 *       Filename:  1_2_1_open_4param.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2016 08:25:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 

int main(void) 
{ 
    int fd = open("test_open.txt", O_CREAT, 0644, "test"); 

    close(fd); 
    return 0; 
}


