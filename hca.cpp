#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

double mean(double, double);
double min(double, double);
double max(double, double);

int solveusingmeanmin();
int solveusingmin();
int solveusingmax();
int solveusingmeanmax();

struct node{
    double value;
    struct node *next;
};

struct partition{
    double xc;
    double yc;
    struct node *next;
    struct partition *down;
    int a[10000];
    int cn;
};

double ycm=0;

typedef struct node n;
typedef struct partition p;

p* head=NULL;
n* column;
n* column1;
n* column2;
n* tcolumn;
n* tcolumn1;
n* tcolumn2;
n* temp;
n* temp2;
p* tempr;
p* tempr2;
p* tempr3;
p* row;
p* row1;
p* row2;
p* trow;
p* trow1;
p* trow2;

n* createcolumn(){
    column = (n*)malloc(sizeof(n));
}

p* createrow(){
    row = (p*)malloc(sizeof(p));
}

long long int nn,nnn,ttt=1;
int grd=DETECT,grm;

int main(){
    while(ttt){
        printf("Enter the number of nodes\n");
        scanf("%lld",&nn);
        if(nn<3){
            printf("Entered wrong number of nodes ... Please try again\n");
            continue;
        }
        else{
            break;
        }
    }
    nnn=nn;
    printf("Enter the matrix\n");
    long long int i=1,j=0;
    for(i=1;i<=nn;i++){
        row = createrow();
        row->a[0]=i;
        row->xc=i;
        row->yc=0;
        row->cn=1;
        row->down=NULL;
        row->next=NULL;
        if(i==1){
            head=row;
            trow=head;
        }
        else{
            trow->down=row;
            trow=row;
        }
        for(j=1;j<=i;j++){
            column = createcolumn();
            double v;
            scanf("%lf",&v);
            column->value=v;
            column->next=NULL;
            if(j==1){
                trow->next=column;
                tcolumn=column;
            }
            else{
                tcolumn->next=column;
                tcolumn=column;
            }
        }
    }
    int xx=1,yy=1;
    while(xx){
    printf("Parameters provided are distance or closeness\nPress 1 for distance and Press 2 for closeness\n");
    int y;
    scanf("%d",&y);
    xx=0;
    switch(y){
        case 1: while(yy){
                    printf("Enter the method : Press 1 for mean method and Press 2 for min method\n");
                    int z;
                    scanf("%d",&z);
                    yy=0;
                    switch(z){
                        case 1: solveusingmeanmin();
                                break;
                        case 2: solveusingmin();
                                break;
                        default: printf("You have entered wrong number ... Please try again\n");
                                 yy=1;
                                 break;
                    }
                }
                break;
        case 2: while(yy){
                    printf("Enter the method : Press 1 for mean method and Press 2 for min method\n");
                    int z;
                    scanf("%d",&z);
                    yy=0;
                    switch(z){
                        case 1: solveusingmeanmax();
                                break;
                        case 2: solveusingmax();
                                break;
                        default: printf("You have entered wrong number ... Please try again\n");
                                 yy=1;
                                 break;
                    }
                }
                break;

        default: printf("You have entered wrong number ... Please try again\n");
                 xx=1;
                 break;
        }
    }
    getch();
    closegraph();
return 0;
}
int display(){
    row = head;
    printf("Final matrix is \n");
    while(row!=NULL){
        column = row->next;
        while(column!=NULL){
            printf("%g ",column->value);
            column = column->next;
        }
        printf("\n");
        row = row->down;
    }
	return 0;
}
int displayfinal(){
    row = head;
    int i;
        printf("Partition 1 is : \n");
        for(i=0;i<((row->cn));i++){
            printf("%d,",row->a[i]);
        }
        printf("\n");
        row = row->down;
        printf("Partition 2 is : \n");
        for(i=0;i<(row->cn);i++){
            printf("%d,",row->a[i]);
        }
        printf("\n");
	return 0;
}
int solveusingmin(){
    detectgraph(&grd,&grm);
    initgraph(&grd, &grm, "C:\\TC\\BGI");
    setfillstyle(SOLID_FILL, BLACK);
    bar(1,1,638,478);
    setcolor(WHITE);
    rectangle(0,0,639,479);
    setlinestyle(1, 1, 1);
	nnn = nn;
    while(nnn>2){
        nnn=nnn-1;
        row = head->down;
        double maxmm = head->down->next->value;
        long long int iiii=2;
        long long int jjjj=1;
        long long int ii=2,jj=1;
        while(row!=NULL){
            tcolumn=row->next;
            while(tcolumn->next!=NULL){
                if(tcolumn->value<maxmm){
                    maxmm=tcolumn->value;
                    iiii=ii;
                    jjjj=jj;
                }
                tcolumn=tcolumn->next;
                jj++;
            }
            jj=1;
            row=row->down;
            ii++;
        }
        row1 = createrow();
        row1->cn=0;
        row1->down=NULL;
        row1->next=NULL;
        row2 = createrow();
        row2->cn=0;
        row2->down=NULL;
        row2->next=NULL;
        int iii;
        if(iiii>jjjj){
            iiii=iiii-jjjj;
            jjjj=jjjj+iiii;
            iiii=jjjj-iiii;
        }
        trow=head;
        for(iii=1;iii<jjjj-1;iii++){
            trow=trow->down;
        }
        trow2=trow;
        trow=trow->down;
        row2->cn=trow->cn;
        row2->xc=trow->xc;
        row2->yc=trow->yc;
        for(iii=0;iii<row2->cn;iii++){
            row2->a[iii]=trow->a[iii];
        }
        column1=trow->next;
        column=createcolumn();
        column->value=column1->value;
        column->next=NULL;
        row2->next=column;
        column2=row2->next;
        column1=column1->next;
        while(column1!= NULL){
            column=createcolumn();
            column->value=column1->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
			column1=column1->next;
        }
        trow=trow->down;
        while(trow!=NULL){
            column1=trow->next;
            for(iii=0;iii<jjjj-2;iii++){
                column1=column1->next;
            }
            column=createcolumn();
            column->value=column1->next->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
            temp=column1->next->next;
            column1->next->next=NULL;
            temp2=column1->next;
            column1->next=temp;
            free(temp2);
			trow=trow->down;
        }
        trow=head;
        for(iii=1;iii<iiii-1;iii++){
            trow=trow->down;
        }
        if(iiii==1){
        	trow1=head;
        }
        else{
        	trow1=trow;
        	trow=trow->down;
        }
        row1->cn=trow->cn;
        row1->xc=trow->xc;
        row1->yc=trow->yc;
        for(iii=0;iii<row1->cn;iii++){
            row1->a[iii]=trow->a[iii];
        }
        column1=trow->next;
        column=createcolumn();
        column->value=column1->value;
        column->next=NULL;
        row1->next=column;
        column2=row1->next;
        column1=column1->next;
        while(column1!= NULL){
            column=createcolumn();
            column->value=column1->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
			column1=column1->next;
        }
        trow=trow->down;
        while(trow!=NULL){
        	if(iiii==1){
        		column=createcolumn();
	            column->value=trow->next->value;
	            column->next=NULL;
	            column2->next=column;
	            column2=column2->next;
	            temp=trow->next->next;
	            trow->next->next=NULL;
	            temp2=trow->next;
	            trow->next=temp;
	            free(temp2);
        	}
        	else{
	            column1=trow->next;
	            for(iii=0;iii<iiii-2;iii++){
	                column1=column1->next;
	            }
	            column=createcolumn();
	            column->value=column1->next->value;
	            column->next=NULL;
	            column2->next=column;
	            column2=column2->next;
	            temp=column1->next->next;
	            column1->next->next=NULL;
	            temp2=column1->next;
	            column1->next=temp;
	            free(temp2);
	        }
			trow=trow->down;
        }
		tempr=trow2->down->down;
		trow2->down->down=NULL;
		tempr3=trow2->down;
		trow2->down=tempr;
		free(tempr3);
		if(iiii==1){
			tempr = head->down;
			head->down=NULL;
			head = tempr;
			tempr=trow1;
			free(tempr);
		}
		else{
			tempr=trow1->down->down;
			trow1->down->down=NULL;
			tempr3 = trow1->down;
			trow1->down=tempr;
			free(tempr3);
		}
		column1=row1->next;
		column2=row2->next;
        ii=1;
	        while(column1!=NULL){
	                if(iiii==1){
	                    row1->next=column1->next;
	                    column1->next=NULL;
			    		temp=column1;
	                    column1=row1->next;
	                    free(temp);
	                    row2->next=column2->next;
	                    column2->next=NULL;
						temp=column2;
	                    column2=row2->next;
						free(temp);
	                    ii++;
			    		iiii=0;
	                    if(jjjj==2){
	                        row1->next=column1->next;
	                        column1->next=NULL;
							temp=column1;
	                        column1=row1->next;
							free(temp);
	                        row2->next=column2->next;
	                        column2->next=NULL;
							temp=column2;
	                        column2=row2->next;
							free(temp);
	                        ii++;
	                    }
	                }
	                else if(ii==iiii || ii==jjjj){
	                    tcolumn1->next=column1->next;
	                    column1->next=NULL;
						temp=column1;
	                    column1=tcolumn1->next;
						free(temp);
	                    tcolumn2->next=column2->next;
	                    column2->next=NULL;
						temp=column2;
	                    column2=tcolumn2->next;
						free(temp);
	                    ii++;
	                }
	                else{
	                    tcolumn1=column1;
	                    column1=column1->next;
	                    tcolumn2=column2;
	                    column2=column2->next;
	                    tcolumn1->value=min(tcolumn1->value,tcolumn2->value);
	                    ii++;
	                }
	        }
        int jjjjj=row1->cn;
        for(iii=0;iii<row2->cn;iii++){
            row1->a[jjjjj]=row2->a[iii];
            jjjjj++;
        }
        row1->cn=jjjjj;
        double nxc;
        nxc=(((row1->xc)+(row2->xc))/2);
        ycm=ycm+1;
        line((row1->xc)*50,(row1->yc)*50, (row1->xc)*50, (ycm)*50);
        line((row2->xc)*50,(row2->yc)*50, (row2->xc)*50, (ycm)*50);
        line((row1->xc)*50,(ycm)*50, (row2->xc)*50, (ycm)*50);
        row1->xc=nxc;
        row1->yc=ycm;
        delay(1);
        column=createcolumn();
        column->value=0;
        column->next=NULL;
        tcolumn1->next=column;
        trow=head;
        while(trow->down!=NULL){
            trow=trow->down;
        }
        trow->down=row1;
    }
    row1=head;
    row2=head->down;
    double nxc;
    nxc=(((row1->xc)+(row2->xc))/2);
    ycm=(ycm+1);
    line((row1->xc)*50,(row1->yc)*50, (row1->xc)*50, (ycm)*50);
    line((row2->xc)*50,(row2->yc)*50, (row2->xc)*50, (ycm)*50);
    line((row1->xc)*50,(ycm)*50, (row2->xc)*50, (ycm)*50);
    line((nxc)*50,(ycm)*50,(nxc)*50,(ycm+1)*50);
	displayfinal();
	display();
	return 0;
}

