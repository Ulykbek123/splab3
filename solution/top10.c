#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
int nbytes=0;
char str[1000];
int lineCount();
void process(int size);

int main(){
	printf("%d\n",lineCount());
	int size = lineCount();
	process(size);
	return 0;

}
int lineCount(){
	int A[2]; // pipe A
	pipe(A);
	pid_t pid1 = fork(); // cat
	if (!pid1) {
		dup2(A[1], 1);
		close(A[0]);
		close(A[1]);
		execlp("cat","cat", "log.txt", NULL);
		
	}
	
	int B[2];
	pipe(B);
	pid_t pid2 = fork();
	if(!pid2){
		dup2(A[0], 0);
		close(A[0]);
		close(A[1]);

		dup2(B[1], 1);
		close(B[0]);
		close(B[1]);

		execlp("cut","cut","-d ","f11", NULL);

	}
	close(A[0]);
	close(A[1]);

	int C[2];
	pipe(C);
	pid_t pid3 = fork();
	if(!pid3){
		dup2(B[0], 0);
		close(B[0]);
		close(B[1]);

		dup2(C[1], 1);
		close(C[0]);
		close(C[1]);

		execlp("grep","grep","-v","\"-\"", NULL);

	}
	close(B[0]);
	close(B[1]);

	int D[2];
	pipe(D);
	pid_t pid4 = fork();
	if(!pid4){
		dup2(C[0], 0);
		close(C[0]);
		close(C[1]);

		dup2(D[1], 1);
		close(D[0]);
		close(D[1]);

		execlp("sort","sort","", NULL);

	}

	close(C[0]);
	close(C[1]);

	int E[2];
	pipe(E);
	pid_t pid5 = fork();
	if(!pid5){
		dup2(D[0], 0);
		close(D[0]);
		close(D[1]);

		dup2(E[1], 1);
		close(E[0]);
		close(E[1]);

		execlp("uniq","uniq","-c", NULL);

	}
	
	close(D[0]);
	close(D[1]);

	
	int F[2];
	pipe(F);
	pid_t pid6 = fork();
	if(!pid6){
		dup2(E[0], 0);
		close(E[0]);
		close(E[1]);

		dup2(F[1], 1);
		close(F[0]);
		close(F[1]);

		execlp("sort","sort","-rn", NULL);

	}
	
	close(E[0]);
	close(E[1]);
	
	int G[2];
	pipe(G);
	pid_t pid8 = fork();
	if(!pid8){
		dup2(F[0], 0);
		close(F[0]);
		close(F[1]);

		dup2(G[1], 1);
		close(G[0]);
		close(G[1]);

		execlp("cat","cat","-n", NULL);

	}
	
	close(F[0]);
	close(F[1]);
	
	int H[2];
	pipe(H);
	pid_t pid9 = fork();
	if(!pid9){
		dup2(G[0], 0);
		close(G[0]);
		close(G[1]);

		dup2(H[1], 1);
		close(H[0]);
		close(H[1]);

		execlp("awk","awk","{print $1"." $3"-" $2"-" int ($2/1120*100) "%"}", NULL);

	}
	
	close(G[0]);
	close(G[1]);

	int K[2];
	pipe(K);
	pid_t pid10 = fork();
	if(!pid10){
		dup2(H[0], 0);
		close(H[0]);
		close(H[1]);

		dup2(K[1], 1);
		close(K[0]);
		close(K[1]);

		execlp("head","head","-n", "-10", NULL);

	}

	
	close(T[0]);
	close(T[1]);
	close(K[1]);
	
	close(G[0]);
	close(G[1]);

	int K[2];
	pipe(K);
	pid_t pid10 = fork();
	if(!pid10){
		dup2(H[0], 0);
		close(H[0]);
		close(H[1]);

		dup2(K[1], 1);
		close(K[0]);
		close(K[1]);

		execlp("head","head","-n", "-10", NULL);

	}

	
	close(H[0]);
	close(H[1]);
	close(H[1]);
	
				execlp("head","head","-n", "-10", NULL);

	FILE* Cin = fdopen(K[0],"r"); // Cin is FILE* object made from C[0]
	int x,sum=0;
	while(fscanf(Cin,"%d",&x)>0){ // this loop is like the loop of shell
		sum+=x;
	}
	return sum;		
	
}

void process(int size){
	int A[2]; // pipe A
	pipe(A);
	
	pid_t pid1 = fork(); // cat
	if (!pid1) {
		dup2(A[1], 1);
		close(A[0]);
		close(A[1]);
		execlp("cat","cat", "log.txt", NULL);
		
	}
	
	int B[2];
	pipe(B);
	
	pid_t pid2 = fork();
	if(!pid2){
		dup2(A[0], 0);
		close(A[0]);
		close(A[1]);

		dup2(B[1], 1);
		close(B[0]);
		close(B[1]);

		execlp("cut","cut","-d ","-f1,11", NULL);

	}
	close(A[0]);
	close(A[1]);

	int C[2];
	pipe(C);
	pid_t pid3 = fork();
	if(!pid3){
		dup2(B[0], 0);
		close(B[0]);
		close(B[1]);

		dup2(C[1], 1);
		close(C[0]);
		close(C[1]);

		execlp("grep","grep","-v","\"-\"", NULL);

	}
	close(B[0]);
	close(B[1]);

	int D[2];
	pipe(D);
	pid_t pid4 = fork();
	if(!pid4){
		dup2(C[0], 0);
		close(C[0]);
		close(C[1]);

		dup2(D[1], 1);
		close(D[0]);
		close(D[1]);

		execlp("sort","sort","-k1", NULL);

	}

	close(C[0]);
	close(C[1]);

	int E[2];
	pipe(E);
	pid_t pid5 = fork();
	if(!pid5){
		dup2(D[0], 0);
		close(D[0]);
		close(D[1]);

		dup2(E[1], 1);
		close(E[0]);
		close(E[1]);

		execlp("awk","awk","{if(lastAddress != $1){print lastAddress,count;lastAddress = $1;count =1;}else{count ++;}}", NULL);

	}
	
	close(D[0]);
	close(D[1]);

	
	int F[2];
	pipe(F);
	pid_t pid6 = fork();
	if(!pid6){
		dup2(E[0], 0);
		close(E[0]);
		close(E[1]);

		dup2(F[1], 1);
		close(F[0]);
		close(F[1]);

		execlp("sort","sort","-k2","-n","-r", NULL);

	}
	
	close(E[0]);
	close(E[1]);

	int H[2];
	pipe(H);
	pid_t pid7 = fork();
	if(!pid7){
		dup2(F[0], 0);
		close(F[0]);
		close(F[1]);

		dup2(H[1], 1);
		close(H[0]);
		close(H[1]);

		execlp("head","head", NULL);

	}
	
	close(F[0]);
	close(F[1]);

	int R[2];
	pipe(R);
	pid_t pid8 = fork();
	if(!pid8){
		dup2(H[0], 0);
		close(H[0]);
		close(H[1]);

		dup2(R[1], 1);
		close(R[0]);
		close(R[1]);
		char s[]="";
		sprintf(s, "{print $1,\"-\",$2,\"-\",$2/%d*100,\"%s\";}",size,"%");
		execlp("awk","awk",s, NULL);
	}
	close(H[0]);
	close(H[1]);
	 while ((nbytes = read(R[0], str, 1000)) > 0) 
            printf("%s\n", str); 
}
