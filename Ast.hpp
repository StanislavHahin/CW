#pragma once

#include "header.hpp"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

extern struct Token* TokenTable;
extern int pos;

namespace AST {
    struct astNode* program();
    struct astNode* programBody();
    struct astNode* variableDeclaration();
    struct astNode* variableList();
    struct astNode* statement();
    struct astNode* inputStatement();
    struct astNode* outputStatement();
    struct astNode* arithmeticExpression();
    struct astNode* lowPriorityExpression();
    struct astNode* middlePriorityExpression();
    struct astNode* assignStatement();
    struct astNode* ifStatement();
    struct astNode* logicalExpression();
    struct astNode* andExpression();
    struct astNode* comparison();
    struct astNode* comparisonExpression();
    struct astNode* gotoStatement();
    struct astNode* labelPoint();
    struct astNode* forStatement();
    struct astNode* whileStatement();
    struct astNode* whileBody();
    struct astNode* repeatStatement();
    struct astNode* repeatBody();
    struct astNode* compoundStatement();

    void deleteNode(struct astNode* node);
    struct astNode* createNode(enum TypeOfNode type, const char* name, struct astNode* left, struct astNode* right);
    void printAST(struct astNode* node, int level);
    void fPrintAST(FILE* outFile, struct astNode* node, int level);
    void match(enum TypeOfToken expectedType);
    struct astNode* astParser();
}
