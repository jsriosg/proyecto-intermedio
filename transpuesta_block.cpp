#include <iostream>
#include <vector>

std::vector<double>transpuesta(const std::vector<double> A, int N , int NB){
  std::vector<double> At(N*N);
  for(int ii=0;ii<N;ii+=NB)
    for(int jj=0;jj<N;jj+=NB)
      for(int kk=0;kk<N;kk+=NB)
	for(int i=ii;i<std::min(N,ii+NB);++i)
	  for(int j=jj;j<std::min(N,jj+NB);++j)
	    for(int k=kk;k<std::min(N,kk+NB);++k)
	      At[(i*N)+j]+= A[(j*N)+i];
  return At;
}
int main (int argc, char* argv[]){
  int N=atoi(argv[1]);
  int NB=2;
  std::vector<double> A(N*N);
  std::vector<double> At(N*N);
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j){
      A[(i*N)+j]=rand();
      At[(i*N)+j]=0;
    }
  }
  At = transpuesta(A,N,NB);
  std::cout<<N<<" done"<<std::endl;
}
