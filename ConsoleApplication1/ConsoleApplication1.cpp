#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct list
{
    list* next = NULL;
    list* prev = NULL;
    char elem = ' ';
    int write = 1;
};

void clean(list* s)
{
    list* k = s->next;
    for (; k; k = k->next)
    {
        delete s;
        s = k;
    }
    delete s;
}


void check(list* n)
{
    while (n->elem != '.')
    {
        if (n->write == 1) 
        {
        printf("%c", n->elem);
        }
        if (n->write == 2)
        {
            printf(" ");
        }
        n = n->next;
    };
    printf("\n");
}


int input(char* fname, list** start)
{
    FILE* file1; 
    list* t, *n;
    char c = ' ';
    fopen_s(&file1, fname, "r");

    if (!file1) //существование файла чеееееек
    {
        fclose(file1);
        return 1;
    }
     
    *start = new list;
    n = *start;
    c = fgetc(file1);
    n->elem = c;
    while(c != '.')
    {
        t = new list;
        t->prev = n;
        n->next = t;
        n = n->next;
        c = fgetc(file1);
        n->elem = c;
    }
    fclose(file1);
    return 0;
}

void mark(list* start, list* stop)
{
     while (start->next != stop->next)
     {
        stop->write = 0;
        stop = stop->prev;
     }
     stop->write = 0;
}

list find_word_begin(list* t)
{
    list* s = t->prev;
    while ((s->elem != ',') && (s->prev != NULL))
    {
        s = s->prev;
    }
    if (s->prev == NULL)
    {
        return *s;
    }
    return *s->next;
}

void save(list* start)
{
    FILE* file2;
    fopen_s(&file2, "output.txt", "w");

    while (start->elem != '.')
    {
        if (start->write == 1)
        {
            fprintf(file2, "%c", start->elem);
        }
        if (start->write == 2)
        {
            fprintf(file2, "%c", ' ');
        }
        start = start->next;
    };
    fclose(file2);
}

void find_max_world(list* start)
{
    int max = -1, amount_letters_now = 0; //переменные хранящие значение длины прошлого и нынешнего слов
    list* n = start;
    list* a = start;
    list* nowworld = new list;

     while (n->next != NULL)
     {
         
        if (n->elem == ',')
        {
            n->write = 2;
            *nowworld = find_word_begin(n);
            if (amount_letters_now > max)
            {
                mark(a, nowworld);
                list* a = nowworld;
                max = amount_letters_now;
            }
            if (amount_letters_now < max)
            {
                mark(nowworld, n);
            }
            amount_letters_now = 0;
        }
        else
        {
            amount_letters_now++;
        }
        n = n->next;

     }
     n->write = 2;
     *nowworld = find_word_begin(n);
     if (amount_letters_now > max)
     {
         mark(a, nowworld);
         list* a = nowworld;
         max = amount_letters_now;
     }
     if (amount_letters_now < max)
     {
         mark(nowworld, n);
     }
}

int main()
{
    list* start;
    char fname[] = "input.txt";
    int c;  
    c = input(fname, &start);
    if (c) {
        printf("0");
        return -1;
    }
    find_max_world(start);
    save(start);
    //check(start);
    clean(start);
    return 0;
};
