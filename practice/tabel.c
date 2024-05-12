#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    int i=0,n,j=0,c;
    void *ptr;
    char a1[10],a2[10];
    printf("give the expression end with $");
    while((c=getchar())!='$'){
    a1[i]=c;
    i++;
    }
    n=i-1;
    for(i=0;i<n;i++){
        printf("%c",a1[i]);
    }
    printf("sysmbol table");
    printf("sys\taddr\ttype\n");

    while(j<=n){
        c=a1[j];
        if (isalpha(c))
{        ptr=malloc(sizeof(char));
        printf("\n%c\t%p\tidentifer\n",a1[j],ptr);
        j++;

}    
        else if (!isalpha(c)){
            ptr=malloc(sizeof(char));
            printf("\n%c\t%p\t opertator\n",a1[j],ptr);
            j++;
        }
        else{
            break;
        }

}return 0;
}
