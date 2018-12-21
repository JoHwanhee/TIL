# XSS(Cross Site Scripting)
지금 껏 HTTP서버 개발을 진행해왔지만, 웹 취약점에 대해 이제서야 알게된 것이 너무 부끄러워 쓰는 글이다.

#### XSS란?
XSS는 공격자에 의해 악의적으로 작성된 스크립트가 다른 사용자에게 전달 되는 것을 의미한다. 가볍게는 페이지를 Redirection 시키는 일을 할 수 있고, 더 나아가 세션 정보를 탈취하는 등 심각한 이슈를 초래할 수 있다.

#### 동작원리
1. XSS 방어조치가 안되어있는 서버에 악의적인 스크립트를 작성하여 저장한다.
2. 웹 서비스 이용자가 해당 스크립트에 접근한다.
3. 웹서버에서 접근한 사용자에게 코드를 전달한다.
4. 사용자 시스템 (웹 브라우져)에서 XSS 코드를 실행한다.
5. 공격 성공!!

- 생각하면 간단하다. XSS 방어조치가 되어있지 않은 웹 서버에 스크립트를 저장하고, 다른 피해자들이 그 스크립트를 접근하는 그런 원리다.
- 결국 다른 피해자들은 브라우져를 통해 접근할테니, 스크립트를 온전히 읽어버리는 것이다.

#### 방어조치
가장 심플하게, 저장되는 글에 부등식기호(<, >)를 &lt; &gt; 등으로 Replace하여 저장하는 방법이 있다. 혹은 <script>가 포함된 글은 무시한다던지..

```python
    description = description.replace('<', '&lt;')
    description = description.replace('>', '&gt;')
```


#### 실습
1. 웹 서버를 준비한다.

```python
#!/usr/local/bin/python3
print("Content-Type: text/html")
print()
import cgi, os, view
 
form = cgi.FieldStorage()
if 'id' in form:
    pageId = form["id"].value
    description = open('data/'+pageId, 'r').read()
    update_link = '<a href="update.py?id={}">update</a>'.format(pageId)
    delete_action = '''
        <form action="process_delete.py" method="post">
            <input type="hidden" name="pageId" value="{}">
            <input type="submit" value="delete">
        </form>
    '''.format(pageId)
else:
    pageId = 'Welcome'
    description = 'Hello, web'
    update_link = ''
    delete_action = ''
print('''<!doctype html>
<html>
<head>
  <title>WEB1 - Welcome</title>
  <meta charset="utf-8">
</head>
<body>
  <h1><a href="index.py">WEB</a></h1>
  <ol>
    {listStr}
  </ol>
  <a href="create.py">create</a>
  {update_link}
  {delete_action}
  <h2>{title}</h2>
  <p>{desc}</p>
</body>
</html>
'''.format(
    title=pageId,
    desc=description,
    listStr=view.getList(),
    update_link=update_link,
    delete_action=delete_action))
```

2. 웹 페이지에서 스크립트를 입력한다.

![](./images/board.jpg)

3. 결과 확인.

#### references
1. https://opentutorials.org/course/3256/19935
2. https://terms.naver.com/entry.nhn?docId=3431916&cid=58437&categoryId=58437

