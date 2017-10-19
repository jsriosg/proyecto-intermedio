#include<iostream>
#include <vector>
std::vector<double>multipli(const std::vector<double> A , const std::vector<double> B, int N , int NB){
  std::vector<double> C(N*N);
  for(int ii=0;ii<N;ii+=NB)
    for(int jj=0;jj<N;jj+=NB)
      for(int kk=0;kk<N;kk+=NB)
	for(int i=ii;i<std::min(N,ii+NB);++i)
	  for(int j=jj;j<std::min(N,jj+NB);++j)
	    for(int k=kk;k<std::min(N,kk+NB);++k)
	      C[(i*N)+j]+= A[(i*N)+k]*B[(k*N)+j];
  return C;
}

int main (int argc, char* argv[]){
  int N=atoi(argv[1]);
  int NB=2;
  std::vector<double> A(N*N);
  std::vector<double> B(N*N);
  std::vector<double> C(N*N);
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j){
      A[(i*N)+j]=rand();
      B[(i*N)+j]=rand()*rand();
      C[(i*N)+j]=0;
    }
  }
  C = multipli(A,B,N,NB);
  std::cout<<C[(1*N)+2]<<std::endl;
}


