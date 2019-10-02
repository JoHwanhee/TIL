### 자바 NIO 기반 Http Server 만들기

1. NIO SocketChannel 생성

```java
ServerSocketChannel serverSocketChannel = null;
serverSocketChannel = ServerSocketChannel.open();
serverSocketChannel.configureBlocking(true);
serverSocketChannel.bind(new InetSocketAddress(PORT));
```

2. Wait
```
SocketChannel socketChannel = serverSocketChannel.accept();
InetSocketAddress isa = (InetSocketAddress) socketChannel.getRemoteAddress();
System.out.println(isa.getHostName());

```

3. Read
```
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
```
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
```
if (serverSocketChannel != null && serverSocketChannel.isOpen()) {
	try {
		serverSocketChannel.close();
	} catch (IOException e1) {
		e1.printStackTrace();
	}
}
```