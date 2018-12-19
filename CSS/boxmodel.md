# Box model
html 에서 태그 하나하나를 박스로 취급하여 부피감을 갖게 한다.

```html
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>box</title>

    <style >
      /*block level element*/
      /*h1 {
        border-width:5px;
        border-color:red;
        border-style:solid;
        display:inline;
      }

      inline level
      a {
        border-width:5px;
        border-color:red;
        border-style:solid;
        display:block;
      }*/
      /*h1, a{
        border:5px solid red;
        display:inline;
      }*/
      h1 {
        border:5px solid red;
        padding:50px;
        margin:20;
        width:100px;
        display: inline;
      }

    </style>
  </head>
  <body>
    <h1>CSS</h1>
    <h1>CSS</h1>
  </body>
</html>
```

[](./images/boxmodel.jpg)