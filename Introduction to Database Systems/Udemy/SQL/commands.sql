-- Start MySQL on Cloud9
mysql-ctl cli;

-- Start MySQL on loacl:
brew install mysql
mysql_secure_installation  //set a password for root user

mysql.server start -- to start the mysql server
mysql -u root -p -- provide the new password
mysql.server stop -- to stop the server