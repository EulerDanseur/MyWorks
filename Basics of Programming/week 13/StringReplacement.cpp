#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str_me[101], find_str[101], replace_str[101];

    cin >> str_me >> find_str >> replace_str;
    bool flag = 1;
    unsigned count = 0, sublen = strlen(find_str);

    for(unsigned i = 0; i < (strlen(str_me) - sublen + 1); i++ , flag = 1)
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

}