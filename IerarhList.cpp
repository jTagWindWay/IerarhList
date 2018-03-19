#include "TText.h"


	TLink::TLink(char * s, TLink * pn, TLink * pd) {

		pNext = pn;
		pDown = pd;

		if (s == NULL)
			str[0] = '\0';
		else
			strcpy(str, s);
	}

	TLink::~TLink() {}

	void* TLink::operator new(size_t s) {

		TLink *temp = mem.pFree;

		if (mem.pFree != NULL)
			mem.pFree = mem.pFree->pNext;

		return temp;
	}

	void TLink::operator delete (void* p) {

		TLink * temp = (TLink*)p;

		temp->pNext = mem.pFree;
		mem.pFree = temp;
	}

	 void TLink::InitMem(int size) {

		mem.pFirst = (TLink*)new char[size * sizeof(TLink)];
		mem.pFree = mem.pFirst;

		mem.pLast = mem.pFirst + (size - 1);
		TLink *temp = mem.pFirst;

		for (int i = 0; i < size - 1; i++)
		{
			temp->pNext = temp + 1;
			temp++;
		}
		mem.pLast->pNext = NULL;
	}

	/* void TLink::MemClean(TText * txt)
	{
		TLink *temp = mem.pFirst;

		while (temp != NULL) {

			temp->status = true;
		}

		for (txt->Reset(); !txt->isEnd(); txt->GoNext()) {

			txt->pCurr->status = true;
		}

		temp = mem.pFirst;

		while (temp <= mem.pLast) {
			if (temp->status == true)   temp->status = false;
			else
			{
				temp->status = false;
				delete temp;
			}
		}
	}*/

	 void TLink::MemClean(TText * txt) {

		 TLink * tmp = mem.pFree;
		 while (tmp != NULL) {
			 strcpy_s(tmp->str, "*");
			 tmp = tmp->pNext;
		 }
		 for (txt->Reset(); !txt->isEnd(); txt->GoNext()) {
			 strcat(txt->pCurr->str, "*");
		 }
		 tmp = mem.pFirst;

		 while (tmp <= mem.pLast) {
			 if (strstr(tmp->str, "*") == NULL) {
				 delete tmp;
				 tmp++;
			 }
			 else {
				 tmp->str[strlen(tmp->str) - 1] = '\n';
			 }
		 }
	 }


