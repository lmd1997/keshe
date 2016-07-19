/*************************************************************************
	> File Name: ks.c
	> Author: liangmengdi
	> Mail: llmmdd1997130@126.com
	> Created Time: 2016年06月16日 星期四 19时58分56秒
 ************************************************************************/
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct book
{
    int booknumber;
    char bookname[100];
    char publishname[100];
    struct book *next;
};
struct reader
{
    int number;
    int age;
    char name[100];
    char sex[20];
    int num;
    struct reader *next;
};
struct reader *phead;
struct book *head;

void readermessage()
{
    phead=(struct reader*)malloc(sizeof(struct reader));
    struct reader *a;
    struct reader *b;
    a=phead;
    FILE *fp;
    if((fp=fopen("ksreader.txt","rt"))==NULL)
    {
        fp=fopen("ksreader.txt","wt");
    }
    else{
        while(!feof(fp))
        {
            b = (struct reader*)malloc(sizeof(struct reader));
            fscanf(fp,"%d %d %s %s %d ",&b->number,&b->age,b->name,b->sex,&b->num);
            a->next=b;
            a=b;
        }
        a->next=NULL;
    }
    fclose(fp);
}

void readfile()
{
    head = (struct book *)malloc(sizeof(struct book));
    struct book *p;
    struct book *q;
    p=head;
    FILE *fp;
    if((fp = fopen("ks.txt","rt")) == NULL)
    {
        fp = fopen("ks.txt","wt");
    }
    else
    {
        while(!feof(fp))
        {
            q=(struct book*)malloc(sizeof(struct book));
            fscanf(fp,"%d %s %s ",&q->booknumber,q->bookname,q->publishname);
            p->next=q;
            p=q;
        }
        p->next=NULL;
    }
    fclose(fp);
}
  void writefile()
{
    FILE *fp;
    struct book *p;
    p=head;
    if((fp=fopen("ks.txt","wt+"))== NULL)
    {
        printf("文件无法打开！\n");
    }
    for(p=head;p->next;p=p->next)
    {
        fprintf(fp,"%d %s %s ",p->next->booknumber,p->next->bookname,p->next->publishname);
    }
    fclose(fp);
}
 void writereader()
{
    FILE *fp;
    struct reader *a;
    a=phead;
    if((fp=fopen("ksreader.txt","wt+"))==NULL)
    {
        printf("文件无法打开！\n");
    }
    for(a=phead->next;a!=NULL;a=a->next)
    {
        fprintf(fp,"%d %d %s %s %d ",a->number,a->age,a->name,a->sex,a->num);
    }
    fclose(fp);
}
void inputreader()
{
     printf("退出此界面请输入0！\n;");
    struct reader *a;
    struct reader *b;
    int n;
    a=phead;
    printf("请录入读者信息：\n");
    printf("请输入读者的编号：\n");
    scanf("%d",&n);
    while(n!=0)
    {
        b=(struct reader*)malloc(sizeof(struct reader));
        b->number=n;
        printf("请输入读者的年龄:\n");
        scanf("%d",&b->age);
        printf("请输入读者的姓名:\n");
        scanf("%s",b->name);
        printf("请输入读者的性别：\n");
        scanf("%s",b->sex);
        printf("请输入读者所有的图书数量：\n");
        scanf("%d",&b->num);
        a->next=b;
        a=b;
        printf("请输入读者的编号：\n");
        setbuf(stdin,NULL);  //清除缓存
        scanf("%d",&n);
    }
    printf("\n");
    printf("                            读   者   信   息   已   成   功   录   入！\n");
    writereader();
}
void input()
{
     printf("退出此界面请输入0！\n");
    struct book *p;
    struct book *q;
    p=head;
    int num;
    printf("请录入图书信息：\n");
    printf("请输入书的编号(结束输入0):");
    scanf("%d",&num);
    while(num != 0)
    {
        q=(struct book*)malloc(sizeof(struct book));
        q->booknumber = num;
        printf("请输入书的名称:");
        scanf("%s",q->bookname);
        printf("请输入书的出版社:");
        scanf("%s",q->publishname);
        p->next=q;
        p=q;
        printf("请输入书的编号(结束输入0):");
        setbuf(stdin,NULL);  //清除缓存
        scanf("%d",&num);
    }
    printf("\n");
    printf("                           图   书   信   息   已   成   功   录   入 ！\n");
    writefile();
}
  void show()
 {
     
    struct book *q;
     struct book *p;
     int i,j,t;
     char a[100];
     char b[100];
     int icount=0;
     p=head;
     
     for(p=head->next;p!=NULL;p=p->next)
     {
         icount++;}
     p=head;
     for(i = 0, p=p->next; i<icount; i++, p=p->next)
     {
         for(j = 0, q=p->next; j<icount-1-i; j++, q=q->next)
         {
             if(p->booknumber > q->booknumber )
             {
                 t=p->booknumber;
                 p->booknumber = q->booknumber;
                 q->booknumber =t;

                 strcpy(a, p->bookname);
                 strcpy(p->bookname, q->bookname);
                 strcpy(q->bookname, a);

                 strcpy(b, p->publishname);
                 strcpy(p->publishname, q->publishname);
                 strcpy(q->publishname, b);

             }
         }
     }


     for(p=head->next;p!=NULL;p=p->next)
     {
         printf("dd");
         printf("书籍的编号为：%d\n书籍的名称为：%s\n书籍的出版社名称为：%s\n",p->booknumber,p->bookname,p->publishname);
     }
     writefile();
    
    




    /*   struct book *p;
      p=head;
      for(p=head->next;p!=NULL;p=p->next)
     {
       printf("书籍的编号为: %d\n书籍的名称为:%s\n书籍的出版社名称为%s\n",p->booknumber,p->bookname,p->publishname);
     }
     writefile();*/
 }
 void showreader()
 {
     printf("若需退出此界面请输入0：\n");
     struct reader *a;
     a=phead;
     for(a=phead->next;a!=NULL;a=a->next)
     {
         printf(" 读者的编号为：%d\n 读者的年龄为：%d\n 读者的姓名为：%s\n 读者的性别为%s\n 读者现有的图书数量：%d\n",a->number,a->age,a->name,a->sex,a->num);
         printf("\n");
     }
 }
 void delete()
 {
     printf("退出此界面请输入0！\n");
     int i;
     int t;
     struct book *p;
     struct book *q;
     p=head;
     printf("请输入要删除的书籍号码:\n ");
     scanf("%d",&t);
     for(i=0;i<t;i++)
     {
         q=p;
         p=p->next;
     }
     q->next=p->next;
     free(p);
     writefile(); }
 void deletereader()
 {
     printf("退出此界面请输入0！\n");
     int i;
     int t;
     struct reader *a;
     struct reader *b;
     a=phead;
     printf("请输入要删除的会员号码：\n");
     scanf("%d",&t);
     for(i=0;i<t;i++)
     {
         b=a;
         a=a->next;
     }
    b->next=a->next;
     free(a);
     writereader();    
 }
 void find()
 {
     printf("退出此界面请输入0！\n");
     int i;
     struct book *p;
     p=head;
     int n;
     printf("请输入要查询的书籍顺序：\n");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         p=p->next;
     }
     printf(" 书籍的编号：%d\n书籍的名称为: %s\n书籍的出版社名称为: %s\n",p->booknumber,p->bookname,p->publishname);
 }
 void findreader()
 {
     printf("退出此界面请输入0！\n");
     int i;
     struct reader *a;
     a=phead;
     int n;
     printf("请输入要查询的游客顺序：\n");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         a=a->next;
     }
     printf("您所查询的游客号码为：%d\n 您所查询的游客年龄为：%d\n 您所查询的游客姓名为：%s\n 您所查询的游客性别为：%s\n 您所查询的游客现有图书数量为：%d\n",a->number,a->age,a->name,a->sex,a->num);
 }
 int legal()
 {
     struct book *p;
     struct book *q;
     p=(struct book*)malloc(sizeof(struct book));
     printf("请输入要添加的书籍信息：\n");
     printf("请输入要添加书籍的名称：\n");
     scanf("%s",p->bookname);
     for(q=head->next;q!=NULL;q=q->next)
     {
         if(strcmp(p->bookname,q->bookname)==0)
         return 1;
         else 
         return 0;
     }
 }
 void insert()
 {   struct book *p;
    printf("退出此界面请输入0！\n");
     p=(struct book*)malloc(sizeof(struct book));
     if (legal()==0)
     {
     printf("请再次输入您要添加的书籍名称：\n");
         scanf("%s",p->bookname);
     printf("请输入要添加书籍的编号：\n");
     scanf("%d",&p->booknumber);
     printf("请输入要添加书籍出版社名称：\n");
     scanf("%s",p->publishname);
     p->next=head->next;
     head->next=p;}
     else 
     printf("您所添加的书籍书库里已有库存，其存书量将自动增加！\n");
     writefile();
 }
 void change(){
     printf("退出此界面请输入0！\n");
     struct book *p;
     int n;
     int i;
     int w;
     p=head;
     printf("请输入您要修改的图书编号：\n");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         p=p->next;
     }
     printf("请选择您要修改的信息：\n");
     printf("1.修改图书编号                                         2.修改图书名称\n");
     printf("3.修改图书出版社名称：\n");
     printf("请输入选项：\n");
     scanf("%d",&w);
     switch(w)
     {
         case 1:{
             printf("请输入修改后的图书编号：\n");
             scanf("%d",&p->booknumber);
             break;
         }
         case 2:{
             printf("请输入修改后的图书名称：\n");
             scanf("%s",p->bookname);
             break;
         }
         case 3:{
             printf("请输入修改后的出版社名称：\n");
             scanf("%s",p->publishname);
             break;
         }
     }
     writefile();
 }
 void changereader()
 {
     printf("退出此界面请输入0！\n");
     struct reader *a;
     a=phead;
     int i;
     int n;
     int w;
     printf("请输入您要修改的游客编号：\n");
     scanf("%d",&n);
     for(i=0;i<n;i++);
     {
         a=a->next;
     }
     printf("请选择您要修改的信息：\n");
     printf("1.修改游客编号                             2.修改游客年龄\n");
     printf("3.修改游客性别                             4.修改游客姓名\n");
     printf("5.修改游客拥有的书籍数量");
     printf("请输入选项：\n");
     scanf("%d",&w);
     switch(w)
     {
         case 1:
         { printf("请输入修改后的会员编号：\n");
           scanf("%d",&a->number);
             break; }
         case 2:{
                    printf("请输入修改后的会员年龄：\n");
                    scanf("%d",&a->age);
                     break;}
         case 3:{
             printf("请输入修改后的游客性别:\n");
             scanf("%s",a->sex);
             break;
         }
         case 4:{
             printf("请输入修改后的游客姓名：\n");
             scanf("%s",a->name);
             break;
         }
         case 5:{
             printf("请输入修改后的游客现有书籍数量：\n");
             scanf("%d",&a->num);
         }
     }
     writereader();
 }
