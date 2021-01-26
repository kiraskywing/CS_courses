-- Start MySQL on Cloud9
mysql-ctl cli;

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
    column_name data_type,
    column_name data_type
    ...
  );

SHOW TABLES;
SHOW COLUMNS FROM tablename;
DESC tablename;

-- Dropping tables:
DROP TABLE tablename;

-- Insert data:
INSERT INTO table_name(column_name) VALUES (data);