# Selector
CSS 선택자를 스스로 알아내는 방법
- ID는 한번만 등장하는것이 좋다.
- 우선순위는 구체적일수록 높다.
- 우선순위가 같으면 더 나중에 등장한 Selector가 적용된다.

```html
<!DOCTYPE html>
<html>

<head>
  <title>JoHwanhee</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="css/uikit.min.css" />
  <script src="js/uikit.min.js"></script>
  <script src="js/uikit-icons.min.js"></script>

  <style>
    /*좀 더 구체적인것이 우선순위가 더 높음*/
  
    /*id 선택자가 가장 우선순위 높음 : id는 단 한번만 등장하기 때문에! */
    #active {
      color : red;
    }
    /*class는 그 다음*/
    .saw {
      color : gray;
    }
    /*마지막은 태그 선택자*/
    a {
      color: black;
      text-decoration: none;
    }
    h1 {
      font-size: 60px;
      text-align: center;
    }
  </style>
</head>

<body background="">
  <h1><a href="index.html">WEB</a></h1>
  <ol>
    <li><a href="1.html" class="saw">HTML</a></li>
    <li><a href="2.html" class="saw" id="active">CSS</a></li>
    <li><a href="3.html">JavaScript</a></li>
  </ol>
  <h2>CSS</h2>
  <p>
    Cascading Style Sheets (CSS) is a style sheet language used for describing the presentation of a document written in a markup language.[1] Although most often used to set the visual style of web pages and user interfaces written in HTML and
    XHTML, the language can be applied to any XML document, including plain XML, SVG and XUL, and is applicable to rendering in speech, or on other media. Along with HTML and JavaScript, CSS is a cornerstone technology used by most websites to
    create visually engaging webpages, user interfaces for web applications, and user interfaces for many mobile applications.
  </p>
</body>

</html>
```


추가정보 : https://www.w3schools.com/csSref/css_selectors.asp
