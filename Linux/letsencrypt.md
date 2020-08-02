습작으로 만든 애플리케이션의 게시판기능이 정상동작하지 않고 있었다. 문제는 인증서가 만료되어있던것! 우선 수동으로 인증서 갱신하는 법을 검색해 갱신을 해주었다. certbot을 이용하면 되었기에 큰 어려움없이 갱신했다.

### 인증서 갱신
```
./certbot-auto renew
```

### COPY
```
sudo cp /etc/letsencrypt/live/[도메인주소]/* ./
```

### .Key 변환
```
openssl rsa -in privkey.pem -text > [도메인 주소].key
```

### .crt 변환
```
openssl x509 -inform PEM -in fullchain.pem -out [도메인 주소].crt
```
