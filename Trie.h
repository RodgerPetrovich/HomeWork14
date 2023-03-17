#pragma once

#include <iostream>
#include <string>

#define ALPHABET 26

using namespace std;
struct Trie
{
	Trie* children[ALPHABET];
	bool wordEnd;
	
	Trie();
	void insert(string word);
	bool search(string key);
	bool isEmpty();
	void remove(Trie* node,string key, int depth = 0);
	void printAllWords(string x);
	bool printWordsByKey(string key);
	
};