# install
opencart.cn

## mCrypt扩展

1.sudo gedit /etc/php4/apache2/php.ini
在 Dynamic Extensions 下添加
    extension=mcrypt.so

2.restart:sudo /etc/init.d/apache2 start

## admin
db:op_db
user:admin 
pw:123456