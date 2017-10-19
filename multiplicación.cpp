#include <iostream>
//using namespace std;


int main()
{
  int N=4;
  int NB=2;
  double A[4][4];
  double B[4][4];
  double C[4][4];
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j){
      A[i][j]=i;
      B[i][j]=i+j;
      C[i][j]=0;
    }
  }
  
  for(int ii=0;ii<N;ii+=NB){
    for(int jj=0;jj<N;jj+=NB){
      for(int kk=0;kk<N;kk+=NB){
	for(int i=ii;i<std::min(N,ii+NB);++i){
	  for(int j=jj;j<std::min(N,jj+NB);++j){
	    for(int k=kk;k<std::min(N,kk+NB);++k){
	      C[i][j]+= A[i][k]*B[k][j];
	    }
	  }
	}
      }
    }
  }
  std::cout<<C[2][3]<<std::endl;
}
