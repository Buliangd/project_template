/**@file  
 * @note   All Copyright (c) reserved
 * @brief 
 *
 * @author buliangd
 * @date   2022/07/02
 *
 * @version
 *  date       |version    |author     |message
 *  :----      |:----      |:----      |:----
 *  2022/07/02 |V1.0.0     |buliangd   |create file
 * @warning  
 */
#include <stdio.h>
#include <stdint.h>
#include "cjson.h"
#include "cli.h"
#include "upg.h"
#include "work.h"
#include "move.h"

int main(int argc, const char *argv[])
{
    printf("this is main entry\n");

    cjson_print_version();
    cli_print_version();
    upg_print_version();
    work_print_version();
    move_print_version();
    return 0;
}
