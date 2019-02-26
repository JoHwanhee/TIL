## NIO 기반 Http Server Lib를 만들어보자.

---
### 테스트코드 작성
---
127.0.0.1:8080에 접속했을 때 ok가 뜨도록 테스트 코드를 작성하자.

```java
public class NIOHttpServerTest
{
    private NIOHttpServer nioHttpServer = null;

    @Before
    public void setUp(){
        nioHttpServer = new NIOHttpServer(8080);
        nioHttpServer.start();
    }

    @Test
    public void localhost_접근시_http_response가_있어야함(){
        try {
            URL url = new URL("http://localhost:8080");
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            System.out.println("Response code: " + conn.getResponseCode());

            Assert.assertTrue(conn.getResponseCode() == 200);

            BufferedReader rd;
            if(conn.getResponseCode() >= 200 && conn.getResponseCode() <= 300) {
                rd = new BufferedReader(new InputStreamReader(conn.getInputStream()));
            } else {
                rd = new BufferedReader(new InputStreamReader(conn.getErrorStream()));
            }
            StringBuilder sb = new StringBuilder();
            String line;
            while ((line = rd.readLine()) != null) {
                sb.append(line);
            }
            rd.close();
            conn.disconnect();
            System.out.println(sb.toString());
        }
        catch (Exception e){
            System.out.println(e);
        }
    }

    @After
    public void dispose(){
        nioHttpServer.stop();
    }
}

```


---
### 서버 생성
---
1. NIO SocketChannel 생성

```java
ServerSocketChannel serverSocketChannel = null;
serverSocketChannel = ServerSocketChannel.open();
serverSocketChannel.configureBlocking(true);
serverSocketChannel.bind(new InetSocketAddress(PORT));
```

2. Wait
```java
SocketChannel socketChannel = serverSocketChannel.accept();
InetSocketAddress isa = (InetSocketAddress) socketChannel.getRemoteAddress();
System.out.println(isa.getHostName());

```

3. Read
```java
ByteBuffer buffer = ByteBuffer.allocate(4096);
int byteCount = socketChannel.read(buffer);
System.out.println(byteCount);
buffer.flip();

Charset charset = Charset.forName("UTF-8");
String data = charset.decode(buffer).toString();

System.out.println(data);
```

4. Write

테스트 용도이기에 HTTP Header를 하드코딩으로 넣어주었다.
```java
byte[] data2 = "ok".getBytes();
String content = "HTTP/1.1 200 OK\n" +
				 "Server: Java HTTP NIO Server from hhcompany : 1.0\n" +
				 "Date: " + new Date()+
				 "Content-type: " +"text/plain" + "\n"+
				 "Content-length: " + data2.length +"\n"+
				 "\n";

content+= "ok";

ByteBuffer byteBuffer = null;
byteBuffer = charset.encode(content);

socketChannel.write(byteBuffer);
```

5. Close
```java
if (serverSocketChannel != null && serverSocketChannel.isOpen()) {
	try {
		serverSocketChannel.close();
	} catch (IOException e1) {
		e1.printStackTrace();
	}
}
```
