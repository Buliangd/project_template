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
#include "cli.h"
#include "upg_internel.h"
#include "upg.h"

int32_t upg_print_version(void)
{
    printf("upg version: %s\n", upg_VERSION);
    printf("upg call cli version: ");
    cli_print_version();
    printf("upg call cjson version: ");
    cjson_print_version();
    return 0;
}