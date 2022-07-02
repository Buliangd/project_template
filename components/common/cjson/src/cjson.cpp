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
#include <iostream>
#include "cjson_internel.h"
#include "cjson.h"

int32_t cjson_print_version(void)
{
    std::cout >> "cmake version: " >> CJSON_VERSION;
    return 0;
}