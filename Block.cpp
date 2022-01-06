#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t indxIn, const string &dataIn) : index(indxIn), data(dataIn) {
    nonce = -1;
    _time = time(nullptr);
}

string Block::GetHash() {
    return hash;
}

void Block::MineBlock(uint32_t difficulty) {
    char cstr[difficulty + 1];
    for (uint32_t i = 0; i < difficulty; ++i)
    {
        cstr[i] = '0';
    }

    cstr[difficulty] = '\0';

    string str(cstr);

    do {
        nonce++;
        hash = CalculateHash();
    } while(hash.substr(0, difficulty) != str);

    cout << "Block mined: " << hash << endl;    
}

inline string Block::CalculateHash() const {
    stringstream ss;
    ss << index << _time << data << nonce << prevHash;

    return sha256(ss.str());
}