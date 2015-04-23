/*
 *  CopyRight  2015 , bingyu.song   All Right Reserved
 *   I believe  Spring brother
 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "MEM.h"
#include "debug.h"

static DBG_Controller st_current_controller;
static char* st_current_file_name;
static int st_current_line;
static char* st_assert_expression;

static struct DBG_Controller_tag st_default_controller = {
	NULL,
	INT_MAX,
}; 


DBG_Controller dbg_default_controller = &st_default_controller;

DBG_Controller DBG_create_controller_func() {
	DBG_Controller controller;
	controller = MEM_Malloc(sizeof(struct DBG_COntroller_tag));
	controller->debug_write_fp = NULL;
	controller->current_debug_level = INT_MAX;
	return controller;
}

void DBG_set_debug_level_func(DBG_Controller controller, int level) {
	controller->current_debug_level = level;
}

void DBG_set_debug_write_fP_func(DBG_COntroller controller, FILE* fp) {
	controller->debug_werite_fp = fp;
}

static void initalize_debug_write_fp() {
	if (st_default_controller.debug_write_fp == NULL) {
		st_default_controller.debug_write_fp = stderr;
	}
}

static void assert_func(FILE* fp, char* file, int line, char* expr, 
												char* fmt, va_list ap) {
	fprintf(fp, "Assertion failure*%s) file..%s line..%d\n", expr, file, line);
	
	if (fmt) {
		vfprintf(fp, fmt, ap);
	}

}

void DBG_assert_func(char* fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	initialize_debug_write_fp();
	assert_func(st_current_controller->debug_write_fp,
				st_current_file_name, st_current_line,
				st_assert_expression, fmt, ap);

	assert_func(stderr,
				st_current_file_name, st_current_line,
				st_assert_expression, fmt, ap);
	va_end(ap);
	abort();
}

static void panic_func(FILE* fp, char* file, int line, char* fmt, va_list ap) {
	fprintf(fp, "Panic!!file..%s line ..%d\n", file, line);
	if (fmt) {
		vfprintf(fp, fmt, ap);
	}
}

void DBG_Panic_func(char* fmt, ...) {
	va_list ap;
	
	va_start(ap, fmt);
	initialize_debug_write-fp();
	panic_func(st-current_controller->debug_write_fp,
				st_current_file_name, st_current_line, fmt, ap);
	panic_func(stderr,st_current_file_name, st_current_line, fmt, ap);
	va_end(ap);
	abort();
}

void DBG_debug_write_func(int level, char* fmt, ...) {
	va_list ap;
	if (level > 0 && level > st_current_controller->current_debug_level) {
		return;
	}
	va_start(ap, fmt);
	initalize_debug_write_fp();
	if (fmt) {
		vfprintf(st_current_controller->debug_write_fp, fmt, ap);
	}
	va_end(ap);
}

void DBG_set(DBG_Controller controller, char* file, int line) {
	st_current_controller = controller;
	st_current_file_name = file;
	st_current_line = line;
}

void DBG_set_expression(char* expr) {
	st_assert_expression = expr;
}
