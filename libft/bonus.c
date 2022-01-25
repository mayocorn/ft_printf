/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 07:15:26 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/15 00:20:45 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

void convprint(void *content)
{
	memset(content,'a',1);
	printf("[%p] : [%c]\n",content,*(char *)content);
}
void *tolower2(void *content)
{
	char *res=(char *)malloc(sizeof(char));
	*res=(*(char *)content)+('a'-'A');
	return (res);
}
int	main(int argc, const char *argv[]){
	if(argc != 2){
		printf("%s\n","invalid arguments\nUSAGE: ./a.out [(without ft_)function name]");
		return 0;
	}
	if(!strcmp(argv[1],"lstnew")){
		int *n=(int *)malloc(sizeof(int));
		*n=42;
		t_list *tl=ft_lstnew(n);
		puts("*n=42;");
		puts("tl=ft_lstnew(n);");
		printf("*(int *)tl->content : (%%d)[%d]\n",*(int *)tl->content);
		printf("tl->next : (%%p)[%p]\n",tl->next);
		free(n);
		free(tl);
	}
	if(!strcmp(argv[1],"lstadd_front")){
		int *a=(int *)malloc(sizeof(int));
		int *b=(int *)malloc(sizeof(int));
		*a=0,*b=1;
		t_list *tl1=ft_lstnew(a);
		t_list *tl2=ft_lstnew(b);
		t_list **lst=(t_list **)malloc(sizeof(t_list *));
		*lst=tl1;
		printf("*a=0,*b=1;\n");
		printf("t_list *tl1=ft_lstnew(a);\n");
		printf("t_list *tl2=ft_lstnew(b);\n");
		printf("*lst=tl1;\n");
		printf("*lst : adr[%p],val[%d]\n",*lst,*(int *)(*lst)->content);
		ft_lstadd_front(lst,tl2);
		printf("ft_lstadd_front(lst,tl2);\n");
		printf("*lst : adr[%p],val[%d]\n",*lst,*(int *)(*lst)->content);
		free(a);
		free(b);
		free(tl1);
		free(tl2);
		free(lst);
	}
	if(!strcmp(argv[1],"lstsize")){
		t_list *tl;
		t_list **lst=(t_list **)malloc(1*sizeof(t_list *));
		*lst=0;
		puts("---create a new element -> add at the beginning -> count the list size---");
		printf("[START] ft_lstsize(*lst) : [%d]\n", ft_lstsize(*lst));
		for(int i=0;i<8;i++){
			tl=ft_lstnew(malloc(1));
			ft_lstadd_front(lst,tl);
			printf("ft_lstsize(*lst) : [%d]\n", ft_lstsize(*lst));
		}
	}
	if(!strcmp(argv[1],"lstlast")){
		t_list *tl;
		t_list **lst=(t_list **)malloc(1*sizeof(t_list *));
		*lst=0;
		puts("---create a new element -> add at the end -> check---");
		for(int i=0;i<8;i++){
			tl=ft_lstnew(malloc(1));
			ft_lstadd_back(lst,tl);
			printf("ft_lstlast(*lst) : [%p]\n",ft_lstlast(*lst));
		}
	}
	if(!strcmp(argv[1],"lstadd_back")){
		t_list *tl;
		t_list **lst=(t_list **)malloc(1*sizeof(t_list *));
		*lst=0;
		puts("---create a new element -> add at the end -> check---");
		for(int i=0;i<8;i++){
			tl=ft_lstnew(malloc(1));
			ft_lstadd_back(lst,tl);
			printf("size : [%d] lastadr : [%p]\n",ft_lstsize(*lst),ft_lstlast(*lst));
		}
	}
	if(!strcmp(argv[1],"lstdelone")){
		t_list *tl=ft_lstnew(malloc(1));
		memset(tl->content,'a',1);
		printf("%p\n",(char *)tl->content);
		ft_lstdelone(tl,free);
		// printf("%p\n",(char *)tl->content);
	}
	if(!strcmp(argv[1],"lstclear")){
		t_list **lst=(t_list **)malloc(1*sizeof(t_list *));
		puts("---create a new element -> add at the end -> check---");
		*lst=0;
		for(int i=0;i<8;i++){
			t_list *tl=ft_lstnew(malloc(1));
			ft_lstadd_back(lst,tl);
		}
		ft_lstclear(lst,free);
		free(lst);
	}
	if(!strcmp(argv[1],"lstiter")){
		t_list **lst=(t_list **)malloc(1*sizeof(t_list *));
		*lst=0;
		puts("---create a new element -> add at the end -> check---");
		for(int i=0;i<8;i++){
			t_list *tl=ft_lstnew(malloc(1));
			*(char *)tl->content='A';
			ft_lstadd_back(lst,tl);
			printf("*(char *)tl->content : [%c]\n",*(char *)tl->content);
		}
		printf("ft_lstiter(*lst,convert)\n");
		ft_lstiter(*lst,convprint);
		ft_lstclear(lst,free);
		free(lst);
	}
	if(!strcmp(argv[1],"lstmap")){
		t_list **lst=(t_list **)malloc(1*sizeof(t_list *));
		*lst=0;
		puts("---create a new element -> add at the end---");
		for(int i=0;i<8;i++){
			t_list *tl=ft_lstnew(malloc(1));
			*(char *)tl->content='A'+i;
			ft_lstadd_back(lst,tl);
			printf("*(char *)tl->content : [%c]\n",*(char *)tl->content);
		}
		t_list *tl2=ft_lstmap(*lst,tolower2,free);
		t_list *tl2_head=tl2;
		while(tl2){
			printf("*(char *)tl2->content : [%c]\n",*(char *)tl2->content);
			tl2=tl2->next;
		}
		ft_lstclear(lst,free);
		ft_lstclear(&tl2_head,free);
		free(lst);
		free(tl2_head);
	}
	return 0;
}