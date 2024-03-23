#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct DataList{
    int data;
    DataList *next;
    DataList *prev;
} DataList;

typedef struct FirstLast{
    DataList *first;
    DataList *last;
} FirstLast;

void initList(FirstLast *Edge);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Menginisialisasi pointer first dan last menjadi NULL, yang artinya belum ada data sama sekali
*/

void createDoubleLinkedList(FirstLast *Edge, int insertValue);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Membuat Double Linked List (pointer first dan last menunjuk node yang sama)
*/

void insertAwal(FirstLast *Edge, int insertValue);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Menginput data di awal list
*/

void insertTengah(FirstLast *Edge, int insertValue, int insertPosition);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Menginput data di tengah list (berdasarkan posisi yang diinginkan user)
*/

void insertAkhir(FirstLast *Edge, int insertValue);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Menginput data di akhir list
*/

void printList(FirstLast *Edge);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Menampilkan seluruh data dalam list ke layar
*/

void printInvertedList(FirstLast *Edge);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Menampilkan seluruh data dalam list ke layar (dimulai dari data terakhir sampai data pertama)
*/

int getJmlData(FirstLast *Edge);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Fungsi   : Mendapatkan banyaknya data dalam list
*/

void deleteAwal(FirstLast *Edge);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Menghapus data di awal list
*/

void deleteTengah(FirstLast *Edge, int deletePosition);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Menghapus data di tengah list (berdasarkan posisi yang diinginkan user)
*/

void deleteAkhir(FirstLast *Edge);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Menghapus data di akhir list
*/

void updateAwal(FirstLast *Edge, int updateValue);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Mengubah data di awal list
*/

void updateAkhir(FirstLast *Edge, int updateValue);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Mengubah data di akhir list
*/

void updateTengah(FirstLast *Edge, int updateValue, int updatePosition);
/*
    Penulis         : Satria Permata Sejati
    Tujuan Prosedur : Mengubah data di tengah list (berdasarkan posisi yang diinginkan user)
*/