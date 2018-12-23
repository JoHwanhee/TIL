# 오브젝트, 타입, 변수에 대하여  

1. Object  
실행시에 표현할 수 있는 값들을 저장하는 곳을 Object라고 합니다.  
예를들어, printf("%d" ,10) 이라고 할 경우에 10이라는 숫자는 한 어느 저장소에 들어있고 이 저장소를 Object라고 합니다.  

2. 타입
타입은 큰 의미로 Object 타입과  function 타입으로 나뉘어집니다. 또 다시 Object 타입은 complete 타입과 imcomplete 타입으로 나뉘어지며  
complete 타입은 `크기를 결정할 정보가 완전한 경우` 입니다.  ( basic types and pointer type )
imcomptete 타입은 `크기를 결정할 정보가 불완전한 경우` 입니다.  ( void, array of unkown size, structure, union, enum )

3. 변수
변수 = Object + 식별자

# References
1. http://www.msg.ucsf.edu/local/programs/IBM_Compilers/C:C++/html/language/ref/clrc03incotyp.htm
