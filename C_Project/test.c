#include <stdio.h>
void main(){
	int tmp=0;
	int max[]={1,0,2,5,8,4};
	int n=sizeof(max)/sizeof(max[0]);

	for(int i=0; i<=n;i++){
		if(tmp<max[i]){
			tmp=max[i];
		};
	};
	printf("max: %d", tmp):
	return 0;
}
