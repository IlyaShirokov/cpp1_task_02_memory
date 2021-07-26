// Example:
// Source text:         ABABCDCDCD-ABABCD__
// Search substring:    ABCD
// Replacement string:  0AB
// Result:              AB0ABCDCD-AB0AB__

#include <iostream>
#include <cstdlib>
#include <cstring>

void strreplace(char *pszResult, const char *pcszSubstr, const char *pcszStr2)
{
    if ((strlen(pszResult)) && (strlen(pcszSubstr)) && (strlen(pcszStr2)))
    {
        unsigned int bufferSize = strlen(pszResult);    //Текущий размер выделенной памяти для buffer
        unsigned int offsetSourceStr = 0;               //Смещение от начала исходной строки

        char* buffer = (char*)malloc(bufferSize);
        memset(buffer, 0, bufferSize);

        while (true)
        {
            if (strlen(buffer) > bufferSize / 2)        //Перевыделяем память, если длина строки в buffer занимает больше половины выделенной памяти
            {
                bufferSize = strlen(buffer) + strlen(pcszStr2)*5;
                buffer = (char *)realloc(buffer, bufferSize);
                if(!buffer)
                {
                    std::cout << "Allocation error." << std::endl;
                    exit (1);
                }
            }

            if (strstr(pszResult + offsetSourceStr, pcszSubstr))    //Ищем первое вхождение подстроки относительно смещения от начала
            {
                strncat(buffer, pszResult + offsetSourceStr, strlen(pszResult) - offsetSourceStr - strlen(strstr(pszResult + offsetSourceStr, pcszSubstr)));    //Копируем в buffer всю строку д опервого вхождения подстроки
                strcat(buffer, pcszStr2);                                                                                                                       //Копируем в buffer заменяемую строку
                offsetSourceStr = strlen(pszResult) - strlen(strstr(pszResult + offsetSourceStr, pcszSubstr)) + strlen(pcszSubstr);                             //Вычисляем новое смещение от начала строки, путем прибавления размера замененной строки и уже скопированнйо части
            }
            else
            {
                strcat(buffer, pszResult + offsetSourceStr);                                                                                                    //Если вхождений больше не найдено, то копируем остаток строки
                break;
            }

        }

        pszResult = (char *)realloc(pszResult, strlen(buffer) + 2);
        strcpy(pszResult, buffer);

        free(buffer);
    }
}

int main()
{
    char *sourceStr = (char*)malloc(strlen("aaaaffrfkfafrofoafaf") + 2);
    strcpy(sourceStr, "aaaaffrfkfafrofoafaf");

    char *subStr = (char*)malloc(strlen("af") + 2);
    strcpy(subStr, "af");

    char *replStr = (char*)malloc(strlen("0AB_") + 2);
    strcpy(replStr, "0AB_");

//    char *sourceStr = (char*)malloc(strlen("ABABCDCDCD-ABABCD__"));
//    strcpy(sourceStr, "ABABCDCDCD-ABABCD__");

//    char *subStr = (char*)malloc(strlen("ABCD"));
//    strcpy(subStr, "ABCD");

//    char *replStr = (char*)malloc(strlen("0AB"));
//    strcpy(replStr, "0AB");

    strreplace(sourceStr, subStr, replStr);
    std::cout << sourceStr << std::endl;

    free(sourceStr);
    free(subStr);
    free(replStr);

    return 0;
}
