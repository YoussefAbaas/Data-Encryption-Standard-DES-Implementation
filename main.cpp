#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int initial_perm_table[8][8] = { 58, 50, 42, 34, 26, 18, 10, 2,
		60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6,
		64, 56, 48, 40, 32, 24, 16, 8,
		57, 49, 41, 33, 25, 17, 9, 1,
		59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5,
		63, 55, 47, 39, 31, 23, 15, 7 };
int inverse_perm_table[8][8]={ 40, 8, 48, 16, 56, 24, 64, 32,
		39, 7, 47, 15, 55, 23, 63, 31,
		38, 6, 46, 14, 54, 22, 62, 30,
		37, 5, 45, 13, 53, 21, 61, 29,
		36, 4, 44, 12, 52, 20, 60, 28,
		35, 3, 43, 11, 51, 19, 59, 27,
		34, 2, 42, 10, 50, 18, 58, 26,
		33, 1, 41, 9, 49, 17, 57, 25 };
int key_perm1[8][7] = { 57, 49, 41, 33, 25, 17, 9,
		1, 58, 50, 42, 34, 26, 18,
		10, 2, 59, 51, 43, 35, 27,
		19, 11, 3, 60, 52, 44, 36,
		63, 55, 47, 39, 31, 23, 15,
		7, 62, 54, 46, 38, 30, 22,
		14, 6, 61, 53, 45, 37, 29,
		21, 13, 5, 28, 20, 12, 4 };
int key_perm2[8][6] = { 14, 17, 11, 24, 1, 5,
		3, 28, 15, 6, 21, 10,
		23, 19, 12, 4, 26, 8,
		16, 7, 27, 20, 13, 2,
		41, 52, 31, 37, 47, 55,
		30, 40, 51, 45, 33, 48,
		44, 49, 39, 56, 34, 53,
		46, 42, 50, 36, 29, 32 };
int expansion_table[8][6]={ 32, 1, 2, 3, 4, 5, 4, 5,
		6, 7, 8, 9, 8, 9, 10, 11,
		12, 13, 12, 13, 14, 15, 16, 17,
		16, 17, 18, 19, 20, 21, 20, 21,
		22, 23, 24, 25, 24, 25, 26, 27,
		28, 29, 28, 29, 30, 31, 32, 1 };
