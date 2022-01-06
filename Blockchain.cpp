#include "Blockchain.h"

Blockchain::Blockchain() {
    chain.emplace_back(Block(0, "Genesis Block"));
    difficulty = 6;
}

void Blockchain::addBlock(Block newBlock) {
    newBlock.prevHash = getLastBlock().GetHash();
    newBlock.MineBlock(difficulty);
    chain.push_back(newBlock); 
}

Block Blockchain::getLastBlock() const {
    return chain.back();
}