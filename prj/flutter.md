## 개요
작년말 이사님의 소개로 Flutter라고하는 모바일 크로스플랫폼을 알게 되었습니다. 크로스플랫폼은 특정 프로그램을 하나의 코드를 토대로 개발하게 되면, 운영체제나 기타 환경에 종속되지 않고 모두 동작되는 것을 의미합니다. Flutter또한 크로스플랫폼의 한 종류이며 Dart라고 하는 언어를 이용해 Android와 IOS모두 동작 할 수 있는 프로그램을 만들 수 있는 하나의 플랫폼을 의미합니다. 우리에게 이는 곧 비용 절감으로 다가옵니다. Flutter와 유사한 기술로 Reactive Native(Facebook), XAMARIN(Microsoft)등이 있으며 크로스플랫폼이라는 시장이 큰 시장은 아니지만, 이름을 대면 알만한 기업들이 돈과 시간을 쏟아 투자를 하고 있는 만큼 떠오르는 시장임에는 분명합니다.

저는 현재 회사에서 클라이언트들을 담당하여 개발하고 있습니다. 주로 맡고 있는 서비스는 '메신저' 프로그램이며 WPF 기반의 윈도우 프로그램, Android 기반의 모바일 프로그램 등의 환경에서 개발을 진행하고 있습니다. 클라이언트 프로그램을 주로 다루다보니 자연스레 크로스플랫폼에 관심이 가게 되었고 회사에서 지원하는 프로그램 중 하나인 팀즈(TEAMS)프로그램을 활용하여 플러터를 미리 학습해보고 기술 검증을 하게 되는 좋은 기회를 갖게 되었습니다. 이번 글에서 플러터를 학습하며 보고 듣고 느낀 것을 생생히 소개드리고자합니다.

글은 다음과 같은 순서로 진행 됩니다.
- 러닝커브
- 성능, 크로스플랫폼은 느리다?
- 디자이너와의 협업, 머티리얼 디자인(Material Design) 가이드
- 개발 운영, CI/CD
- 애플리케이션 아키텍쳐, bloc 패턴
- 결론, 실무에 적용하기 위해선

## 0. 러닝커브
새로운 언어를 도입하는데 있어 생각해야할 중요한 점들 중 하나가 러닝커브라고 생각합니다. 이번에 플러터를 하고자 결심한뒤에도 이에대한 점을 버릴수가 없었는데요, 하지만 다행이도 플러터는 java와 매우 유사한 문법을 채택하고 있어 기존 java 베이스로 개발하고 있는 안드로이드 개발자들이라면 플러터 개발에대한 진입장벽이 그렇게 크리라 생각되진 않습니다. 하지만 이는 필자가 Java와 C#에 익숙한 개발자이기에 적용되는 부분이라 생각합니다. JavaScript Base에서 ReactNative에 익숙한 상태라면 제가 느낀 러닝커브와는 반대의 경험을 갖게 되리라 생각됩니다.

## 1. 크로스플랫폼은 느리다?
플러터는 UI를 코드로 그립니다. 윈도우의 XAML, 안드로이드의 XML, 웹의 HTML등 마크업으로 진행하는 UI작업에 너무 익숙해져있던지라 처음에는 굉장히 불편하고 예전 JAVA의 SWING을 떠올리기도 했습니다. 개발하다보니 이는 굉장히 큰 장점으로 다가왔습니다. UI에 로직을 추가하는 일, 데이터 바인딩을 하는 일 등을 마크업과 코드를 왔다갔다하지않고 Dart코드 하나로 모두 처리할 수 있어 개발속도를 높일 수 있었습니다. 

여담으로 더 이상 UI에 주석을 `<!-- 이처럼 달지않고 -->` `//이와같이 달 수 있습니다!`

다음은 플러터로 화면을 그리는 간단한 예 입니다.

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

그렇다면, Flutter는 어떻게 하나의 코드로 두 가지 플랫폼에서 앱을 그릴 수 있을까요? 자세히 알아보기전에 기존 Java나 object-c로 native app이 구동 되는 원리를 보겠습니다. 

![image](uploads/1f35ccfc350433fdabf08cad9c947922/image.png)

