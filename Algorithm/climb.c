int climb(int n){
  if( n == 0 )
    return 1;
    
  return climb(n - 1) + climb(n - 2) + climb(n - 3);
}

printf("%d", climb(5));
