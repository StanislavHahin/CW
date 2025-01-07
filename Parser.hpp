#pragma once

#include "header.hpp"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern struct Token* TokenTable;
extern unsigned int TokensNum;

extern struct id* idTable;
extern unsigned int idNum;

extern struct id* labelTable;
extern unsigned int labelNum;

namespace Parser {
    void Parser();
    void Semantic();
    void match(enum TypeOfToken expectedType);
    unsigned int IdIdentification(struct id idTable[], struct Token TokenTable[], unsigned int tokenCount);
    unsigned int LabelIdentification(struct id labelTable[], struct Token TokenTable[], unsigned int tokenCount);
    void printIdentifiers(int num, struct id* table);
    void fprintIdentifiers(FILE* F, int num, struct id* table);
    // program ::= "program", {"var", variable_declaration, ";"}, "start", {statement, ";"}, "finish";
    void program();
    //  programBody ::= { statement, ";" };
    void programBody();
    //  variable_declaration ::= "int16_t", variable_list;
    void variableDeclaration();
    //  variable_list ::= identifier, {",", identifier};
    void variableList();
    //  statement ::= input_statement | output_statement | assign_statement | if_else_statement | goto_statement | label_point | for_statement | while_statement | repeat_until_statement | compound_statement;
    void statement();
    //  input_statement ::= "get", identifier;
    void inputStatement();
    //  output_statement ::= "put", arithmetic_expression;    
    void outputStatement();
    //  arithmetic_expression :: = low_priority_expression{ low_priority_operator, low_priority_expression };
    void arithmeticExpression();
    //  low_priority_expression :: = middle_priority_expression{ middle_priority_operator, middle_priority_expression };
    void lowPriorityExpression();
    //  low_priority_operator :: = "+" | "-";
    //void lowPriorityOperator();
    //  middle_priority_expression :: = identifier | number | "(", arithmetic_expression, ")";
    void middlePriorityExpression();
    //  middle_priority_operator :: = "*" | "/" | "%";
    //void middlePriorityOperator();
    //  assign_statement :: = arithmetic_expression, "<-", identifier;
    void assignStatement();
    //  if_else_statement :: = "if", "(", logical_expression, ")", statement, [";", "ELSE", statement];
    void ifStatement();
    //  logical_expression :: = and_expression{ or_operator, and_expression };
    void logicalExpression();
    //  or_operator :: = "or";
    //void orOperator();
    //  and_expression :: = comparison{ and_operator, and_expression };
    void andExpression();
    //  and_operator :: = "and";
    //  void andOperator();
    //  comparison :: = comparison_expression | [not_operator] "(", logical_expression, ")";
    void comparison();
    //  not_operator :: = "!";
    //  void notOperator();
    //  comparison_expression :: = arithmetic_expression comparison_operator arithmetic_expression;
    void comparisonExpression();
    //  comparison_operator :: = "eg" | "ne" | "<=" | ">=";
    //  void comparisonOperator();
    //  goto_statement :: = "goto", identifier;
    void gotoStatement();
    //  label_point :: = identifier, ":";
    void labelPoint();
    //  for_to_statement ::= "for", assign_statement, "to" | "downto", arithmetic_expression, "do", statement;    
    void forStatement();
    //  while_statement :: = "while", logical_expression, { statement, ";" }, "wend";
    void whileStatement();
    //  repeat_until_statement :: = "repeat", { statement, ";" }, "until", "(", logical_expression, ")";
    void repeatStatement();
    //  compoundStatement :: = "start", { statement, ";" }, "finish";
    void compoundStatement();
}