Your App 부분이 네이티브 언어로 만들어진 부분입니다. 네이티브 앱은 OEM 위젯이라 하는 플랫폼이 지원하는 위젯들과 소통하여 어떤 위젯을 화면에 표시할지 정하고, 캔버스라는 화면 표시기를 통해 화면에 노출한다. 그리고 그 위젯은 사용자에게 입력을 받아 이벤트를 발생하고, 이 이벤트가 OEM 위젯을 통해 각 위젯의 이벤트로 변환된 뒤에 네이티브 앱으로 돌아온다. 개발자는 이 이벤트를 처리하는 코드를 작성해서 이벤트를 처리할 수 있다. 

위처럼 네이티브 언어로 앱을 개발 하는 방식은 앱의 속도 측면에 있어 큰 이점으로 다가옵니다. ios, android가 모두 하나의 네이티브 언어로 만들어진다면 말이죠. 문제는 여기 있습니다. 하나의 서비스를 출시하기 위해선 ios, android 모두 각기 다른 언어로 똑같은 기능을 만들어야하는 문제가 발생하게 됩니다.

이 불편한 점을 탈피하고자 크로스플랫폼이라는 개념이 나오기 시작했습니다. 이때 등장한것이 ReactNative 라는 크로스플랫폼입니다. Java Script를 이용해 하나의 코드로 앱을 만들고 Bridge에서 각기 다른 플랫폼별 OEM에 접근하여 네이티브 코드로 바꿔서 변환해주었고 이를통해 기존 네이티브 언어로 개발하는 것과 유사한 수준의 개발 경험을 만들어냈습니다.

![image](uploads/fd8a1cd4b342ab5e2a1b8f175035134f/image.png)

하지만 결국 자바스크립트에서 브릿지를 거쳐야하는 이 메커니즘에는 성능 이슈를 계속 야기해왔고 구글은 이를 해결하기 위한 방법을 모색하기 시작했습니다. Flutter는 브릿지 부분을 과감히 빼버리고 아예 네이티브 언어로 코드를 컴파일 해서 앱에 넣어준다.

자세히 알아보자. Flutter는 일종의 프레임워크이며 Dart로 작성된 앱을 컴파일하는 방식이다. Flutter자체적으로 Widget을 제공하며 코드를 작성하게 되면 Flutter Framework에서 자체적으로 네이티브 앱으로 렌더링 해 앱을 만든다.

![image](uploads/9bf68272c5356acfe81bab8c74fd2bb2/image.png)

## 2. Hot reload 기능
Flutter는 앱의 성능 또한 놓치지 않으면서 Hot reload 기능을 제공할 수 있습니다.

Hot reload 기능은 앱이 동작하고 있는 동안 소스코드의 변경사항을 앱에서 확인 할 수 있습니다. 만약 에러가 발생하더라도 앱이 종료되는 것이 아니라 에러 위치를 앱내에서 표시해주며 앱이 구동되고 있는 시점에 개발자가 이를 수정하기만하면 Flutter는 마치 에러가 없었던것처럼 동작합니다. 

이러한 기능은 개발 생산성에 있어 네이티브 언어를 개발과는 차원이 다른 수준의 디버깅 경험을 선사해주었습니다. 

![image](uploads/78f2e8e63ef1dfb85ab718eb526918c0/image.png)

그렇다면 어떻게 이와 같은 일이 가능한걸까요? 핫 리로드 기능이 가능하단걸 알아내기 위해선 우선 Dart가 어떤식으로 컴파일 되는지 알아봐야합니다.

#### 2-1. Dart의 컴파일 방식
Dart는 순수 Dart 인터프리터, JIT(Just-In-Time) 컴파일러, AOT(Ahead-Of-Time) 컴파일러 모두 지원합니다.

JIT 컴파일은 인터프리터처럼 실행 전에 코드를 컴파일하지 않아도 되기 때문에, 코드 수정 때마다 발생하는 빌드 시간을 줄여서 개발자들이 더 편리하게 개발할 수 있다는 장점이 있습니다. 이는 Dart-VM 위에서 동작하기 때문에 가능한 부분이며 큰 장점이기도 하지만 이렇게되면 성능적인 면에서 다른 Native 플랫폼들에 비하면 느리다는 단점이 있습니다. 따라서 Dart는 AOT 컴파일도 지원하기 때문에 실제 배포 시에는 앱능 성능 문제가 해결됩니다.

