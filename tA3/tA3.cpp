#include <iostream>
#include <string>
#include <vector>

#define SizeTable 1500
struct HashTable
{
private:
	void FillVectors()
	{
		for (int i = 0; i < SizeTable; i++)
		{
			states.push_back(0);
			array.push_back("");
		}
	}

public:
	std::vector<std::string> contains;
	std::vector<std::string> array;
	std::vector<int> states;
	
	int length;
	HashTable()
	{
		array.reserve(SizeTable);
		states.reserve(SizeTable);
		FillVectors();
		length = 0;
	};
	HashTable(std::string str)
	{
		array.reserve(SizeTable);
		states.reserve(SizeTable);
		FillVectors();
		int num = HashFunc(str);
		array[num] = str;
		states[num] = 1;
		length=1;
		contains.push_back(str);
	}
	int HashFunc(std::string str)
	{
		int stri = ((str[0]*100+str[1]*10+str[2])xor(1)+ (str[3] * 100 + str[4] * 10 + str[5]) xor (2)+ (str[6] * 100 + str[7] * 10 + str[8]) xor (3))%SizeTable;
		
		return stri ;
	}
	int FindElem(std::string str)
	{
	
		int num = HashFunc(str);
	
		int repeats = 1;
		while (array[num]!=str)
		{
		
			num = (num + repeats * repeats) % SizeTable;
			repeats++;
			

		}
		return repeats;
		//return w;
	}
	int InsertElem(std::string str)
	{
		
		int hash_value = HashFunc(str);
		int i = hash_value;
		int repeats=1;
		while (states[i] == 1)
		{
			i = (i + repeats* repeats) % SizeTable;
			repeats++;

			
		}
		array[i] = str;
		states[i] = 1;
		
		length++;
		contains.push_back(str);
		return repeats ;
	}
	int DelElem(std::string str)
	{
	
		int num = HashFunc(str);
	
		int repeats = 1;
		while (array[num]!=str)
		{
			
			num = (num + repeats * repeats) % SizeTable;
				
				repeats++;
				
			
		


		}
	array[num] = "0";
	states[num] = 2;
	length--;
	contains.erase(std::remove(contains.begin(), contains.end(), str), contains.end());
		return repeats;
	}
	void Clear()
	{
		states.clear();
		array.clear();
		FillVectors();
	}

	
	bool isEmpty()
	{
		if (length == 0)
		{
			return true;
		}
		return false;
	}
	void Print()
	{
		for (int i = 0; i < SizeTable; i++)
		{
			if (array[i] != "")
			{
				std::cout << i << ": " << array[i] << " : " << states[i] << '\n';
			}
		}
	}
	
	
};
int GetRandomNumber(int min, int max)
{
	// Установить генератор случайных чисел
	srand(time(NULL));

	// Получить случайное число - формула
	int num = min + rand() % (max - min + 1);

	return num;
}

int main()
{
	HashTable hash1("295207554");
	
	hash1.length;
	hash1.Clear();
	int t = 0;
	long int temp = 111111111;
	for (int i = 0; i < 750; i++)
	{
		temp++;

		t=hash1.InsertElem(std::to_string(temp));
	
	}
	std::cout <<"Insert(0,5):"<< hash1.InsertElem("112111650") << std::endl;
	std::cout << "Find(0,5):" << hash1.FindElem("112111650") << std::endl;
	std::cout << "Delete(0,5):" << hash1.DelElem("112111650") << std::endl;
	std::cout << "\n";
	hash1.Clear();
	 t = 0;
	 temp = 111111111;
	for (int i = 0; i < 1050; i++)
	{
		temp++;

		t = hash1.InsertElem(std::to_string(temp));

	}
	std::cout << "Insert(0,7):" << hash1.InsertElem("112111650") << std::endl;
	std::cout << "Find(0,7):" << hash1.FindElem("112111650") << std::endl;
	std::cout << "Delete(0,7):" << hash1.DelElem("112111650") << std::endl;
	std::cout << "\n";

	hash1.Clear();
	 t = 0;
	 temp = 111111111;
	for (int i = 0; i < 1350; i++)
	{
		temp++;

		t = hash1.InsertElem(std::to_string(temp));

	}
	std::cout << "Insert(0,9):" << hash1.InsertElem("112111650") << std::endl;
	std::cout << "Find(0,9):" << hash1.FindElem("112111650") << std::endl;
	std::cout << "Delete(0,9):" << hash1.DelElem("112111650") << std::endl;
	std::cout << "\n";





	//std::vector<std::string> mas;

	//for (int j = 0; j <hash1.length; j++)
	//{
	//	
	//		for (int i = 0; i < hash2.length; i++)
	//		{
	//			if  (hash1.contains[j] == hash2.contains[i])
	//			{
	//				mas.push_back(hash1.contains[j]);
	//				break;
	//			}
	//		}
	//	
	//}
	//for (std::vector<std::string>::iterator it = mas.begin(); it != mas.end(); ++it)
	//{
	//	std::cout << "\n" << *it;
	//}
}
	
