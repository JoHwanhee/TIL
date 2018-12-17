
# 그런 REST API로 괜찮은가?

![]({{site.baseurl}}/Images/web_page_first_screen.jpg)


 DEVIEW 2017 2-2 SECTION [그런 REST API로 괜찮은가](https://tv.naver.com/v/2292653) 영상을 보고나서 작성 하는 글이다. 영상을 본 뒤 전 회사에서 작성했던 REST API를 돌이켜 생각해보니 이런 REST API로는 괜찮지 않았다. 당시에도 REST API 설계에 관심이 많았으나, 내가 작성했던 것들은 무언가 하나씩 잘못되어있었다.
 
 영상에선 [Roy T. Felding](https://twitter.com/fielding?lang=en)의 직접적인 의견들을 토대로 World wide web 부터 현재의 Rest API까지 이르기까지를 설명하고 있다.
 
### Web (1991)
 Q. 어떻게 인터넷에서 정보를 공유할 것인가? 
 
 A. 정보들을 하이퍼텍스트로 연결한다.
 
 1) 표현형식 : HTML
 
 2) 식별자 : URI
 
 3) 전송방법 : HTTP
 
 
**Roy T. Fielding Says**
- _"How do I improve HTTP without breaking the Web?"_
- _"Rest APIs must be hypertext-driven"_
- _"REST API를 위한 최고의 버저닝 전략은 버저닝을 안 하는 것"_

### REST API
REST API는 분산 하이퍼미디어 시스템을 위한 아키텍쳐 스타일이다. 아키텍쳐 스타일은 제약조건의 집합인데, 이 말은 즉 제약조건을 모두 지켜야 REST API라고 말을 할 수 있다는 것이다.

**다음은 REST API의 제약조건들 이다.**

- client-server
- stateless
- cache
- **uniform interface**
- layered system
- code-on-demand (optional) -> 서버에서 코드를 client로 보내어 바로 실행할 수 있어야한다

**uniform interface**
- identification of resources
- manipulation of resources through representations
- self-descriptive messages
- hypermedia as the engine of application sate

self-descriptive messages
 메세지는 스스로에 설명할 수 있어야 한다. 다음은 강연자가 설명하는 self-descriptive messages의 예시이다. Response Message에서 HTTP의 상태 설명과 body의 media type을 충분히 설명하고 있어 self-descriptive 하다고 하는 것이다.

![](./그런%20RestAPI로%20괜찮은가/Images/Self-descriptive message.jpg)