int s_box[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
		0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
		4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
		15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
		{ 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
				3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
				0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
				13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },
				{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
						13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
						13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
						1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
						{ 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
								13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
								10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
								3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
								{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
										14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
										4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
										11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
										{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
												10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
												9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
												4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
												{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
														13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
														1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
														6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
														{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
																1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
																7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
																2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

int plain_perm1[8][4]={ 16, 7, 20, 21,
		29, 12, 28, 17,
		1, 15, 23, 26,
		5, 18, 31, 10,
		2, 8, 24, 14,
		32, 27, 3, 9,
		19, 13, 30, 6,
		22, 11, 4, 25 };
int plain_perm2[8][6] = { 14, 17, 11, 24, 1, 5,
		3, 28, 15, 6, 21, 10,
		23, 19, 12, 4, 26, 8,
		16, 7, 27, 20, 13, 2,
		41, 52, 31, 37, 47, 55,
		30, 40, 51, 45, 33, 48,
		44, 49, 39, 56, 34, 53,
		46, 42, 50, 36, 29, 32 };
int left_shift_table[4][4] = { 1, 1, 2, 2,
		2, 2, 2, 2,
		1, 2, 2, 2,
		2, 2, 2, 1 };
string hex_char_to_bin(char c)
{
	// TODO handle default / error
	switch(toupper(c))
	{
	case '0': return "0000";
	case '1': return "0001";
	case '2': return "0010";
	case '3': return "0011";
	case '4': return "0100";
	case '5': return "0101";
	case '6': return "0110";
	case '7': return "0111";
	case '8': return "1000";
	case '9': return "1001";
	case 'A': return "1010";
	case 'B': return "1011";
	case 'C': return "1100";
	case 'D': return "1101";
	case 'E': return "1110";
	case 'F': return "1111";
	}
}
string hex_str_to_bin_str(const std::string& hex)
{
	std::string bin;
	for(unsigned i = 0; i != hex.length(); ++i)
		bin += hex_char_to_bin(hex[i]);
	return bin;
}
string round_string(string&s, int no_shift)
{
	string temp = "";
	for (int i = 0; i < no_shift; i++) {
		for (int j = 1; j < 28; j++) {
			temp += s[j];
		}
		temp += s[0];
		s = temp;
		temp = "";
	}
	return s;
}
string xoring(string a, string b, int n){
	string ans = "";

	// Loop to iterate over the
	// Binary Strings
	for (int i = 0; i < n; i++)
	{
		// If the Character matches
		if (a[i] == b[i])
			ans += "0";
		else
			ans += "1";
	}
	return ans;
}
string DecimalToBinaryString(int a)
{
	string binary = "";
	binary += char(a / 8 + '0');
	a = a % 8;
	binary += char(a / 4 + '0');
	a = a % 4;
	binary += char(a / 2 + '0');
	a = a % 2;
	binary += char(a + '0');
	return binary;
}
string GetHexFromBin(string binary)
{
	string rest(""),tmp,chr = "0000";
	int len = binary.length()/4;
	chr = chr.substr(0,len);
	binary = chr+binary;
	for (int i=0;i<binary.length();i+=4)
	{
		tmp = binary.substr(i,4);
		if (!tmp.compare("0000"))
		{
			rest = rest + "0";
		}
		else if (!tmp.compare("0001"))
		{
			rest = rest + "1";
		}
		else if (!tmp.compare("0010"))
		{
			rest = rest + "2";
		}
		else if (!tmp.compare("0011"))
		{
			rest = rest + "3";
		}
		else if (!tmp.compare("0100"))
		{
			rest = rest + "4";
		}
		else if (!tmp.compare("0101"))
		{
			rest = rest + "5";
		}
		else if (!tmp.compare("0110"))
		{
			rest = rest + "6";
		}
		else if (!tmp.compare("0111"))
		{
			rest = rest + "7";
		}
		else if (!tmp.compare("1000"))
		{
			rest = rest + "8";
		}
		else if (!tmp.compare("1001"))
		{
			rest = rest + "9";
		}
		else if (!tmp.compare("1010"))
		{
			rest = rest + "A";
		}
		else if (!tmp.compare("1011"))
		{
			rest = rest + "B";
		}
		else if (!tmp.compare("1100"))
		{
			rest = rest + "C";
		}
		else if (!tmp.compare("1101"))
		{
			rest = rest + "D";
		}
		else if (!tmp.compare("1110"))
		{
			rest = rest + "E";
		}
		else if (!tmp.compare("1111"))
		{
			rest = rest + "F";
		}
		else
		{
			continue;
		}
	}
	return rest;
}
void reverse_arr(string arr[],int len)
{
	for (int low = 0, high = len - 1; low < high; low++, high--) {
		swap(arr[low], arr[high]);
	}
}
int main(int argc,char**argv)
{
	string key;
	string plain;
	string type;
	//cin>>type>>plain>>key;
	type=argv[1];
	plain=argv[2];
	key=argv[3];
	key=hex_str_to_bin_str(key);
	/*Key operations*/
	/*permutation choice1*/
	string tempresult="";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 7; j++)
			tempresult += key[key_perm1[i][j] - 1];
	}
	key=tempresult;
	/*left circular shift for key and permutation choice 2*/
	string left_key=key.substr(0,28);
	string right_key=key.substr(28,28);
	string round_keys[16];
	tempresult="";
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			tempresult="";
			left_key=round_string(left_key,left_shift_table[i][j]);
			right_key=round_string(right_key,left_shift_table[i][j]);
			string combined_key=left_key+right_key;

			for (int k= 0; k < 8; k++) {
				for (int h = 0; h < 6; h++){
					tempresult += combined_key[key_perm2[k][h] - 1];
				}
			}
			round_keys[i*4+j]=tempresult;
		}
	}

	/*check type*/
	if(type=="decrypt")
	{reverse_arr(round_keys,16);
	cout<<"plain: ";
	}
	else if(type=="encrypt")
	{
		cout<<"cipher: ";
	}

	/*data*/
	plain=hex_str_to_bin_str(plain);
	/*initial permutation*/
	tempresult="";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			tempresult += plain[initial_perm_table[i][j] - 1];
	}
	plain=tempresult;
	string left_plain=plain.substr(0,32);
	string right_plain=plain.substr(32,32);


	for(int i=0;i<16;i++)
	{
		/*expansion for right part 32bit to 48 bit*/
		string expanded_right="";
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 6; j++){
				expanded_right += right_plain[expansion_table[i][j] - 1];
			}}
		/*xor with sub key 48 bit*/
		string val="";
		string xor_result=xoring(expanded_right,round_keys[i],48);
		for(int j=0;j<8;j++)
		{
			/*S-Box*/
			int row = (xor_result[j*6]-'0')*2+(xor_result[j*6+5]-'0');
			int col = (xor_result[j*6+1]-'0')*8+(xor_result[j*6+2]-'0')*4+(xor_result[j*6+3]-'0')*2+(xor_result[j*6+4]-'0');
			int value=s_box[j][row][col];
			val+=DecimalToBinaryString(value);
		}
		/*permutation*/
		tempresult="";
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 4; k++)
				tempresult += val[plain_perm1[j][k] - 1];
		}
		xor_result=xoring(tempresult,left_plain,32);
		left_plain=xor_result;
		/*swapping*/
		if(i!=15)
		{
			string temp=left_plain;
			left_plain=right_plain;
			right_plain=temp;
		}
	}
	string cipher =left_plain+right_plain;
	/*inverse permutation*/
	tempresult="";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			tempresult += cipher[inverse_perm_table[i][j] - 1];
	}
	cipher=GetHexFromBin(tempresult);
	cout<<cipher;
}
