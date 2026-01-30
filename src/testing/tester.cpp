#include "tester.hpp"

int main(){
    print("Running block tests");
    run_block_tests();
    print("Running blockbuilder tests");
    run_blockbuilder_tests();
    print("Running chainverifier tests");
    run_chainverifier_tests();
}