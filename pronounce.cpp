//
/*
Author: Nuzhat Khan, Nuzhat.Khan86@macaulay.cuny.edu
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: PROJECT2
Write a program pronounce.cpp that
Lets the user input a 
 (let’s call the input word W).
If the word is not found in the dictionary, print 
“Not found”. Otherwise, report:
Pronunciation : the pronunciation of the word W 
(as given in the dictionary),
Identical : other words from the dictionary with 
the same pronunciation as W,
Replace phoneme : words that can be obtained from 
W by replacing one phoneme.
Add phoneme : words that can be obtained from W by
adding one phoneme,
Remove phoneme : words that can be obtained
from W by removing one phoneme,
*/

#include <cctype>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

void splitOnSpace(string s, string & before, string & after)  // Given
{													
  // reset strings
	before = ""; 
	after = "";
  // accumulate before space
    int i = 0;
    while (i < s.size() && not isspace(s[i])) { 
        before = before + s[i]; 
        i++; 
    }
  // skip the space
    i++;
    // accumulate after space
    while (i < s.size()) { 
        after = after + s[i]; 												
        i++; 
    }
}

//~~~~~~~~~~~~~PRONOUNCE~~~~~~~~~~~~~~
//checks which word the user input matches with by analyzing the first portion from the split f(x) and, once found, prints the latter portion
string how_say(string txt)											
{
	ifstream file;
	file.open("cmudict.0.7a");

	if (file.fail())

	{
		cerr << "Fail";
	}

	string have_split;
	string read;
	string havent_split;

	while (getline(file, read))

	{
		splitOnSpace(read, havent_split, have_split);

		if (havent_split == txt)

		{
			return have_split;
		}

	}

	cout << "Not found";
}

//~~~~~~~~~~~~~IDENTICAL~~~~~~~~~~~~~~
//if two words have the same pronounciation and if they are not pronounciations of the same word (possibly a doouble dictionary entry) then continue filling in an empty string until you find and store all the word in it
string mood(string text, string how_to_say)
{
	ifstream file;
	file.open("cmudict.0.7a");

	if (file.fail())

	{
		cerr << "Fail";
	}

	string have_split;
	string read;
	string same = "";
	string havent_split;
	

	while (getline(file, read))

	{
		splitOnSpace(read, havent_split, have_split);

		if (how_to_say == have_split)

		{	
			if (havent_split != text)

			{
				same += havent_split + " ";
			}
		}
            
	} 
  
	return same;
}

//Replace Member F(x)s
//~~~~~~~~~~~~~1~~~~~~~~~~~~~~
//loop thru thr string, turning them all into chars
//if any of the chars are spaces, then increment and return the counter
int how_many_phenome(string strong)
{
	int how_many;
	how_many = 0;

	for (int juz = 0; juz < strong.length(); juz = (juz + 1))

	{
		char strong_into_chars = strong[juz];

		if (isspace(strong_into_chars))

		{
			how_many = how_many + 1;
			
		}

    }
   
    return how_many;
}

//~~~~~~~~~~~~~REPLACE~~~~~~~~~~~~~~
//first checks if the number of phenomes for both strings are correct
//loops thru the first one, splitting both of them
//if the newly split first parts of each word are not the same, increment the counter
//if just one phenome is diff, and not more or less than that, then the word is acceptable and the f(x) is true
bool to_the_left(string first, string second)
{
	int how_many_again;
	how_many_again = 0;

	string dee = first;
	string dum = second;

	if (how_many_phenome(first) != how_many_phenome(second))

	{
	  return false;
	}

	for (int juz = 0; juz < (1 + how_many_phenome(first)); juz = (juz + 1))

	{
		string first_portion_first;
		string second_portion_first;
		string first_portion_second;
		string second_portion_second;

		splitOnSpace(dee, first_portion_first, dee);
		splitOnSpace(dum, first_portion_second, dum);

		if (first_portion_first != first_portion_second)

		{
			how_many_again = how_many_again + 1;
		}

		if (first_portion_first == first_portion_second)

		{
			how_many_again = how_many_again;
		}
	}

	if (how_many_again == 1)

	{
		return true;
	}

	return false;
}

//Add & Remove Member F(x)s
//~~~~~~~~~~~~~1~~~~~~~~~~~~~~
//checks if the changed word and the original pronounciation are the same or diff
bool confirm(string say_it, string change_it)
{

	if (change_it != say_it)

	{
		return false;
	}

	else if (change_it == say_it)

	{
		return true;
	}
}

//~~~~~~~~~~~~~2~~~~~~~~~~~~~~
//cheks if two words, the original pronounciation, and the word modified, have the same pronounciation or not
//stores in diff vars
string doppleganger(string say_it, string say_it_anew)
{
	string unit_venn_glycogen = "";

	int nuz = 0;	

	string unlike_glycogen = "";
	int unlike_times;
	unlike_times = 0;
		
	for (int juz = 0; juz < say_it_anew.length(); juz = (juz + 1))

	{
		if (say_it_anew[juz] != say_it[nuz])

		{
			unlike_glycogen += say_it_anew[juz];
		}

		else if (say_it_anew[juz] == say_it[nuz])

		{
			unit_venn_glycogen += say_it_anew[juz];
			nuz = nuz + 1;
		}
	}

	return unit_venn_glycogen;
}