int solveusingmeanmin(){
    detectgraph(&grd,&grm);
    initgraph(&grd, &grm, "C:\\TC\\BGI");
    setfillstyle(SOLID_FILL, BLACK);
    bar(1,1,638,478);
    setcolor(WHITE);
    rectangle(0,0,639,479);
    setlinestyle(1, 1, 1);
	nnn = nn;
    while(nnn>2){
        nnn=nnn-1;
        row = head->down;
        double maxmm = head->down->next->value;
        long long int iiii=2;
        long long int jjjj=1;
        long long int ii=2,jj=1;
        while(row!=NULL){
            tcolumn=row->next;
            while(tcolumn->next!=NULL){
                if(tcolumn->value<maxmm){
                    maxmm=tcolumn->value;
                    iiii=ii;
                    jjjj=jj;
                }
                tcolumn=tcolumn->next;
                jj++;
            }
            jj=1;
            row=row->down;
            ii++;
        }
        row1 = createrow();
        row1->cn=0;
        row1->down=NULL;
        row1->next=NULL;
        row2 = createrow();
        row2->cn=0;
        row2->down=NULL;
        row2->next=NULL;
        int iii;
        if(iiii>jjjj){
            iiii=iiii-jjjj;
            jjjj=jjjj+iiii;
            iiii=jjjj-iiii;
        }
        trow=head;
        for(iii=1;iii<jjjj-1;iii++){
            trow=trow->down;
        }
        trow2=trow;
        trow=trow->down;
        row2->cn=trow->cn;
        row2->xc=trow->xc;
        row2->yc=trow->yc;
        for(iii=0;iii<row2->cn;iii++){
            row2->a[iii]=trow->a[iii];
        }
        column1=trow->next;
        column=createcolumn();
        column->value=column1->value;
        column->next=NULL;
        row2->next=column;
        column2=row2->next;
        column1=column1->next;
        while(column1!= NULL){
            column=createcolumn();
            column->value=column1->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
			column1=column1->next;
        }
        trow=trow->down;
        while(trow!=NULL){
            column1=trow->next;
            for(iii=0;iii<jjjj-2;iii++){
                column1=column1->next;
            }
            column=createcolumn();
            column->value=column1->next->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
            temp=column1->next->next;
            column1->next->next=NULL;
            temp2=column1->next;
            column1->next=temp;
            free(temp2);
			trow=trow->down;
        }
        trow=head;
        for(iii=1;iii<iiii-1;iii++){
            trow=trow->down;
        }
        if(iiii==1){
        	trow1=head;
        }
        else{
        	trow1=trow;
        	trow=trow->down;
        }
        row1->cn=trow->cn;
        row1->xc=trow->xc;
        row1->yc=trow->yc;
        for(iii=0;iii<row1->cn;iii++){
            row1->a[iii]=trow->a[iii];
        }
        column1=trow->next;
        column=createcolumn();
        column->value=column1->value;
        column->next=NULL;
        row1->next=column;
        column2=row1->next;
        column1=column1->next;
        while(column1!= NULL){
            column=createcolumn();
            column->value=column1->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
			column1=column1->next;
        }
        trow=trow->down;
        while(trow!=NULL){
        	if(iiii==1){
        		column=createcolumn();
	            column->value=trow->next->value;
	            column->next=NULL;
	            column2->next=column;
	            column2=column2->next;
	            temp=trow->next->next;
	            trow->next->next=NULL;
	            temp2=trow->next;
	            trow->next=temp;
	            free(temp2);
        	}
        	else{
	            column1=trow->next;
	            for(iii=0;iii<iiii-2;iii++){
	                column1=column1->next;
	            }
	            column=createcolumn();
	            column->value=column1->next->value;
	            column->next=NULL;
	            column2->next=column;
	            column2=column2->next;
	            temp=column1->next->next;
	            column1->next->next=NULL;
	            temp2=column1->next;
	            column1->next=temp;
	            free(temp2);
	        }
			trow=trow->down;
        }
		tempr=trow2->down->down;
		trow2->down->down=NULL;
		tempr3=trow2->down;
		trow2->down=tempr;
		free(tempr3);
		if(iiii==1){
			tempr = head->down;
			head->down=NULL;
			head = tempr;
			tempr=trow1;
			free(tempr);
		}
		else{
			tempr=trow1->down->down;
			trow1->down->down=NULL;
			tempr3 = trow1->down;
			trow1->down=tempr;
			free(tempr3);
		}
		column1=row1->next;
		column2=row2->next;
        ii=1;
	        while(column1!=NULL){
	                if(iiii==1){
	                    row1->next=column1->next;
	                    column1->next=NULL;
			    		temp=column1;
	                    column1=row1->next;
	                    free(temp);
	                    row2->next=column2->next;
	                    column2->next=NULL;
						temp=column2;
	                    column2=row2->next;
						free(temp);
	                    ii++;
			    		iiii=0;
	                    if(jjjj==2){
	                        row1->next=column1->next;
	                        column1->next=NULL;
							temp=column1;
	                        column1=row1->next;
							free(temp);
	                        row2->next=column2->next;
	                        column2->next=NULL;
							temp=column2;
	                        column2=row2->next;
							free(temp);
	                        ii++;
	                    }
	                }
	                else if(ii==iiii || ii==jjjj){
	                    tcolumn1->next=column1->next;
	                    column1->next=NULL;
						temp=column1;
	                    column1=tcolumn1->next;
						free(temp);
	                    tcolumn2->next=column2->next;
	                    column2->next=NULL;
						temp=column2;
	                    column2=tcolumn2->next;
						free(temp);
	                    ii++;
	                }
	                else{
	                    tcolumn1=column1;
	                    column1=column1->next;
	                    tcolumn2=column2;
	                    column2=column2->next;
	                    tcolumn1->value=mean(tcolumn1->value,tcolumn2->value);
	                    ii++;
	                }
	        }
        int jjjjj=row1->cn;
        for(iii=0;iii<row2->cn;iii++){
            row1->a[jjjjj]=row2->a[iii];
            jjjjj++;
        }
        row1->cn=jjjjj;
        double nxc;
        nxc=(((row1->xc)+(row2->xc))/2);
        ycm=ycm+1;
        line((row1->xc)*50,(row1->yc)*50, (row1->xc)*50, (ycm)*50);
        line((row2->xc)*50,(row2->yc)*50, (row2->xc)*50, (ycm)*50);
        line((row1->xc)*50,(ycm)*50, (row2->xc)*50, (ycm)*50);
        row1->xc=nxc;
        row1->yc=ycm;
        delay(1);
        column=createcolumn();
        column->value=0;
        column->next=NULL;
        tcolumn1->next=column;
        trow=head;
        while(trow->down!=NULL){
            trow=trow->down;
        }
        trow->down=row1;
    }
    row1=head;
    row2=head->down;
    double nxc;
    nxc=(((row1->xc)+(row2->xc))/2);
    ycm=(ycm+1);
    line((row1->xc)*50,(row1->yc)*50, (row1->xc)*50, (ycm)*50);
    line((row2->xc)*50,(row2->yc)*50, (row2->xc)*50, (ycm)*50);
    line((row1->xc)*50,(ycm)*50, (row2->xc)*50, (ycm)*50);
    line((nxc)*50,(ycm)*50,(nxc)*50,(ycm+1)*50);
	displayfinal();
	display();
	return 0;
}

