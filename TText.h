#pragma once
#include "IerarhList.h"


class TText {

public:

	TLink * pFirst;
	TLink * pCurr;
	TStack <TLink*> st;
	int level = 0;

	TText(TLink * pf = NULL);

	void GoNextLink();

	void GoDownLink();

	void GoPrevLink();

	void InsNextLine(char * ch);

	void InsNextSection(char * ch);

	void InsDownSection(char * ch);

	void InsDownLine(char * ch);

	void DelNext();

	void DelDown();

	TLink* readREC(ifstream &f);

	void Read(char * fn);

	void Print();

	void printREC(TLink *p);

	void saveREC(TLink *tmp, ofstream &ofs);

	void Save(char *fn);

	TLink* copyREC(TLink * pF);

	TLink* Copy();

	void Reset();

	bool isEnd();

	void GoNext();
};

