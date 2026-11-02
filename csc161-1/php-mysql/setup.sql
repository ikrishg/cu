-- Run this once in phpMyAdmin (or mysql CLI) before using Lab 7.

CREATE DATABASE IF NOT EXISTS student_db;
USE student_db;

CREATE TABLE IF NOT EXISTS students (
  id INT AUTO_INCREMENT PRIMARY KEY,
  name VARCHAR(100) NOT NULL,
  email VARCHAR(100) NOT NULL,
  password VARCHAR(100) NOT NULL,
  mobile VARCHAR(20) NOT NULL,
  age INT NOT NULL
);
