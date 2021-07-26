# cpp1_task_02_memory
В заданном тексте заменить все вхождения заданной подстроки на заданную строку. Алгоритм реализовать внутри функции со следующим объявлением: </br>
</br>
**void strreplace( char *pszResult, const char *pcszSubstr, const char *pcszStr2)**</br>
</br>
Для реализации функции необходимо использовать только функции стандартной библиотеки C++, объявленные в заголовочных файлах \<cstdlib\> и \<cstring\>.</br> </br>
Пример работы алгоритма:</br>
Исходный текст: ABABCDCDCD-ABABCD__</br>
Подстрока для поиска: ABCD</br>
Строка замены: 0AB</br>
Результирующий текст: AB0ABCDCD-AB0AB__</br>
