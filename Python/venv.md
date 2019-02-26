### 가상환경이란?  
프로젝트를 진행하다보면 외부 패키지의 버전관리와 디펜던시 관리는 필수적으로 진행되어야 한다. 파이썬에서는 디펜던시 관리를 가상환경으로 관리를 하고 있다.

---
### 설정

python에서 제공되는 기능으로 간단히 설정할 수 있다. 아래처럼 하면 가상환경 폴더가 생성된다.

```
[root@s16786679aff testProject]# python3 -m venv venv
[root@s16786679aff testProject]# ls
venv
```

---
### 활성화

설정이 되었다면 아래와 같이 활성화를 해준다. (venv)가 보이면 성공.

```
[root@s16786679aff testProject]# source venv/bin/activate
(venv) [root@s16786679aff testProject]#
```

---
### 패키지 설치해보기

Flask를 설치하고 실행해보자.

```
(venv) [root@s16786679aff testProject]#pip3 install flask
(중략)
Successfully installed Jinja2-2.10 MarkupSafe-1.1.1 Werkzeug-0.14.1 click-7.0 flask-1.0.2 itsdangerous-1.1.0
```

소스 작성
```python
from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello World!'

if __name__ == '__main__':
    app.run()
```

동작 확인
```
(venv) [root@s16786679aff testProject]# python3 app.py
 * Serving Flask app "app" (lazy loading)
 * Environment: production
   WARNING: Do not use the development server in a production environment.
   Use a production WSGI server instead.
 * Debug mode: off
 * Running on http://127.0.0.1:5000/ (Press CTRL+C to quit)
```

---
### 가상환경 종료

아래와 같이 가상환경을 빠져나올 수 있다.
```
(venv) [root@s16786679aff testProject]# deactivate
[root@s16786679aff testProject]#
```

---
### 디펜던시 관리하기 requirements.txt

아래와 같이 입력하면 requirements.txt 파일이 생성된걸 볼 수 있다.
```
[root@s16786679aff testProject]# pip freeze > requirements.txt
[root@s16786679aff testProject]# ls
app.py  requirements.txt  venv
```

vi requirements.txt 로 열어보면 현재 관리되고 있는 디펜던시를 확인할 수 있다.
```
      1 bottle==0.12.16
      2 Click==7.0
      3 docutils==0.14
      4 EasyProcess==0.2.3
      5 Flask==1.0.2
      6 itsdangerous==1.1.0
      7 Jinja2==2.10
      8 lockfile==0.12.2
      9 MarkupSafe==1.1.0
     10 pidlockfile==0.3
     11 python-daemon==2.2.0
     12 PyVirtualDisplay==0.2.1
     13 selenium==3.141.0
     14 urllib3==1.24.1
     15 Werkzeug==0.14.1
```

새로운 패키지를 추가하고 pip install -r requirements.txt를 통해 패키지를 관리할 수 있다.
