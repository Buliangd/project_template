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

#include "move_internal.h"
#include "move.h"

int32_t move_print_version(void)
{
    printf("move version %s\n", MOVE_VERSION);
    printf("move call upg version: ");
    upg_print_version();
    printf("move call cli version: ");
    cli_print_version();
    printf("move call cjson version: ");
    cjson_print_version(); 

    return 0;
}

