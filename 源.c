#include<stdio.h>
#include<pthread.h>
#include<time.h>
int m=0;
long long sum=0;
pthread_mutex_t lock;
void mythread(){
	usleep(1000);
	while(1){
		pthread_mutex_lock(&lock);
		if(m>0){
			sum+=m--;
			printf("THREAD!  sum: %d   m: %d\n",sum,m);
			//usleep(100000);
			pthread_mutex_unlock(&lock);
			}
		else{
			pthread_mutex_unlock(&lock);
			break;
			}
		}
	}

int main(){
	int n=0;
	pthread_t id[100];
	
	//输入
	FILE *ff;
	if(!(ff=fopen("input.txt","r"))){
		printf("File open failed.");
		return 0;
		}
	fseek(ff,2,0);
	fscanf(ff,"%d",&m);
	fseek(ff,2,1);
	fscanf(ff,"%d",&n);
	
	//计算
	for(int i=0;i<n;i++){
		pthread_create(&id[i],NULL,(void*)mythread,NULL);
		printf("create new!\n");
		}
	for(int i=0;i<n;i++)
		pthread_join(id[i],NULL);
	pthread_mutex_destroy(&lock);
	
	//输出
	fclose(ff);
	ff=fopen("output.txt","w");
	fprintf(ff,"%d",sum);
	fclose(ff);
	}
