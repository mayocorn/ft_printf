/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:16:27 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/14 07:15:55 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

char	ft_conv(unsigned int index, char c)
{
	return ('a' + (index + c) % 26);
} 
void ft_conv2(unsigned int index, char *ptr)
{
	*ptr = (index+'a');
	return ;
}
int	main(int argc, const char *argv[]){
	if(argc != 2){
		printf("%s\n","invalid arguments\nUSAGE: ./a.out [(without ft_)function name]");
		return 0;
	}
	if(!strcmp(argv[1],"isalpha")){
		printf("isalpha('a') : %d\n",isalpha('a'));
		printf("ft_isalpha('a') : %d\n",ft_isalpha('a'));
		printf("isalpha('a'-1) : %d\n",isalpha('a'-1));
		printf("ft_isalpha('a'-1) : %d\n",ft_isalpha('a'-1));
		printf("isalpha('a'+1) : %d\n",isalpha('a'+1));
		printf("ft_isalpha('a'+1) : %d\n",ft_isalpha('a'+1));
		printf("isalpha('z') : %d\n",isalpha('z'));
		printf("ft_isalpha('z') : %d\n",ft_isalpha('z'));
		printf("isalpha('z'+1) : %d\n",isalpha('z'+1));
		printf("ft_isalpha('z'+1) : %d\n",ft_isalpha('z'+1));
		printf("isalpha('A') : %d\n",isalpha('A'));
		printf("ft_isalpha('A') : %d\n",ft_isalpha('A'));
		printf("isalpha('A'-1) : %d\n",isalpha('A'-1));
		printf("ft_isalpha('A'-1) : %d\n",ft_isalpha('A'-1));
		printf("isalpha('A'+1) : %d\n",isalpha('A'+1));
		printf("ft_isalpha('A'+1) : %d\n",ft_isalpha('A'+1));
		printf("isalpha('Z') : %d\n",isalpha('Z'));
		printf("ft_isalpha('Z') : %d\n",ft_isalpha('Z'));
		printf("isalpha('Z'+1) : %d\n",isalpha('Z'+1));
		printf("ft_isalpha('Z'+1) : %d\n",ft_isalpha('Z'+1));
		printf("isalpha(65) : %d\n",isalpha(65));
		printf("ft_isalpha(65) : %d\n",ft_isalpha(65));
		printf("isalpha(-1) : %d\n",isalpha(-1));
		printf("ft_isalpha(-1) : %d\n",ft_isalpha(-1));
		printf("isalpha(200) : %d\n",isalpha(200));
		printf("ft_isalpha(200) : %d\n",ft_isalpha(200));
	}
	if(!strcmp(argv[1],"isdigit")){
		printf("isdigit('0') : %d\n",isdigit('0'));
		printf("ft_isdigit('0') : %d\n",ft_isdigit('0'));
		printf("isdigit('1') : %d\n",isdigit('1'));
		printf("ft_isdigit('1') : %d\n",ft_isdigit('1'));
		printf("isdigit('9') : %d\n",isdigit('9'));
		printf("ft_isdigit('9') : %d\n",ft_isdigit('9'));
		printf("isdigit(47) : %d\n",isdigit(47));
		printf("ft_isdigit(47) : %d\n",ft_isdigit(47));
		printf("isdigit(48) : %d\n",isdigit(48));
		printf("ft_isdigit(48) : %d\n",ft_isdigit(48));
		printf("isdigit(57) : %d\n",isdigit(57));
		printf("ft_isdigit(57) : %d\n",ft_isdigit(57));
		printf("isdigit(58) : %d\n",isdigit(58));
		printf("ft_isdigit(58) : %d\n",ft_isdigit(58));
	}
	if(!strcmp(argv[1],"isalnum")){
		printf("isalnum('a') : %d\n",isalnum('a'));
		printf("ft_isalnum('a') : %d\n",ft_isalnum('a'));
		printf("isalnum('a'-1) : %d\n",isalnum('a'-1));
		printf("ft_isalnum('a'-1) : %d\n",ft_isalnum('a'-1));
		printf("isalnum('a'+1) : %d\n",isalnum('a'+1));
		printf("ft_isalnum('a'+1) : %d\n",ft_isalnum('a'+1));
		printf("isalnum('z') : %d\n",isalnum('z'));
		printf("ft_isalnum('z') : %d\n",ft_isalnum('z'));
		printf("isalnum('z'+1) : %d\n",isalnum('z'+1));
		printf("ft_isalnum('z'+1) : %d\n",ft_isalnum('z'+1));
		printf("isalnum('A') : %d\n",isalnum('A'));
		printf("ft_isalnum('A') : %d\n",ft_isalnum('A'));
		printf("isalnum('A'-1) : %d\n",isalnum('A'-1));
		printf("ft_isalnum('A'-1) : %d\n",ft_isalnum('A'-1));
		printf("isalnum('A'+1) : %d\n",isalnum('A'+1));
		printf("ft_isalnum('A'+1) : %d\n",ft_isalnum('A'+1));
		printf("isalnum('Z') : %d\n",isalnum('Z'));
		printf("ft_isalnum('Z') : %d\n",ft_isalnum('Z'));
		printf("isalnum('Z'+1) : %d\n",isalnum('Z'+1));
		printf("ft_isalnum('Z'+1) : %d\n",ft_isalnum('Z'+1));
		printf("isalnum(65) : %d\n",isalnum(65));
		printf("ft_isalnum(65) : %d\n",ft_isalnum(65));
		printf("isalnum(-1) : %d\n",isalnum(-1));
		printf("ft_isalnum(-1) : %d\n",ft_isalnum(-1));
		printf("isalnum(200) : %d\n",isalnum(200));
		printf("ft_isalnum(200) : %d\n",ft_isalnum(200));
		printf("isalnum('0') : %d\n",isalnum('0'));
		printf("ft_isalnum('0') : %d\n",ft_isalnum('0'));
		printf("isalnum('1') : %d\n",isalnum('1'));
		printf("ft_isalnum('1') : %d\n",ft_isalnum('1'));
		printf("isalnum('9') : %d\n",isalnum('9'));
		printf("ft_isalnum('9') : %d\n",ft_isalnum('9'));
		printf("isalnum(47) : %d\n",isalnum(47));
		printf("ft_isalnum(47) : %d\n",ft_isalnum(47));
		printf("isalnum(48) : %d\n",isalnum(48));
		printf("ft_isalnum(48) : %d\n",ft_isalnum(48));
		printf("isalnum(57) : %d\n",isalnum(57));
		printf("ft_isalnum(57) : %d\n",ft_isalnum(57));
		printf("isalnum(58) : %d\n",isalnum(58));
		printf("ft_isalnum(58) : %d\n",ft_isalnum(58));	
	}
	if(!strcmp(argv[1],"isascii")){
		printf("isascii(-1) : %d\n",isascii(-1));
		printf("ft_isascii(-1) : %d\n",ft_isascii(-1));
		printf("isascii(0) : %d\n",isascii(0));
		printf("ft_isascii(0) : %d\n",ft_isascii(0));
		printf("isascii(1) : %d\n",isascii(1));
		printf("ft_isascii(1) : %d\n",ft_isascii(1));
		printf("isascii(126) : %d\n",isascii(126));
		printf("ft_isascii(126) : %d\n",ft_isascii(126));
		printf("isascii(127) : %d\n",isascii(127));
		printf("ft_isascii(127) : %d\n",ft_isascii(127));
		printf("isascii(128) : %d\n",isascii(128));
		printf("ft_isascii(128) : %d\n",ft_isascii(128));
	}
	if(!strcmp(argv[1],"isprint")){
		printf("isprint(31) : %d\n",isprint(31));
		printf("ft_isprint(31) : %d\n",ft_isprint(31));
		printf("isprint(32) : %d\n",isprint(32));
		printf("ft_isprint(32) : %d\n",ft_isprint(32));
		printf("isprint(126) : %d\n",isprint(126));
		printf("ft_isprint(126) : %d\n",ft_isprint(126));
		printf("isprint(127) : %d\n",isprint(127));
		printf("ft_isprint(127) : %d\n",ft_isprint(127));
		printf("isprint(' ') : %d\n",isprint(' '));
		printf("ft_isprint(' ') : %d\n",ft_isprint(' '));
		printf("isprint('~') : %d\n",isprint('~'));
		printf("ft_isprint('~') : %d\n",ft_isprint('~'));
		printf("isprint('\\n') : %d\n",isprint('\n'));
		printf("ft_isprint('\\n') : %d\n",ft_isprint('\n'));
	}
	if(!strcmp(argv[1],"strlen")){
		const char s[]="HELLO";
		printf("strlen(\"HELLO\") : %zu\n",strlen("HELLO"));
		printf("ft_strlen(\"HELLO\") : %zu\n",ft_strlen("HELLO"));
		printf("strlen(\"HELLO, WORLD!\\n\") : %zu\n",strlen("HELLO, WORLD!\n"));
		printf("ft_strlen(\"HELLO, WORLD!\\n\") : %zu\n",ft_strlen("HELLO, WORLD!\n"));
		printf("strlen(\"\") : %zu\n",strlen(""));
		printf("ft_strlen(\"\") : %zu\n",ft_strlen(""));
		printf("-----const char s[]=\"HELLO\";-----");
		printf("strlen(s) : %zu\n",strlen(s));
		printf("ft_strlen(s) : %zu\n",ft_strlen(s));
	}
	if(!strcmp(argv[1],"memset")){
		char str1[6]="abcde";
		char str2[6]="abcde";
		puts("**************** str1,str2 = \"abcde\" ****************");
		printf("memset(str1,'A',3) : str1 = %s\n",(unsigned char *)memset(str1,'A',3));
		printf("ft_memset(str2,'A',3) : str2 = %s\n",(unsigned char *)ft_memset(str2,'A',3));
		// strcpy(str1,"abcde");
		// strcpy(str2,"abcde");
		// puts("**************** str1,str2 = \"abcde\" ****************");
		// printf("memset(str1,'A',0) : str1 = %s\n",(unsigned char *)memset(str1,'A',0));
		// printf("ft_memset(str2,'A',0) : str2 = %s\n",(unsigned char *)ft_memset(str2,'A',0));
		strcpy(str1,"abcde");
		strcpy(str2,"abcde");
		puts("**************** str1,str2 = \"abcde\" ****************");
		printf("memset(str1,-190,4) : str1 = %s\n",(unsigned char *)memset(str1,-190,4));
		printf("ft_memset(str2,-190,4) : str2 = %s\n",(unsigned char *)ft_memset(str2,-190,4));
		strcpy(str1,"abcde");
		strcpy(str2,"abcde");
		puts("**************** str1,str2 = \"abcde\" ****************");
		printf("memset(str1,'A'+256,3) : str1 = %s\n",(unsigned char *)memset(str1,'A'+256,4));
		printf("ft_memset(str2,'A'+256,3) : str2 = %s\n",(unsigned char *)ft_memset(str2,'A'+256,4));
		//SEGV
		//printf("memset(0,'A',3) : %s\n",(unsigned char *)memset(0,'A',3));
		//printf("ft_memset(0,'A',3) : %s\n",(unsigned char *)ft_memset(0,'A',3));
		//strcpy(str1,"abcde");
		//strcpy(str2,"abcde");
		// UNDEFINED
		//puts("**************** str1,str2 = \"abcde\" ****************");
		//printf("memset(str1,'A',6) : str1 = %s\n",(unsigned char *)memset(str1,'A',6));
		//printf("ft_memset(str2,'A',6) : str2 = %s\n",(unsigned char *)ft_memset(str2,'A',6));
	}
	if(!strcmp(argv[1],"bzero")){
		char str1[6]="abcde";
		char str2[6]="abcde";
		puts("**************** str1,str2 = \"abcde\" ****************");
		bzero(str1,3);
		ft_bzero(str2,3);
		printf("bzero(str1,3) : str1 = ");
		for(int i=0;i<6;i++)printf("[%c]",str1[i]);
		puts("");
		printf("ft_bzero(str2,3) : str2 = ");
		for(int i=0;i<6;i++)printf("[%c]",str1[i]);
		puts("");
		// strcpy(str1,"abcde");
		// strcpy(str2,"abcde");
		// puts("**************** str1,str2 = \"abcde\" ****************");
		// bzero(str1,0);
		// ft_bzero(str2,0);
		// printf("bzero(str1,0) : str1 = ");
		// for(int i=0;i<6;i++)printf("[%c]",str1[i]);
		// puts("");
		// printf("ft_bzero(str2,0) : str2 = ");
		// for(int i=0;i<6;i++)printf("[%c]",str1[i]);
		// puts("");
	}
	if(!strcmp(argv[1],"memcpy")){
		char str1[6]="abcde";
		char str2[6]="abcde";
		puts("**************** str1,str2 = \"abcde\" ****************");
		printf("memcpy(str1,\"ZZZZZ\",3) : str1 = ");
		memcpy(str1,"ZZZZZ",3);
		for(int i=0;i<6;i++){
			printf("[%c]",str1[i]);
		}
		puts("");
		printf("ft_memcpy(str2,\"ZZZZZ\",3) : str2 = ");
		ft_memcpy(str2,"ZZZZZ",3);
		for(int i=0;i<6;i++){
			printf("[%c]",str2[i]);
		}
		puts("");
		strcpy(str1,"abcde");
		strcpy(str2,"abcde");
		puts("**************** str1,str2 = \"abcde\" ****************");
		printf("memcpy(str1,0,0) : str1 = ");
		memcpy(str1,0,0);
		for(int i=0;i<6;i++){
			printf("[%c]",str1[i]);
		}
		puts("");
		printf("ft_memcpy(str2,0,0) : str2 = ");
		ft_memcpy(str2,0,0);
		for(int i=0;i<6;i++){
			printf("[%c]",str2[i]);
		}
		puts("");
	}
	if(!strcmp(argv[1],"memmove")){
		char str1[6]="abcde";
		char str2[6]="abcde";
		puts("**************** str1,str2 = \"abcde\" ****************");
		printf("memmove(str1,\"ZZZZZ\",3) : str1 = ");
		memmove(str1,"ZZZZZ",3);
		for(int i=0;i<6;i++){
			printf("[%c]",str1[i]);
		}
		puts("");
		printf("ft_memmove(str2,\"ZZZZZ\",3) : str2 = ");
		ft_memmove(str2,"ZZZZZ",3);
		for(int i=0;i<6;i++){
			printf("[%c]",str2[i]);
		}
		puts("");
		strcpy(str1,"abcde");
		strcpy(str2,"abcde");
		puts("**************** str1,str2 = \"abcde\" ****************");
		printf("memmove(str1,str1+1,3) : str1 = ");
		memmove(str1,str1+1,3);
		for(int i=0;i<6;i++){
			printf("[%c]",str1[i]);
		}
		puts("");
		printf("ft_memmove(str2,str2+1,3) : str2 = ");
		ft_memmove(str2,str2+1,3);
		for(int i=0;i<6;i++){
			printf("[%c]",str2[i]);
		}
		puts("");
		strcpy(str1,"abcde");
		strcpy(str2,"abcde");
		puts("**************** str1,str2 = \"abcde\" ****************");
		printf("memmove(str1+1,str1,3) : str1 = ");
		memmove(str1+1,str1,3);
		for(int i=0;i<6;i++){
			printf("[%c]",str1[i]);
		}
		puts("");
		printf("ft_memmove(str2+1,str2,3) : str2 = ");
		ft_memmove(str2+1,str2,3);
		for(int i=0;i<6;i++){
			printf("[%c]",str2[i]);
		}
		puts("");
		strcpy(str1,"abcde");
		strcpy(str2,"abcde");
		puts("**************** str1,str2 = \"abcde\" ****************");
		printf("memmove(str1,0,0) : str1 = ");
		memmove(str1,0,0);
		for(int i=0;i<6;i++){
			printf("[%c]",str1[i]);
		}
		puts("");
		printf("ft_memmove(str2,0,0) : str2 = ");
		ft_memmove(str2,0,0);
		for(int i=0;i<6;i++){
			printf("[%c]",str2[i]);
		}
		puts("");
	}
	if(!strcmp(argv[1],"strlcpy")){
		size_t a,b;
		char str1[6]="abcde";
		char str2[6]="abcde";
		puts("**************** str1,str2 = \"abcde\" ****************");
		printf("strlcpy(str1,\"ZZZZZ\",3) : str1 = ");
		a=strlcpy(str1,"ZZZZZ",3);
		for(int i=0;i<6;i++){
			printf("[%c]",str1[i]);
		}
		puts("");
		printf("return value : %zu\n",a);
		printf("ft_strlcpy(str2,\"ZZZZZ\",3) : str2 = ");
		b=ft_strlcpy(str2,"ZZZZZ",3);
		for(int i=0;i<6;i++){
			printf("[%c]",str2[i]);
		}
		puts("");
		printf("return value : %zu\n",b);
		strcpy(str1,"abcde");
		strcpy(str2,"abcde");
		puts("**************** str1,str2 = \"abcde\" ****************");
		printf("strlcpy(str1,\"Z\",4) : str1 = ");
		a=strlcpy(str1,"Z",4);
		for(int i=0;i<6;i++){
			printf("[%c]",str1[i]);
		}
		puts("");
		printf("return value : %zu\n",a);
		printf("ft_strlcpy(str2,\"Z\",4) : str2 = ");
		b=ft_strlcpy(str2,"Z",4);
		for(int i=0;i<6;i++){
			printf("[%c]",str2[i]);
		}
		puts("");
		printf("return value : %zu\n",b);
		puts("**************** dst = NULL ****************");
		printf("strlcpy(0,\"Z\",0) : ");
		a=strlcpy(0,"Z",0);
		puts("OK");
		printf("return value : %zu\n",a);
		printf("ft_strlcpy(0,\"Z\",0) : ");
		b=ft_strlcpy(0,"Z",0);
		puts("OK");
		printf("return value : %zu\n",b);
	}
	if(!strcmp(argv[1],"strlcat")){
		size_t a,b;
		char str1[6]="abc";
		char str2[6]="abc";
		puts("**************** str1,str2 = [a][b][c][\\0][][] ****************");
		printf("strlcat(str1,\"Z\",6) : str1 = ");
		a=strlcat(str1,"Z",6);
		for(int i=0;i<6;i++)
			printf("[%c]",str1[i]);
		puts("");
		printf("return value : %zu\n",a);
		printf("ft_strlcat(str2,\"Z\",6) : str2 = ");
		b=ft_strlcat(str2,"Z",6);
		for(int i=0;i<6;i++)
			printf("[%c]",str2[i]);
		puts("");
		printf("return value : %zu\n",b);
		bzero(str1+3,3);
		bzero(str2+3,3);
		puts("**************** str1,str2 = [a][b][c][\\0][\\0][\\0] ****************");
		printf("strlcat(str1,\"ZZZZZZZZZZ\",6) : str1 = ");
		a=strlcat(str1,"ZZZZZZZZZZ",6);
		for(int i=0;i<6;i++)
			printf("[%c]",str1[i]);
		puts("");
		printf("return value : %zu\n",a);
		printf("ft_strlcat(str2,\"ZZZZZZZZZZ\",6) : str2 = ");
		b=ft_strlcat(str2,"ZZZZZZZZZZ",6);
		for(int i=0;i<6;i++)
			printf("[%c]",str2[i]);
		puts("");
		printf("return value : %zu\n",b);
		bzero(str1+3,3);
		bzero(str2+3,3);
		puts("**************** str1,str2 = [a][b][c][\\0][\\0][\\0] ****************");
		printf("strlcat(str1,\"ZZ\",2) : str1 = ");
		a=strlcat(str1,"ZZ",2);
		for(int i=0;i<6;i++)
			printf("[%c]",str1[i]);
		puts("");
		printf("return value : %zu\n",a);
		printf("ft_strlcat(str2,\"ZZ\",2) : str2 = ");
		b=ft_strlcat(str2,"ZZ",2);
		for(int i=0;i<6;i++)
			printf("[%c]",str2[i]);
		puts("");
		printf("return value : %zu\n",b);
		puts("**************** dst = NULL ****************");
		printf("strlcat(0,\"Z\",0) : ");
		a=strlcat(0,"Z",0);
		printf("return value : %zu\n",a);
		printf("ft_strlcat(0,\"Z\",0) : ");
		b=ft_strlcat(0,"Z",0);
		printf("return value : %zu\n",b);
	}
	if(!strcmp(argv[1],"toupper")){
		printf("toupper(\'a\') : %c\n",toupper('a'));
		printf("ft_toupper(\'a\') : %c\n",ft_toupper('a'));
		printf("toupper(\'b\') : %c\n",toupper('b'));
		printf("ft_toupper(\'b\') : %c\n",ft_toupper('b'));
		printf("toupper(\'z\') : %c\n",toupper('z'));
		printf("ft_toupper(\'z\') : %c\n",ft_toupper('z'));
		printf("toupper(\'5\') : %c\n",toupper('5'));
		printf("ft_toupper(\'5\') : %c\n",ft_toupper('5'));
		printf("toupper(112) : %c\n",toupper(112));
		printf("ft_toupper(112) : %c\n",ft_toupper(112));
		printf("toupper(112) : (int)%d\n",toupper(112));
		printf("ft_toupper(112) : (int)%d\n",ft_toupper(112));
		printf("toupper('a'+256) : %c\n",toupper('a'+256));
		printf("ft_toupper('a'+256) : %c\n",ft_toupper('a'+256));
	}
	if(!strcmp(argv[1],"tolower")){
		printf("tolower(\'A\') : %c\n",tolower('A'));
		printf("ft_tolower(\'A\') : %c\n",ft_tolower('A'));
		printf("tolower(\'B\') : %c\n",tolower('B'));
		printf("ft_tolower(\'B\') : %c\n",ft_tolower('B'));
		printf("tolower(\'Z\') : %c\n",tolower('Z'));
		printf("ft_tolower(\'Z\') : %c\n",ft_tolower('Z'));
		printf("tolower(\'5\') : %c\n",tolower('5'));
		printf("ft_tolower(\'5\') : %c\n",ft_tolower('5'));
		printf("tolower(80) : %c\n",tolower(80));
		printf("ft_tolower(80) : %c\n",ft_tolower(80));
		printf("tolower(80) : (int)%d\n",tolower(80));
		printf("ft_tolower(80) : (int)%d\n",ft_tolower(80));
		printf("tolower('A'+256) : %c\n",tolower('A'+256));
		printf("ft_tolower('A'+256) : %c\n",ft_tolower('A'+256));
	}
	if(!strcmp(argv[1],"strchr")){
		const char str[]="ABCDABCD";
		puts("**************** str = \"ABCDABCD\" ****************");
		printf("strchr(str,'C') : %p\n",strchr(str,'C'));
		printf("ft_strchr(str,'C') : %p\n",ft_strchr(str,'C'));
		printf("strchr(str,'z') : %p\n",strchr(str,'z'));
		printf("ft_strchr(str,'z') : %p\n",ft_strchr(str,'z'));
		printf("strchr(str,'\\0') : %p\n",strchr(str,'\0'));
		printf("ft_strchr(str,'\\0') : %p\n",ft_strchr(str,'\0'));
		printf("strchr(str,'C'+256) : %p\n",strchr(str,'C'+256));
		printf("ft_strchr(str,'C'+256) : %p\n",ft_strchr(str,'C'+256));
	}
	if(!strcmp(argv[1],"strrchr")){
		const char str[]="ABCDABCD";
		puts("**************** str = \"ABCDABCD\" ****************");
		printf("strrchr(str,'C') : %p\n",strrchr(str,'C'));
		printf("ft_strrchr(str,'C') : %p\n",ft_strrchr(str,'C'));
		printf("strrchr(str,'z') : %p\n",strrchr(str,'z'));
		printf("ft_strrchr(str,'z') : %p\n",ft_strrchr(str,'z'));
		printf("strrchr(str,'\\0') : %p\n",strrchr(str,'\0'));
		printf("ft_strrchr(str,'\\0') : %p\n",ft_strrchr(str,'\0'));
		printf("strrchr(str,'C'+256) : %p\n",strrchr(str,'C'+256));
		printf("ft_strrchr(str,'C'+256) : %p\n",ft_strrchr(str,'C'+256));
	}
	if(!strcmp(argv[1],"strncmp")){
		printf("strncmp(\"ABCDE\",\"ABCDE\",3) : %d\n",strncmp("ABCDE","ABCDE",3));
		printf("ft_strncmp(\"ABCDE\",\"ABCDE\",3) : %d\n",ft_strncmp("ABCDE","ABCDE",3));
		printf("strncmp(\"ABCDE\",\"ABCDE\",8) : %d\n",strncmp("ABCDE","ABCDE",8));
		printf("ft_strncmp(\"ABCDE\",\"ABCDE\",8) : %d\n",ft_strncmp("ABCDE","ABCDE",8));
		printf("strncmp(\"ABCDE\",\"ABCAA\",3) : %d\n",strncmp("ABCAA","ABCDE",3));
		printf("ft_strncmp(\"ABCDE\",\"ABCAA\",3) : %d\n",ft_strncmp("ABCAA","ABCDE",3));
		printf("strncmp(\"ABCDE\",\"AAAAA\",3) : %d\n",strncmp("ABCDE","AAAAA",3));
		printf("ft_strncmp(\"ABCDE\",\"AAAAA\",3) : %d\n",ft_strncmp("ABCDE","AAAAA",3));
		printf("strncmp(\"ABCDE\",\"ZZZZZ\",3) : %d\n",strncmp("ABCDE","ZZZZZ",3));
		printf("ft_strncmp(\"ABCDE\",\"ZZZZZ\",3) : %d\n",ft_strncmp("ABCDE","ZZZZZ",3));
		printf("strncmp(\"ABCDE\",\"ZZZZZ\",0) : %d\n",strncmp("ABCDE","ZZZZZ",0));
		printf("ft_strncmp(\"ABCDE\",\"ZZZZZ\",0) : %d\n",ft_strncmp("ABCDE","ZZZZZ",0));
		printf("strncmp(0,\"ZZZZZ\",0) : %d\n",strncmp(0,"ZZZZZ",0));
		printf("ft_strncmp(0,\"ZZZZZ\",0) : %d\n",ft_strncmp(0,"ZZZZZ",0));
	}
	if(!strcmp(argv[1],"memchr")){
		const char str[]="ABCDABCD";
		puts("**************** str = \"ABCDABCD\" ****************");
		printf("memchr(str,'C',8) : %p\n",memchr(str,'C',8));
		printf("ft_memchr(str,'C',8) : %p\n",ft_memchr(str,'C',8));
		printf("memchr(str,'C',2) : %p\n",memchr(str,'C',2));
		printf("ft_memchr(str,'C',2) : %p\n",ft_memchr(str,'C',2));
		printf("memchr(str,'C',100) : %p\n",memchr(str,'C',100));
		printf("ft_memchr(str,'C',100) : %p\n",ft_memchr(str,'C',100));
		printf("memchr(str,'C',0) : %p\n",memchr(str,'C',0));
		printf("ft_memchr(str,'C',0) : %p\n",ft_memchr(str,'C',0));
		printf("memchr(str,'z',10) : %p\n",memchr(str,'z',10));
		printf("ft_memchr(str,'z',10) : %p\n",ft_memchr(str,'z',10));
		printf("memchr(str,'\\0',10) : %p\n",memchr(str,'\0',10));
		printf("ft_memchr(str,'\\0',10) : %p\n",ft_memchr(str,'\0',10));
		printf("memchr(str,'C'+256,8) : %p\n",memchr(str,'C'+256,8));
		printf("ft_memchr(str,'C'+256,8) : %p\n",ft_memchr(str,'C'+256,8));
		printf("memchr(0,'C',0) : %p\n",memchr(0,'C',0));
		printf("ft_memchr(0,'C',0) : %p\n",ft_memchr(0,'C',0));
	}
	if(!strcmp(argv[1],"memcmp")){
		printf("memcmp(\"ABCDE\",\"ABCDE\",3) : %d\n",memcmp("ABCDE","ABCDE",3));
		printf("ft_memcmp(\"ABCDE\",\"ABCDE\",3) : %d\n",ft_memcmp("ABCDE","ABCDE",3));
		printf("memcmp(\"ABCDE\",\"ABCDE\",8) : %d\n",memcmp("ABCDE","ABCDE",8));
		printf("ft_memcmp(\"ABCDE\",\"ABCDE\",8) : %d\n",ft_memcmp("ABCDE","ABCDE",8));
		printf("memcmp(\"ABCDE\",\"ABCAA\",3) : %d\n",memcmp("ABCAA","ABCDE",3));
		printf("ft_memcmp(\"ABCDE\",\"ABCAA\",3) : %d\n",ft_memcmp("ABCAA","ABCDE",3));
		printf("memcmp(\"ABCDE\",\"AAAAA\",3) : %d\n",memcmp("ABCDE","AAAAA",3));
		printf("ft_memcmp(\"ABCDE\",\"AAAAA\",3) : %d\n",ft_memcmp("ABCDE","AAAAA",3));
		printf("memcmp(\"ABCDE\",\"ZZZZZ\",3) : %d\n",memcmp("ABCDE","ZZZZZ",3));
		printf("ft_memcmp(\"ABCDE\",\"ZZZZZ\",3) : %d\n",ft_memcmp("ABCDE","ZZZZZ",3));
		printf("memcmp(\"ABCDE\",\"ZZZZZ\",0) : %d\n",memcmp("ABCDE","ZZZZZ",0));
		printf("ft_memcmp(\"ABCDE\",\"ZZZZZ\",0) : %d\n",ft_memcmp("ABCDE","ZZZZZ",0));
		printf("memcmp(0,0,0) : %d\n",memcmp(0,0,0));
		printf("ft_memcmp(0,0,0) : %d\n",ft_memcmp(0,0,0));
	}
	if(!strcmp(argv[1],"strnstr")){
		const char str[] ="ABCDABCD";
		const char str2[] ="AAAB";
		puts("**************** str = \"ABCDABCD\" ****************");
		printf("strnstr(str,\"\",10) : %p\n",strnstr(str,"",10));
		printf("ft_strnstr(str,\"\",10) : %p\n",ft_strnstr(str,"",10));
		printf("strnstr(\"\",str,10) : %p\n",strnstr("",str,10));
		printf("ft_strnstr(\"\",str,10) : %p\n",ft_strnstr("",str,10));
		printf("strnstr(str,\"ABCD\",10) : %p\n",strnstr(str,"ABCD",10));
		printf("ft_strnstr(str,\"ABCD\",10) : %p\n",ft_strnstr(str,"ABCD",10));
		printf("strnstr(str,\"ABCD\",3) : %p\n",strnstr(str,"ABCD",3));
		printf("ft_strnstr(str,\"ABCD\",3) : %p\n",ft_strnstr(str,"ABCD",3));
		printf("strnstr(str,\"ABCD\",4) %p\n",strnstr(str,"ABCD",4));
		printf("ft_strnstr(str,\"ABCD\",4) %p\n",ft_strnstr(str,"ABCD",4));
		printf("strnstr(str,\"ZZZZ\",10) %p\n",strnstr(str,"ZZZZ",10));
		printf("ft_strnstr(str,\"ZZZZ\",10) %p\n",ft_strnstr(str,"ZZZZ",10));
		puts("**************** str2 = \"AAAB\" ****************");
		printf("strnstr(str2,\"AAB\",10) %p\n",strnstr(str2,"AAB",10));
		printf("ft_strnstr(str2,\"AAB\",10) %p\n",ft_strnstr(str2,"AAB",10));
		printf("**************** NULL ****************\n");
		printf("strnstr(0,\"AAB\",0) %p\n",strnstr(0,"AAB",0));
		printf("ft_strnstr(0,\"AAB\",0) %p\n",ft_strnstr(0,"AAB",0));
	}
	if(!strcmp(argv[1],"atoi")){
		printf("atoi(\"   12345\") : %d\n",atoi("   12345"));
		printf("ft_atoi(\"   12345\") : %d\n",ft_atoi("   12345"));
		printf("atoi(\"12345\") : %d\n",atoi("12345"));
		printf("ft_atoi(\"12345\") : %d\n",ft_atoi("12345"));
		printf("atoi(\"   +12345\") : %d\n",atoi("   +12345"));
		printf("ft_atoi(\"   +12345\") : %d\n",ft_atoi("   +12345"));
		printf("atoi(\"   -12345\") : %d\n",atoi("   -12345"));
		printf("ft_atoi(\"   -12345\") : %d\n",ft_atoi("   -12345"));
		printf("atoi(\"   +-12345\") : %d\n",atoi("   +-12345"));
		printf("ft_atoi(\"   +-12345\") : %d\n",ft_atoi("   +-12345"));
		printf("atoi(\"ABC\") : %d\n",atoi("ABC"));
		printf("ft_atoi(\"ABC\") : %d\n",ft_atoi("ABC"));
		printf("atoi(\"2147483647\") : %d\n",atoi("2147483647"));
		printf("ft_atoi(\"2147483647\") : %d\n",ft_atoi("2147483647"));
		printf("atoi(\"-2147483648\") : %d\n",atoi("-2147483648"));
		printf("ft_atoi(\"-2147483648\") : %d\n",ft_atoi("-2147483648"));
		printf("atoi(\"9223372036854775807\") : %d\n",atoi("9223372036854775807"));
		printf("ft_atoi(\"9223372036854775807\") : %d\n",ft_atoi("9223372036854775807"));
		printf("atoi(\"-9223372036854775808\") : %d\n",atoi("-9223372036854775808"));
		printf("ft_atoi(\"-9223372036854775808\") : %d\n",ft_atoi("-9223372036854775808"));
	}
	if(!strcmp(argv[1],"calloc")){
		char *a,*b;
		int n=2*sizeof(int);
		a=(char *)calloc(2,sizeof(int));
		b=(char *)ft_calloc(2,sizeof(int));
		printf("calloc(2,sizeof(int)) : ");
		for(int i=0;i<n;i++){
			printf("[%d]",*(a+i));
		}
		printf("\nft_calloc(2,sizeof(int)) : ");
		for(int i=0;i<n;i++){
			printf("[%d]",*(b+i));
		}
		free(a);
		free(b);
		n=2*sizeof(char);
		a=(char *)calloc(2,sizeof(char));
		b=(char *)ft_calloc(2,sizeof(char));
		printf("\ncalloc(2,sizeof(char)) : ");
		for(int i=0;i<n;i++){
			printf("[%d]",*(a+i));
		}
		printf("\nft_calloc(2,sizeof(char)) : ");
		for(int i=0;i<n;i++){
			printf("[%d]",*(b+i));
		}
		free(a);
		free(b);
		//system("leaks a.out");
	}
	if(!strcmp(argv[1],"strdup")){
		char *a,*b;
		a=strdup("ABC");
		b=ft_strdup("ABC");
		printf("a=strdup(\"ABC\") : a = [%p], %s\n",a,a);
		printf("b=ft_strdup(\"ABC\") : b = [%p], %s\n",b,b);
		free(a);
		free(b);
		a=strdup("");
		b=ft_strdup("");
		printf("a=strdup(\"\") : a = [%p], %s\n",a,a);
		printf("b=ft_strdup(\"\") : b = [%p], %s\n",b,b);
		free(a);
		free(b);
	}
	if(!strcmp(argv[1],"substr")){
		char *s;
		s=ft_substr("HELLO",2,2);
		printf("ft_substr(\"HELLO\",2,2) : %s\n",s);
		free(s);
		s=ft_substr("HELLO",2,10);
		printf("ft_substr(\"HELLO\",2,10) : %s\n",s);
		free(s);
		s=ft_substr("HELLO",6,10);
		printf("ft_substr(\"HELLO\",6,10) : %s\n",s);
		free(s);
		s=ft_substr("HELLO",3,0);
		printf("ft_substr(\"HELLO\",3,0) : %s\n",s);
		free(s);
		s=ft_substr(0,1,1);
		printf("ft_substr(0,1,1) : %s\n",s);
		free(s);
	}
	if(!strcmp(argv[1],"strjoin")){
		char *s;
		s=ft_strjoin("abc","ABC");
		printf("ft_strjoin(\"abc\",\"ABC\") : %s\n",s);
		free(s);
		s=ft_strjoin("","ABC");
		printf("ft_strjoin(\"\",\"ABC\") : %s\n",s);
		free(s);
		s=ft_strjoin("abc","");
		printf("ft_strjoin(\"abc\",\"\") : %s\n",s);
		free(s);
		s=ft_strjoin("","");
		printf("ft_strjoin(\"\",\"\") : %s\n",s);
		free(s);
	}
	if(!strcmp(argv[1],"strtrim")){
		char *s;
		s=ft_strtrim("abcABCabc","abc");
		printf("ft_strtrim(\"abcABCabc\",\"abc\") : %s\n",s);
		free(s);
		s=ft_strtrim("abcbca","abc");
		printf("ft_strtrim(\"abcbca\",\"abc\") : %s\n",s);
		free(s);
		s=ft_strtrim("ABCABC","abc");
		printf("ft_strtrim(\"ABCABC\",\"abc\") : %s\n",s);
		free(s);
		s=ft_strtrim("ABCAB","AB");
		printf("ft_strtrim(\"ABCAB\",\"AB\") : %s\n",s);
		free(s);
	}
	if(!strcmp(argv[1],"split")){
		char **s=ft_split("AABBBAAABA1234A",'A');
		size_t index=0;
		printf("ft_split(\"AABBBAAABA1234A\",'A') : ");
		while(*(s+index)){
			printf("[%s]",*(s+index));
			free(*(s+index));
			index++;
		}
		puts("");
		free(s);
		s=ft_split("AAAAA",'A');
		index = 0;
		printf("ft_split(\"AAAAA\",'A') : ");
		while(*(s+index)){
			printf("[%s]",*(s+index));
			free(*(s+index));
			index++;
		}
		puts("");
		free(s);
	}
	if(!strcmp(argv[1],"itoa")){
		char *s;
		s=ft_itoa(1);
		printf("ft_itoa(1) =");
		for(int i=0;*(s+i);i++)printf("[%c]",s[i]);
		puts("");
		free(s);
		s=ft_itoa(-1);
		printf("ft_itoa(-1) =");
		for(int i=0;*(s+i);i++)printf("[%c]",s[i]);
		puts("");
		free(s);
		s=ft_itoa(0);
		printf("ft_itoa(0) =");
		for(int i=0;*(s+i);i++)printf("[%c]",s[i]);
		puts("");
		free(s);
		s=ft_itoa(2147483647);
		printf("INT_MAX : ft_itoa(2147483647) =");
		for(int i=0;*(s+i);i++)printf("[%c]",s[i]);
		puts("");
		free(s);
		s=ft_itoa(-2147483648);
		printf("INT_MIN : ft_itoa(-2147483648) =");
		for(int i=0;*(s+i);i++)printf("[%c]",s[i]);
		puts("");
		free(s);
	}
	if(!strcmp(argv[1],"strmapi")){
		char *s;
		s=ft_strmapi("ABCDEF",ft_conv);
		printf("f : 'a'+(index+c)%%26\n");
		printf("ft_strmapi(\"ABCDEF\",ft_conv) : ");
		for(int i=0;*(s+i);i++)printf("[%c]",s[i]);
		puts("");
		free(s);
	}
	if(!strcmp(argv[1],"striteri")){
		char s[] = "ABCDE";
		printf("f : index + 'a'\n");
		ft_striteri(s,ft_conv2);
		printf("\"ABCDE\" : %s\n",s);
	}
	if(!strcmp(argv[1],"putchar_fd")){
		int fd1;
		fd1=open("./test", O_WRONLY);
		if(fd1==-1)
			return 0;
		ft_putchar_fd('A',fd1);
		printf("ft_putchar_fd('A',fd1)\n");
		close(fd1);
	}
	if(!strcmp(argv[1],"putstr_fd")){
		int fd1;
		fd1=open("./test", O_WRONLY);
		if(fd1==-1)
			return 0;
		char s[]="ABCDEF";
		ft_putstr_fd(s,fd1);
		printf("ft_putstr_fd(s,fd1) : s=\"ABCDEF\"\n");
		close(fd1);
	}
	if(!strcmp(argv[1],"putendl_fd")){
		int fd1;
		fd1=open("./test", O_WRONLY);
		if(fd1==-1)
			return 0;
		char s[]="123456";
		ft_putendl_fd(s,fd1);
		printf("ft_putendl_fd(s,fd1) : s=\"123456\"\n");
		close(fd1);
	}
	if(!strcmp(argv[1],"putnbr_fd")){
		int fd1;
		fd1=open("./test", O_WRONLY);
		if(fd1==-1)
			return 0;
		ft_putnbr_fd(0,fd1);
		ft_putnbr_fd(1,fd1);
		ft_putnbr_fd(-1,fd1);
		ft_putnbr_fd(2147483647,fd1);
		ft_putnbr_fd(-2147483648,fd1);
		printf("test 0 1 -1 (INT_MAX)2147483647 (INT_MIN)-2147483648\n");
		close(fd1);
	}
	return (0);
}
