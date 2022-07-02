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
#include "cjson.h"
#include "cli_internal.h"
#include "cli.h"

int32_t cli_print_version(void)
{
    printf("cli version: %s\n", CLI_VERSION);
    printf("cli call cjson version: ");
    cjson_print_version();
    return 0;
}