#include "Blockchain.h"

Blockchain::Blockchain() 
{
    vChain.emplace_back(Block(0, "Genesis Block"));
    _difficulty = 6;
}

void Blockchain::AddBlock(Block bNew) 
{
    bNew.previousHashValue = GetLastBlock().GetHashValue();
    bNew.MineBlock(_difficulty);
    vChain.push_back(bNew);
}

Block Blockchain::GetLastBlock() const 
{
    return vChain.back();
}
