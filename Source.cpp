#include <iostream>
using namespace std;
struct Node
{
	int x;
	Node *l, *r;
};
void Show(Node *&Tree)
{
	if (Tree != NULL)
	{
		Show(Tree->l);
		cout << Tree->x;
		Show(Tree->r);
	}
}
void add(int x, Node *&Tree)
{
	if (NULL == Tree)
	{
		Tree = new Node;

	}
	if (x < Tree->x)
	{
		if (Tree->l != NULL) add(x, Tree->l); //При помощи рекурсии заталкиваем элемент на свободный участок
		else                                          //Если элемент получил свой участок, то
		{
			Tree->l = new Node;                      //Выделяем память левому подзвену. Именно подзвену, а не просто звену
			Tree->l->l = Tree->l->r = NULL;        //У левого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
			Tree->l->x = x;                          //Записываем в левое подзвено записываемый элемент
		}
	}
	if (x > Tree->x)
	{
		if (Tree->r != NULL) add(x, Tree->r); //При помощи рекурсии заталкиваем элемент на свободный участок
		else                                          //Если элемент получил свой участок, то
		{
			Tree->r = new Node;                      //Выделяем память левому подзвену. Именно подзвену, а не просто звену
			Tree->r->l= Tree->r->r = NULL;        //У левого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
			Tree->r->x = x;                          //Записываем в левое подзвено записываемый элемент
		}
	}
}
void del(Node *&Tree)
{
	if (Tree != NULL)
	{
		del(Tree->l);
		del(Tree->r);
		delete Tree;
	}
}
int main()
{
	int x = 0;
	int A[20] = { 15,17,24,31,83,23,57,99,77,66,0,37,94,23,74,1,85,2};


	return 0;
}