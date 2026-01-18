#include "../utils/block.cpp"

int main()
{
    string firstHash = "000000000000000000";

    Block a(firstHash, "Hello World", 101010);
    Block b(a.getHash(), "Hello World 2", 202020);
}