실제로 flutter의 debug 모드의 apk파일과 release 모드의 apk파일을 열어보면 다음과 같은 파일들이 다르고 app의 size도 34MB -> 15.2MB로 확연히 다르단걸 확인 할 수 있습니다.

![image](uploads/a850e7cbe97e0762db6dfc63199d113b/image.png)

디버그 빌드시 플러터는 kernel snaphost 방식을 채택하고 있어 생기는 byte code 파일들이며 Hot reload 기능을 제공하기 위해선 단순 JIT 컴파일보다 빠른 UI Rendering이 필요한데, kernel snaphost 방식으로 Hot reload 기능을 제공하고 있습니다. 
- kernel_blob.bin
- isolate_snapshot_data
- vm_snapshot_data

### 이 파일들은 무엇을 하는가??
#### isolate_snapshot_data
- Dart 힙의 초기 상태를 나타내며 isolate 관련 정보를 포함합니다.
- VM snapshot과 함께 특정 isolate를보다 빠르게 시작하는 데 도움이됩니다.

#### vm_snapshot_data
- isolate간 공유 된 Dart 힙의 초기 상태를 나타냅니다.
- isolate를 더 빨리 시작하도록 도와줍니다.
- VM에서 주로 사용하는 predefined string 정보를 갖고 있습니다.

플러터 엔진의 코드를 살펴보면 AttemptVMLaunchWithCurrentSettings라는 함수에서 어플리케이션 실행 시에 isolate_snapshot_data와 vm_snapshot_data를 load하고 있는 것을 볼 수 있습니다.

#### kernel_blob.bin
- Flutter 컴파일러에 의해 생성 된 앱 소스의 Dart kernel byte code 입니다. Dart 코드가 변경되면 해당 파일도 함께 변경됩니다. apktool 로 apk파일을 분리하고 kernel_blob.bin의 string을 출력해보면 다음과 같이 실제 소스와 동일한 내용이 포함되어있는걸 확인할 수 있습니다.
    ```console
    apktool d kernel_blob.bin
    ```
    ![image](uploads/e4682ac3d725123821f0ea3eb9be0eda/image.png)
     ```console
    strings kernel_blob.bin > extracted.dart
    ```
    ![image](uploads/aea19052e9b4558c3efde4531b30c0b1/image.png)

## 2-2. flutter의 스레드, isolate
flutter는 기본적으로 단일 스레드에서 동작하고 Reactive Programming을 권장합니다. 이는 이번 프로젝트를 진행하면서도 대부분의 경우 문제가 되지 않았는데, 위에서 isolate라는 개념이 등장하여 간단하게 개념과 사용법 정도로만 훑고 지나가고자 합니다.

isolate는 flutter에서 사용하는 스레드라고 생각하면 됩니다. 다만 특이한 점은 embedder라고 하는 녀셕이 관리하는데 다음 그림과 같이 flutter engine 레이어가 아닌 플랫폼 레이어에 위치하고 있습니다. 따라서 당연하게도 isolate 서로간의 메모리를 공유할 수 없게 되고 API를 통해 flutter engine과 통신하게 됩니다.

![image](uploads/126189661b1ef1564ee8c3569fa73ad3/image.png)

다시 코드 레벨로 돌아와서 앞서 언급했듯이 flutter는 reactive programming 방식을 채택하고 있기때문에 일반적인 경우에선 별도로 isolate를 이용할 필요는 없으나, 비용처리가 큰 연산이 필요한 경우 flutter에서 제공하는 compute 함수를 이용하면 됩니다. compute는 별도의 isolate를 생성하여 특정 연산을 backgroud에서 동작하게 하는 방법이며 다음과 같이 사용할 수 있습니다.

```dart
// 응답 결과를 List<Photo>로 변환하는 함수.
List<Photo> parsePhotos(String responseBody) {
  final parsed = json.decode(responseBody).cast<Map<String, dynamic>>();

  return parsed.map<Photo>((json) => Photo.fromJson(json)).toList();
}

// compute 미 적용 버전
Future<List<Photo>> fetchPhotos(http.Client client) async {
  final response = await client.get('https://jsonplaceholder.typicode.com/photos');

  return parsePhotos(response.body);
}

// compute 적용 버전
Future<List<Photo>> fetchPhotos(http.Client client) async {
  final response = await client.get('https://jsonplaceholder.typicode.com/photos');

  // compute 함수를 사용하여 parsePhotos를 별도 isolate에서 수행합니다.
  return compute(parsePhotos, response.body);
}
```

