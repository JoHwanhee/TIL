# 플러터로 개발하기
작년말 지인의 소개로 Flutter라고하는 모바일 크로스플랫폼을 알게 되었습니다. 크로스플랫폼은 특정 프로그램을 하나의 코드를 토대로 개발하게 되면, 운영체제나 기타 환경에 종속되지 않고 모두 동작되는 것을 의미합니다. 앞에서 언급한 Flutter또한 크로스플랫폼의 한 종류이며 조금 더 구체적으로 말해서, Flutter는 Dart라고 하는 언어를 이용해 Android와 IOS모두 동작 할 수 있는 프로그램을 만들 수 있는 하나의 플랫폼을 의미합니다. 이는 곧 비용 절감으로 우리에게 다가옵니다. Flutter와 유사한 기술로 Reactive Native(Facebook), XAMARIN(Microsoft)등이 있으며 크로스플랫폼이라는 시장이 큰 시장은 아니지만, 이름을 대면 알만한 기업들이 돈과 시간을 쏟아 투자를 하고 있는 만큼 떠오르는 시장임에는 분명합니다.

저는 현재 회사에서 클라이언트들을 담당하여 개발하고 있습니다. 주로 맡고 있는 서비스는 '메신저' 프로그램이며 WPF 기반의 윈도우 프로그램, Android 기반의 모바일 프로그램 등의 환경에서 개발을 진행하고 있습니다. 클라이언트 프로그램을 주로 다루다보니 자연스레 크로스플랫폼에 관심이 가게 되었고 회사에서 지원하는 프로그램 중 하나인 팀즈(TEAMS)프로그램을 활용하여 플러터를 미리 학습해보고 기술 검증을 하게 되는 좋은 기회를 갖게 되었습니다. 이번 글에서 플러터를 학습하며 보고 듣고 느낀 것을 생생히 소개드리고자합니다.

### 머테리얼 디자인 가이드
플러터는 구글에서 개발하고 있는 프레임워크이며 머테리얼 디자인 가이드또한 구글에서 제시하는 UI 디자인 가이드다보니, 프레임워크차원에서 머테리얼 디자인 가이드에 맞춰 개발을 진행할 수 있는 점이 상당히 매력적으로 다가왔습니다. 처음에는 생소한 디자인 가이드라 그런지 저도 그렇고 디자이너님도 그렇고 어떤식으로 방향을 잡아야할지 난항을 겪었으나, 이후 개발을 직접 진행하면서는 전체적인 스타일이 다 잡힌 상태로 개발을 하는거라 그런지 코드양이 확실히 많이 줄고 새로운 컴포넌트를 추가할때도 편리하다는 장점이 있었습니다. 또한 테마변경 기능이 제공되어 다크테마 / 라이트테마 적용을 정말 색상값만 추가해주기만해도 바로 적용되는 모습을 봤을 때 감격을 눈물을 감출 수 없었습니다.

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

### UI 개발
플러터는 UI를 코드로 그립니다. 윈도우의 XAML, 안드로이드의 XML, 웹의 HTML등 마크업으로 진행하는 UI작업에 너무 익숙해져있던지라 처음에는 굉장히 불편하고 예전 JAVA의 SWING을 떠올리기도 했습니다. 개발하다보니 이는 굉장히 큰 장점으로 다가왔습니다. UI에 로직을 추가하는 일, 데이터 바인딩을 하는 일 등을 마크업과 코드를 왔다갔다하지않고 Dart코드 하나로 모두 처리할 수 있어 개발속도를 높일 수 있었습니다. 그리고 가장 큰 장점으로 `<!-- UI에 주석을 이처럼 달지않고 -->` `//이와같이 달 수 있습니다!`

다음은 플러터로 화면을 그리는 간단한 예 입니다.

```dart
return Scaffold(
      body: SafeArea(
        child: Center(
            // 이런식으로 주석이 가능하다.
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

### 러닝커브
새로운 언어를 도입하는데 있어 생각해야할 중요한 점들 중 하나가 러닝커브라고 생각합니다. 이번에 플러터를 하고자 결심한뒤에도 이에대한 점을 버릴수가 없었는데요, 하지만 다행이도 플러터는 java와 매우 유사한 문법을 채택하고 있어 기존 java 베이스로 개발하고 있는 안드로이드 개발자들이라면 플러터 개발에대한 진입장벽이 그렇게 크리라 생각되진 않습니다.

### 생산성
확실히 앱 개발속도는 빠릅니다. 특히나 hot reload의 runtime debuging 기능은 java를 통한 android 개발과는 차원이 다른 수준의 디버깅 경험을 선사해주었습니다. 집에선 flutter를 하고 사무실에선 android를 하는데, 사무실에서 작업할때마다 얼른 퇴근하고 집에가서 flutter로 개발 하고 싶다는 생각이 들게끔 해주는 정도였습니다.

![](https://flutter.dev/assets/tools/android-studio/hot-reload-36252b9c05984443ea5cd1960bab0f4ca904a6dfbe71165af4ed7f1b1c037124.gif)

### CI/CD
CI/CD가 지원됩니다. 자료가 많진 않았지만, gitbub에 새롭게 도입된 actions에서 이 처리를 했습니다. 다음은 ubuntu 환경에서 jvm과 flutter를 설치하고 flutter package 설치, 테스트, 빌드, 플레이스토어 등록까지 이뤄지는 스크립트입니다. 간단하게 빌드, 테스트, 배포까지 자동화할 수 있었습니다.

```yaml
name: Flutter action

