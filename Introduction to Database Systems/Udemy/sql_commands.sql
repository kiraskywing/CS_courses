-- Start MySQL on Cloud9
mysql-ctl cli;

-- Start MySQL on loacl:
brew install mysql
mysql_secure_installation  //set a password for root user

mysql.server start -- to start the mysql server
mysql -u root -p -- provide the new password
mysql.server stop -- to stop the server

-- List available databases:
show databases;

-- The general command for creating a database:
CREATE DATABASE database_name;

-- To drop a database:
DROP DATABASE database_name;

-- Using databases:
USE database_name;
-- Show currently database:
SELECT database();

-- Create & show table:
CREATE TABLE tablename
  (
    column_name data_type NOT NULL DEFAULT ...,
    column_name data_type NOT NULL DEFAULT ...,
    ...
  );

SHOW TABLES;
SHOW COLUMNS FROM tablename;
DESC tablename;

-- Dropping tables:
DROP TABLE tablename;

-- Insert data:
INSERT INTO table_name(column_name) VALUES (data);

-- Show all datas in table:
SELECT * FROM tablename;

-- Show warnings:
SHOW WARNINGS;

-- Primary key & automatic increment:
CREATE TABLE unique_cats2 (
    cat_id INT NOT NULL AUTO_INCREMENT,
    name VARCHAR(100),
    age INT,
    PRIMARY KEY (cat_id)
);