## 3. 머티리얼 디자인(Material Design) 가이드
머티리얼 디자인은 플랫폼 차원에서 각 디바이스들이 나타내야할 UI/UX에 최적화된 가이드입니다. 해당 가이드는 Google/Android 앱에서 주도적으로 제시하고 있으며 플러터 또한 머티리얼 디자인 가이드를 따르도록 구글에서 제시하고 있습니다. 머티리얼 디자인 가이드를 따른다는 것은 개발자와 디자이너 간 협업에 있어 큰 매력으로 다가오는 부분입니다. 하나의 어플리케이션을 만들고자하면 어플리케이션 설계단계에서 공용 컴포넌트들을 미리 구상하곤 하는데, 이 때 디자이너와 많은 대화를 하며 가이드를 서로 맞춰가는 작업이 필요합니다. 만약 서로 합의된 디자인 가이드가 없다면 매번 새로 생성하는 화면 마다 색상 값을 떠올려야하며, 텍스트 필드가 비슷하지만 어딘지 모르게 종류별로 생겨나게 될것이며 프로젝트 유집보수/관리에 있어 상당한 어려움을 겪게 될 것입니다. 

플러터 내에서는 프레임워크 차원에서 머티리얼 디자인 가이드를 바로 적용할 수 있도록 패키지를 제공하고있고, 디자인 단계에서도 스케치와 제플린을 활용하여 머티리얼 디자인 가이드 적용에 용이합니다. 다음으로는 저희가 이번 프로젝트를 진행하면서 적용하였던 디자인가이드와 그에 대응되는 플러터 디자인 패키지를 통해 플러터에서 어떤 형태로 디자이너와 협업이 되는지 소개드리고자합니다.

### 3-1 색상 가이드
앱 전반적으로 사용되는 색상 가이드입니다. 주요 컬러값을 컬러 팔레트로 추출할 수 있으며 이는 특정 값의 값의 불투명도값을 50 100 200 ... 900 까지 지정하여 코드내에서 Opacity로 조절하는 것이 아니라 각각의 불투명도 값을 Hex code 추출하여 특정 컬러에대한 하나의 색상 팔레트를 완성할 수 있습니다.

![image](uploads/e618cbfd1b97d564878f4eb828894d3d/image.png)
 
다음과 같이하면 플러터 코드 내에서 주요 컬러 팔레트를 쉽게 적용할 수 있습니다.

```dart
// 컬러
MaterialColor createMaterialColor(Color color) {
  List strengths = <double>[.05];
  Map swatch = <int, Color>{};
  
  final int r = color.red, 
            g = color.green, 
            b = color.blue;

  for (int i = 1; i < 10; i++) {
    strengths.add(0.1 * i);
  }

  strengths.forEach((strength) {
    final double ds = 0.5 - strength;
    swatch[(strength * 1000).round()] = Color.fromRGBO(
      r + ((ds < 0 ? r : (255 - r)) * ds).round(),
      g + ((ds < 0 ? g : (255 - g)) * ds).round(),
      b + ((ds < 0 ? b : (255 - b)) * ds).round(),
      1,
    );
  });
  return MaterialColor(color.value, swatch);
}

// 테마 컬러 적용
var primary = createMaterialColor(HexColor.fromHex("FF9E00"))
primarySwatch: primary

// 특정 불투명도가 필요할 경우
Color color = primary[100]
```

### 3-2 테마 적용
또한 머티리얼 디자인 가이드에 맞는 주요 컬러셋을 맞춰 플러터 코드 내에서 쉽게 적용이 가능합니다. 아래는 이번 프로젝트에서 적용한 디자인 컬러 가이드입니다. 

![image](uploads/9454f53693120ae616cc4ec97894de3e/image.png)

위에 대응되는 플러터 코드는 다음과 같습니다. 다음과 같이 적용해두면 앱 전반적으로 각 텍스트의 컬러값과 에러일때의 컬러값 등 모두 통일된 형태로 앱 내에 표시가 되어, 개별 컴포넌트별로 컬러값을 지정해야하는 수고스러움을 덜 수 있습니다.

