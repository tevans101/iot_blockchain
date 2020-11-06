#pragma once
#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain
{
public:
    Blockchain();
    void AddBlock(Block newBlock);

private:
    uint32_t _difficulty;
    std::vector<Block> vChain;
    Block GetLastBlock() const;
};

