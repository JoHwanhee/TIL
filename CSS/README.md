# CSS 학습 내용
CSS는 html에서 기능적 요소와 디자인적 요소를 분리하고자 개발된 언어이다.

만약 다음과 같은 코드에서 글자의 색상을 변경하고자 한다면.
```html
  <h1><a href="index.html">WEB</a></h1>
  <ol>
    <li><a href="1.html">HTML</a></li>
    <li><a href="2.html">CSS</a></li>
    <li><a href="3.html">JavaScript</a></li>
  </ol>
```

이와 같이 html에서 문서의 구조가 아닌, 디자인적 기능을 하는 태그를 이용하게 된다. 
```html
  <h1><a href="index.html"><font color="red">WEB</font></a></h1>
  <ol>
    <li><a href="1.html"><font color="red">HTML</font></a></li>
    <li><a href="2.html"><font color="red">CSS</font></a></li>
    <li><a href="3.html"><font color="red">JavaScript</font></a></li>
  </ol>
```

이럴때 html에서 디자인적 기능을 분리하는 CSS를 이용하면, html은 문서의 구조만을 나타내게 되고 코드의 가독성은 훨씬 올라갈 수 있다.
```html
<head>
  <title>JoHwanhee</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="css/uikit.min.css" />
  <script src="js/uikit.min.js"></script>
  <script src="js/uikit-icons.min.js"></script>

  <style>
    a {
      color: black;
      text-decoration: none;
    }
  </style>
</head>

<body background="">
  <h1><a href="index.html">WEB</a></h1>
  <ol>
    <li><a href="1.html">HTML</a></li>
    <li><a href="2.html" style="color:red; text-decoration:underline;">CSS</a></li>
    <li><a href="3.html">JavaScript</a></li>
  </ol>
  <h2>CSS</h2>
  <p>
    Cascading Style Sheets (CSS) is a style sheet language used for describing the presentation of a document written in a markup language.[1] Although most often used to set the visual style of web pages and user interfaces written in HTML and
    XHTML, the language can be applied to any XML document, including plain XML, SVG and XUL, and is applicable to rendering in speech, or on other media. Along with HTML and JavaScript, CSS is a cornerstone technology used by most websites to
    create visually engaging webpages, user interfaces for web applications, and user interfaces for many mobile applications.
  </p>
</body>
```