```dart
class Constants {
  static Color lightPrimary = HexColor.fromHex("fdfdfd");
  static Color lightPrimaryLight = HexColor.fromHex("ffffff");
  static Color lightPrimaryDark = HexColor.fromHex("faf8f6");
  static Color lightAccent = HexColor.fromHex("ff9e00");
  static Color lightAccentLight = HexColor.fromHex("ffd69b");
  static Color lightAccentDark = HexColor.fromHex("ec8102");
  
  static Color darkPrimary = HexColor.fromHex("323232");
  static Color darkPrimaryLight = HexColor.fromHex("505050");
  static Color darkPrimaryDark = HexColor.fromHex("121212");
  static Color darkAccent = HexColor.fromHex("F08E02");
  static Color darkAccentLight = HexColor.fromHex("F7C67E");
  static Color darkAccentDark = HexColor.fromHex("E67302");

  // 라이트 테마
  static ThemeData lightTheme = ThemeData(
    fontFamily: "NotoSans",
    backgroundColor: lightBG,
    accentColor:  lightAccent,
    primaryColorLight: lightPrimaryLight,
    primaryColorDark: lightPrimaryDark,
    primaryColor: lightPrimary
  );

  // 다크 테마
  static ThemeData darkTheme = ThemeData(
    fontFamily: "NotoSans",
    backgroundColor: darkBG,
    accentColor:  darkAccent,
    primaryColorLight: darkPrimaryLight,
    primaryColorDark: darkPrimaryDark,
    primaryColor: darkPrimary
  );
}

// 실제 테마가 적용되는 코드 (어플리케이션의 최상단 클래스)
class MyApp extends StatelessWidget {
    @override
    Widget build(BuildContext context) {
        return Consumer<AppProvider>(
            builder: (BuildContext context, AppProvider appProvider, Widget child) {
                return MaterialApp(
                    key: appProvider.key,
                    debugShowCheckedModeBanner: false,
                    navigatorKey: appProvider.navigatorKey,
                    title: Constants.appName,
                    // 라이트테마 적용
                    theme: Constants.lightTheme,
                    // 다크테마 적용
                    darkTheme: Constants.darkTheme,
                    // 중략     
                    },
                );
            },
        );
    }
}

```

## 4. CI/CD
CI/CD 없이 개발 하는것은 유지보수에 있어 큰 불편함을 주게 됩니다. 앱을 배포하려면 내 로컬 PC에 관련 개발환경을 모두 구축 한 뒤 릴리즈 빌드를 하고 앱 서명하고 서명된 파일 (안드로이드 기준, apk 혹은 aab)을 구글 플레이 스토어에 등록해야합니다. 이 과정에서 테스트 코드가 있다면 로컬에서 따로 테스트도 진행해주어야 합니다.

사실 이러한 일은 크게 어려움으로 다가오진 않습니다. 하지만 여러 사람이 협업하는 과정에선 큰 불편함이 될 수 있습니다. 빌드 환경이 한 PC에만 구축되어있다면 대상 PC의 사용자가 자리에 없다면 다른 사람의 PC에 또 같은 환경 설정을 해주어야겠죠.

플러터또한 CI/CD를 설정할 수 있습니다. 저는 이번프로젝트에서 플러터 CI/CD를 gitbub에 새롭게 도입된 actions로 이 처리를 했습니다. 

다음은 ubuntu 환경에서 jvm과 flutter를 설치하고 flutter package 설치, 테스트, 빌드, 플레이스토어 등록까지 이뤄지는 스크립트입니다. 간단하게 빌드, 테스트, 배포까지 자동화할 수 있었습니다.

Ubuntu 개발환경
``` yaml
    runs-on: ubuntu-latest
```

java 및 flutter 설정
```yaml
    steps:
    - uses: actions/checkout@v1
    - uses: actions/setup-java@v1
      with:
        java-version: '12.x'
    - uses: subosito/flutter-action@v1
      with:
        channel: 'stable' # or: 'dev' or 'beta'
```

flutter 패키지설치, 테스트, 빌드
```yaml
    - run: flutter pub get
    - run: flutter test
    - run: flutter build appbundle
```