//~~~~~~~~~~~~~3~~~~~~~~~~~~~~
//replaces string of pronounciation with new found string using npos
string pushed_out(string say_it, string minus)
{
	static const size_t npos = -1;
	int look = say_it.find(minus);
	string finale = "";

	if (look != npos) 

	{   
		if (look != 0)

		{
			finale = say_it.substr(0, (look - 1)) + say_it.substr((look + (minus.length())));              
		}

		else if (look == 0)

		{
			finale = say_it.substr((look + (minus.length() + 1)));
		}
		
	}

	else if (look == npos)

	{          
		return say_it;
	}

	return finale;
}

//~~~~~~~~~~~~~4~~~~~~~~~~~~~~
//compares two strings and checks if theyre the same or diff
bool venn(string say_it, string say_it_anew)
{
	string unit = "";
	string unlike = "";
	int unlike_times = 0;	
	static const size_t npos = -1;
	
	for (int juz = 1; juz <= say_it_anew.length(); (juz = juz + 1))

	{
		int look = say_it.find(unit);

		char strong_into_chars = say_it_anew[juz];

		if (juz == (say_it_anew.length() - 1) ||isspace(strong_into_chars))

		{

			if (juz == (say_it_anew.length() - 1))

			{
				unit = unit + strong_into_chars;
			}

			if (look == npos)

			{    
				unlike_times = unlike_times + 1;
				unlike = unit;

				if (1 < unlike_times)

				{
					return false;
				}
			}

			unit = "";
		}

		else if (juz != (say_it_anew.length() - 1) && !(isspace(strong_into_chars)))

		{
	         unit = unit + strong_into_chars;
		}  

	}

	if (unlike_times == 0)

	{
		string dopplegang = (doppleganger(say_it, say_it_anew));

		if (confirm(say_it, dopplegang))

		{
			return true;
		}

		return false;
	}

	bool finale = confirm(say_it,  pushed_out(say_it_anew, unlike));

	return finale;
}

//~~~~~~~~~~~~~ADDITION~~~~~~~~~~~~~~
//changes one phenome in the original pronounciation and finds words that are one phenome off
//stores those words and returns them
bool addition(string first, string second)
{
	if (how_many_phenome(second) == 1 + (how_many_phenome(first)))

	{
		bool finale = venn(first, second);

		if (!(finale))

		{
			return false;
		}

		else if (finale)

		{
			return true;
		} 
	}

	else if (how_many_phenome(second) != (1 + how_many_phenome(first)))

	{        
		return false;
	}
}

//~~~~~~~~~~~~~REMOVE~~~~~~~~~~~~~~
//removes one phenome from the original pronounciation and looks for words that are one phenome off
//stores those words and returns them
bool subtraction(string first, string second)
{
	if (how_many_phenome(second) == (how_many_phenome(first) - 1))

	{
		bool finale = venn(second, first);
		
		if (!(finale))

		{
			return false;
		}

		else if (finale)

		{
			return true;
		} 
	}

	else if (how_many_phenome(second) != (how_many_phenome(first) - 1))

	{
		return false;
	}
}

int main()
{
	string text;
	cout << "Enter: ";
	cin >> text;


	for (int caps = 0; caps < text.length(); caps++)

	{
		if ((text[caps] <= 122) && (text[caps] >= 97))

		{
			text[caps] = (65 + (text[caps] - 97));
		}
	}

	string nuzhat = how_say(text);

//PRONOUNCIATION
	cout << "Pronunciation    : " << how_say(text) << endl; 

//IDENTICAL
	cout << "Identical        : " << mood(text, how_say(text)) << endl; 

//ADD
	ifstream aisle;
	aisle.open("cmudict.0.7a");

	if (aisle.fail())

	{
		cerr << "Fail";
	}  

	string have_split;
	string read;	
	string big = "";
	string havent_split;

	cout << "Add phoneme      : ";
	
	while (getline(aisle, read))

	{
		splitOnSpace(read, havent_split, have_split);

		if (havent_split[havent_split.length() - 1] == ')')
		
		{
			big = big;
		}
	
		else if (havent_split[havent_split.length() - 1] != ')')

		{
			if (addition(nuzhat, have_split))

			{
				big += havent_split + " ";            
			}
		} 
		   
	}

	cout << big << endl;

//REMOVE
	ifstream dial;
	dial.open("cmudict.0.7a");

	if (dial.fail())

	{
		cerr << "Fail";
	} 

	string have_split_two;
	string read_two;	
	string small = "";
	string havent_split_two;

	cout << "Remove phoneme   : ";
	
	while (getline(dial, read_two))

	{
		splitOnSpace(read_two, havent_split_two, have_split_two);

		if (havent_split_two[havent_split_two.length() - 1] == ')')
		
		{
			small = small;
		}
	
		else if (havent_split_two[havent_split_two.length() - 1] != ')')

		{
			if (subtraction(nuzhat, have_split_two))

			{
				small += havent_split_two + " ";            
			}
		} 
		   
	}

	cout << small << endl;
    
//REPLACE
   ifstream style;
	style.open("cmudict.0.7a");

	if (style.fail())

	{
		cerr << "Fail";
	} 

	string have_split_three;
	string read_three;	
	string medium = "";
	string havent_split_three;

	cout << "Replace phoneme  : ";
	
	while (getline(style, read_three))

	{
		splitOnSpace(read_three, havent_split_three, have_split_three);

		if (havent_split_three[havent_split_three.length() - 1] == ')')
		
		{
			medium = medium;
		}
	
		else if (havent_split_three[havent_split_three.length() - 1] != ')')

		{
			if (to_the_left(nuzhat, have_split_three))

			{
				medium += havent_split_three + " ";            
			}
		} 
		   
	}

	cout << medium << endl;

	return 0;
}

