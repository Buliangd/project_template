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

#include "work_internal.h"
#include "work.h"

int32_t work_print_version(void)
{
    printf("work version %s\n", WORK_VERSION);
    printf("work call upg version: ");
    upg_print_version();
    printf("work call cli version: ");
    cli_print_version();
    printf("work call cjson version: ");
    cjson_print_version(); 

    return 0;
}

