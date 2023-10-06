#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
    char word[100]="UnityChan";
    char temp[50]="";
    char temp2[50]="Halloween";

    cout<<"len = "<<strlen(word)<<"\n";
    strcat(word," is cute");
    cout<<word<<"\n";
    strcpy(temp, word);
    cout<<temp<<"\n";
    
    if(strcmp(temp,temp2))
        cout<<"Different";
}