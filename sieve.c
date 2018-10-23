#include "sieve.h"

int sieve(int n){
  //finding upper bound of list used in sieve
  int upperBound;
  if (n<10){
    upperBound = 10;
  }
  else{
    upperBound = (int) n*log(n) + n*log(log(n));
    //according to the AKS primality test
  }


  //creating a list of 1's (for true) to sieve through
  int numList[upperBound];
  int x;
  for (x = 0; x < upperBound; x++){
    numList[x] = 1;
  }


  //sieve algorithm
  int cnt = 1; //which # prime we're up to
  int prime = 2; //what the value of that prime is
  int i; //counter for for loop
  while (cnt != n){
    for (i = 1; i < upperBound; i++){
      if (numList[i] != 0 && i % prime == 0){
        numList[i] = 0;
      }
    }
    prime++;
    while (numList[prime] != 1){
      prime++;
    }
    cnt++;
  }
  return prime;
}
