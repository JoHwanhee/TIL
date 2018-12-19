
# 프로세스 종료 없이 ssh exit하는 방법

```
$ python3 test.py

$ ctrl + z

[1]+ Stopped 					python3 test.py

$ bg 1

$ disown -a
$ exit
```
