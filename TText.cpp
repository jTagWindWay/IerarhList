#include "TText.h"


	TText::TText(TLink * pf) {
		if (pf == NULL)  pf = new TLink();
		pFirst = pf;
	}

	void TText::GoNextLink() {
		if (pCurr->pNext != NULL) st.Push(pCurr);
		pCurr = pCurr->pNext;
	}

	void TText::GoDownLink() {
		if (pCurr->pDown != NULL) st.Push(pCurr);
		pCurr = pCurr->pDown;
	}

	void TText::GoPrevLink() {
		if (!st.isEmpty()) pCurr = st.Pop();
	}

	void TText::InsNextLine(char * ch) {
		TLink * tmp = new TLink(ch, pCurr->pNext, NULL);
		pCurr->pNext = tmp;
	}

	void TText::InsNextSection(char * ch) {
		TLink * tmp = new TLink(ch, NULL, pCurr->pNext);
		pCurr->pNext = tmp;
	}

	void TText::InsDownSection(char * ch) {
		TLink * tmp = new TLink(ch, NULL, pCurr->pDown);
		pCurr->pDown = tmp;

	}

	void TText::InsDownLine(char * ch) {
		TLink * tmp = new TLink(ch, pCurr->pDown, NULL);
		pCurr->pDown = tmp;
	}

	void TText::DelNext() {
		TLink * tmp = pCurr->pNext;
		if (pCurr->pNext != NULL) {
			pCurr->pNext = tmp->pNext;
			delete tmp;
		}
	}

	void TText::DelDown() {
		TLink * tmp = pCurr->pDown;
		if (pCurr->pDown != NULL) {
			pCurr->pDown = tmp->pNext;
			delete tmp;
		}
	}

	TLink* TText::readREC(ifstream &f) {
		TLink *First, *Current;
		First = Current = new TLink();
		char tmp[80];

		while (!f.eof()) {

			f.getline(tmp, 80, '\n');

			if (tmp[0] == '}')   break;

			else {
				if (tmp[0] == '{') {
					Current->pDown = readREC(f);
				}
				else {
					if (First == NULL) {
						First = new TLink(*Current);
						Current = First;
					}
					else {
						Current->pNext = new TLink(*Current);   //CHEK IT!!!!!!!!!!!!!!!!!!
						Current = Current->pNext;
					}
				}
			}
		}
		return First;
	}

	void TText::Read(char * fn) {
		ifstream ifs(fn);
		pFirst = readREC(ifs);
	}

	void TText::Print() {
		int level = 0;
		printREC(pFirst);
	}

	void TText::printREC(TLink *p) {
		for (int i = 0; i < level; i++) {
			cout << " ";
			cout << p->str << endl;
			if (p->pDown != NULL) {
				level++;
				printREC(p->pDown);
				level--;
			}
			if (p->pNext != NULL)  printREC(p->pNext);
		}
	}

	void TText::saveREC(TLink *tmp, ofstream &ofs) {
		ofs << tmp->str << '\n';
		if (tmp->pDown != NULL) {
			ofs << "{\n";
			saveREC(tmp->pDown, ofs);
			ofs << "}\n";
		}
		if (tmp->pNext != NULL) saveREC(tmp->pNext, ofs);
	}

	void TText::Save(char *fn) {
		ofstream ofs(fn);
		saveREC(pFirst, ofs);
	}

	TLink* TText::copyREC(TLink * pF) {
		TLink * tmp = new TLink(pF->str);
		if (pF->pDown != NULL) tmp->pDown = copyREC(pF->pDown);
		if (pF->pNext != NULL) tmp->pNext = copyREC(pF->pNext);
		return tmp;
	}

	TLink* TText::Copy() {
		return copyREC(pFirst);
	}

	void TText::Reset() {
		st.Clear();
		pCurr = pFirst;
		st.Push(pCurr);
		if (pCurr->pNext != NULL)  st.Push(pCurr->pNext);
		if (pCurr->pDown != NULL)  st.Push(pCurr->pDown);
	}

	bool TText::isEnd() {
		if (st.isEmpty()) return true;
		else
			return true;
	}

	void TText::GoNext() {
		pCurr = st.Pop();
		if (pCurr != pFirst) {
			if (pCurr->pNext)  st.Push(pCurr->pNext);
			if (pCurr->pDown)  st.Push(pCurr->pDown);
		}
	}


