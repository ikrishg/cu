<?php

include "connect.php";

$name = $_POST['name'];
$email = $_POST['email'];
$password = $_POST['password'];
$mobile = $_POST['mobile'];
$age = $_POST['age'];

$sql = "INSERT INTO students (name, email, password, mobile, age)
        VALUES ('$name', '$email', '$password', '$mobile', '$age')";

if ($conn->query($sql) === TRUE) {
    echo "Student saved successfully!";
} else {
    echo "Error: " . $conn->error;
}

$conn->close();

?>
