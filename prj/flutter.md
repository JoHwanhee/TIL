# 플러터로 개발하기

작년말 이사님의 추천(?)으로 올해 팀즈에서 플러터를 이용한 앱을 만들어보기로했습니다. 
큰 주제는 머테리얼 디자인 가이드와 플러터 학습으로 방향을 잡고 실제 서비스할 수 있는 앱을 런칭하는 것까지 목표를 세웠습니다.
이번 프로젝트에서 플루터를 통해 개발 하면서 느낀 주제들(머테리얼 가이드, UI 개발, 크로스플랫폼, 생산성)에 대해 이야기해볼까합니다.

### 머테리얼 디자인 가이드
플러터는 구글에서 개발하고 있는 프레임워크이며 머테리얼 디자인 가이드또한 구글에서 제시하는 UI 디자인 가이드다보니, 
프레임워크차원에서 머테리얼 디자인 가이드에 맞춰 개발을 진행할 수 있는 점이 상당히 매력적으로 다가왔습니다.

#### 다음은 플러터에서 제시하는 앱 테마 코드와 구글 머테리얼 디자인 가이드입니다.
```dart
  static Color lightPrimary = HexColor.fromHex("fdfdfd");
  static Color lightPrimaryLight = HexColor.fromHex("ffffff");
  static Color lightPrimaryDark = HexColor.fromHex("faf8f6");
  static Color lightAccent = HexColor.fromHex("ff9e00");
  static Color lightAccentLight = HexColor.fromHex("ffd69b");
  static Color lightAccentDark = HexColor.fromHex("ec8102");
  
  static ThemeData lightTheme = ThemeData(
    fontFamily: "NotoSans",
    backgroundColor: lightBG,
    accentColor:  lightAccent,
    primaryColorLight: lightPrimaryLight,
    primaryColorDark: lightPrimaryDark,
    primaryColor: lightPrimary,
    primaryIconTheme: IconThemeData(
      color: HexColor.fromHex("c4c4c4")
    ),
    
    // 중략
  );
```
![img](https://storage.googleapis.com/spec-host/mio-staging%2Fmio-design%2F1584058305895%2Fassets%2F1hg4iTKzTMMgtJRx7bhaE2kSYR5BRYz1g%2Fcolor-colorsystem-schemecreation-theme.png)

처음에는 생소한 디자인 가이드라 그런지 저도 그렇고 디자이너님도 그렇고 어떤식으로 방향을 잡아야할지 난항을 겪었으나, 
이후 개발을 직접 진행하면서는 전체적인 스타일이 다 잡힌 상태로 개발을 하는거라 그런지 코드양이 확실히 많이 줄고 새로운 컴포넌트를 추가할때도 편리하다는 장점이 있었습니다.
또한 테마변경 기능이 제공되어 다크테마 / 라이트테마 적용을 정말 색상값만 추가해주기만해도 바로 적용되는 모습을 봤을 때 감격을 눈물을 감출 수 없었습니다.

### UI 개발
플러터는 UI를 코드로 그립니다. 아래 처럼요

```dart
return Scaffold(
      body: SafeArea(
        child: Center(
            child: ListView(
              shrinkWrap: true,
              padding: EdgeInsets.only(left: 20.0, right: 20.0),
              children: <Widget>[
                email,
                SizedBox(height: 8.0),
                password,
                SizedBox(height: 24.0),
                loginButton,
              ],
            ),
          ),

      ),
    );
```

윈도우의 XAML, 안드로이드의 XML, 웹의 HTML등 마크업으로 진행하는 UI작업에 너무 익숙해져있던지라 처음에는 굉장히 불편하고 예전 JAVA의 SWING을 떠올리기도 했습니다.

개발하다보니 이는 굉장히 큰 장점으로 다가왔습니다. UI에 로직을 추가하는 일, 데이터 바인딩을 하는 일 등을 마크업과 코드를 왔다갔다하지않고 Dart코드 하나로 모두 처리할 수 있어 개발속도를 높일 수 있었습니다.

그리고 가장 큰 장점으로 `<!-- UI에 주석을 이처럼 달지않고 -->` `//이와같이 달 수 있습니다!`

### 크로스 플랫폼
크로스 플랫폼은 오히려 단점으로 다가왔습니다. 라이브러리 하나를 추가하려면 ios / android 하나 하나 확인해가며 라이브러리 수정을 해야하거나 각기 다른 환경설정을 넣어줘야했고 이후에는 라이브러리 추가하는일이 "상당히 귀찮은 일"로 자리잡게 되었습니다.
또한 ios와 android모두 지향하는 ux부분이 다른데, 플루터는 one code base로 진행되다보니 ios, android가 정체성없는 ux가 나오는 점이 제게는 큰 단점으로 다가왔습니다.
코드내에서 ios android 플랫폼 검사를하여 view를 다르게 보여줄 수 도있는데, 이는 크로스플랫폼이 추구하는 방향은 아니라고 생각되어 적용해보진 않았습니다.

### 생산성
확실히 앱 개발속도는 빠릅니다. 특히나 hot reload의 runtime debuging 기능은 java를 통한 android 개발과는 차원이 다른 수준의 디버깅 경험을 선사해주었습니다. 
집에선 flutter를 하고 사무실에선 android를 하는데, 사무실에서 작업할때마다 얼른 퇴근하고싶다(?)는 생각이 들게끔 해주는 정도였습니다.

![](https://flutter.dev/assets/tools/android-studio/hot-reload-36252b9c05984443ea5cd1960bab0f4ca904a6dfbe71165af4ed7f1b1c037124.gif)


### 결론, 플러터 장점과 단점
장단점을 논하기엔 짧은 기간의 개발이라 조심스럽고 섣부른 판단일수도있습니다만, 
플러터 자체적으로는 실무에 적용하기에 적당히 고려해볼수도있으나 `크로스플랫폼`앱을 실무에 적용하는건 무리가 있을것이라 판단됩니다.

그런데 만약 `크로스플랫폼`을 도입하기로 결정이 된 상태이며 RN/xamarin/flutter중 하나를 고려해야한다면, flutter는 좋은 선택이 될것이라 생각됩니다.


### 장점
- 생산성/디버깅
    - 핫 리로딩은 진짜 환상적임..
- 라이브러리 
    - 생각보다 라이브러리가 많고 라이브러리 가져다쓰기가 편함
    - https://pub.dev/
- 디자인 
    - 머테리얼 디자인이 최적화 되어있고 코드베이스에서 디자인 가이드 적용을 지원함

### 단점
- 디자인 
    - 주관적인 의견이지만 ios android 모두 하나의 ux로 가는건 최악이라고 생각함
    - (사실 이는 모든 크로스플랫폼을 부정하는 것이라..)
    - android용 ios용으로 알아서 view가 변경되는 그런 기술이 나온다면 좋을 것 같음
- 라이브러리 
    - 장점이자 단점인데, 라이브러리 적용할때마다 각 플랫폼별로 설정체크를 해주거나 심할경우 네이티브를 작성해야함
