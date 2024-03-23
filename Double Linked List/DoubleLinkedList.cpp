#include "DoubleLinkedList.h"

void initList(FirstLast *Edge)
{
    Edge->first = NULL;
    Edge->last = NULL;
}

void CreateDoubleLinkedList(FirstLast *Edge, int insertValue)
{
    DataList *newNode = (DataList *)malloc(sizeof(DataList));
    if (newNode == NULL)
    {
        printf("alokasi memori gagal");
        return;
    }
    newNode->data = insertValue;
    newNode->prev = NULL;
    newNode->next = NULL;
    Edge->first = newNode;
    Edge->last = newNode;
}

void insertAwal(FirstLast *Edge, int insertValue)
{
    if (getJmlData(Edge) == 0)
    {
        CreateDoubleLinkedList(Edge, insertValue);
    }
    else
    {
        DataList *newNode = (DataList *)malloc(sizeof(DataList));
        if (newNode == NULL)
        {
            printf("alokasi memori gagal");
            return;
        }
        newNode->data = insertValue;
        newNode->next = Edge->first;
        Edge->first->prev = newNode;
        Edge->first = newNode;
        newNode->prev = NULL;
    }
}

void insertTengah(FirstLast *Edge, int insertValue, int insertPosition)
{
    if (insertPosition <= 0 || insertPosition > getJmlData(Edge) + 1)
    {
        printf("Posisi tidak valid.\n");
        printf("tekan tombol apapun untuk kembali...\n");
        getch();
    }
    else
    {
        DataList *newNode = (DataList *)malloc(sizeof(DataList));
        if (newNode == NULL)
        {
            printf("alokasi memori gagal");
            return;
        }
        newNode->data = insertValue;

        if (insertPosition == 1)
        {
            insertAwal(Edge, insertValue);
        }
        else
        {
            DataList *current = Edge->first;
            int currentPosition = 1;
            while (currentPosition < insertPosition - 1)
            {
                current = current->next;
                currentPosition++;
            }
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != NULL)
            {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }
}

void insertAkhir(FirstLast *Edge, int insertValue)
{
    if (getJmlData(Edge) == 0)
    {
        CreateDoubleLinkedList(Edge, insertValue);
    }
    else
    {
        DataList *newNode = (DataList *)malloc(sizeof(DataList));
        if (newNode == NULL)
        {
            printf("alokasi memori gagal");
            return;
        }
        newNode->data = insertValue;
        newNode->next = NULL;
        Edge->last->next = newNode;
        newNode->prev = Edge->last;
        Edge->last = newNode;
    }
}

void deleteAwal(FirstLast *Edge)
{
    if (getJmlData(Edge) == 0)
    {
        printf("data tidak ditemukan, lakukan Insert Data !!");
    }
    else if (getJmlData(Edge) == 1)
    {
        free(Edge->first);
        Edge->first = NULL;
        Edge->last = NULL;
    }
    else
    {
        DataList *temp = Edge->first;
        Edge->first = Edge->first->next;
        Edge->first->prev = NULL;
        free(temp);
    }
}

void deleteAkhir(FirstLast *Edge)
{
    if (getJmlData(Edge) == 0)
    {
        printf("data tidak ditemukan, lakukan Insert Data !!");
    }
    else if (getJmlData(Edge) == 1)
    {
        free(Edge->last);
        Edge->first = NULL;
        Edge->last = NULL;
    }
    else
    {
        DataList *temp = Edge->last;
        Edge->last = Edge->last->prev;
        Edge->last->next = NULL;
        free(temp);
    }
}

void deleteTengah(FirstLast *Edge, int deletePosition)
{
    if (getJmlData(Edge) == 0)
    {
        printf("data tidak ditemukan, lakukan Insert Data !!");
    }
    else if (deletePosition <= 0 || deletePosition > getJmlData(Edge))
    {
        printf("Posisi tidak valid.\n");
        printf("tekan tombol apapun untuk kembali...\n");
        getch();
    }
    else
    {
        if (deletePosition == 1)
        {
            deleteAwal(Edge);
        }
        else if (deletePosition == getJmlData(Edge))
        {
            deleteAkhir(Edge);
        }
        else
        {
            DataList *beforeDelete, *temp, *current;
            int currentPosition = 1;
            current = Edge->first;
            while (currentPosition <= deletePosition)
            {
                if (currentPosition == deletePosition - 1)
                {
                    beforeDelete = current;
                }
                if (currentPosition == deletePosition)
                {
                    temp = current;
                }

                current = current->next;
                currentPosition++;
            }
            beforeDelete->next = current;
            current->prev = beforeDelete;
            free(temp);
        }
    }
}

void updateAwal(FirstLast *Edge, int updateValue)
{
    if (getJmlData(Edge) == 0)
    {
        printf("data tidak ditemukan, lakukan Insert Data !!");
    }
    else
    {
        Edge->first->data = updateValue;
    }
}

void updateAkhir(FirstLast *Edge, int updateValue)
{
    if (getJmlData(Edge) == 0)
    {
        printf("data tidak ditemukan, lakukan Insert Data !!");
    }
    else
    {
        Edge->last->data = updateValue;
    }
}

void updateTengah(FirstLast *Edge, int updateValue, int updatePosition)
{
    if (getJmlData(Edge) == 0)
    {
        printf("data tidak ditemukan, lakukan Insert Data !!");
    }
    else if (updatePosition <= 0 || updatePosition > getJmlData(Edge))
    {
        printf("Posisi tidak valid.\n");
        printf("tekan tombol apapun untuk kembali...\n");
        getch();
    }
    else if (updatePosition == 1)
    {
        updateAwal(Edge,updateValue);
    }
    else if (updatePosition == getJmlData(Edge))
    {
        updateAkhir(Edge,updateValue);
    }
    else
    {
        int currentPosition = 1;
        DataList *current = Edge->first;
        while (currentPosition < updatePosition)
        {
            current = current->next;
            currentPosition++;
        }
        current->data = updateValue;
    }
}

int getJmlData(FirstLast *Edge)
{
    int jmlData = 0;
    DataList *current = Edge->first;
    while (current != NULL)
    {
        current = current->next;
        jmlData++;
    }
    return jmlData;
}

void printList(FirstLast *Edge)
{
    if (getJmlData(Edge) == 0)
    {
        system("cls");
        printf("data linked list saat ini :\n\n");
        printf("data tidak ditemukan, lakukan Insert Data !!\n");
        printf("tekan tombol apapun untuk kembali...\n");
        getch();
    }
    else
    {
        system("cls");
        DataList *current = Edge->first;
        printf("data linked list saat ini :\n");
        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("\n\ntekan tombol apapun untuk kembali...\n");
        getch();
    }
}

void printInvertedList(FirstLast *Edge)
{
    if (getJmlData(Edge) == 0)
    {
        system("cls");
        printf("data linked list saat ini :\n\n");
        printf("data tidak ditemukan, lakukan Insert Data !!\n");
        printf("tekan tombol apapun untuk kembali...\n");
        getch();
    }
    else
    {
        system("cls");
        DataList *current = Edge->last;
        printf("data linked list saat ini :\n");
        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->prev;
        }
        printf("\ntekan tombol apapun untuk kembali...\n");
        getch();
    }
}