环境：ubuntu16.04 LLVM 3.9.0
IRgenerator.h、IRgenerator.cpp 生成中间代码
main.cpp 程序入口
LLVMtest.cpp LLVM测试代码
array_for_test.c、if_fun_op_test.c测试样例

运行：
make array_for_test 生成测试样例array_for_test.c的LLVM IR
make array_for_testrun 运行 array_for_test.c并输出
make if_fun_op_test 生成测试样例if_fun_op_test.c的LLVM IR
make if_fun_op_testrun 运行 if_fun_op_test.c并输出
