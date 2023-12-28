#include <iostream>
#include <string.h>
using namespace std;

int lengthOfLongestSubstring(char* s)
{
    char *p = s;
    int count = 0;
    while(*s != 0)
    {
        int temp = 1;
        int unrepeat = 1;
        p = s;
        while(unrepeat && *p != 0)
        {
            if(p == s)
            {
                p++;
                continue;
            }
            for(int i = 0; i < p - s; i++)
                if(*p == s[i])
                {
                    unrepeat = 0;
                    break;
                }
            if(unrepeat)
            {
                temp++;
                p++;
            }
        }

        count = max(count, temp);
        s++;
    }
    return count;
}

char* longestPalindrome(char* s) 
{
    char *ans = s;
    //memset(ans, 0, sizeof(ans));
    
    char *p = s + 1;
    int count = 1;
    
    while(*(p))
    {
        char *left = p, *right = p;
        while(left-1 >= s && *(left-1) == *p)
            left--;
        while(!*(right+1) && *(right+1) == *p)
            right++;
        
        if(left == s || *(right + 1) == 0 || *left != *right)
        {
            if(*left == *right && count < right - left + 1)
            {
                ans = left; //strncpy(ans, left, right - left + 1);
                count =right - left +1; 
            }
            p++;
            continue;
        }    

            
        while(left != s && *(right + 1) != 0)
        {
            if(*(left-1) == *(right + 1))
            {
                left--;
                right++;
            }
            else
                break;
        }
        
        if(*left == *right && count < right - left + 1)
        {
            //strncpy(ans, left, right - left + 1);
            ans = left;
            count =right - left +1; 
        }
        p++;
    }
    *(ans + count) = 0;
    return ans;
}

char* convert1(char* s, int numRows) 
{
    if(numRows == 1) return s;
    int index = 0;
    int row;
    int a = numRows - 1;
    int b = strlen(s) / a + 1 ;
    char sq[numRows][ strlen(s) / a + 1 ]={0};
    memset(sq, 0, sizeof(sq));
    for(int i = 0; i < strlen(s) / a + 1 ; i += a)
    {
        row = 0;
        int k = 1;
        for(int j = 0; j < a * 2; j++)
        {
            if(j <= a)
            {
               
                sq[row][i] = s[index];
                index++;
                row++;
            }
            else
            {
                   
                sq[row-1-k][i+k]=s[index];
                index++;
                k++;
            }
        }
    }
    index = 0;
    memset(s, 0, sizeof(s));
    for(int i = 0; i < numRows; i++)
    for(int j = 0; j < b; j++)
    {
            if(sq[i][j]!=0)
            {
                s[index] = sq[i][j];
                index++;
            }

    }
    return s;
}

char* convert(char* s, int numRows) 
{
    int length = strlen(s);
    if(numRows == 1 || length <= numRows) return s;
    int onecirc = (numRows - 1) * 2;
    int onewidth = numRows - 1;
    
    int width = length / onewidth + width;

    int **board = (int **)malloc(numRows * sizeof(int *));
    for(int i = 0; i < numRows; i++)
    {
        board[i] = (int *)malloc(width * sizeof(int)); 
        memset(board[i], 0, width * sizeof(int));
    }

    int col = 0;

    for(int i = 0; i < length; i++)
    {
        if(i % onecirc < numRows)
        {
            board[i % onecirc][col] = s[i];
            if(i % onecirc == numRows - 1)
                col++;
        }
        else
        {
            board[2 * (numRows - 1) - i % onecirc][col] = s[i];
            col++;
        }

    }

    int index = 0;
    for(int i = 0; i < numRows; i++)
    for(int j = 0; j < width; j++)
    {
        if(board[i][j] != 0)
        {
            s[index] = board[i][j];
            index++;
        }
    }
    return s;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) 
{
    char answer[strsSize][strsSize][101];
    char *hash[strsSize];
    int hadex[strsSize][strsSize];
    memset(hadex, -1, sizeof(hadex));
    memset(hash, 0, sizeof(hash));
    memset(answer, 0, sizeof(answer));
    int hashamount = 0;
    for(int i = 0; i < strsSize; i++)
    {
        char temp[strlen(strs[i]) + 1];
        strcpy(temp, strs[i]);
        Sort(temp);
        bool matched = 0, pos = 0;
        for(int j = 0; j < hashamount; j++)
        {
            if(strcmp(temp, hash[j]) == 0)
            {
                matched = 1;
                pos = j;
            }
        }
        if(matched)
        {
            for(int j = 0; j < strsSize; j++)
            {
                if(hadex[pos][j] == -1)
                {
                    hadex[pos][j] = i;
                
                    break;
                }
            }
        }
        else
        {
            hash[hashamount] = (char*) malloc((strlen(temp)+1) * sizeof(char));
            hadex[hashamount][0] = i;
            hashamount++;
        }

    }
    *returnSize = 0;
    *returnColumnSizes = new int[strsSize];
    memset(*returnColumnSizes, 0, sizeof(*returnColumnSizes));
    for(int i = 0; i < hashamount; i++)
    {
        (*returnSize)++;
        for(int j = 0; hadex[i][j] != -1; j++)
        {
            strcpy(answer[i][j], strs[hadex[i][j]]);
            (*returnColumnSizes[i])++;
        }
    }

    for(int i = 0; i < *returnSize; i++)
    {
        for(int j = 0; j < *returnColumnSizes[i]; j++)
        {
            cout <<answer[i][j] <<' ';
        }
        cout << endl;
    }

}

void Sort(char *str)
{
    int n = strlen(str);
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(str[i] > str[j])
            {
                char temp = str[i];
                str[i] = str[j]; 
                str[j] = temp;
            }
        }
    }
}

int main()
{

    int n;
    cin >> n;
    char s[n][10];
    memset()
    //cout << lengthOfLongestSubstring(s);
    cout << convert(s, n);
}