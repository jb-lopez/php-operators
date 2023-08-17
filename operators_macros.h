#ifndef OPERATORS_OPERATORS_MACROS_H
#define OPERATORS_OPERATORS_MACROS_H

//<editor-fold desc="Macros" defaultstate="collapse">

#define USE_OPLINE const zend_op *opline = EX(opline);

#define ASSIGN_OPERATORS(OP) \
OP(ADD, add) \
OP(SUB, sub) \
OP(MUL, mul) \
OP(DIV, div) \
OP(MOD, mod) \
OP(SL, sl) \
OP(SR, sr) \
OP(CONCAT, concat) \
OP(BW_OR, bw_or) \
OP(BW_AND, bw_and) \
OP(BW_XOR, bw_xor) \
OP(POW, pow)

#define OPERATORS(OP) \
ASSIGN_OPERATORS(OP) \
OP(IS_IDENTICAL, is_identical) \
OP(IS_NOT_IDENTICAL, is_not_identical) \
OP(IS_EQUAL, is_equal) \
OP(IS_NOT_EQUAL, is_not_equal) \
OP(ASSIGN, assign) \
OP(ASSIGN_OP, assign_op)

#define ASSIGN_OPERATORS_METHOD_SWITCH(opcode, handler) \
    case ZEND_##opcode: \
        magic_method = "__" #handler "_assign"; \
        break;

#define OPERATOR_GLOBAL(opcode, handler) user_opcode_handler_t original_##handler##_handler;

#define OPERATOR_LOCAL(opcode, handler) static int handle_##handler(zend_execute_data *execute_data);

#define OPERATOR_HANDLE(opcode, handler) \
static int handle_##handler(zend_execute_data *execute_data) { \
    return handle_operator(execute_data, "__" #handler); \
}

#define OPERATOR_MINIT(opcode, handler) \
    operators_globals.original_##handler##_handler = zend_get_user_opcode_handler(ZEND_##opcode); \
    zend_set_user_opcode_handler(ZEND_##opcode, handle_##handler);

#define OPERATOR_MSHUTDOWN(opcode, handler) zend_set_user_opcode_handler(ZEND_##opcode, operators_globals.original_##handler##_handler);

#define DEBUG_PRINTF(...) if (operators_globals.debug) { printf(__VA_ARGS__); }

//</editor-fold>

#endif //OPERATORS_OPERATORS_MACROS_H
