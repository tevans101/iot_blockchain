#pragma once
//Block class representing individual block in chain

class Block
{
public:
	std::string previousHashValue;

	Block(uint32_t _indexIn, const std::string& dataIn);
	std::string GetHashValue();
	void MineBlock(const uint32_t _difficulty);

private:
	uint32_t _index;	//32bit int location of block in blockchain
	int64_t _nonce;		//64bit used for mining
	std::string bData;
	std::string bHash;
	time_t _time;
	
	std::string CalculateHash() const;
};