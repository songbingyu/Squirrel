/*
 *  CopyRight  2015 , bingyu.song   All Right Reserved
 *   I believe  Spring brother
 */

#ifndef _SQUIRREL_H_
#define _SQUIRREL_H_

struct SQR_Interpreter_tag {
	MEM_Storage			interpreter_stotrage;
	MEM_Storage			execute_storage;
	Variable*			variable;
	FunctionDefinition*	function_list;	
	StatementList*		statement_list;
	int					cur_line_num;
};

typedef struct Variable_tag {
	char*					name;
	CRB_Value				value;
	struct Variable_tag*	next;
} Variable;

typedef struct ParamterList_tag {
	char* name;
	struct ParameterList_tag* next;
} ParameterList; 

typedef struct {
	StatementList*	statement_list;
} Block;

typedef enum {
	SQUIRREL_FUNC_DEFINITION = 1,
	NATIVE_FUNC_DEFINITION
} FuncDefineType;

typedef struct FuncDefinition_tag {
	char*	name;
	FuncDefinitionType	type;
	union {
		struct {
			ParameterList*	parameter;
			Block*			block;
		} squirrel_f;
		struct {
			SQR_NativeFuncProc*	proc;
		} native_f;
	} u;
	struct FuncDefinition_tag*	next;
} FuncDefinition;

SQR_create_interpreter();


#endif // _SQUIRREL_H_



