# Grid
CSS레이아웃 구성 방법 중 가장 최근에 나온 기술로 그리드 형태의 레이아웃 구성에 유리하다.

#### Point 
1. Property를 다음과 같이 준다.
- display:grid;
- grid-template-columns: 150px 1fr;

#### ETC
- div, span은 모두 레이아웃을 위한 태그인데 div는 block level이고 span은 inline level이다.

```html
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
    <style>
      #grid {
        border:5px solid pink;
        display:grid;
        /*nfr : weight 라고 생각하면 됨*/
        grid-template-columns: 150px 1fr;
      }
      div {
        border:5px solid gray;
      }

    </style>
  </head>
  <body>
    <div id="grid">
      <div>NAVIGATION</div>
      <div>askdfjksadjfkls
        adjfklasdjfkasdjfkasdjkfsd
        jkfjsadkfjkasldfjklasdaskdf
        jksadjfklsadjfklasdjfkasdjfka
        sdjkfsdjkfjsadkfjkasldfjk
      </div>
    </div>
<!-- display : inline
    <span>NAVIGATION<span>
    <span>ARTICLE<span>
    -->
  </body>
</html>
```
