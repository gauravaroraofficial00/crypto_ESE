#include<bits/stdc++.h>
using namespace std;
string ceser(string text, int s)
{
    string result = "";
 
    for (int i=0;i<text.length();i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i]+s-65)%26 +65);
    else
        result += char(int(text[i]+s-97)%26 +97);
    }
    return result;
}
string deceser(string text,int s)
{
	string result = "";
 
    for (int i=0;i<text.length();i++)
    {
        if (isupper(text[i]))
        	{
        	if(int(text[i]-s-65)<0)
        		text[i]+=26;
        	
            result += char(int(text[i]-s-65)%26 +65);
            }
    else{
    if(int(text[i]-s-65)<0)
        		text[i]+=26;
        result += char(int(text[i]-s-97)%26+97);
    }
    }
    return result;
}
string encryptrail(string text, int key)
{
    char rail[key][(text.length())];
    for (int i=0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';
 

    bool dir_down = false;
    int row = 0, col = 0;
 
    for (int i=0; i < text.length(); i++)
    {
        
        if (row == 0 || row == key-1)
            dir_down = !dir_down;
 
    
        rail[row][col++] = text[i];
 
        
        dir_down?row++ : row--;
    }
    
    for (int i=0; i < key; i++){
        for (int j=0; j < text.length(); j++)
        {
        	if(rail[i][j] == '\n')
        		continue;
        	cout<<rail[i][j]<<"    ";
        }
       cout<<endl<<" ";
 }

    string result;
    for (int i=0; i < key; i++)
        for (int j=0; j < text.length(); j++)
            if (rail[i][j]!='\n')
                result.push_back(rail[i][j]);
                
 
	 
    return result;
}
 
string decryptrail(string cipher, int key)
{
    
    char rail[key][cipher.length()];
 
    for (int i=0; i < key; i++)
        for (int j=0; j < cipher.length(); j++)
            rail[i][j] = '\n';
 
    
    bool dir_down;
 
    int row = 0, col = 0;
 
    
    for (int i=0; i < cipher.length(); i++)
    {
        
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;
 
        rail[row][col++] = '*';
 
        
        dir_down?row++ : row--;
    }
 
    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<cipher.length(); j++)
            if (rail[i][j] == '*' && index<cipher.length())
                rail[i][j] = cipher[index++];
 
 
    string result;
 
    row = 0, col = 0;
    for (int i=0; i< cipher.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);
        dir_down?row++: row--;
    }
    return result;
}
 
int main()
{	
string s;
	cout<<"Enter the string: ";
	cin>>s;
	cout<<endl;
	cout<<"Enter the Key: ";
	int key;
	cin>>key;
	cout<<endl;
	string ans;
	ans=ceser(s,key);
	cout<<"encryption using caesar: "<<ans<<endl<<endl;
	cout<<"enter key for railfence: ";
	int key2;	
	cin>>key2;
	cout<<endl;
	ans=encryptrail(ans,key2);
	cout<<"encryption using railfence: "<<ans<<endl<<endl;
	ans=decryptrail(ans,key2);
	cout<<"decryption using railfence: "<<ans<<endl<<endl;
	ans=deceser(ans,key);
	cout<<"decryption using caesar: "<<ans<<endl<<endl;
	return 0;
	
}
