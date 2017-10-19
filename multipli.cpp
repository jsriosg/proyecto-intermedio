#include<iostream>
#include<vector>
std::vector<double> multipli (const std::vector<double> A,const std::vector<double> B, int N){
  std::vector<double> C(N*N);
  for(int i = 0; i < N ; ++i){
    for(int j = 0; j < N ; ++j){
      for(int k = 0 ; k < N ; ++k){
	C[(i*N)+j] += A[(i*N)+k]*B[(k*N)+j];
      }
    }
  }
  return C;
}
int main(int argc, char* argv[]){
    int N=atoi(argv[1]);
  std::vector<double> A(N*N);
  std::vector<double> B(N*N);
  std::vector<double> C(N*N);//C=A*B -> C[i][j] = A[i][k]*B[k][j]
  srand(1);
  for(int i=0;i<N*N;++i){
    A[i]=rand();
  }
  srand(3);
  for(int i=0;i<N*N;++i){
    B[i]=rand();
  }
  std::cout << A[5] << '\t' << B[5] << std::endl;
  /*for(int i = 0; i < N ; ++i){
    for(int j = 0; j < N ; ++j){
      for(int k = 0 ; k < N ; ++k){
	C[(i*N)+j]+=A[(i*N)+k]*B[(k*N)+j];
      }
    }
    }*/
  C = multipli(A,B,N);
  std::cout << C[24] << std::endl;
}
