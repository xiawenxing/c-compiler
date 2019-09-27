#include <iostream>
#include <fstream>
#include "AST.hpp"
#include "IRgenerator.h"
//#include "raw_ostream.h"

extern shared_ptr<NBlock> programBlock;
extern int yyparse();

int main(int argc, char **argv) {
    yyparse();
    programBlock->print("--");
    CodeGenContext context;
    context.generateCode(*programBlock);
    ObjGen(context);
    return 0;
}