on:
  push:
    branches: [ master ]
  pull_request:
    branches: [ master ]

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v1
    - uses: actions/setup-java@v1
      with:
        java-version: '12.x'
    - uses: subosito/flutter-action@v1
      with:
        channel: 'stable' # or: 'dev' or 'beta'
    - run: flutter pub get
    - run: flutter test
    - run: flutter build appbundle
    - uses: r0adkll/upload-google-play@v1
      with:
        packageName: 
        releaseFile: 
        serviceAccountJson: /app/serviceAccount.json
        track: beta
        userFraction: 0.33
        whatsNewDirectory: /distribution/whatsnew
        mappingFile: /app/build/outputs/mapping/release/mapping.txt
```

### bloc 패턴
보통 클라이언트 프로그램을 개발할 때 클라이언트 개발 패턴을 적용하는 일은 굉장히 중요합니다. 클라이언트 특성상 앱을 한 번 배포해버리면 롤백이 힘들고 수 많은 유저들이 어떤 행위(?)를 할지 예측이 안 되기때문에 항상 언제든 변경 가능한 코드를 유지하는점이 중요합니다. 

또한 클라이언트 프로그램에서 정말 중요한 점은 Reactive Programming 입니다. Reactive Programming은 이야기하면 할 이야기가 정말 많으니, 링크하나 남기는것으로 대체하도록 하겠습니다. (https://www.didierboelens.com/2018/08/reactive-programming-streams-bloc/)

글을 이어가서, 필자는 현재 Windows Client (WPF) 기반의 메신저 개발을 주로 하고 있는데, WPF는 주로 MVVM패턴으로 개발이 이뤄지며 이번에 플러터를 학습하면서도 이와 비슷한 개발 패턴이 무엇이있나 찾아보았습니다.

다행이도 MVVM과 비슷한 개발패턴이 있었고, Google에서 권장하는 Bloc 개발 패턴이 있었습니다. 간단한 그림을 통해 전체적인 구조도를 보면 좋을 것 같습니다. 

![](https://miro.medium.com/max/1400/1*MqYPYKdNBiID0mZ-zyE-mA.png)

### 크로스 플랫폼
플러터에서 채택하고있는 크로스 플랫폼 환경은 오히려 단점으로 다가왔습니다. 라이브러리 하나를 추가하려면 ios / android 하나 하나 확인해가며 라이브러리 수정을 해야하거나 각기 다른 환경설정을 넣어줘야했고 이후에는 라이브러리 추가하는일이 "상당히 귀찮은 일"로 자리잡게 되었습니다. 또한 ios와 android모두 지향하는 ux부분이 다른데, 플루터는 one code base로 진행되다보니 ios, android가 정체성없는 ux가 나오는 점이 제게는 큰 단점으로 다가왔습니다. 코드내에서 ios android 플랫폼 검사를하여 view를 다르게 보여줄 수 도있는데, 공식문서에서 말하길 이런식으로 사용할 경우 성능상 문제가 발생할 수 있어 되도록 지양한다고 적혀 있었습니다. 아무래도 하지말라는 짓은 하지 않는 편이기에 결국 ios와 android 모두 통일된 ui/ux로 개발을 할 수 밖에없었습니다.

### 앞으로 실무에서 사용할 예정인가?
장단점을 논하기엔 짧은 기간의 개발이라 조심스럽고 섣부른 판단일수도있습니다만, 플러터 자체적으로는 실무에 적용하기에 아직 부족한 감이 없지않나 싶습니다. 위에서 생산성과 크로스 플랫폼 이야길 했지만 아직 라이브러리 차원에서 제공해야할 문제점들이 많이 보였습니다.

이번 프로젝트에서 QR코드를 찍어 사내 도서 대출을 하는 기능이 있었는데요, 아주 당연한 이야기지만 플러터가 세상 밖으로 나온지 얼마 채 되지 않았기에 제공하는 플러그인이 아직 불안정한 모습을 많이 보였습니다. ios / android native 소스를 별도로 커스텀하는 과정이 필요했습니다. 이렇게 코드를 짜다보니 크로스플랫폼이 가지는 의미가 무엇인지 반추하게 되었습니다. 여담으로 오픈소스 환경이 제대로 갖춰지지 않아 문의를 남기면 한달뒤에나 답변오는 일이 많았고 오픈소스 라이브러리들의 대부분이 아직은 중국어로 되어있어 언어의 장벽에도 부딪혔습니다. 

지금까지 이야기한 내용들을 종합해 결론 내보면 플러터는 높은 생산성을 가지고 있지만 개발 이후에 유지보수가 필요할때마다 생기는 리스크가 너무 크다라는 결론까지 도달할 수 있었습니다. 따라서 저희 가비아 애플리케이션 개발팀내의 실무에서 플러터를 사용하는 일은 힘들거같다라는 결론을 내리게 됐습니다. 개인적인 생각으로는 업무외에 따로 진행하는 토이프로젝트 혹은 빠르게 선보여야할 프로토타입용 프로젝트에 플러터가 적합하지 않을까 사료됩니다.
