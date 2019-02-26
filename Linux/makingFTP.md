---
### CentOS vsftpd 설치 및 설정
---

#### 확인
```
rpm -qa vsftpd*
```

#### 설치
```
[root@s16786679aff ~]# yum install vsftpd -y                                                                    
Failed to set locale, defaulting to C                                                                           ```
Loaded plugins: fastestmirror, langpacks                                                                        
                                                                                                      
(중략)

Installed:
  vsftpd.x86_64 0:3.0.2-25.el7

Complete!
```

#### vsftpd.conf 설정
```
vi /etc/vsftpd/vsftpd.conf

anonymous_enable=NO
local_enable=YES
write_enable=YES
local_umask=022
dirmessage_enable=YES
xferlog_enable=YES
connect_from_port_20=YES
xferlog_file=/var/log/xferlog
xferlog_std_format=YES
chroot_local_user=YES
listen=YES
pam_service_name=vsftpd
userlist_enable=YES
tcp_wrappers=YES
```

#### vsftpd 시작
```
service vsftpd start
```

#### vsftpd 자동시작
```
chkconfig vsftpd on
```

#### test 계정 생성
```
useradd testuser
echo 'password' | passwd --stdin testuser
```

#### 접속테스트
```
root@JHH:/mnt/c/Users/JoHwanHui# ftp 0.0.0.0  
Connected to 0.0.0.0                        
220 (vsFTPd 3.0.2)                                  
Name (106.10.35.123:root): testuser                 
331 Please specify the password.                    
Password:                                           
230 Login successful.                               
Remote system type is UNIX.                         
Using binary mode to transfer files.    
```