void insertreader()
{
     printf("退出此界面请输入0！\n");
    struct reader *a;
    a=(struct reader*)malloc(sizeof(struct reader));
    printf("请输入要添加的会员信息：\n");
    printf("请输入要添加的会员编号：\n");
    scanf("%d",&a->number);
    printf("请输入要添加的会员年龄：\n");
    scanf("%d",&a->age);
    printf("请输入要添加的会员姓名：\n");
    scanf("%s",a->name);
    printf("请输入要添加的会员性别：\n");
    scanf("%s",a->sex);
    printf("请输入要添加会员现有的图书数量：\n");
    scanf("%d",&a->num);
    a->next=phead->next;
    phead->next=a;
    writereader();
}
  void borrow()
{
     printf("退出此界面请输入0！\n");
    struct reader *a;
    struct book *p;
    a=phead;
    p=head;
    int n;
    int i;
    int s;
    printf("请输入您的读者编号：\n");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        a=a->next;
    }
    if(a->num>4)
   {
        printf("您的借阅数量已满！\n");
    }
    else
    {
        printf("请输入您所借阅图书的编号:");
        scanf("%d",&s);
        for(i=0;i<s;i++)
        {
            p=p->next;
        }
        a->num++;
        printf("您已借阅成功！\n");
        printf("您所借阅的图书信息为：\n");
        printf("图书编号：%d\n图书名称：%s\n图书出版社名称：%s\n",p->booknumber,p->bookname,p->publishname);
    }
}
void mima()
{
    char aaaaa[10]="11111";
    char s[10];
    printf("请输入密码:");
     scanf("%s",s);
    printf("\n");
    printf("\n");
    if(strcmp(s,aaaaa)==0)
    {printf("                 您   已   以   管   理   员   身   份   进   入   图   书   管   理   借   阅   系   统!");
     printf("\n");
     printf("\n");
     printf("\n");
    int choice; 
    do
    {
        printf("                                            ---------------------\n");
        printf("                                               图  书  管  理\n");
        printf("                                           ---------------------\n");
        printf("                                    ( 如 需 退 出 管  理  员  页  面 请 输 入 0)\n");
        printf("                                        1: 创建图书信息：\n");
        printf("                                        2: 删除图书信息：\n");
        printf("                                        3：删除游客信息：\n");
        printf("                                        4：增添图书信息：\n");
        printf("                                        5：创建游客信息：\n");
        printf("                                        6: 修改图书信息：\n");
        printf("                                        7: 修改游客信息：\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: {
                printf("============\n");
                printf("创建图书信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                input();
                break;}
            case 2: {
                printf("============\n");
                printf("删除图书信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                delete();
                break;}
            case 3: {
                printf("============\n");
                printf("删除游客信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                deletereader();
                break;}
            case 4: {
                printf("============\n");
                printf("增添图书信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                insert();
                break;}
            case 5: {
                printf("============\n");
                printf("创建游客信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                inputreader();
                break;
            }
            case 6: {
                printf("============\n");
                printf("修改图书信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                change();
                break;
            }
            case 7:{
                printf("============\n");
                printf("修改游客信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                changereader();
                break;
            }

        }
    }
        while(choice!=0);}
}
void owner()
{
    char aaaaa[10]="11111";
    char s[10];
    printf("请输入密码:");
    scanf("%s",s);
    printf("\n");
    printf("\n");
    if(strcmp(s,aaaaa)==0)
    {printf("                 您   已   以   管   理   员   身   份   进   入   图   书   管   理   借   阅   系   统 !");
     printf("\n");
     printf("\n");
     printf("\n");
    int choice; 
    do
    {
        printf("                                              ---------------------\n");
        printf("                                                  图  书  管  理\n");
        printf("                                              ---------------------\n");
        printf("                                     ( 如 需 退 出 管  理  员  页  面 请 输 入 0)\n");
        printf("                                         1: 创建图书信息：\n");
        printf("                                         2: 删除图书信息：\n");
        printf("                                         3：删除游客信息：\n");
        printf("                                         4：增添图书信息：\n");
        printf("                                         5：创建游客信息：\n");
        printf("                                         6: 修改图书信息：\n");
        printf("                                         7: 修改游客信息：\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: {
                printf("============\n");
                printf("创建图书信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                input();
                break;}
            case 2: {
                printf("============\n");
                printf("删除图书信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                delete();
                break;}
            case 3: {
                printf("============\n");
                printf("删除游客信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                deletereader();
                break;}
            case 4: {
                printf("============\n");
                printf("增添图书信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                insert();
                break;}
            case 5: {
                printf("============\n");
                printf("创建游客信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                inputreader();
                break;
            }
            case 6: {
                printf("============\n");
                printf("修改图书信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                change();
                break;
            }
            case 7:{
                printf("============\n");
                printf("修改游客信息：\n");
                printf("============\n");
                printf("\n");
                printf("\n");
                changereader();
                break;
            }

        }
    }
        while(choice!=0);}
else{
printf("密码错误,请您重新输入！\n");
    mima();
}}
void visitor()
{
    int choice;
     do
     {
        printf("                                  ------------------------\n");
        printf("                                       游客登陆界面\n");
        printf("                                  ------------------------\n");
        printf("                               ( 如  需  退  出  游  客  界  面  请  输  入  0\n");
        printf("                                 1: 显示图书信息：\n");
        printf("                                 2: 显示读者信息：\n");
        printf("                                 3: 办理图书馆会员：\n");
        printf("                                 4: 查找图书信息：\n");
        printf("                                 5: 查找读者信息：\n");
        printf("                                 6：借阅图书\n");
        printf("                                    请输入编号 :");
        scanf("%d",&choice);
         switch(choice)
         {

            case 1: {
                printf("==============\n");
                printf("显示图书信息：\n");
                printf("==============\n");
                printf("\n");
                printf("\n");
                show();
                break;}
            case 2: {
                printf("==============\n");
                printf("显示读者信息：\n");
                printf("==============\n");
                printf("\n");
                printf("\n");
                showreader();
                break;}
            case 3: {
                printf("===============\n");
                printf("办理图书馆会员：\n");
                printf("================\n");
                printf("\n");
                printf("\n");
                insertreader();
                break;}
            case 4: {
                printf("================\n");
                printf("查找图书信息：\n");
                printf("================\n");
                printf("\n");
                printf("\n");
                find();
                break;}
            case 5:{
                printf("================\n");
                printf("查找读者信息：\n");
                printf("================\n");
                printf("\n");
                printf("\n");
                findreader();
                break;}
            case 6:{
                printf("================\n");
                printf("借阅图书\n");
                printf("================\n");
                printf("\n");
                printf("\n");
                borrow();}
         }
    }
         while(choice!=0);
 }
 int main(int argc,char *argv[])
{
        int q;
        readfile();
        readermessage();
    do
    {
        printf("********************************************************************************************************************\n");
        printf("                    欢   迎   使   用   图   书   管   理   借   阅   系   统！\n"); 
        printf("**********************************************************************************************************************\n");
        printf("\n");
        printf("\n");
        printf("                                    请选择您的身份：(若需退出请输入0)\n");
        printf("                    =========                                         ========\n");
        printf("                   |         |                                       |        |\n");
        printf("                    1.管理员                                           2.游客\n");
        printf("                   |         |                                       |        |\n");
        printf("                    =========                                         ========\n");
        printf("\n");
        scanf("%d",&q);
        if(q!=1&&q!=2)
        {
            printf("您输入0或错误选项，系统将退出请您重新选择！\n");
            break;
        }
        switch(q)
        {
            case 1:{
                owner();
                break;
            }
            case 2:{
                visitor();
                break;
            }   
        }   
    }
        while(q!=0);
}                                                                                  
