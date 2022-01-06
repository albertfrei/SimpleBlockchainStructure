#include <cstdint>
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;

class Block {
public:
    string prevHash;
    Block(uint32_t indxIn, const string &dataIn);

    string GetHash();
    void MineBlock(uint32_t difficulty);

private:
    uint32_t index;
    int64_t nonce;
    string data;
    string hash;
    time_t _time;

    string CalculateHash() const;
};