int solveusingmax(){
    detectgraph(&grd,&grm);
    initgraph(&grd, &grm, "C:\\TC\\BGI");
    setfillstyle(SOLID_FILL, BLACK);
    bar(1,1,638,478);
    setcolor(WHITE);
    rectangle(0,0,639,479);
    setlinestyle(1, 1, 1);
	nnn = nn;
    while(nnn>2){
        nnn=nnn-1;
        row = head->down;
        double maxmm = head->down->next->value;
        long long int iiii=2;
        long long int jjjj=1;
        long long int ii=2,jj=1;
        while(row!=NULL){
            tcolumn=row->next;
            while(tcolumn->next!=NULL){
                if(tcolumn->value>maxmm){
                    maxmm=tcolumn->value;
                    iiii=ii;
                    jjjj=jj;
                }
                tcolumn=tcolumn->next;
                jj++;
            }
            jj=1;
            row=row->down;
            ii++;
        }
        row1 = createrow();
        row1->cn=0;
        row1->down=NULL;
        row1->next=NULL;
        row2 = createrow();
        row2->cn=0;
        row2->down=NULL;
        row2->next=NULL;
        int iii;
        if(iiii>jjjj){
            iiii=iiii-jjjj;
            jjjj=jjjj+iiii;
            iiii=jjjj-iiii;
        }
        trow=head;
        for(iii=1;iii<jjjj-1;iii++){
            trow=trow->down;
        }
        trow2=trow;
        trow=trow->down;
        row2->cn=trow->cn;
        row2->xc=trow->xc;
        row2->yc=trow->yc;
        for(iii=0;iii<row2->cn;iii++){
            row2->a[iii]=trow->a[iii];
        }
        column1=trow->next;
        column=createcolumn();
        column->value=column1->value;
        column->next=NULL;
        row2->next=column;
        column2=row2->next;
        column1=column1->next;
        while(column1!= NULL){
            column=createcolumn();
            column->value=column1->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
			column1=column1->next;
        }
        trow=trow->down;
        while(trow!=NULL){
            column1=trow->next;
            for(iii=0;iii<jjjj-2;iii++){
                column1=column1->next;
            }
            column=createcolumn();
            column->value=column1->next->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
            temp=column1->next->next;
            column1->next->next=NULL;
            temp2=column1->next;
            column1->next=temp;
            free(temp2);
			trow=trow->down;
        }
        trow=head;
        for(iii=1;iii<iiii-1;iii++){
            trow=trow->down;
        }
        if(iiii==1){
        	trow1=head;
        }
        else{
        	trow1=trow;
        	trow=trow->down;
        }
        row1->cn=trow->cn;
        row1->xc=trow->xc;
        row1->yc=trow->yc;
        for(iii=0;iii<row1->cn;iii++){
            row1->a[iii]=trow->a[iii];
        }
        column1=trow->next;
        column=createcolumn();
        column->value=column1->value;
        column->next=NULL;
        row1->next=column;
        column2=row1->next;
        column1=column1->next;
        while(column1!= NULL){
            column=createcolumn();
            column->value=column1->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
			column1=column1->next;
        }
        trow=trow->down;
        while(trow!=NULL){
        	if(iiii==1){
        		column=createcolumn();
	            column->value=trow->next->value;
	            column->next=NULL;
	            column2->next=column;
	            column2=column2->next;
	            temp=trow->next->next;
	            trow->next->next=NULL;
	            temp2=trow->next;
	            trow->next=temp;
	            free(temp2);
        	}
        	else{
	            column1=trow->next;
	            for(iii=0;iii<iiii-2;iii++){
	                column1=column1->next;
	            }
	            column=createcolumn();
	            column->value=column1->next->value;
	            column->next=NULL;
	            column2->next=column;
	            column2=column2->next;
	            temp=column1->next->next;
	            column1->next->next=NULL;
	            temp2=column1->next;
	            column1->next=temp;
	            free(temp2);
	        }
			trow=trow->down;
        }
		tempr=trow2->down->down;
		trow2->down->down=NULL;
		tempr3=trow2->down;
		trow2->down=tempr;
		free(tempr3);
		if(iiii==1){
			tempr = head->down;
			head->down=NULL;
			head = tempr;
			tempr=trow1;
			free(tempr);
		}
		else{
			tempr=trow1->down->down;
			trow1->down->down=NULL;
			tempr3 = trow1->down;
			trow1->down=tempr;
			free(tempr3);
		}
		column1=row1->next;
		column2=row2->next;
        ii=1;
	        while(column1!=NULL){
	                if(iiii==1){
	                    row1->next=column1->next;
	                    column1->next=NULL;
			    		temp=column1;
	                    column1=row1->next;
	                    free(temp);
	                    row2->next=column2->next;
	                    column2->next=NULL;
						temp=column2;
	                    column2=row2->next;
						free(temp);
	                    ii++;
			    		iiii=0;
	                    if(jjjj==2){
	                        row1->next=column1->next;
	                        column1->next=NULL;
							temp=column1;
	                        column1=row1->next;
							free(temp);
	                        row2->next=column2->next;
	                        column2->next=NULL;
							temp=column2;
	                        column2=row2->next;
							free(temp);
	                        ii++;
	                    }
	                }
	                else if(ii==iiii || ii==jjjj){
	                    tcolumn1->next=column1->next;
	                    column1->next=NULL;
						temp=column1;
	                    column1=tcolumn1->next;
						free(temp);
	                    tcolumn2->next=column2->next;
	                    column2->next=NULL;
						temp=column2;
	                    column2=tcolumn2->next;
						free(temp);
	                    ii++;
	                }
	                else{
	                    tcolumn1=column1;
	                    column1=column1->next;
	                    tcolumn2=column2;
	                    column2=column2->next;
	                    tcolumn1->value=max(tcolumn1->value,tcolumn2->value);
	                    ii++;
	                }
	        }
        int jjjjj=row1->cn;
        for(iii=0;iii<row2->cn;iii++){
            row1->a[jjjjj]=row2->a[iii];
            jjjjj++;
        }
        row1->cn=jjjjj;
        double nxc;
        nxc=(((row1->xc)+(row2->xc))/2);
        ycm=ycm+1;
        line((row1->xc)*50,(row1->yc)*50, (row1->xc)*50, (ycm)*50);
        line((row2->xc)*50,(row2->yc)*50, (row2->xc)*50, (ycm)*50);
        line((row1->xc)*50,(ycm)*50, (row2->xc)*50, (ycm)*50);
        row1->xc=nxc;
        row1->yc=ycm;
        delay(1);
        column=createcolumn();
        column->value=0;
        column->next=NULL;
        tcolumn1->next=column;
        trow=head;
        while(trow->down!=NULL){
            trow=trow->down;
        }
        trow->down=row1;
    }
    row1=head;
    row2=head->down;
    double nxc;
    nxc=(((row1->xc)+(row2->xc))/2);
    ycm=(ycm+1);
    line((row1->xc)*50,(row1->yc)*50, (row1->xc)*50, (ycm)*50);
    line((row2->xc)*50,(row2->yc)*50, (row2->xc)*50, (ycm)*50);
    line((row1->xc)*50,(ycm)*50, (row2->xc)*50, (ycm)*50);
    line((nxc)*50,(ycm)*50,(nxc)*50,(ycm+1)*50);
	displayfinal();
	display();
	return 0;
}

