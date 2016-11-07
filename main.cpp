//
//  main.cpp
//  链表3
//
//  Created by s20151104710 on 16/10/17.
//  Copyright © 2016年 s20151104710. All rights reserved.
//

#include<stdio.h>
#define N 5
struct Node
{
    char name[50];
    int age;
    struct Node *next;
};
int main()
{
    struct Node * head;
    struct Node a={"aaaaa",20,NULL},b={"bbbbb",21,NULL},c={"ccccc",22,NULL};
    head=&a;
    a.next=&b;
    b.next=&c;
    return 0;
}