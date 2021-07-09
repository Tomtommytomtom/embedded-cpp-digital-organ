#ifndef _SONG_H
#define _SONG_H

#include "Tone.h"

class SongItem{
private:
	SongItem *next;
	Tone tone;
	char hasNext;
public:
	SongItem(Tone *t);

	char getHasNext();

	Tone *getTone();
	void setTone(Tone *t);
	
	SongItem* getNext();
	void setNext(SongItem* n);
	void clearNext();
};

class Song{
private:
	SongItem *first;
	SongItem *last;
	int length;

public:
	char* name;
	char* artist;
	Song(char* name, char* artist);

	int getLength();

	SongItem *getFirst();
	SongItem *getAt(int index);

	char *toString();

	void add(SongItem *item);
	void insertAt(SongItem *item, int index);
	void insertFirst(SongItem *item);
	void removeAt(int index);
	void removeFirst();
	void removeLast();
};
#endif