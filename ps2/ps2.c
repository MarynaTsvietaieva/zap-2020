#include <stdio.h>




float lift_a_car(const int, const int, const int);
float unit_price(const float, const int, const int);
int collatz(const int);
int opposite_number(const int, const int);
int counter(const int[], const int, int[]);
unsigned long sum_squared(const int);
int array_max(const int[], const int);
int array_min(const int[], const int);
unsigned long special_counter(const int[], const int);
int special_numbers(const int[], const int, int[]);
int main(){      

printf("%.4f\n", lift_a_car(2, 80, 1400));
printf("%.4f\n", lift_a_car(4, 90, 1650));

printf("%.4f\n", unit_price(4.79, 16, 150));
printf("%.4f\n", unit_price(5.63, 20, 200));


printf("%d\n", collatz(20));
printf("%d\n", collatz(35));

printf("%d\n", opposite_number(10, 2));
printf("%d\n", opposite_number(12, 9));

int input_array[] = {16,17,4,3,5,2};
int result_array[6];
counter(input_array, 6, result_array);
printf("%d %d\n", result_array[0], result_array[1]);

printf("%lu\n", sum_squared(1));
printf("%lu\n", sum_squared(2));
printf("%lu\n", sum_squared(3));

printf("%d\n", array_min(input_array, 5));
printf("%d\n", array_max(input_array, 5));
printf("%d\n", array_max(NULL, 5));

//int input_array[] = {11,12,13,14,15};
printf("%lu\n", special_counter(input_array, 5));

//int input_array[] = {16,17,4,3,5,2};
//int result_array[6];
int count = special_numbers(input_array, 6, result_array);
for(int i = 0; i < count; i++){
   printf("%d ", result_array[i]);
 }
 printf("\n");

return 0;
}

float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
  float result =(float)(stick_length*human_weight)/(float)(human_weight + car_weight);
  int r =(float)result*100;
  float re = (float)r/(float)100;
  float okruglenie =(float)result - re;
  if(okruglenie > 0.005){
  re = re + 0.01;
  }
  return re;
 }

float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
  float result =(float)pack_price/(float)rolls_count/(float)pieces_count*(float)100;
int r =(float)result*100;
float re = (float)r/(float)100;
 float okruglenie =(float)result - re;
 if(okruglenie > 0.005){
  re = re + 0.01;
 }
return re;
 }

int collatz(const int number){
 int idx = 1;
 int cislo = number;
 while(cislo !=1){
  if ( cislo%2 == 0){
     cislo = cislo/2;
  }
  else{
 cislo = 3*cislo + 1;
  } 
  idx++;
 }
 return idx;
}

int opposite_number(const int n, const int number){
int opp;
if(number <  n/2){
 opp = n/2 + number;
   }
else if(number > n/2){
opp = -n/2 + number;
  }
 else{
  opp = 0;
   }
 return opp;
}

int counter(const int input_array[], const int array_size, int result_array[2]){
 result_array[1]=0;
 result_array[0]=0;

  for (int idx=0; idx < array_size; idx++){
   if(idx%2==0){
    result_array[0]= result_array[0] + input_array[idx];
    }
   else{
   result_array[1]=result_array[1] + input_array[idx];
  }
  }
  return 0;
}

//unsigned long sum_squared(const int line){

//if (line == 1){
//return 2;
//}
//int p = line +1;
//int l[p];
//int k[p];
//int sume=0;
//for(int s = 2; s <= line; s++){
// for(int idx=1;idx < s+1; idx++){
// if(s%2==0){
 // l[0]=1;
 // l[s+1]=1;
 // k[idx] = l[idx-1] + l[idx];
 // }
 // else{
 // k[0]=1;
 // k[s+1]=1;
 // l[idx]= k[idx-1] + k[idx];
 // }
  //if(s == line){
  //sume = 0 + l[idx]*l[idx];
// }
// if(line%2==0){
// return l[idx];
// }
// else{
// return 
// k[idx];
// }
// }
// }
// return 0;
// }


unsigned long sum_squared(const int line){
const int lien = line*2;
long long factorial1(long long, const int);
long long factorial(long long);
long long p = (long long)factorial1(lien,line)/(long long)factorial(line);
return p;
}

long long factorial(long long n){
if(n==0 || n ==1) return 1;
return n*factorial(n-1);
}


long long factorial1(long long k, const int a){
if (k > a){
 return k*factorial1(k-1, a);
 }
 else{
return 1;
}
}

int array_min(const int input_array[], const int array_size){

if(input_array == NULL){
 return -1;
}
int min = input_array[0];
 for(int idx=0; idx !=array_size; idx++){
  if(min>input_array[idx]){
   min = input_array[idx];
   }
}
return min;
}

int array_max(const int input_array[], const int array_size){
if(input_array == NULL){
return -1;
}
int  max = input_array[0];
for(int idx=0; idx !=array_size; idx++){
if( max < input_array[idx]){
 max = input_array[idx];
 }
}
return max;
}

unsigned long special_counter(const int input_array[], const int array_size){
int p=0;
for( int idx=0; idx < array_size; idx++){
 if(idx%2 == 0){
  p = p + input_array[idx];
  }
 else{
 p = p + input_array[idx]*input_array[idx];
 }
}
return p;
}

int special_numbers(const int input_array[], const int array_size, int result_array[]){
int p=0;
int m=0;
 for(int idx=0; idx < array_size; idx++){
 int k=0;
   for(int f= idx +1; f < array_size; f++){
   k=k+input_array[f];
  } 
  if(input_array[idx] > k){
  p=p+1;
  result_array[m] = input_array[idx];
  m = m +1;
 }
 }
 return p;
}



