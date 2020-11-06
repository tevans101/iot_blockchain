#include "Block.h"
#include "sha256.h"
#include "time.h"
#include <iostream>
#include <sstream>
#include <vector>
//#include <cstring>
//#include <string>


Block::Block(uint32_t _indexIn, const std::string& dataIn) : _index(_indexIn), bData(dataIn)
{
    _nonce = -1;
    _time = time(NULL);
}

std::string Block::GetHashValue()
{
    return bHash;
}

void Block::MineBlock(uint32_t _difficulty) 
{
    std::vector<char> cstr[_difficulty + 1];

    for (uint32_t _i = 0; _i < _difficulty; ++_i) 
    {
        cstr[_i] = '0';
    }
    
    cstr[_difficulty] = '\0';

    std::string str(cstr);

    do 
    {
        _nonce++;
        bHash = CalculateHash();
    } while (bHash.substr(0, _difficulty) != str);

    std::cout << "Block mined: " << bHash << std::endl;
}

inline std::string Block::CalculateHash() const 
{
    std::stringstream ss;
    ss << _index << _time << bData << _nonce << previousHashValue;

    return sha256(ss.str());
}