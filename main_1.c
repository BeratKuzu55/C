#include <stdio.h>
#include <stdlib.h>



typedef struct node
{

    int data;
    struct node* link;

}node;


node* create_node(int data)
{

    node* yeni_node;
    yeni_node = (node*)malloc(sizeof(node));
    yeni_node->data = data;
    yeni_node->link = NULL;
    return yeni_node;

}






void odev1 ()
{
    node* node1 = create_node(1);
    node* node2 = create_node(2);
    node* node3 = create_node(3);
    node* node4 = create_node(4);
    node* node5 = create_node(5);
    node* node6 = create_node(6);

    node1->link = node2;
    node2->link = node3;
    node3->link = node4;
    node4->link = node5;
    node5->link = node6;

    int c = node1->link->link->data;
       // printf("%d\n" , c);
    int sonuc = list_lenght(node1);
    printf("%d\n" , sonuc);

}

int list_lenght(node* pHead)
{
    int a = 1;

    if(pHead->link==NULL)
    {

        return a;
    }
    else
    {

        node* yeni_phead = pHead->link;
        a = a + list_lenght(yeni_phead);
    }

        return a;
}


int main()
{
    odev1();
    return 0;
}
