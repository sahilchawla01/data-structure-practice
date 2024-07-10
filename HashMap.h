#pragma once
struct ChainNode
{
	int value;
	ChainNode* next;

	ChainNode(int x) : value(x), next(nullptr) {};
	ChainNode(int x, ChainNode* nextElement) : value(x), next(nextElement) {};
};

//Abstract class for hash maps
class HashMap
{
public:
	virtual void Put(int element) = 0;
	virtual bool Search(int elementToSearch) = 0;
	virtual void Delete(int elementToDelete) = 0;
	virtual void TestDisplayHashMap() = 0;
private:

	//hash function
	virtual int Hash(int element) = 0;
protected:
	int hashSize;
};

class ChainingHashMap : HashMap
{
public:
	ChainingHashMap(int inputHashSize);

	void Put(int element) override;
	bool Search(int elementToSearch) override;
	void Delete(int elementToDelete) override;
	void TestDisplayHashMap() override;
private:

	//hash function
	int Hash(int element) override;
	ChainNode** hashTable;
};

class LinearProbingHashMap : HashMap
{
public:
	LinearProbingHashMap(int inputHashSize);

	void Put(int element) override;
	bool Search(int elementToSearch) override;
	void TestDisplayHashMap() override;
	//Not implemented as not recommended in linear probing, one can remove element and do re-hashing
	void Delete(int elementToDelete) override {};
private:

	int* hashTable;
	//hash function
	int Hash(int element) override;
	int Probe(int element);
};


//class HashMap
//{
//
//public:
//	HashMap(int inputHashSize);
//
//private:
//
//	int hashSize;
//
//	int* hashTable;
//};

