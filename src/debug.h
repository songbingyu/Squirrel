/*
 *  CopyRight  2015 , bingyu.song   All Right Reserved
 *   I believe  Spring brother
 */
#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>
#include "DBG.h"

struct DBG_Controller_tag {
	FILE*	debug_write_fp;
	int		current_debug_level;
};

#endif // _DBG_H_