int solveusingmeanmax(){
    detectgraph(&grd,&grm);
    initgraph(&grd, &grm, "C:\\TC\\BGI");
    setfillstyle(SOLID_FILL, BLACK);
    bar(1,1,638,478);
    setcolor(WHITE);
    rectangle(0,0,639,479);
    setlinestyle(1, 1, 1);
	nnn = nn;
    while(nnn>2){
        nnn=nnn-1;
        row = head->down;
        double maxmm = head->down->next->value;
        long long int iiii=2;
        long long int jjjj=1;
        long long int ii=2,jj=1;
        while(row!=NULL){
            tcolumn=row->next;
            while(tcolumn->next!=NULL){
                if(tcolumn->value>maxmm){
                    maxmm=tcolumn->value;
                    iiii=ii;
                    jjjj=jj;
                }
                tcolumn=tcolumn->next;
                jj++;
            }
            jj=1;
            row=row->down;
            ii++;
        }
        row1 = createrow();
        row1->cn=0;
        row1->down=NULL;
        row1->next=NULL;
        row2 = createrow();
        row2->cn=0;
        row2->down=NULL;
        row2->next=NULL;
        int iii;
        if(iiii>jjjj){
            iiii=iiii-jjjj;
            jjjj=jjjj+iiii;
            iiii=jjjj-iiii;
        }
        trow=head;
        for(iii=1;iii<jjjj-1;iii++){
            trow=trow->down;
        }
        trow2=trow;
        trow=trow->down;
        row2->cn=trow->cn;
        row2->xc=trow->xc;
        row2->yc=trow->yc;
        for(iii=0;iii<row2->cn;iii++){
            row2->a[iii]=trow->a[iii];
        }
        column1=trow->next;
        column=createcolumn();
        column->value=column1->value;
        column->next=NULL;
        row2->next=column;
        column2=row2->next;
        column1=column1->next;
        while(column1!= NULL){
            column=createcolumn();
            column->value=column1->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
			column1=column1->next;
        }
        trow=trow->down;
        while(trow!=NULL){
            column1=trow->next;
            for(iii=0;iii<jjjj-2;iii++){
                column1=column1->next;
            }
            column=createcolumn();
            column->value=column1->next->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
            temp=column1->next->next;
            column1->next->next=NULL;
            temp2=column1->next;
            column1->next=temp;
            free(temp2);
			trow=trow->down;
        }
        trow=head;
        for(iii=1;iii<iiii-1;iii++){
            trow=trow->down;
        }
        if(iiii==1){
        	trow1=head;
        }
        else{
        	trow1=trow;
        	trow=trow->down;
        }
        row1->cn=trow->cn;
        row1->xc=trow->xc;
        row1->yc=trow->yc;
        for(iii=0;iii<row1->cn;iii++){
            row1->a[iii]=trow->a[iii];
        }
        column1=trow->next;
        column=createcolumn();
        column->value=column1->value;
        column->next=NULL;
        row1->next=column;
        column2=row1->next;
        column1=column1->next;
        while(column1!= NULL){
            column=createcolumn();
            column->value=column1->value;
            column->next=NULL;
            column2->next=column;
            column2=column2->next;
			column1=column1->next;
        }
        trow=trow->down;
        while(trow!=NULL){
        	if(iiii==1){
        		column=createcolumn();
	            column->value=trow->next->value;
	            column->next=NULL;
	            column2->next=column;
	            column2=column2->next;
	            temp=trow->next->next;
	            trow->next->next=NULL;
	            temp2=trow->next;
	            trow->next=temp;
	            free(temp2);
        	}
        	else{
	            column1=trow->next;
	            for(iii=0;iii<iiii-2;iii++){
	                column1=column1->next;
	            }
	            column=createcolumn();
	            column->value=column1->next->value;
	            column->next=NULL;
	            column2->next=column;
	            column2=column2->next;
	            temp=column1->next->next;
	            column1->next->next=NULL;
	            temp2=column1->next;
	            column1->next=temp;
	            free(temp2);
	        }
			trow=trow->down;
        }
		tempr=trow2->down->down;
		trow2->down->down=NULL;
		tempr3=trow2->down;
		trow2->down=tempr;
		free(tempr3);
		if(iiii==1){
			tempr = head->down;
			head->down=NULL;
			head = tempr;
			tempr=trow1;
			free(tempr);
		}
		else{
			tempr=trow1->down->down;
			trow1->down->down=NULL;
			tempr3 = trow1->down;
			trow1->down=tempr;
			free(tempr3);
		}
		column1=row1->next;
		column2=row2->next;
        ii=1;
	        while(column1!=NULL){
	                if(iiii==1){
	                    row1->next=column1->next;
	                    column1->next=NULL;
			    		temp=column1;
	                    column1=row1->next;
	                    free(temp);
	                    row2->next=column2->next;
	                    column2->next=NULL;
						temp=column2;
	                    column2=row2->next;
						free(temp);
	                    ii++;
			    		iiii=0;
	                    if(jjjj==2){
	                        row1->next=column1->next;
	                        column1->next=NULL;
							temp=column1;
	                        column1=row1->next;
							free(temp);
	                        row2->next=column2->next;
	                        column2->next=NULL;
							temp=column2;
	                        column2=row2->next;
							free(temp);
	                        ii++;
	                    }
	                }
	                else if(ii==iiii || ii==jjjj){
	                    tcolumn1->next=column1->next;
	                    column1->next=NULL;
						temp=column1;
	                    column1=tcolumn1->next;
						free(temp);
	                    tcolumn2->next=column2->next;
	                    column2->next=NULL;
						temp=column2;
	                    column2=tcolumn2->next;
						free(temp);
	                    ii++;
	                }
	                else{
	                    tcolumn1=column1;
	                    column1=column1->next;
	                    tcolumn2=column2;
	                    column2=column2->next;
	                    tcolumn1->value=mean(tcolumn1->value,tcolumn2->value);
	                    ii++;
	                }
	        }
        int jjjjj=row1->cn;
        for(iii=0;iii<row2->cn;iii++){
            row1->a[jjjjj]=row2->a[iii];
            jjjjj++;
        }
        row1->cn=jjjjj;
        double nxc;
        nxc=(((row1->xc)+(row2->xc))/2);
        ycm=ycm+1;
        line((row1->xc)*50,(row1->yc)*50, (row1->xc)*50, (ycm)*50);
        line((row2->xc)*50,(row2->yc)*50, (row2->xc)*50, (ycm)*50);
        line((row1->xc)*50,(ycm)*50, (row2->xc)*50, (ycm)*50);
        row1->xc=nxc;
        row1->yc=ycm;
        delay(1);
        column=createcolumn();
        column->value=0;
        column->next=NULL;
        tcolumn1->next=column;
        trow=head;
        while(trow->down!=NULL){
            trow=trow->down;
        }
        trow->down=row1;
    }
    row1=head;
    row2=head->down;
    double nxc;
    nxc=(((row1->xc)+(row2->xc))/2);
    ycm=(ycm+1);
    line((row1->xc)*50,(row1->yc)*50, (row1->xc)*50, (ycm)*50);
    line((row2->xc)*50,(row2->yc)*50, (row2->xc)*50, (ycm)*50);
    line((row1->xc)*50,(ycm)*50, (row2->xc)*50, (ycm)*50);
    line((nxc)*50,(ycm)*50,(nxc)*50,(ycm+1)*50);
	displayfinal();
	display();
	return 0;
}

double min(double a, double b){
    if(a<b)
        return a;
    else
        return b;
}

double mean(double a, double b){
    return ((a+b)/2);
}

double max(double a, double b){
    if(a>b)
        return a;
    else
        return b;
}
