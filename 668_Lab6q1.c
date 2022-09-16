#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
int msum,csum;
void *crunner(void *param);
void *prunner(void *param);

int main(int argc,char *argv[]){
	
	pthread_t ptid,ctid;

	pthread_attr_t attr;

	pthread_attr_init(&attr);

	pthread_create(&ctid,&attr,crunner,argv[1]);
	pthread_create(&ptid,&attr,prunner,argv[1]);

	pthread_join(ctid,NULL);
	pthread_join(ptid,NULL);
	printf("csum-msum =%d\n",csum-msum);	

	return 0;
}
void *crunner(void *param){
	int upper=atoi(param);
	csum=0;
	if(upper>0){
		for(int i=0;i<=upper*2;++i){
		csum+=i;
		}
	}
	pthread_exit(0);
}
void *prunner(void *param){
	int upper=atoi(param);
	msum=0;
	if(upper>0){
		for(int i=0;i<=upper;++i){
		msum+=i;
		}
	}
	pthread_exit(0);
}
