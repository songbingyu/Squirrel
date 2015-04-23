/*
*  CopyRight  2015 , bingyu.song   All Right Reserved
*   I believe  Spring brother
*/
#ifndef _MEMORY_H_
#define _MEMORY_H_
#include "MEM.h"

typedef union Header_tag Header;

struct MEM_Controller_tag {
	FILE* error_fp;
	MEM_ErrorHandler error_handler;
	MEM_FailMode fail_mode;
	Header*	block_header;
};
#endif // __MEMORY_H_