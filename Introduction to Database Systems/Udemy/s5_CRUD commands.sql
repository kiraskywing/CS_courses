-- List available databases:
SHOW databases;
-- The general command for creating a database:
CREATE DATABASE database_name;
-- To drop a database:
DROP DATABASE database_name;
-- Using databases:
USE database_name;
-- Show currently database:
SELECT database();
-- Show table:
SHOW TABLES;
SHOW COLUMNS FROM tablename;
DESC tablename;
-- Show all datas in table:
SELECT * FROM tablename;
-- Show warnings:
SHOW WARNINGS;
-- Dropping tables:
DROP TABLE tablename;
-- Show warnings:
SHOW WARNINGS;


CREATE TABLE employees (
    id INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
    first_name VARCHAR(255) NOT NULL,
    last_name VARCHAR(255) NOT NULL,
    middle_name VARCHAR(255),
    age INT NOT NULL,
    current_status VARCHAR(255) NOT NULL DEFAULT 'employed'
);

INSERT INTO employees(first_name, last_name, age) 
VALUES ('Dora', 'Smith', 58);

CREATE TABLE cats 
( 
    cat_id INT NOT NULL AUTO_INCREMENT, 
    name   VARCHAR(100), 
    breed  VARCHAR(100), 
    age    INT, 
    PRIMARY KEY (cat_id) 
); 

INSERT INTO cats(name, breed, age) 
VALUES ('Ringo', 'Tabby', 4),
       ('Cindy', 'Maine Coon', 10),
       ('Dumbledore', 'Maine Coon', 11),
       ('Egg', 'Persian', 4),
       ('Misty', 'Tabby', 13),
       ('George Michael', 'Ragdoll', 9),
       ('Jackson', 'Sphynx', 7);

SELECT cat_id, name, age FROM cats;
SELECT * FROM cats WHERE age=4;
SELECT * FROM cats WHERE name='Egg';
SELECT * FROM cats WHERE cat_id=age;
SELECT name AS 'cat name', breed AS 'kitty breed' FROM cats;
UPDATE cats SET breed='Shorthair' WHERE breed='Tabby';
UPDATE cats SET age=14 WHERE name='Misty'; 
DELETE FROM cats WHERE name='Egg';
DELETE FROM cats; -- Delete every entry in the table, but the table still exists.