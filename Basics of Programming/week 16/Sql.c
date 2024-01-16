#include <stdio.h>
#include <string.h>
#define bool _Bool;
typedef void (*pf)();

typedef union entity entity;

typedef struct entityint
{
    int value;
    struct entityint* nextentityint;
    entity *nextentityrow;
}entityint;

typedef struct entitychar
{
    char* value;
    struct entitychar* nextentitychar;
    entity *nextentityrow;
}entitychar;

union entity
{
    entityint Int;
    entitychar Char;
};

typedef struct Keys Keys;
struct Keys
{
    char keyname[20];
    int length;
    int bonusfeature;//0 = null, 1 = primarykey, 2 = notnull, 3 = unique 
    entity * nextentitycol;
    Keys *nextKey;
};
    
typedef struct sheetnamelist sheetnamelist;
struct sheetnamelist
{
    char *headname;
    sheetnamelist *nextsheetname;
    Keys *nextKey;
};

enum 
{
    null,
    primarykey,
    notnull,
    unique
};

sheetnamelist *sheetnamehead = NULL;
sheetnamelist *sheetnametail = NULL;

char *keyword[22] = {"INT","CHAR", "CREATE TABLE", "PRIMARY KEY", "NOT NULL",
  "UNIQUE","INSERT INTO", "VALUES", "DELETE FROM",
"WHERE", "UPDATE", "ORDER", "BY",
"ASC", "DESC", "AND", "OR",
"BETWEEN", "IS"};

char *Typew[2] = {"INT", "CHAR"};
char *Senw[5] = {"CREATE", "INSERT", "DELETE", "UPDATE", "SELECT"};
void Create();
void Insert();
pf List[5] = {Create, Insert}; //Delete, Update, Select};


//void Select();
//void Delete();
//void Update();

int main()
{
    char operate[8] = {""};
    //scanf("%s",operate);
    
    while(scanf("%s",operate) != EOF)
    {
        int error = 1;
        for(int i = 0; i < 5; i++)
        {
            if(strcmp(operate, Senw[i]) == 0)
            {
                List[i]();
                error = 0;
                break;
            }
        }
        if(error)
        {
            while(getchar()!=';');
            printf("SYNTAX ERROR\n");
        }
    }
}

void Create()
{
    char tabl[6] = {0};
    scanf("%s", tabl);
    int Ifprim = 0;

    if(strcmp(tabl, "TABLE") != 0)
    {
        printf("SYNTAX ERROR\n");
        while(getchar() != ';');
        return;
    }

    char *sheetname = malloc(100 * sizeof(char));
    memset(sheetname, 0, sizeof(sheetname));
    scanf("%s", sheetname);
    if(*sheetname == '(')
    {
        printf("SYNTAX ERROR\n");
        while(getchar() != ';');
        return;       
    }

    gets(tabl);
    if(strcmp(tabl," (")!= 0)
    {
        printf("SYNTAX ERROR\n");
        while(getchar() != ';');
        return;       
    }

    sheetnamelist *p = malloc(sizeof(sheetnamelist));
    p->headname = sheetname;
    p->nextsheetname = NULL;
    p->nextKey = NULL;
    if(sheetnamehead)
    {    
        sheetnametail->nextsheetname = p;
    }
    else sheetnamehead = p;
    sheetnametail = p;


    Keys *keyhead = 0;
    int keyamount = 0;
    char word[20] = {0};
    scanf("%s", word);
    while(*word != ')')
    {

        keyamount++;
        Keys *k = malloc(sizeof(Keys));
        strcpy(k->keyname, word);
        scanf("%s", word);
        k->nextentitycol = 0;
        
        if(strcmp(word, "INT") == 0)
        {
            k->length = -1;
        }
        else
        {
            int temp = 0;
            for(char *slow = word + 5; *slow != ')'; slow++)
            {
                temp *= 10;
                temp += *slow - '0';
            }
            k->length = temp;
        }

        gets(word);
        if(strncmp(word," PRIMARY KEY",12)==0)
        {
            k->bonusfeature = 1;
            if(Ifprim == 0)
                Ifprim = 1;
            else
            {
                printf("SYNTAX ERROR\n");
                while(getchar() != ';');
                //need to free the list
                return;
            }
                    k->nextKey = keyhead;
            keyhead = k;
        }
        else if(strncmp(word," NOT NULL",9)==0)
        {
            k->bonusfeature = 2;
            k->nextKey = keyhead;
            keyhead = k;
        }
        else
        {
            k->bonusfeature = 0;
            k->nextKey = keyhead;
            keyhead = k;
        }
        //for(char *s = word; s && *s == ',';s++)
        scanf("%s",word);
    }
    p->nextKey = keyhead;

    if(*word!=')' || word[1] != ';' || Ifprim == 0)
    {
        printf("SYNTAX ERROR\n");
        while(getchar() != ';');
        //need to free the list;
        return;
    }

    printf("CREATE TABLE SUCCESSFULLY\n");

}

