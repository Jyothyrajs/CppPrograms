#include<iostream>
#include<string>
using namespace std;
class Solution
 {
	public:
	string run(bool , string);
	string lowercase (string message)
	{

   	 	for(int x=0; x < message.length(); x++)
		{
        	if(65 >= (int)message[x] || (int)message[x] <= 90) 
			{
        		message[x] += 32;
	        	}
    		}
        return message;
	}

	string toEnglish (string morseText )
	{
		string translatedText = "";
		string alphabet = "abcdefghijklmnopqrstuvwxyz";
    	string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....",
    "..",".---","-.-",".-..","--","-.","---",".--.","--.-", ".-.","...",
    "-","..-","...-",".--","-..-","-.--","--."};
		for ( int i = 0; i < morseText.length(); i++)
		{
			string code = "";
			int pos;
			int j = 0;
			if(morseText[i] != ' ' )
				code.append(morseText,i,1);
			else
			{
				j++;
				pos = morseText.find(code);
				translatedText.append(alphabet,pos,1);
				j++;
				translatedText.append(" ",j,1);
				code = "";
			}
		}
		return translatedText;
	}
	
	 string toMorse ( string englishtext )
	 {
		 string translatedText = "";
		 string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string morse[] = {"*-","-***","-*-*","-**","*","**-*","--*","****",
    "**","*---","-*-","*-**","--","-*","---","*--*","--*-", "*-*","***",
    "-","**-","***-","*--","-**-","-*--","--*"};
		int i = 0;
		int pos = 0 ;
		while( englishtext[i] != '\0' && i >=0)
		{
			pos = alphabet.find(englishtext[i]);
			cout << "pos of :" <<englishtext[i] <<" : " << pos <<endl;
			translatedText.append(morse[pos]);
			char ch = '@';
			if( englishtext[i] == ch )
			{
				translatedText[++pos] = ch;
				cout << "added space " <<endl;				
			}			
//			cout << translatedText;
			i++;
		}
		return translatedText;
	 }
 };


string Solution::run(bool morseToEnglish, string textToTranslate)
	{
		
		string translatedText = "";
	
	if( morseToEnglish)
		translatedText =  toEnglish(lowercase(textToTranslate));
	else
		translatedText = toMorse(lowercase(textToTranslate));

	return translatedText;
	}

int main()
{
	Solution s;
	bool v = false;
	cout << s.run(v," The The ");
	v=true;
	
}





