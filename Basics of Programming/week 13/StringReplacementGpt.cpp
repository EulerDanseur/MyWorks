#include <iostream>
#include <cstring>
using namespace std;

// 函数声明
int replaceSubstring(char *str, const char *find_str, const char *replace_str);

int main() 
{
    // 读取输入字符串
    char str_me[100], str[100], find_str[100], replace_str[100];
    cin >> str >> find_str >> replace_str;
    // 调用替换函数
    strcpy(str_me, str);

    int replace_count = replaceSubstring(str, find_str, replace_str);

    // 输出替换次数和结果字符串
    printf("%d %s\n", replace_count, str);

    bool flag = 1;
    unsigned count = 0, sublen = strlen(find_str);

    for(unsigned i = 0; i < (strlen(str_me) - sublen); i++ , flag = 1)
    {
        
        for(unsigned j = 0; j < sublen; j++)
        {
            if(str_me[j + i] != find_str[j])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            count++;
            char backstr[strlen(str_me) - i - sublen + 1]={0};
            

            for(int k = i + sublen; str_me[k] != 0; k++)
            {
                backstr[k - i - sublen] = str_me[k]; 
            }

            char frontstr[strlen(str_me) - sublen + strlen(replace_str)] = {0};
            strncpy(frontstr, str_me, i);


            strcat(frontstr, replace_str);
            strcat(frontstr, backstr);

            memset(str_me, 0, sizeof(str_me));
            strcpy(str_me, frontstr);
            i = i + strlen(replace_str) - 1;

        }
    }

    cout << count << ' ' << str_me;


    return 0;
}

// 替换子串的函数
int replaceSubstring(char *str, const char *find_str, const char *replace_str)
{
    int str_len = strlen(str);
    int find_len = strlen(find_str);
    int replace_len = strlen(replace_str);

    int replace_count = 0;

    // 在主串中查找子串
    for (int i = 0; i <= str_len - find_len;)
    {
        if (strncmp(str + i, find_str, find_len) == 0) 
        {
            // 找到子串，进行替换
            memmove(str + i + replace_len, str + i + find_len, str_len - i - find_len + 1);
            strncpy(str + i, replace_str, replace_len);
            i += replace_len;
            replace_count++;
        } 
        else 
        {
            i++;
        }
    }

    return replace_count;
}