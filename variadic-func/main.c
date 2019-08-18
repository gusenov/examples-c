#include <stdlib.h>
#include <stdio.h>

#include <stdarg.h>
// Прежде использовался varargs.h, который был объявлен устаревшим.

// Эта функция позволяет вычислить среднее значение от произвольного количества
// аргументов:
double average(int count, ...) {

    va_list ap;  // stdarg.h объявляет тип va_list.

    int j;
    double sum = 0;

    // Требуется последний известный аргумент
    // (чтобы получить адрес первого неизвестного):
    va_start(ap, count);
    // va_start принимает два аргумента, объект va_list  и ссылку на последний
    // параметр функции (тот, что перед многоточием). Она инициализирует va_list
    // объект для использования в va_arg или va_copy. Компилятор обычно выдает
    // предупреждение, если ссылка неверная (например, ссылка на параметры,
    // отличающиеся от последнего, или ссылка на совершенно другой объект).

    for (j = 0; j < count; j++) {  // число параметров передается в первом аргументе.

        // Увеличивает ap до следующего аргумента:
        sum += va_arg(ap, double);  // функция ожидает, что типы будут double.
        // va_arg принимает два аргумента, va_list объект (ранее
        // инициализированный) и дескриптор типа. Он расширяется на следующей
        // переменной аргумент, и имеет указанный тип. Каждый следующий вызов
        // возвращает следующий аргумент.
    }

    // va_end принимает один аргумент типа va_list и очищает его:
    va_end(ap);
    // Если вы хотели, например, сканировать переменное число аргументов более
    // чем один раз, вам надо будет повторно инициализировать va_list путём
    // вызова va_end и затем va_start.

    return sum / count;
}

// В других случаях, например для функции printf(), число и типы аргументов
// выясняются из строки формата.

//---------------------------------------------------------------------------

void Print(const char *arg, ...) {
    va_list arguments;
    for (va_start(arguments, arg); arg != NULL; arg = va_arg(arguments, const char *)) {
        printf("%s", arg);
    }
    va_end(arguments);
}

#define mPrint(...) Print(__VA_ARGS__, NULL)

//---------------------------------------------------------------------------

int main(int argc, const char * argv[]) {
    printf("---------------------------------------------------------------------------\n");

    printf("Ср. знач. 1 + 2 + 3 = %f\n", average(3,  1., 2., 3.));  // Ср. знач. 1 + 2 + 3 = 2.000000
                                                     // тип должен точно
                                                     // соответствовать тому,
                                                     // что указан в va_arg.

    printf("---------------------------------------------------------------------------\n");

    Print("foo", "bar", NULL);  // foobar
    printf("\n");
    mPrint("fooo", "bar");  // fooobar

    printf("\n---------------------------------------------------------------------------\n");

    return EXIT_SUCCESS;
}