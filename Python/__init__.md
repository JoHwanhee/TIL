#### 파이썬__init.py__ ####
package 초기화 역할을 하는 파일, package에는 __init.py__가 있어야한다.

package ?  
- 모듈의 모임  

package이름의 의미는?  
- 모듈을 모아둔 디렉토리의 이름 

init.py ?
- __all__ : import *을 했을 때, 포함될 모듈들의 이름  
- __version__ : package의 버전


활용 하는 방법은 ?
1. 그렇다면 다음과 같이 파일 구조가 되어있고,  
```
myItems - __init.py__  
        - phone.py  
        - mic.py
```


2. home>__init.py에 다음과 같이 기입되어있다면,  
```
__all__=["phone", "mic"]
```

3. from home import *를 했을시 __all__에 정의된 phone.py와 mic.py가 임포트 된다.
