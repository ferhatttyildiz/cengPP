#include <stdio.h>
#include <ctype.h>
#include <windows.h>	

#define LETTER 0
#define DIGIT 1
#define OPERATOR 2
#define INT_LIT 3
#define IDENT 4
#define UNKNOWN -1
#define FINISHED -2

char input[100];
int inputIndex=0;
int token=-1;

int charClass;
char lexeme[10];
char nextChar;
int lexLen;

void addChar()
{
    if (lexLen<=9)
    {
        lexeme[lexLen++] =nextChar;
    }
    else
    {
        printf("Error - lexeme too long\n");
    }
}

char getNextChar()
{
	if(input[inputIndex] !='\0')
	{
		return input[inputIndex++];
	}
	else return NULL;
}
void getChar()
{
    if((nextChar=getNextChar())!=NULL)
    {

        if (nextChar=='+' || nextChar=='-' || nextChar=='*' || nextChar=='/' )
            charClass = OPERATOR;
        else
        {
            if (isalpha(nextChar))
            {
                charClass=LETTER;
            }
            else
            {
                if (isdigit(nextChar))
                    charClass = DIGIT;
                else
                    charClass = UNKNOWN;
            }
        }
    }

    else
        charClass = FINISHED;
}


int lex()
{
    int i;
    static int first = 1;
    for (i=0; i<lexLen; i++)
        lexeme[i]='\0';
    lexLen=0;
    
    if (first)
    {
        getChar();
        first=0;
    }
    switch(charClass)
    {
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT)
            {
                addChar();
                getChar();
            }
            return IDENT;
            break;
        case DIGIT:
            //Write the required code when a digit is matched

            return INT_LIT;
            break;
        case OPERATOR:
            //Write the required code when an operator is matched

            return OPERATOR;
            break;
        case FINISHED:
            return FINISHED;
            break;
        case UNKNOWN:
            addChar();
            getChar();
            return UNKNOWN;
            break;
    }
}

int main()
{ 
    printf("Input your string: ");
    scanf("%s", input);

while((token = lex())!=FINISHED){
		printf(" token: %d \tlexeme: %s \tnextChar: %c \tinputIndex: %d \tcharClass: %d\n",token,lexeme,nextChar,inputIndex,charClass);
	}
    system("PAUSE");
    return 0;
} 

