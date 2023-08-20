<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

/** @var int */
const OPERATORS_ADD = 1;
/** @var int */
const OPERATORS_SUB = 2;
/** @var int */
const OPERATORS_MUL = 3;
/** @var int */
const OPERATORS_DIV = 4;
/** @var int */
const OPERATORS_MOD = 5;
/** @var int */
const OPERATORS_POW = 12;
/** @var int */
const OPERATORS_SL = 6;
/** @var int */
const OPERATORS_SR = 7;
/** @var int */
const OPERATORS_CONCAT = 8;
/** @var int */
const OPERATORS_BW_OR = 9;
/** @var int */
const OPERATORS_BW_AND = 10;
/** @var int */
const OPERATORS_BW_XOR = 11;
/** @var int */
const OPERATORS_IS_IDENTICAL = 16;
/** @var int */
const OPERATORS_IS_NOT_IDENTICAL = 17;
/** @var int */
const OPERATORS_IS_EQUAL = 18;
/** @var int */
const OPERATORS_IS_NOT_EQUAL = 19;
/** @var int */
const OPERATORS_PRE_INC = 34;
/** @var int */
const OPERATORS_PRE_DEC = 35;
/** @var int */
const OPERATORS_POST_INC = 36;
/** @var int */
const OPERATORS_POST_DEC = 37;
/** @var int */
const OPERATORS_SPACESHIP = 170;
/** @var int */
const OPERATORS_ASSIGN = 22;


function register_operator_overload(string $class, int $operator, callable $callable): bool {}
