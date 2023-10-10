#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1406
#define M 200
typedef struct Samples{ //create my stuck that will have a collection of samples with their parameters
float degrees;
float PO4uM;
float SiO3uM;
float NO2uM ;
float NO3uM;
float Salnty;
float O2ml_L;
char dates[M];
}Samples;
void storelements(Samples x[] , FILE *filename);
void copystructs(Samples base[], Samples copy[]);
void displaysamples(Samples x[]);
void insertion(Samples x[]);
void displayinsertion(Samples x[]);
void quicksort(Samples x[], int low , int high);
int piviot(Samples x[] , int low , int high);
void swap(Samples x[], Samples s[]);
void displayquicksort(Samples x[]);
float findthemin(Samples x[]);
float findthemax(Samples x[]);
//void countingsort(Samples x[]);
char * copyjustdatesandsortthem(Samples x[]);
int binarysearch( char *dates[],Samples x[], char date[] ,int min, int max);
int main(){
FILE *file;
file=fopen("ocean.csv" ,"r");
char line[200];
if(file==NULL){
perror("Error: ");
return 1;
}
Samples s[N],p[N];
char *po[N];
float max,min;
storelements(s,file);
copystructs(p,s);
//insertion(p);
// displaysamples(p );
//displayinsertion(p);
//quickSort(p,0,N-1);
//displayquicksort(p);
//countingsort(p);
po=copyjustdatesandsortthem(p );
printf("%s" , po);
char givendate[20];
printf("Give a date:");
scanf("%s" , givendate);
binarysearch( po,p, givendate ,min,max );
fclose(file);
return 0;
}
char * copyjustdatesandsortthem(Samples x[]){
char temp[100];
static char *dates[N];
for(int i=0; i<N; i++){
dates[i]=x[i].dates;}
int i;
char *month[N];
char *year[N];
char *day[N];
char *p;
char line[100];
for( i=1; i<N; i++){
strcpy(line , x[i].dates);
p=strtok(line , " /");
sscanf(p ,"%s" , &month[i]);
p=strtok(NULL , " /");
sscanf(p ,"%s" , &day[i]);
p=strtok(NULL , " ,");
sscanf(p ,"%s" , &year[i]);
}
for(int i=0; i<N; i++){
while(year[i]==2000){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2001){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2002){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2003){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2004){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2005){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2006){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2007){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2008){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2009){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2010){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2011){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2012){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2013){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2014){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2015){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2016){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2017){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2018){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
while(year[i]==2019){
int jmin=i;
for(int j=jmin+1; j<N; j++)
if(strcmp(dates[j] , dates[jmin])<0)
jmin=j;
if(jmin!=i){
strcpy(temp,dates[i]);
strcpy(dates[i],dates[jmin]);
strcpy(dates[jmin],temp);
}
}
}
//printf("%s", dates[702]);
//for(int i=0; i<N; i++){
// printf("%s\n" ,dates[i]);
// }
printf("%s" , dates);
return dates;
}
int binarysearch(char *dates[],Samples x[], char date[],int min ,int max){
//min=findthemin(x);
// max=findthemax(x);
min=0;
max=N;
if (max >= min) {
int mid=min+(max-1)/2;
printf("%s" , &dates[mid]);
if (strcmp(dates[mid] , &date)==0)
printf("%f" , x[mid].degrees);
return 0;
if (strcmp(dates[mid] , &date)>0){
int data= binarySearch(x, min, mid - 1, date);
printf("%f" , x[data].degrees);
return 0;
}
else{
int data=binarySearch(x, mid + 1, max,date);
printf("%f" , x[data].degrees);
return 0;
}
}
return -1;
}
void storelements(Samples x[] , FILE *filename){
char line[200];
int i ;
while(fgets(line , sizeof(line) , filename )){
char *p;
p=strtok(line , " , ");
while(p!=NULL){
sscanf(p,"%s " ,x[i].dates );
p=strtok(NULL , ",");
x[i].degrees=atof(p);
sscanf(p,"%f " ,&x[i].degrees );
p=strtok(NULL , ",");
x[i].NO2uM=atof(p);
sscanf(p,"%f " ,&x[i].PO4uM );
p=strtok(NULL , ",");
x[i].NO3uM=atof(p);
sscanf(p,"%f " ,&x[i].SiO3uM);
p=strtok(NULL , ",");
x[i].O2ml_L=atof(p);
sscanf(p,"%f " ,&x[i].NO2uM );
p=strtok(NULL , ",");
x[i].PO4uM=atof(p);
sscanf(p,"%f " ,&x[i].NO3uM );
p=strtok(NULL , ",");
x[i].Salnty=atof(p);
sscanf(p,"%f " ,&x[i].Salnty );
p=strtok(NULL , ",");
x[i].O2ml_L=atof(p);
sscanf(p,"%f " ,&x[i].O2ml_L);
p=strtok(NULL , ",");
}
i++;
}
}
void copystructs(Samples copy[], Samples base[]){
for(int i=0; i<N; i++){
copy[i].degrees=base[i].degrees;
copy[i].NO2uM=base[i].NO2uM;
copy[i].NO3uM=base[i].NO3uM;
copy[i].O2ml_L=base[i].O2ml_L;
copy[i].PO4uM=base[i].PO4uM;
copy[i].Salnty=base[i].Salnty;
copy[i].SiO3uM=base[i].SiO3uM;
strcpy(copy[i].dates, base[i].dates);
}
}
void displaysamples(Samples x[]){
for(int i=0; i<N; i++){
printf("%d\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t" ,i , x[i].dates ,x[i].degrees, x[i].PO4uM , x[i].SiO3uM , x[i].NO2uM ,x[i].NO3uM , x[i].Salnty ,x[i].O2ml_L);
printf("\n");
}
}
void insertion(Samples x[]){
int i,j;
Samples key[N];
for(i=1; i<N; i++){
key[i].degrees=x[i].degrees;
strcpy(key[i].dates,x[i].dates);
j=i-1;
while(j>=0 && x[j].degrees>key[i].degrees)
{
x[j+1].degrees=x[j].degrees;
strcpy(x[j+1].dates,x[j].dates);
j=j-1;
}
x[j+1].degrees=key[i].degrees;
strcpy(x[j+1].dates, key[i].dates);
}
}
void displayinsertion(Samples x[]){
for(int i=0; i<N; i++){
printf("%d\t%s\t%f" ,i , x[i].dates ,x[i].degrees);
printf("\n");
}
}
void swap(Samples x[] , Samples s[]){
x->degrees=s->degrees;
s->degrees=x->degrees;
}
int piviot(Samples x[], int low , int high)
{
float piviot=x[high].degrees;
int i=low-1; //tracks the smallest element and find the correct position
for(int j=low; j<=high-1; j++){
if(x[j].degrees<piviot){
i++;
//x[i].degrees=x[j].degrees;
//strcpy(x[i].dates,x[j].dates);
swap(&x[i].degrees,&x[j].degrees);
swap(x[i].dates,x[j].dates);
}
}
//x[i+1].degrees=x[high].degrees;
// strcpy(x[i+1].dates,x[high].dates);
swap(&x[i + 1].degrees, &x[high].degrees);
swap(x[i+1].dates,x[high].dates);
return (i + 1);
}
void quickSort(Samples x[], int low , int high)
{
if (low < high)
{
float pi = piviot(x,low , high);
quickSort(x, low, pi - 1);
quickSort(x, pi + 1, high);
}
}
void displayquicksort(Samples x[])
{
for(int i=0; i<N; i++){
printf("%d\t%s\t%f" ,i , x[i].dates ,x[i].degrees);
printf("\n");
}
}
float findthemin(Samples x[]){
float min=x[0].degrees;
for(int i=0; i<N; i++){
if(x[i].degrees<min)
min=x[i].degrees;
}
return min;
}
float findthemax(Samples x[]){
float max=0;
max=x[0].degrees;
for(int i=0; i<N; i++){
if(x[i].degrees>max)
max=x[i].degrees;
}
return max;
}
void countingsort(Samples x[]){
float min=findthemin(x);
float max=findthemax(x);
int track[N] ,i ;//number of occurrences
int j;
memset(track, 0, sizeof(track));
for(int i =1; i<N; i++){
while(j <N){
if(x[i].PO4uM==x[j].PO4uM){
track[i]=track[i] +1;}
j++;
}
track[i]=track[i]+1;
}
for(int i =0; i<N; i++){
printf("%d\t%d\n",i, track[i]);
}
} 