google play store 등록
```yaml
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

## 5. bloc 패턴
클라이언트 프로그램을 개발 하는 방법은 아주 다양하고 인터넷 세상엔 수 많은 개발자들의 소스코드가 존재합니다. 이에 있어 같은 동작을 하는 프로그램일지라도 각기 다른 형태의 소스코드가 있으며 정답 또한 없습니다. 프로그래밍엔 정답이 없기 때문입니다. 하지만 한 번 작성한 코드를 다시 봤을 때 유지보수하기 좋은 코드는 분명 존재합니다. 잘 설계된 프로그램의 구조는 시시때때로 변화하는 요구사항에 대한 대처를 용이하게 해주며 각 계층별 테스트 코드를 작성할 수 있게끔 해주고 개발자들의 퇴근 시간을 앞 당길 수 있는 좋은 이점으로 다가옵니다.

수 많은 선배 개발자들이 좋은 구조를 소개하고 있으며 여러 개발환경에 따라 적용되는 프로그램의 구조또한 다양합니다. 플러터에서는 클라이언트 프로그램 설계 패턴 중 하나인 MVVM패턴의 일환인 Bloc 패턴을 권장하고 있습니다. 

클라이언트 프로그램 설계 패턴에서 중요시하게 생각되는 점은 Separation of concerns (https://en.wikipedia.org/wiki/Separation_of_concerns) 즉, 관심사 분리 입니다. 흔히 일어나는 실수중 하나는 UI에 모든 코드를 작성하는 경우입니다. 

UI 기반의 클래스는 사용자와 UI 그리고 운영체제 간의 인터페이스 역할을 처리하는 로직만 작성해야합니다. UI 관련 클래스를 최대한 가볍게 유지하면 라이프 사이클에 관련된 많은 에러로부터 자유로워질 수 있습니다. 반대로 UI 클래스가 무거워질수록 프로그램의 유지보수는 어려워지고 코드가 분리되어있지 않기때문에 중복된 코드가 발생할 확률이 커지게 됩니다. Android에서는 Activity와 Fragment, ios에서는 ViewController와 ContainerView가 이에 해당합니다.

MVVM패턴에서 중요하게 보는 점은 바로 이런 점 입니다. View(UI)는 사용자와의 상호작용을 담당하고 ViewModel에서 UI에 표시될 데이터를 관리하며 실제 데이터는 Model에 적재 됩니다. 

Flutter의 Bloc 패턴을 적용하면 다음 그림처럼 관심사가 분리됩니다.

![image](uploads/945ffddd2d7b7ec78fd21bc26bdda405/image.png)

플러터 앱을 만들면 기본적으로 생성되는 카운터 예제를 통해 아주 간단하게 Bloc 패턴을 사용하는 예제를 보여드리도록 하겠습니다.

다음은 Android studio에서 flutter 앱을 만들면 기본으로 제공되는 소스입니다.
```dart
class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;

  void _incrementCounter() {
    setState(() {
      _counter++;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              'You have pushed the button this many times:',
            ),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.display1,
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementCounter,
        tooltip: 'Increment',
        child: Icon(Icons.add),
      ), 
    );
  }
}
```

다음 소스를 보면 ui 에서 _incrementCounter이벤트 발생 시 setState로 화면 갱신을 하고 있으며 ui에서 데이터에 직접 접근하는 일이 발생하고 있습니다. 또한 이는 다른 UI에서 동일한 데이터를 참조할 수 있는 방법이 없어 다른 ui에서 counter라는 데이터에 접근하기가 매우 까다로운 구조입니다.
```dart
    setState(() {
      _counter++;
    });
```

bloc 패턴 적용을 위해 먼저 rxdart 라이브러리를 참조합니다.
```yaml
dependencies:
  rxdart: ^0.24.0
```

그리고나서 CounterBloc.dart 파일을 생성하여 다음과 같이 작성해줍니다. 다음은 Stream을 만들어 ui에서 구독할 수 있는 형태로 개선될겁니다. 이렇게되면 여러 ui에서 _counter라는 데이터에 접근할 수 있게 됩니다. xxBloc는 mvvm의 ViewModel에 해당하고 _counter가 Model에 해당합니다. 이 예제에선 간단한 형태의 앱 이기에 Model class를 따로 분리하지 않았습니다.

```dart
import 'dart:async';
import 'package:rxdart/rxdart.dart';

class CounterBloc {
  int _counter;

  CounterBloc() {
    _counter = 1;
    _actionController.stream.listen(_increaseStream);
  }

  final _counterStream = BehaviorSubject<int>.seeded(1);

