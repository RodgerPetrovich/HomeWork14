#include "Trie.h"

Trie::Trie()
{
	wordEnd = false;
	for (int i = 0; i < ALPHABET; i++)
		children[i] = nullptr;
}
void Trie::insert(string word)
{
	Trie* currentNode = this;
	for (int i = 0; i < word.size(); i++)
	{
		int index = word[i] - 'a';
		if (!currentNode->children[index])
		{
			Trie* newNode = new Trie();
			currentNode->children[index] = newNode;
			
		}
		currentNode = currentNode->children[index];
	}
	currentNode->wordEnd = true;

}

bool Trie::search(string key)
{
	Trie* current = this;
	for (int i = 0; i < key.size(); i++)
	{
		int index = key[i] - 'a';
		if (current->children[index])
		{
			current = current->children[index];
		}
		else return false;
			
	}
	return (current && current->wordEnd);
}

bool Trie::isEmpty()
{
	for (int i = 0; i < ALPHABET; i++)
	{
		if (children[i])return false;
	}
	return true;
}

void Trie::remove(Trie* node,string key, int depth)
{
	if (!node) return;
	if (depth == key.size())
	{
		if (wordEnd)wordEnd = false;
		if (isEmpty())
		{
			delete node;
			node = nullptr;
			
		}
		return;
	}
	int index = key[depth] - 'a';
	node->remove(children[index],key, depth + 1);
	if (node->isEmpty() && node->wordEnd == false) {
		delete (node);
		node = nullptr;
	}
	return;
}

void Trie::printAllWords(string x)
{
	
	if (wordEnd)
	{
		cout << x << endl;
		
	}
	if (isEmpty())
	{
		
		return;
	}
	for (int i = 0; i < ALPHABET; i++)
	{
		if (children[i])
		{
			x.push_back('a' + i);
			children[i]->printAllWords(x);
			x.pop_back();
		}
	}
}

bool Trie::printWordsByKey(string key)
{
	Trie* current = this;
	bool isKey = true;
	for (int i = 0; i < key.size(); i++)
	{
		int index = key[i] - 'a';
		if (current->children[index])
			current = current->children[index];
		else
		{
			isKey = false;
			break;
		}
	}
	if (!isKey) 
	{ 
		cout << "Данного сочетания нет в словаре!!!";
		return false;
	}
	else
	{
		string z=key;
		while (!current->wordEnd)
		{
			for (int i = 0; i < ALPHABET; i++)
			{
				if (current->children[i])
				{

					z.push_back('a' + i);
					current = current->children[i];
				}
			}
		}
		cout << z;
	}
	return true;
}