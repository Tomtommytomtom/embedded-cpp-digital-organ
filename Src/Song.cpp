#include "Song.h"

//item
SongItem::SongItem(Tone *t): tone(*t){

}

char* Song::toString(){
	//this is buggy for some reason, probably off by one errors
	char* delimiter = " - ";
	int delLen = strlen(delimiter);
	int songLen = strlen(name);
	int artistLen = strlen(artist);
	int size =  songLen + delLen + artistLen;
	char *label = (char*) malloc(sizeof(char) * size);
	int labelCount = 0;
	for(int i = 0; i < songLen; i++){
		label[labelCount] = name[i]; 
		labelCount++;
	}
	for(int i = 0; i < delLen; i++){
		label[labelCount] = delimiter[i]; 
		labelCount++;
	}
	for(int i = 0; i < artistLen; i++){
		label[labelCount] = artist[i]; 
		labelCount++;
	}
	return label;
}

char SongItem::getHasNext(){
	return hasNext;
}

Tone *SongItem::getTone(){
	return &tone;
}

void SongItem::setTone(Tone *t){
	tone = *t;
}

SongItem*::SongItem::getNext(){
	return next;
}

void SongItem::setNext(SongItem* n){
	next = n;
	hasNext = 1;
}

void SongItem::clearNext(){
	next = 0;
	hasNext = 0;
}

//song
Song::Song(char* name, char* artist): name(name), artist(artist){
	length = 0;
}

int Song::getLength(){
	return length;
}

SongItem *Song::getFirst(){
	return first;
}

//returns last if index >= length
SongItem *Song::getAt(int index){
	SongItem *iterator = first;
	for(int i = 1; i < index && i < length; i++)
		iterator = iterator->getNext();
	return iterator;
}

void Song::add(SongItem *item){
	if(length != 0)
		last->setNext(item);
	else
		first = item;
	
	last = item;
	length++;
}

void Song::insertAt(SongItem *item, int index){
	if(index == 0)
		return insertFirst(item);
	if(index == length)
		return add(item);
	SongItem *iterator = first;
	for(int i = 2; i < index && i < length; i++)
		iterator = iterator->getNext();
	if(iterator)
	{
		item->setNext(iterator->getNext());
		iterator->setNext(item);
	}
	length++;
}

void Song::insertFirst(SongItem *item){
	item->setNext(first);
	first = item;
	length++;
}

void Song::removeAt(int index){
	if(index == 0)
		return removeFirst();
	if(index == length - 1)
		return removeLast();
	SongItem *iterator = first;
	for(int i = 2; i < index && i < length; i++)
		iterator = iterator->getNext();
	if(iterator)
		if(iterator->getNext())
			iterator->setNext(iterator->getNext()->getNext());
	length--;
}

void Song::removeFirst(){
	if(first->getHasNext())
		first = first->getNext();
	else
	{
		last = 0;
		first = 0;
	}
	length--;
}

void Song::removeLast(){
	if(length == 1)
		return removeFirst();
	SongItem *iterator = first;
	for(int i = 2; i < length; i++)
		iterator = iterator->getNext();
	iterator->clearNext();
	last = iterator;
	length--;
}

		