  Stream get pressedCount => _counterStream.stream;
  Sink get _addValue => _counterStream.sink;

  StreamController _actionController = StreamController();
  StreamSink get incrementCounter => _actionController.sink;

  void _increaseStream(data) {
    _counter += 1;
    _addValue.add(_counter);
  }

  void dispose() {
    _counterStream.close();
    _actionController.close();
  }
}
```

그리고 ui로직을 다음과 같이 변경합니다.

```dart

class MyHomePage extends StatelessWidget {
  CounterBloc counterBloc = CounterBloc();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: StreamBuilder<int>(
            stream: counterBloc.pressedCount,
            builder: (context, snapshot) {
              return Text(
                '${snapshot.data.toString()}',
              );
            }),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              'You have pushed the button this many times:',
            ),
            StreamBuilder<int>(
                stream: counterBloc.pressedCount,
                builder: (context, snapshot) {
                  return Text(
                    '${snapshot.data.toString()}',
                    style: Theme.of(context).textTheme.display1,
                  );
                }),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
          onPressed: () {
            // event를 정의하여 넘겨주어야 되지만, 예제 특성 상 null을 전달
            counterBloc.incrementCounter.add(null);
          },
          tooltip: 'Increment',
          child: Icon(Icons.add),
        ),
    );
  }
}
```

다음 코드를 확인해보면, UI에서 `onPressed`에 event를 걸어 `setState()`로 데이터를 조작하던 방식을 `onPressed`에 counterBloc(ViewModel)에게 add envet를 전달하는 형태로 변경되었고, StreamBuilder로 data를 구독하는 형태로 변경하여 `setState()`를 할 필요가 없어졌습니다.
 
```dart
onPressed: () {
            // event를 정의하여 넘겨주어야 되지만, 예제 특성 상 null을 전달
            counterBloc.incrementCounter.add(null);
          },

StreamBuilder<int>(
            stream: counterBloc.pressedCount,
            builder: (context, snapshot) {
              return Text(
                '${snapshot.data.toString()}',
              );
            }),
```

또한 자세히 확인해보면, 기본 예제에선 StatefulWidget을 상속받아 화면을 만들고 있었지만 Bloc 패턴을 사용함으로써 StatelessWidget만으로도 화면 갱신이 가능한 코드를 작성할 수 있게 만들어졌습니다.

## 6. 앞으로 실무에서 사용할 예정인가?
위에서 소개드린바와 같이 이번 프로젝트를 통해 플러터의 성능, 머티리얼 디자인(Material Design) 가이드, CI/CD, 애플리케이션 아키텍쳐(bloc 패턴) 모두 만족할만한 결과를 얻었습니다. 하지만 장단점을 논하기엔 짧은 기간의 개발이라 조심스럽고 섣부른 판단일수도있습니다만, 플러터 자체적으로는 실무에 적용하기에 충분하지만, 플러터가 제공하는 라이브러리이 현재로서는 아직 부족한 감이 없지않나 싶습니다.

이번 프로젝트에서 QR코드를 찍어 사내 도서 대출을 하는 기능이 있었는데, 아주 당연한 이야기지만 플러터가 세상 밖으로 나온지 얼마 채 되지 않았기에 제공하는 플러그인이 아직 불안정한 모습을 많이 보였습니다. ios / android native 소스를 별도로 커스텀하는 과정이 필요했습니다. 이렇게 코드를 짜다보니 크로스플랫폼이 가지는 의미가 무엇인지 반추하게 되었습니다. 

지금까지 이야기한 내용들을 종합해 결론 내보면 플러터는 높은 생산성과 만족할만한 앱 퍼포먼스를 가지고 있지만 개발 이후에 유지보수가 필요할때마다 생기는 리스크가 어느정도 있다라는 결론에 도달할 수 있었습니다. 

하지만 플러터는 아직 성장단계이며 오픈소스 라이브러리의 이슈는 플러터의 성장에따라 이슈가 적어지리라 생각됩니다. 2018년도에 배우지 말아야할 언어 1위로 선정되기도 했지만 구글과 관련 개발자들의 노력으로 2019년도에는 Job market 부분을 제외하고선 모두 하위권으로 내려간 상태입니다. 

![image](uploads/d1d3dfa65b5aa79ac58c38aa219bcaec/image.png)
- https://www.codementor.io/blog/worst-languages-to-learn-3phycr98zk

