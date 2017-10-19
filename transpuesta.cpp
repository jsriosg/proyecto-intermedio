#include <iostream>
#include <vector>

std::vector<double> transp( const std::vector<double> M ,int N){
  std::vector<double> Mt(N*N);
  for(int i = 0 ; i < N ; ++i ){
    for(int j = 0; j < N ; ++j ){
      Mt[(i*N) + j] = M[(j*N)+i]; 
    }
  }
  return Mt;
}

int main(int argc, char* argv[]){
  int N=atoi(argv[1]);
  srand(0);
  std::vector<double> M(N*N);
  std::vector<double> Mt(N*N);
  for(int m = 0 ; m < N*N ; ++m){
    M[m]=rand();
  }
  Mt = transp(M,N);
  int ii=0;
  int jj=1;
  std::cout << M[(ii*N)+jj] << '\t' << Mt[(jj*N)+ii] << std::endl;
}
