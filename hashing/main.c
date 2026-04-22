#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "array.h"

int search(char const* name)
{
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(g_people[i].name, name) == 0) {
            return i; // Возвращает индекс элемента
        }
    }
    return -1; // Не найден
}

/*
порядковый номер заданной комбинации можно определить, 
интерпретируя строку как число в 26-ричной системе счисления.

'A' → 0, 'B' → 1, ..., 'Z' → 25
Index = (s[0] * 26^(n-1)) + (s[1] * 26^(n-2)) + ... + (s[n-1] * 26^0)

     7        6        5        4        3        2        1        0
A        A        A        A        A        A        A        A
0*26^7 + 0*26^6 + 0*26^5 + 0*26^4 + 0*26^3 + 0*26^2 + 0*26^1 + 0*26^0 = 0

      7         6         5         4         3         2         1         0
 Z         Z         Z         Z         Z         Z         Z         Z
25*26^7 + 25*26^6 + 25*26^5 + 25*26^4 + 25*26^3 + 25*26^2 + 25*26^1 + 25*26^0 = 208 827 064 575

26 ^ 8 = 208 827 064 576


индекс вычисляется по схеме "умножь на основание и прибавь новый разряд", 
что эквивалентно позиционной системе счисления.
На каждом шаге цикла текущее значение index умножается на 26 и добавляется следующий "разряд". 
Это эквивалентно возведению в степень для каждого разряда, но реализовано более эффективно.

Почему это работает
- Первый символ становится самым старшим разрядом.
- При добавлении нового символа, предыдущее значение "сдвигается" на один разряд (умножение на 26).
- В конце цикла получается то же самое, как если бы вы вручную считали сумму с возведением в степень.

Пример по шагам для "XYZ"
index = 0
'X' (23): index = 0 * 26 + 23 = 23
'Y' (24): index = 23 * 26 + 24 = 622
'Z' (25): index = 622 * 26 + 25 = 16197

как это работает на примере десятичной системы счисления
Пошагово для "1234":

index = 0

Первый символ: '1' → 1
index = 0 * 10 + 1 = 1

Второй символ: '2' → 2
index = 1 * 10 + 2 = 12

Третий символ: '3' → 3
index = 12 * 10 + 3 = 123

Четвертый символ: '4' → 4
index = 123 * 10 + 4 = 1234

*/
long long ORD(char const* name)
{
    // Long long signed integer type. 
    // Capable of containing at least the [−9 223 372 036 854 775 807, +9 223 372 036 854 775 807] range.

    long long index = 0;
    for (int i = 0; i < LEN; i++) {
        int digit = toupper(name[i]) - 'A'; // 'A' = 0, ... 'Z' = 25
        //printf("char = %c, digit = %d\n", name[i], digit);
        
        //index += digit * pow(26, LEN - i - 1);
        index = index * 26 + digit;
    }

    return index;
}

// длина строки для фиксированного алфавита и числа
int len(long long num, int base)
{
    int length = 0;
    long long tmp = num;
    do {
        length++;
        tmp /= base;
    } while (tmp > 0);
    return length;
}

void chr(char* name, long long idx)
{
    int n = len(idx, 26);
    // Строить строку с конца (так как первый остаток — младший разряд).
    for (int i = n - 1; i >= 0; i--) {
        name[i] = 'A' + (idx % 26);
        idx /= 26;
    }
    str[n] = '\0'; // не забываем про терминальный ноль
}

// отношение порядка
int cmp(char const* name1, char const* name2)
{
    long long n1 = ORD(name1);
    long long n2 = ORD(name2);
    if (n1 < n2)
        return -1;  // < 0
    else if (n1 > n2)
        return 1;  // > 0
    else
        return 0;
}

int hash(char const* name)
{
    int idx = ORD(name) % SIZE;
    return idx;
}

void insert(char const* name)
{
    int idx = hash(name);
    printf("Insert: '%s' Index: %d\n", name, idx);
    strncpy(g_array[idx].name, name, LEN);
}

int extract(char const* name)
{
    int idx = hash(name);
    
    if (strcmp(g_people[idx].name, name) != 0) {
        // пробы
    }

    return -1; // Не найден
}

void test_search()
{
    int idx = search("Bonnie");
    if (idx != -1) {
        printf("Index: %d\n", idx);
        printf("Name: %s\n", g_people[idx].name);
    } else {
        printf("Name not found\n");
    }
}

void test_insert()
{
    for (int i = 0; i < 16; i++) {
        insert(g_people[i].name);
    }
}

void test_extract()
{
    for (int i = 0; i < 16; i++) {
        int idx = hash(g_people[i].name);
        printf("Extract: '%s' Index: %d\n", g_people[i].name, idx);
    }
}

int main()
{
    test_insert();
    test_extract();
    return 0;
}