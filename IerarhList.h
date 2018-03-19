#pragma once
#include <fstream>
#include "TStack.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;


class TText;	
class TLink;

struct TMem{
	TLink * pFree, *pFirst, *pLast;
};

class TLink {

public:
	char str[80];
	TLink * pNext;
	TLink * pDown;
	static TMem mem;


	bool status;

	TLink(char * s = NULL, TLink * pn = NULL, TLink * pd = NULL);

	~TLink();

	void* operator new(size_t s);

	void operator delete (void* p);

	static void InitMem(int size);

	static void MemClean(TText* txt);

};



