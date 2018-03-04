#include<stdio.h>
#include<stdlib.h>
using namespace std;
// ´ð°¸ÓÃ1 2 3 4±íÊ¾
int ans[11] = {1};
//Ñ¡Ïî 
int opts[11][5] = {
	0,0,0,0,0,
	0,1,2,3,4,
	0,3,4,1,2,
	0,3,6,2,4,
	0,1,2,3,4,
	0,8,4,9,7,
	0,1,2,3,4,
	0,3,2,1,4,
	0,7,5,2,10,
	0,6,10,2,9,
	0,3,2,4,1
};
int opts_4[5][2]={	//question 4 
	0,0,
	1,5,
	2,7,
	1,9,
	6,10
};
int opts_6[5][2]={		// question 6
	0,0,
	2,4,
	1,6,
	3,10,
	5,9
};
int frequency(FILE *fp){
	int times[5]={0};
	
	for(int i=1;i<=10;i++){
		times[ans[i]]++;
	}
	int min=1,mint=times[1],max=1,maxt=times[1];
	
	for(int z=2;z<=4;z++){
		if(times[z]>maxt){
			maxt = times[z];
			max =z;
		}else if(times[z]<mint){
			mint = times[z];
			min = z;
		}
	}
	//ques 7 and 10
	if(opts[7][ans[7]]!= min){
		fprintf(fp," your answer:%d, the min answer:%d ",ans[7],min);
		return 7;
	}
	
	if(opts[10][ans[10]] != maxt-mint){
		fprintf(fp," your answer:%d, the cmp answer:%d ",ans[10],maxt-mint);
		return 10;
	}
	
	return 0;
}
int test(){
	//question 2
	if(opts[2][ans[2]]!=ans[5]){
//		printf("question 2 can't queried\n");
		return 2;
	}
	//ques 3
	int ans3 = ans[3];
	int ans2 = ans[2];
	int ans4 = ans[4];
	int ans6 = ans[6];
	bool ans3IsRight = false;
	switch(ans3){
		case 1:
			ans3IsRight =  ans3!=ans2 && ans3!=ans4 && ans3!=ans6;
			break;
		case 2:
			ans3IsRight =  ans6!=ans2 && ans6!=ans3 && ans6!=ans4;
			break;
		case 3:
			ans3IsRight =  ans2!=ans3 && ans2!=ans6 && ans2!=ans4;
			break;
		case 4:
			ans3IsRight =  ans4!=ans2 && ans4!=ans3 && ans4!=ans6;
			break;
	}
	if(!ans3IsRight){
//		printf("question 3 can't queried\n");
		return 3;
	}
	//ques 4
	int ques4_1 = opts_4[ans[4]][0];
	int ques4_2 = opts_4[ans[4]][1];
	if(ans[ques4_1]!=ans[ques4_2]){
//		printf("question 4 can't queried\n");
		return 4;
	}
	//ques 5
	int ques5PointQues = opts[5][ans[5]];
	if(ans[5]!=ans[ques5PointQues]){
//		printf("question 5 can't queried\n");
		return 5;
	}
	//ques 6
	int ques6_1 = opts_6[ans[6]][0];
	int ques6_2 = opts_6[ans[6]][1];
	if(ans[ques6_1] != ans[8] || ans[ques6_2] != ans[8]){
//		printf("question 6 can't queried\n");
		return 6;
	}
	//ques 8
	int ques8PointQues = opts[8][ans[8]];
	if(ans[ques8PointQues] - ans[1] == 1 || ans[ques8PointQues] - ans[1] == -1 || ans[ques8PointQues] - ans[1] == 0 ){
//		printf("question 8 can't queried\n");
		return 8;
	}
	
	//ques 9
	int ques9PointQues = opts[9][ans[9]];
	bool btw1_6 = ans[1] == ans[6];
	bool btw5_x = ans[ques9PointQues] == ans[5];
	if(btw1_6 == btw5_x){
//		printf("question 9 can't queried\n");
		return 9;
	}  
	
	return 0;
}

int main(){
	system("pause");
	
	FILE *fp = NULL;
	fp = fopen("res.txt", "w+");

 
	for(int a=1;a<=4;a++){	//1th
		ans[1]=a;
		for(int b=1;b<=4;b++){ //2th
		ans[2]=b;
			for(int c=1;c<=4;c++){ //3th
				ans[3]=c;
				for(int d=1;d<=4;d++){ //4th
					ans[4]=d;
					for(int e=1;e<=4;e++){ //5th
						ans[5]=e;
						for(int f=1;f<=4;f++){ //6th
							ans[6]=f;
							for(int g=1;g<=4;g++){ //7th
								ans[7]=g;
								for(int h=1;h<=4;h++){ //8th
									ans[8]=h;
									for(int i=1;i<=4;i++){ //9th
										ans[9]=i;
										for(int j=1;j<=4;j++){ //10th
											ans[10] = j;
											int isRight = test();
											
											
											if(isRight == 0){
												for(int k=1;k<=10;k++){
													printf("%d ",ans[k]);
													fprintf(fp,"%d ",ans[k]);
												}
												int fre = frequency(fp) ;
												if(fre == 0){
													fprintf(fp,"right\n");
												}else{
													fprintf(fp,"question %d wrong\n",fre);
												}
											}
										} 
									} 
								} 
					
							} 
						} 
					} 
				} 
			} 
		} 
	}
	printf("Finish\n");
	system("pause");
	fclose(fp);
	return 0;
}