void Insert()
{
    char into[100] = {0};
    scanf("%s", into);
    if(strcmp(into, "INTO"))
    {
        printf("SYNTAX ERROR");
        while(getchar() != ';');
        return;
    }

    char sheetname[20] = {0};
    scanf("%s", sheetname);
    int searched = 0;
    sheetnamelist * insertsheet = 0;
    for(insertsheet = sheetnamehead; insertsheet; insertsheet = insertsheet->nextsheetname)
    {
        if(strcmp(insertsheet->headname, sheetname) == 0)
        {
            searched = 1;
            break;
        }
    }
    if(!searched)
    {
        printf("ERROR");
        while(getchar() != ';');
        return;
    }

    scanf("%s", into);
    char word[20] = {0};
    if(strcmp(into, "VALUES") == 0)
    {
        while(getchar()!='(');
    }
    else 
    {
        printf("SYNTAX ERROR\n");
        while(getchar() != ';');
        return;
    }

    scanf("%s", word);
    Keys *keyptr = sheetnamehead->nextKey;
    entity *prvrowentity = 0;
    int flag = 1;
    while(*word != ')' && flag)
    {
        if(word[strlen(word) - 1] == ';' || word[strlen(word) - 1] == ')' )
            flag = 0;
        
        if(strncmp(word, "NULL",4) == 0)
        {
            if(keyptr->bonusfeature == notnull || keyptr->bonusfeature == primarykey)
            {
                printf("ERROR\n");
                while(getchar() != ';');
                return;
            }
            else
            {
                entityint * inttail = keyptr->nextentitycol;
                for(; inttail && inttail->nextentityint;inttail= inttail->nextentityint);

                entityint *pint = malloc(sizeof(entityint));
                char * s = word;
                pint->value = 0;
                pint->nextentityint = 0;
                pint->nextentityrow = 0;
                if(inttail)
                    inttail->nextentityint = pint;
                else
                    keyptr->nextentitycol = pint;
                if(prvrowentity)
                {
                    prvrowentity->Int.nextentityrow = pint;
                    prvrowentity=prvrowentity->Int.nextentityrow;
                }
                else
                    prvrowentity=pint;               
            }
        }
        else if(keyptr->length == -1)
        {
            char * s = word;
            int temp = 0;
            while(*s != ','&& *s !=')')
            {
                temp *= 10;
                temp += *s - '0';
                s++;
            }
            entityint * inttail = keyptr->nextentitycol;
            for(; inttail && inttail->nextentityint;inttail= inttail->nextentityint)
                if((keyptr->bonusfeature == unique || keyptr->bonusfeature == primarykey) && inttail->value == temp)
                {
                    printf("ERROR\n");
                    while(getchar() != ';');
                    return;
                }
            entityint *pint = malloc(sizeof(entityint));
            pint->value = temp;
            pint->nextentityint = 0;
            pint->nextentityrow = 0;
            if(inttail)
                inttail->nextentityint = pint;
            else
                keyptr->nextentitycol = pint;
            
            if(prvrowentity)
            {
                prvrowentity->Int.nextentityrow = pint;
                prvrowentity=prvrowentity->Int.nextentityrow;
            }
            else
                prvrowentity=pint;
        }
        else
        {
            char *s = word+1;
            for(;*s != '\'';s++);
            *s = 0;
            entitychar *chartail = keyptr->nextentitycol;
            for(; chartail && chartail->nextentitychar; chartail = chartail->nextentitychar)
                if((keyptr->bonusfeature == unique || keyptr->bonusfeature == primarykey) && strcmp(chartail->value, word) == 0)
                {
                    printf("ERROR\n");
                    while(getchar() != ';');
                    return;
                }
            if(strlen(word+1) > keyptr->length)
            {
                printf("ERROR\n");
                while(getchar() == ';');
                return;
            }

            entitychar *pchar = malloc(sizeof(entitychar));
            pchar->value = malloc(strlen(word + 1) * sizeof(char));
            strcpy(pchar->value,word+1);

            pchar->nextentitychar = 0;
            pchar->nextentityrow = 0;
            if(chartail)
                chartail->nextentitychar = pchar;
            else
                keyptr->nextentitycol = pchar;
            
            if(prvrowentity)
            {
                prvrowentity->Char.nextentityrow = pchar;
                prvrowentity=prvrowentity->Char.nextentityrow;
            }
            else
                prvrowentity=pchar;


        }
        keyptr = keyptr->nextKey;


        if(flag == 1)
            scanf("%s", word);
    }    
    printf("1 RECORDS INSERTED\n");
}

























