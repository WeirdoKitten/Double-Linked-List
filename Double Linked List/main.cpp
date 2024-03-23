#include "DoubleLinkedList.h"
#include "Menu.h"

int main()
{
    FirstLast Edge;
    initList(&Edge);
    int inputMainMenu, inputPrintMenu, inputInsertMenu, inputDeleteMenu, inputUpdateMenu, inputInsertValue, inputInsertPosition, inputDeletePosition, inputUpdateValue, inputUpdatePosition;
    while (true)
    {
        system("cls");
        showMainMenu();
        scanf("%d", &inputMainMenu);
        switch (inputMainMenu)
        {
        case 1:
            system("cls");
            showPrintMenu();
            scanf("%d", &inputPrintMenu);
            if (inputPrintMenu == 1)
            {
                printList(&Edge);
            }
            else if (inputPrintMenu == 2)
            {
                printInvertedList(&Edge);
            }
            else
            {
                printf("nomor menu tidak valid\n");
                printf("tekan tombol apapun untuk kembali...\n");
                getch();
            }
            break;
        case 2:
            system("cls");
            showInsertMenu();
            scanf("%d", &inputInsertMenu);
            if (inputInsertMenu == 1)
            {
                printf("inputkan nilai yang ingin diinsert :");
                scanf("%d", &inputInsertValue);
                insertAwal(&Edge, inputInsertValue);
                printList(&Edge);
            }
            else if (inputInsertMenu == 2)
            {
                printf("inputkan nilai yang ingin diinsert :");
                scanf("%d", &inputInsertValue);
                printf("inputkan posisi insert :");
                scanf("%d", &inputInsertPosition);
                insertTengah(&Edge, inputInsertValue, inputInsertPosition);
                printList(&Edge);
            }
            else if (inputInsertMenu == 3)
            {
                printf("inputkan nilai yang ingin diinsert :");
                scanf("%d", &inputInsertValue);
                insertAkhir(&Edge, inputInsertValue);
                printList(&Edge);
            }
            else
            {
                printf("nomor menu tidak valid\n");
                printf("tekan tombol apapun untuk kembali...\n");
                getch();
            }
            break;
        case 3:
            system("cls");
            showDeleteMenu();
            scanf("%d", &inputDeleteMenu);
            if (inputDeleteMenu == 1)
            {
                deleteAwal(&Edge);
                printList(&Edge);
            }
            else if (inputDeleteMenu == 2)
            {
                printf("inputkan posisi delete :");
                scanf("%d", &inputDeletePosition);
                deleteTengah(&Edge, inputDeletePosition);
                printList(&Edge);
            }
            else if (inputDeleteMenu == 3)
            {
                deleteAkhir(&Edge);
                printList(&Edge);
            }
            else
            {
                printf("nomor menu tidak valid\n");
                printf("tekan tombol apapun untuk kembali...\n");
                getch();
            }
            break;
        case 4:
            system("cls");
            showUpdateMenu();
            scanf("%d", &inputUpdateMenu);
            if (inputUpdateMenu == 1)
            {
                printf("inputkan nilai baru :");
                scanf("%d", &inputUpdateValue);
                updateAwal(&Edge, inputUpdateValue);
                printList(&Edge);
            }
            else if (inputUpdateMenu == 2)
            {
                printf("inputkan nilai baru :");
                scanf("%d", &inputUpdateValue);
                printf("inputkan posisi update :");
                scanf("%d", &inputUpdatePosition);
                updateTengah(&Edge, inputUpdateValue, inputUpdatePosition);
                printList(&Edge);
            }
            else if (inputUpdateMenu == 3)
            {
                printf("inputkan nilai baru :");
                scanf("%d", &inputUpdateValue);
                updateAkhir(&Edge, inputUpdateValue);
                printList(&Edge);
            }
            else
            {
                printf("nomor menu tidak valid\n");
                printf("tekan tombol apapun untuk kembali...\n");
                getch();
            }
            break;
        case 5:
            exit(false);
        default:
            printf("nomor menu tidak valid\n");
            printf("tekan tombol apapun untuk kembali...\n");
            getch();
            break;
        }
    }
    return 0;
}