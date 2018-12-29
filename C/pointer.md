# 여러 포인터 종류들
	
### 포인터 배열
원소가 포인터인 배열, 주로 여러줄의 문자열을 나타낼때 쓴다.
```C
char *arps[] = { "고양이","개","오랑우탄","돼지","지렁이" };
int i;

for (i = 0; i < 5; i++) 
{
	printf("%s\n", arps[i]);
}
```

### 배열 포인터
단순히 배열의 번지수를 담는 포인터, 주로 2중 배열 인자로 받기 위해 쓴다..
```C
int arr[5][4] =
{
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12}
};

int (*ptr)[4] = (int (*)[4])malloc(sizeof(int) * 5 * 4);
ptr[1][2] = 1;
printf("%d\n", ptr[1][2]);
```

### 2중포인터
포인터의 포인터!
```C
int **ppArr = (int **)malloc(sizeof(int *) * 5);

for(int i = 0; i < 5; i++)
{
	ppArr[i] = (int *)malloc(sizeof(int) * 4);
}
ppArr[1][2] = 10;
printf("%d\n", ppArr[1][2]);
```